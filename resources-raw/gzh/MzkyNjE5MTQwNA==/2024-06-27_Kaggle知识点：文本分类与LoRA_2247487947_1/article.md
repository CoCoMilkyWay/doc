# Kaggle知识点：文本分类与LoRA

Coggle 量化前沿速递 2024-06-27 12:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487947&idx=1&sn=10e3f9c6740d1d0f0980bdfd73846c92&chksm=c35bf2f1084f70c16f46e30d955ee9d1d0dedb1d494ad0a3bab8427164028df75d88d8ffa8c3#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487947&idx=1&sn=10e3f9c6740d1d0f0980bdfd73846c92&chksm=c35bf2f1084f70c16f46e30d955ee9d1d0dedb1d494ad0a3bab8427164028df75d88d8ffa8c3#rd)

在这篇博客中，我们逐步进行`参数高效微调（Parameter Efficient Fine Tuning，简称PEFT）`，使用`大语言模型（LLM）`的`低秩适配（Low Rank Adaptation，LoRA）`。我们将了解如何使用参数高效微调来针对特定应用微调选定的可训练参数，以最低的成本和最少的基础设施实现这一目标。

## unsetunset为什么需要参数高效微调？unsetunset

大语言模型（LLM）已经针对某些任务进行了预训练；我们可以在应用程序中使用LLM来执行它们已经训练过的任何任务。然而，这些LLM在我们的环境中运行需要非常昂贵的资源，因此需要参数高效微调。

假设我们能够以经济有效的方式在我们的系统上使用大语言模型。这可以通过使用PEFT库来实现，因为它允许我们单独使用LLM的一些参数。

### PEFT（参数高效微调）

参数高效微调（Parameter Efficient Fine Tuning，简称PEFT）是一个库，它允许我们在不对完整模型进行微调的情况下使用大语言模型（LLM）来执行任务，而是对一些（额外的）参数进行微调。完整模型的微调通常需要昂贵的计算成本，而PEFT通过微调额外参数显著减少了计算和存储成本。

#### 参数高效微调的优势

-   **计算和存储成本降低**：微调额外参数显著减少了计算和存储成本。
    
-   **性能保持一致**：与完全微调的LLM模型相比，性能没有下降。
    
-   **适用于CPU支持的硬件**：额外参数的微调使得在CPU支持的硬件上训练和存储LLM变得更加容易。
    
-   **易于集成**：PEFT与诸如transformers和diffusers等库的集成，使得加载、训练和使用LLM进行推理变得更加容易。
    

## unsetunsetLoRA（低秩适配）unsetunset

LoRA（Low Rank Adaptation）是一种低秩分解方法，旨在减少可训练参数的数量，从而在微调大语言模型（LLM）时降低内存消耗。通过使用LoRA，可以更加轻松地进行LLM的微调，同时显著减少所需的计算和存储资源。

![](assets/001.png)

在PEFT（参数高效微调）中，LoRA配置通过`get_peft_model()`函数封装，以创建一个可训练的`PeftModel`。通过调整`LoraConfig`中的`init_lora_weights`参数，可以增加或减少模型权重，从而优化模型的性能和资源消耗。

`from peft import LoraConfig, get_peft_model   from transformers import AutoModelForSeq2SeqLM, AutoTokenizer      # 加载预训练的模型和分词器   model_name = "t5-small"   model = AutoModelForSeq2SeqLM.from_pretrained(model_name)   tokenizer = AutoTokenizer.from_pretrained(model_name)      # 配置LoRA参数   lora_config = LoraConfig(       r=8,  # 低秩矩阵的秩       lora_alpha=32,  # LoRA的alpha参数       lora_dropout=0.1,  # Dropout率       init_lora_weights=0.02  # 初始化LoRA权重   )      # 获取PEFT模型   peft_model = get_peft_model(model, lora_config)      # 对输入进行编码   input_text = "Translate English to French: The weather is nice today."   input_ids = tokenizer(input_text, return_tensors="pt").input_ids      # 使用PEFT模型进行推理   outputs = peft_model.generate(input_ids)   output_text = tokenizer.decode(outputs[0], skip_special_tokens=True)      print("Translated text:", output_text)   `

-   `r`：低秩矩阵的秩。较低的秩会减少参数数量，从而降低内存消耗。
    
-   `lora_alpha`：LoRA的alpha参数，用于调整模型的学习率。
    
-   `lora_dropout`：Dropout率，有助于防止模型过拟合。
    
-   `init_lora_weights`：初始化LoRA权重的值，可以根据需要增加或减少模型权重。
    

## unsetunsetLoRA文本分类案例unsetunset

-   安装依赖环境
    

`!pip install transformers datasets evaluate accelerate peft   `

-   加载数据集
    

`import torch   from transformers import RobertaModel, RobertaTokenizer, AutoModelForSequenceClassification, TrainingArguments, Trainer, DataCollatorWithPadding   from peft import LoraConfig, get_peft_model   from datasets import load_dataset            peft_model_name = 'roberta-base-peft'   modified_base = 'roberta-base-modified'   base_model = 'roberta-base'      dataset = load_dataset('ag_news')   tokenizer = RobertaTokenizer.from_pretrained(base_model)      def preprocess(examples):       tokenized = tokenizer(examples['text'], truncation=True, padding=True)       return tokenized      tokenized_dataset = dataset.map(preprocess, batched=True,  remove_columns=["text"])   train_dataset=tokenized_dataset['train']   eval_dataset=tokenized_dataset['test'].shard(num_shards=2, index=0)   test_dataset=tokenized_dataset['test'].shard(num_shards=2, index=1)         # Extract the number of classess and their names   num_labels = dataset['train'].features['label'].num_classes   class_names = dataset["train"].features["label"].names   print(f"number of labels: {num_labels}")   print(f"the labels: {class_names}")      # Create an id2label mapping   # We will need this for our classifier.   id2label = {i: label for i, label in enumerate(class_names)}      data_collator = DataCollatorWithPadding(tokenizer=tokenizer, return_tensors="pt")   `

-   常规微调
    

`# use the same Training args for all models   training_args = TrainingArguments(       output_dir='./results',       evaluation_strategy='steps',       learning_rate=5e-5,       num_train_epochs=1,       per_device_train_batch_size=16,   )   def get_trainer(model):         return  Trainer(             model=model,             args=training_args,             train_dataset=train_dataset,             eval_dataset=eval_dataset,             data_collator=data_collator,         )   full_finetuning_trainer = get_trainer(       AutoModelForSequenceClassification.from_pretrained(base_model, id2label=id2label),   )      full_finetuning_trainer.train()   `

-   LoRA微调
    

`model = AutoModelForSequenceClassification.from_pretrained(base_model, id2label=id2label)      peft_config = LoraConfig(task_type="SEQ_CLS", inference_mode=False, r=8, lora_alpha=16, lora_dropout=0.1)   peft_model = get_peft_model(model, peft_config)      peft_model.print_trainable_parameters()   peft_lora_finetuning_trainer = get_trainer(peft_model)   peft_lora_finetuning_trainer.train()`