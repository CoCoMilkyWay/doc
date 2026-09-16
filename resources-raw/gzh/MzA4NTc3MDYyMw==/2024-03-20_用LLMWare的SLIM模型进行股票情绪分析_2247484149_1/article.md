# 用LLMWare的SLIM模型进行股票情绪分析

小燕子搬砖 映翡量化 2024-03-20 20:14 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484149&idx=1&sn=030ac6859a25af5ed5e6fcea9482d093&chksm=9e4695d79cd5fe2c158f21d080323d45f5d627aa3ef00ab1a0bf9218db4ad6e6d0a24db0a293#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484149&idx=1&sn=030ac6859a25af5ed5e6fcea9482d093&chksm=9e4695d79cd5fe2c158f21d080323d45f5d627aa3ef00ab1a0bf9218db4ad6e6d0a24db0a293#rd)

# LLMWare及其SLIM模型

## LLMWare概述

LLMWare是制作企业级、知识驱动的LLM应用程序的瑞士军刀，特别适合需要高水平知识整合的行业，如**金融、法律、合规和监管密集型等**行业。LLMWare在私有云环境中无缝运行，其易于集成开源、专业模型，同时确保企业知识的安全连接。

LLMWare的核心是专注于两个方面：创新的“软件”——包括旨在轻松集成大型语言模型（LLM）的中间件和软件——以及在Hugging Face上创建高质量、面向自动化的企业模型。这种双重方法不仅确保了无缝集成，还确保了对敏感行业至关重要的可靠性和安全性。

## SLIM模型简介

LLMWare的SLIM（结构化语言指令模型）模型是**小型**、**专门的**模型，针对**函数调用**和**多步、多模型代理工作流程进行了**微调。

由于它们针对非常具体的任务进行了微调，因此对有针对性的分析非常有效。

  

![](assets/001.jpg)

**主要特点和用例：**

-   **情绪分析**：SLIM模型在精确定位文本中的情绪方面大放异彩，区分语气是积极的、消极的还是中性的。这种精确度允许对市场情绪或客户反馈进行细致入微的理解。
    
-   **情绪检测**：超越一般情绪分析，SLIM模型可以检测特定情绪，提供用户反馈或市场新闻中情绪暗流的精细视图。
    
-   **评级分析：**这些模型熟练地分析评论中的评级，为客户满意度和产品接收提供了宝贵的见解。
    
-   **无缝数据管道集成：**SLIM模型的设计考虑到了灵活性，毫不费力地集成到现有的数据管道中，凭借其高级功能增强了各种应用程序的分析能力。
    

  

## 为什么要使用SLIM模型？

LLMWare的SLIM模型引入了一种生成结构化输出的革命性方法，具有几个显著优势，使其成为各种应用程序的杰出选择，特别是在需要高级分析、研究和基于代理的工作流程的领域。以下是SLIM模型特点：

1.  **针对结构化输出进行优化**：SLIM模型擅长提供结构化数据，如Python字典、JSON和SQL格式，开箱即用。在结构化信息至关重要的情况下，这种能力特别有价值，可以简化数据处理和分析工作。
    
2.  **紧凑高效**：从小底座开始，这些模型通过量化进行进一步优化，显著缩小其尺寸。这种紧凑的占地面积转化为更快的负载和推理时间，使其成为在计算资源有限的环境中使用的理想选择。
    
3.  **无缝工作流程集成**：专为轻松纳入现有的LLMWare工作流程而设计，由于高级LLm FX类API，SLIM模型可以毫不费力地集成。此功能通过简化多模型交互来促进复杂多步骤分析的编排。
    
4.  **多样化的应用潜力**：无论是尖端分析、NLP解决方案还是复杂的多模型系统，SLIM模型的多功能性都闪耀着光芒。LLm FX类API增强了模型编排，将其适用性扩展到许多领域。
    

‍  

# 使用LLMWare实现SLIM模型的实用指南

## 步骤1——设置环境

将利用https://newsapi.org/的力量来收集最新消息。REST API从全球80,000多个来源获取当前和历史新闻文章的JSON格式的搜索结果。访问https://newsapi.org/，注册一个帐户，并获取您的API密钥。

python -m venv venv  
source venv/bin/activate  #activate the venv on Mac/Linux  
\# venv\\Scripts\\activate  #activate the venv on Windows  
pip install llmware  
pip install streamlit

接下来，我们将在您的系统和其他依赖项上设置LLMWare。我们还将使用Streamlit以用户友好的格式呈现我们的股票情绪分析。

import os  
import requests  
import json  
import streamlit as st  
from llmware.agents import LLMfx  
from llmware.library import Library  
from llmware.retrieval import Query  
from llmware.configs import LLMWareConfig  
from llmware.setup import Setup

> 在深入研究之前，请确保您正在使用Python 3.10运行。事实上，Python 3.12有一个关键的兼容性问题需要注意。

## 第2步-获取新闻

设置一个功能来获取与给定公司名称相关的新闻文章。

NEWS\_ENDPOINT = "https://newsapi.org/v2/everything"  \# Your news API endpoint  
NEWS\_API\_KEY = "your\_api\_key\_here"  \# Your News API key  
parameters\_news = {  
   "q": "",  \# The query or company name  
   "apiKey": NEWS\_API\_KEY,  
   "language": "en",  \# Language of the articles  
   "sortBy": "publishedAt"  \# Sorting by publication date  
}

def get\_news(company\_name):  
   parameters\_news\["q"\] = company\_name  
   news\_response = requests.get(NEWS\_ENDPOINT, parameters\_news)  
   news\_response.raise\_for\_status()  \# Ensures a successful response  
   news\_data = news\_response.json()\["articles"\]  \# Extracts the articles  
  
   news\_folder\_path = os.path.join(os.getcwd(), "news")  
   if not os.path.exists(news\_folder\_path):  
       os.makedirs(news\_folder\_path)  \# Creates the folder if it doesn't exist  
   file\_path = os.path.join(news\_folder\_path, "news\_data.txt")  
     
   with open(file\_path, "w") as file:  
       json.dump(news\_data, file)  \# Writes the news data to the file

