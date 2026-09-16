# 使用机器学习进行隐喻检测——代码复制可用

小燕子搬砖 映翡量化 2024-04-03 18:45 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484156&idx=1&sn=d71c14c05af22fa4bff4a6b01a7f0c18&chksm=9ea448600bbafb12bef545a21da31c1316580b2a26a846fcbeade486bdc7662df34ca157f81e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484156&idx=1&sn=d71c14c05af22fa4bff4a6b01a7f0c18&chksm=9ea448600bbafb12bef545a21da31c1316580b2a26a846fcbeade486bdc7662df34ca157f81e#rd)

![](assets/001.gif)

​

## 介绍

在自然语言处理（NLP）中，隐喻检测是一个挑战，吸引着无数从业者一直致力于深入研究语言的复杂性。隐喻具有简洁地传达复杂想法和情感的能力，在丰富沟通方面起着关键作用。然而，它们固有的模糊性和上下文性质为NLP系统提供了一个独特的难题。

  

![](assets/002.jpg)

> 隐喻是语言的颜色：看不见，它们为我们的言语着色；被理解，它们照亮了我们的思想。

## 背景

自然语言处理（NLP）中的隐喻检测是指识别和解释文本中的隐喻语言。隐喻是修辞格，其中单词或短语应用于不适用的对象或行动，通常暗示相似性或做出象征性陈述。这是NLP中一个具有挑战性的领域，原因有几个：

1.  **语言的复杂性：**隐喻可能是微妙的和复杂的，它们难以用算法检测和解释。他们通常依赖于文化和背景知识。
    
2.  **字面意义与比喻意义：**区分字面语言和比喻语言不仅需要理解单词，还需要理解单词背后的上下文和预期含义。
    
3.  **表达的可变性：**隐喻可以用许多不同的方式表达，包括以前从未使用过的新颖隐喻，因此很难仅仅依赖预先存在的数据库或模式。
    

为了应对这些挑战，已经开发了各种方法：

-   **基于规则的系统：**早期尝试依靠预定义的规则或模式来识别隐喻，但这些系统需要自然语言的灵活性和多样性方面的帮助。
    
-   **统计和机器学习模型：**这些模型使用大文本语料库来学习可能表示隐喻语言的模式。它们可能比基于规则的系统更灵活，但可能需要广泛的训练数据。
    
-   **深度学习：**最近，深度学习模型，特别是那些基于神经网络的模型，已被应用于隐喻检测。这些模型可以学习语言的复杂模式和细微差别，使它们在识别隐喻方面更有效。
    
-   **混合方法：**结合多种方法可以利用每种方法的优势。例如，一个系统可能会使用基于规则的方法来识别潜在的隐喻，然后应用机器学习来确认它们是否真的是隐喻。
    
-   **上下文和文化考虑因素：**先进的NLP系统越来越多地结合更广泛的上下文和文化知识，以更好地了解何时以及如何使用隐喻。
    

隐喻检测在NLP中至关重要，因为隐喻是自然语言的标准部分，可以显著影响文本的含义。改进隐喻检测可以增强各种NLP应用程序，包括情感分析、文本解释和机器翻译。

## 语言中隐喻的挑战

当单词超越其字面意义来传达更深刻、往往是抽象的想法时，检测是隐喻的核心。与直截了当的事实陈述不同，隐喻需要理解上下文、文化和语言元素的微妙相互作用。语言的动态本质放大了复杂性，新的隐喻不断出现，现有的隐喻不断演变。

## 隐喻检测的方法

NLP中的隐喻检测之旅已经走过了各种路径，每条路径都有其工具和理论。早期的方法主要基于规则，依赖于固定的模式和语言线索。然而，这些系统的僵化往往导致高误报或阴性，这凸显了对更适应性解决方案的需求。

统计和机器学习模型的出现标志着一个重大转变，在检测能力方面提供了更大的灵活性和广度。这些模型在大型文本语料库上训练，试图识别可能表示隐喻语言的模式和异常。然而，虽然机器学习提高了检测率，但它也面临着局限性，特别是在处理新颖的隐喻和上下文丰富的表达方面。

目前隐喻检测的前沿以深度学习技术为主，特别是那些使用神经网络的技术。这些模型擅长捕捉语言复杂、多层次的特征，使它们特别擅长破译隐喻。深度学习系统可以通过单词嵌入和序列建模等方法将语言置于上下文中，以反映人类的解释，从而实现更准确、更细致的检测。

