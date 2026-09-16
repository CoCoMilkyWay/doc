# Kaggle Optiver量化竞赛金牌网络方案分享-含代码。

None 量化前沿速递 2024-04-08 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487739&idx=1&sn=a6677a58da788c0f60026f44f5f8e0ed&chksm=c31aa3f30bbf14cb9a16b8659bd4c034516c570f899db34895bd9c54ce3bde6c62b2e18cb738#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487739&idx=1&sn=a6677a58da788c0f60026f44f5f8e0ed&chksm=c31aa3f30bbf14cb9a16b8659bd4c034516c570f899db34895bd9c54ce3bde6c62b2e18cb738#rd)

# 

  

**Kaggle Optiver量化竞赛金牌网络方案分享-含代码。**

##   

简介

![](assets/001.png)

本文介绍在最新结束的Kaggle Optiver量化比赛中第七名的网络模型框架。第七名方案的网络框架主要是LSTM和ConvNet模型，其中包含了全局的股票统计特征以及偏离的特征用来加速收敛。

## 

细节

![](assets/001.png)

-   online learning可以大大降低误差；
    
-   Deviation特征可以帮助大大降低误差；
    
-   Deviation主要是使用原始特征减去中位数；
    

##   

网络代码

![](assets/001.png)

-   cate特征的embedding之后+convnet
    
-   数值特征的序列+convnet
    
-   diff数值特征+convnet
    

### ConvNet

`def apply_conv_layers(input_layer, kernel_sizes, filters=16, do_ratio=0.5):              conv_outputs = []          for kernel_size in kernel_sizes:                      conv_layer = Conv1D(filters=filters, kernel_size=kernel_size, activation='relu', padding='same')(input_layer)           conv_layer = BatchNormalization()(conv_layer)           conv_layer = Dropout(do_ratio)(conv_layer)              shortcut = conv_layer              conv_layer = Conv1D(filters=filters, kernel_size=kernel_size, padding='same')(conv_layer)           conv_layer = BatchNormalization()(conv_layer)           conv_layer = Activation('relu')(conv_layer)              # Add the output of the first Conv1D layer           conv_layer = Add()([conv_layer, shortcut])           conv_outputs.append(conv_layer)             concatenated_conv = Concatenate(axis=-1)(conv_outputs)       flattened_conv_output = Flatten()(concatenated_conv)          return flattened_conv_output   `

`def create_rnn_model_with_residual(window_size, numerical_features, initial_learning_rate=0.001):          categorical_features = 'seconds_in_bucket'       categorical_uniques  = { 'seconds_in_bucket' : 55}       embedding_dim        = {'seconds_in_bucket'  : 10}          input_layer = Input(shape=(window_size, len(numerical_features) + 1), name="combined_input")          # Split the input into numerical and categorical parts       numerical_input   = Lambda(lambda x: x[:, :, :-1], name="numerical_part")(input_layer)       categorical_input = Lambda(lambda x: x[:, :, -1:], name="categorical_part")(input_layer)          first_numerical = Lambda(lambda x: x[:, 0])(numerical_input)             # diffrentiate layers       def create_difference_layer(lag):           return Lambda(lambda x: x[:, lag:, :] - x[:, :-lag, :], name=f"difference_layer_lag{lag}")          difference_layers = []       for lag in range(1, window_size):           diff_layer = create_difference_layer(lag)(numerical_input)           padding    = ZeroPadding1D(padding=(lag, 0))(diff_layer)  # Add padding to the beginning of the sequence           difference_layers.append(padding)       combined_diff_layer = Concatenate(name="combined_difference_layer")(difference_layers)             # Embedding for categorical part       vocab_size, embedding_dim = categorical_uniques[categorical_features], embedding_dim[categorical_features]       embedding = Embedding(vocab_size, embedding_dim, input_length=window_size)(categorical_input)       embedding = Reshape((window_size, -1))(embedding)          first_embedding = Lambda(lambda x: x[:, 0])(embedding)          # Concatenate numerical input and embedding       # conv_input = concatenate([enhanced_numerical_input, embedding], axis=-1)          kernel_sizes = [2,3]       do_ratio     = 0.4          flattened_conv_output      = apply_conv_layers(numerical_input,     kernel_sizes, do_ratio=do_ratio)       flattened_conv_output_cat  = apply_conv_layers(embedding,           kernel_sizes, do_ratio=do_ratio)       flattened_conv_output_diff = apply_conv_layers(combined_diff_layer, kernel_sizes, do_ratio=do_ratio)          dense_output = Concatenate(axis=-1)([flattened_conv_output,flattened_conv_output_cat,flattened_conv_output_diff, Reshape((-1,))(combined_diff_layer),first_numerical,first_embedding])          dense_sizes = [512, 256, 128, 64, 32]       do_ratio = 0.5       for size in dense_sizes:           dense_output = Dense(size, activation='swish')(dense_output)           dense_output = BatchNormalization()(dense_output)           dense_output = Dropout(do_ratio)(dense_output)          # Output layer       output      = Dense(1, name='output_layer')(dense_output)          # Learning rate schedule       lr_schedule = ExponentialDecay(           initial_learning_rate=initial_learning_rate,           decay_steps=10000,           decay_rate=0.7,           staircase=True)          # Create and compile the model       model = Model(inputs=input_layer, outputs=output)       optimizer = Adam(learning_rate=lr_schedule)          model.compile(optimizer=optimizer, loss="mean_absolute_error")          return model`

# 

参考文献

![](assets/001.png)

1.  https://github.com/nimashahbazi/optiver-trading-close
    
2.  https://www.kaggle.com/competitions/optiver-trading-at-the-close/discussion/486169