`get_news`函数将公司名称作为输入，并使用新闻API获取相关新闻文章。

## 第3步—执行多步股票新闻情绪分析

部署SLIM模型来深入分析新闻文章。目标是剖析和理解与特定公司相关的情感、情感、标签、命名实体和关键主题，将研究提升到前所未有的水平。以下是多步分析过程的详细细分概述。

  

![](assets/002.png)

def multistep\_analysis(company\_name):  
  
   """ In this example, our objective is to research Microsoft history and rivalry in the 1980s with IBM. """  
  
   \#   step 1 - assemble source documents and create library  
  
   print("update: Starting example - agent-multistep-analysis")  
  
   print("update: Loading  files")  
  
   news\_folder = os.path.join(os.getcwd(), "news")  
   \#   create library  
   print("update: creating library and parsing source document")  
  
   LLMWareConfig().set\_active\_db("sqlite")  
   my\_lib = Library().create\_new\_library(company\_name)  
   my\_lib.add\_files(news\_folder)  
  
   \#   run our first query  
   query = company\_name  
   search\_results = Query(my\_lib).text\_query(query)  
   print(f"update: executing query to filter to key passages - {query} - results found - {len(search\_results)}")  
  
   \#   create an agent and load several tools that we will be using  
   agent = LLMfx()  
   agent.load\_tool\_list(\["sentiment", "emotions", "topic", "tags", "ner", "answer"\])  
  
   \#   load the search results into the agent's work queue  
   agent.load\_work(search\_results)  
  
   while True:  
  
       agent.sentiment()  
  
       if not agent.increment\_work\_iteration():  
           break  
  
   \#   analyze sections where the sentiment on the company was negative or positive  
   follow\_up\_list = agent.follow\_up\_list(key="sentiment", value="negative")  
   follow\_up\_list.extend(agent.follow\_up\_list(key="sentiment", value="positive"))  
   for job\_index in follow\_up\_list:  
  
       \# follow-up 'deep dive' on selected text that references  the company  
       agent.set\_work\_iteration(job\_index)  
       agent.exec\_multitool\_function\_call(\["tags", "emotions", "topics", "ner"\])  
       agent.answer("What is a brief summary?", key="summary")  
  
   my\_report = agent.show\_report(follow\_up\_list)  
  
   activity\_summary = agent.activity\_summary()  
  
   for entries in my\_report:  
       print("my report entries: ", entries)  
  
   return my\_report

## 第4步——在Streamlit中可视化报告

在进行彻底的多步情绪分析后，

  

![](assets/003.jpg)

multistep\_analyis函数的输出是字典格式的详细报告的集合。‍

def format\_report\_entries\_as\_table(report\_entries):  
   table\_data = \[\]  
   for entry in report\_entries:  
       table\_entry = {  
           "Sentiment": ", ".join(entry.get('sentiment', \[\])),  
           "Tags": ", ".join(json.loads(entry.get('tags', '\[\]'))),  
           "Emotions": ", ".join(entry.get('emotions', \[\])),  
           "Topics": ", ".join(entry.get('topics', \[\])),  
           "People": ", ".join(entry.get('people', \[\])),  
           "Organization": ", ".join(entry.get('organization', \[\])),  
           "Misc": ", ".join(entry.get('misc', \[\])),  
           "Summary": entry.get('summary', \[''\])\[0\],  
           "Source": entry.get('source', {}).get('query', '')  
       }  
       table\_data.append(table\_entry)  
   return table\_data

这就是Streamlit发挥作用的地方，将复杂数据转化为用户友好的报告。

在进入Streamlit之前，我们首先需要将报告条目中包含的数据重新格式化为表格格式，重点关注情绪、标签、情绪、主题等关键方面。

company\_name = "Google"  
get\_news(company\_name)  
  
report\_entries = multistep\_analysis(company\_name)  
table\_data = format\_report\_entries\_as\_table(report\_entries)  
  
\# Streamlit app  
st.title("Report Entries Table")  
st.table(table\_data)

  

![](assets/004.jpg)

# 结论‍‍‍‍

探索了使用SLIM模型进行深入的股票情绪分析，所有这些都可以在适度的CPU上实现！

这为更广泛的应用程序开辟了令人兴奋的可能性，从复杂的业务工作流程到客户审查分析等自动化流程。通过应用这些模型，企业可以自动对客户反馈进行排序，确定见解，并有效地将查询引导到正确的支持团队。

对于希望深入了解市场情绪的研究人员，以及有兴趣通过复杂的文本分析增强其应用程序的开发人员来说，这些模型是一个福音。

此外，有了LLMWare，开发高级分析工具变得更加容易，同时还有各种专业模型，随时准备处理各种任务：

-   DRAGON模型系列：生产级RAG优化的6-7B参数模型——“在...上交付RAG”领先的基础模型。
    
-   BLING模型系列：基于小型CPU的RAG优化，指导遵循1B-3B参数模型。
    
-   行业BERT模型：开箱即用的定制训练句子变压器嵌入模型，针对以下行业进行了微调：保险、合同、资产管理、SEC。
    
-   GGUF量化：许多SLIM、DRAGON和BLING模型的“gguf”和“工具”版本，针对CPU部署进行了优化。
    

  

资料来源：

https://levelup.gitconnected.com/the-future-of-financial-ai-stock-sentiment-analysis-with-slim-models-3c7000046ae0  

https://github.com/llmware-ai/llmware