## 混合模型和上下文理解

认识到隐喻的多方面性，该领域正日益转向整合各种方法的混合模型。这些模型结合了基于规则系统的精度、机器模型的学习能力和深度学习的上下文深度。人们越来越强调纳入文化和背景知识，承认隐喻不仅仅是语言结构，而且深深植根于社会和文化框架中。

## NLP中隐喻检测的影响和未来

高级隐喻检测的意义是深远的，跨越了NLP的各个领域。在情感分析中，理解隐喻可以揭开文本的潜在情感和观点。准确的隐喻检测和翻译可以防止机器翻译中意义和文化细微差别的丧失。此外，随着NLP系统通过虚拟助理和对话代理进一步融入我们的日常生活，有效处理隐喻的能力对于自然和有意义的人机交互至关重要。

## 代码

在NLP中为隐喻检测创建完整的Python代码示例涉及生成合成数据集、预处理数据、训练模型、评估和解释结果。以下是如何一步一步地做到这一点：

1.  **合成数据集创建：**生成带和不带隐喻的合成句子。
    
2.  **特征工程：**使用NLP技术从文本中提取特征。
    
3.  **模型训练：**使用机器学习模型来区分隐喻和字面句子。
    
4.  **评估：**使用适当的指标评估模型的性能。
    
5.  **可视化：**绘制结果以更好地理解。
    
6.  **解释：**分析模型的性能并讨论结果。
    

Python简化示例：

  

import numpy as np  

import pandas as pd

from sklearn.model\_selection import train\_test\_split

from sklearn.feature\_extraction.text import TfidfVectorizer

from sklearn.ensemble import RandomForestClassifier

from sklearn.metrics import classification\_report, confusion\_matrix

import matplotlib.pyplot as plt

import seaborn as sns

  

\# Synthetic dataset creation

\# For simplicity, we're using a very basic example where "metaphor" is in metaphorical sentences

data = {

    "sentence": \[

        "Time is a thief",

        "She is an angel",

        "The computer is slow",

        "He is a lion in battle",

        "The car is fast"

    \],

    "is\_metaphor": \[1, 1, 0, 1, 0\]  # 1 for metaphor, 0 for literal

}

df = pd.DataFrame(data)

  

\# Feature engineering

vectorizer = TfidfVectorizer()

X = vectorizer.fit\_transform(df\['sentence'\])

y = df\['is\_metaphor'\]

  

\# Model training

X\_train, X\_test, y\_train, y\_test = train\_test\_split(X, y, test\_size=0.3, random\_state=42)

model = RandomForestClassifier(random\_state=42)

model.fit(X\_train, y\_train)

  

\# Evaluation

predictions = model.predict(X\_test)

print(classification\_report(y\_test, predictions))

  

\# Visualization

cm = confusion\_matrix(y\_test, predictions)

sns.heatmap(cm, annot=True, fmt='g')

plt.xlabel('Predicted')

plt.ylabel('True')

plt.title('Confusion Matrix')

plt.show()

该代码为NLP中的隐喻检测提供了一个基本框架，其中：

-   合成数据集是用标记为隐喻与否的句子创建的。
    
-   `TfidfVectorizer`用于特征工程，将文本数据转换为适合机器学习的数字格式。
    
-   在此数据集上训练和评估RandomForestClassifier。
    
-   使用混淆矩阵将结果可视化，并将根据分类报告和混淆矩阵进行解释。
    

模型输出结果：

  

![](assets/003.png)

在现实世界中，隐喻检测将涉及更复杂的数据集、高级特征工程（如单词嵌入或基于深度学习的方法），以及彻底的评估和解释，以了解NLP中隐喻语言使用的细微差别。

## 结论

NLP中的隐喻检测不仅仅是一个技术挑战，更是对人类语言和思想本质的冒险。随着人工智能和机器学习的进步，我们正处于揭开语言隐喻的全部前景，承诺一个机器理解我们所说的单词和我们传达的无数含义的未来。

  

参考资料：

https://pub.aimind.so/deciphering-the-veiled-meanings-advancements-in-metaphor-detection-using-machine-learning-edd32c775c70  

https://arxiv.org/abs/2308.04306?source=post\_page-----edd32c775c70--------------------------------

  

![](assets/004.jpg)