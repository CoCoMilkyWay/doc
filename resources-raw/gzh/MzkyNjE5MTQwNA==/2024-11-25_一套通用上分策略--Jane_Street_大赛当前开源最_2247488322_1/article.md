# 一套通用上分策略--Jane Street 大赛当前开源最高方案

Xiang Sheng 量化前沿速递 2024-11-25 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247488322&idx=1&sn=bb4a903b8cccf984f7235052fac23c6d&chksm=c342d393b2bbea75bd7641289e9d8ca54e773a17b8214790ff9d29541f22dbe7574a21087c34#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247488322&idx=1&sn=bb4a903b8cccf984f7235052fac23c6d&chksm=c342d393b2bbea75bd7641289e9d8ca54e773a17b8214790ff9d29541f22dbe7574a21087c34#rd)

# 

**Jane Street 大赛当前开源最高方案**

## 

竞赛背景

![](assets/001.png)

最近Jane Street又在kaggle出的一个量化预测大赛，在这个挑战中，要求选手使用一些生产系统的真实数据构建一个模型。这些数据非常贴近我们每天在现代金融市场交易成功所需做的一些事情。我们汇集了一系列与我们运行自动化交易策略的市场相关的特征和响应者，并且我们非常关注拥有良好的基础模型。为了平衡打造一个具有挑战性且与我们业务相关的问题，同时尊重我们交易的专有性和高度竞争性，你会注意到我们对一些特征和响应者进行了匿名化和轻微模糊处理。这些修改并没有改变问题的本质，但确实让我们能够给你一个有挑战性的任务，真实地展示我们在Jane Street所做的工作。

本文分享该竞赛截止目前为止开源方案中高分数的方案，该方案距离银牌方案的分差非常小，建议有兴趣的朋友可以多加进行尝试。本文分享的方案思路在99%的竞赛中都是非常适用的，非常值得借鉴。

## 

方案解读

![](assets/001.png)

方案主要简单可以拆解为XGB+NN模型的融合，其中：

-   XGB在我们早期的文章中已经提到过；
    
-   NN模型此处主要用的是基础的MLP模型，对应的网络框架可以参见下面的代码，详细的训练过程可以参考对应的链接。
    

最终模型的融合则直接对XGB和NN进行简单的加权进行处理。

### 

![](assets/002.png)

![](assets/003.png)

1\. 网络框架

-   网络主要是基础的MLP模型，具体的训练代码可以参见：https://www.kaggle.com/code/voix97/jane-street-rmf-training-nn
    

```
from pytorch_lightning import (LightningDataModule, LightningModule, Trainer)class NN(LightningModule):    def __init__(self, input_dim, hidden_dims, dropouts, lr, weight_decay):        super().__init__()        self.save_hyperparameters()        layers = []        in_dim = input_dim        for i, hidden_dim in enumerate(hidden_dims):            layers.append(nn.BatchNorm1d(in_dim))            if i > 0:                layers.append(nn.SiLU())            if i < len(dropouts):                layers.append(nn.Dropout(dropouts[i]))            layers.append(nn.Linear(in_dim, hidden_dim))            # layers.append(nn.ReLU())            in_dim = hidden_dim        layers.append(nn.Linear(in_dim, 1))         layers.append(nn.Tanh())        self.model = nn.Sequential(*layers)        self.lr = lr        self.weight_decay = weight_decay        self.validation_step_outputs = []    def forward(self, x):        return 5 * self.model(x).squeeze(-1)  
```

### 

![](assets/002.png)

![](assets/003.png)

2\. 预测框架

```
lags_ : pl.DataFrame | None = None    def predict(test: pl.DataFrame, lags: pl.DataFrame | None) -> pl.DataFrame | pd.DataFrame:    global lags_    if lags is not None:        lags_ = lags    predictions = test.select(        'row_id',        pl.lit(0.0).alias('responder_6'),    )    symbol_ids = test.select('symbol_id').to_numpy()[:, 0]    if not lags is None:        lags = lags.group_by(["date_id", "symbol_id"], maintain_order=True).last() # pick up last record of previous date        test = test.join(lags, on=["date_id", "symbol_id"],  how="left")    else:        test = test.with_columns(            ( pl.lit(0.0).alias(f'responder_{idx}_lag_1') for idx in range(9) )        )        preds = np.zeros((test.shape[0],))    preds += xgb_model.predict(test[xgb_feature_cols].to_pandas()) / 2    test_input = test[CONFIG.feature_cols].to_pandas()    test_input = test_input.fillna(method = 'ffill').fillna(0)    test_input = torch.FloatTensor(test_input.values).to("cuda:0")    with torch.no_grad():        for i, nn_model in enumerate(tqdm(models)):            nn_model.eval()            preds += nn_model(test_input).cpu().numpy() / 10    print(f"predict> preds.shape =", preds.shape)        predictions = \    test.select('row_id').\    with_columns(        pl.Series(            name   = 'responder_6',             values = np.clip(preds, a_min = -5, a_max = 5),            dtype  = pl.Float64,        )    )    # The predict function must return a DataFrame    assert isinstance(predictions, pl.DataFrame | pd.DataFrame)    # with columns 'row_id', 'responer_6'    assert list(predictions.columns) == ['row_id', 'responder_6']    # and as many rows as the test data.    assert len(predictions) == len(test)    return predictions
```

## 

小结

![](assets/001.png)

树模型和NN模型的融合在99%的竞赛中基本都是能带来稳定的分数提升，哪怕网络端只是简单的MLP，所以无论任何比赛都非常建议大家进行此类融合。

## 

参考文献

![](assets/001.png)

1.  https://www.kaggle.com/competitions/jane-street-real-time-market-data-forecasting/overview
    
2.  https://www.kaggle.com/code/voix97/jane-street-rmf-inference-nn-xgb
    
3.  https://www.kaggle.com/code/voix97/jane-street-rmf-training-nn