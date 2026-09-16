# 从市场新闻情绪到量化交易的Python实践——如何量化“上海爷叔”

小燕子 映翡量化 2024-07-23 20:38 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484854&idx=1&sn=7119b225f8aa211af47205a46bc5c748&chksm=9e0b55bd857ccfd4dc31b6cd27ae13903f725ff65fdf040cd2138cc4ee962f66728ab4fb46cb#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484854&idx=1&sn=7119b225f8aa211af47205a46bc5c748&chksm=9e0b55bd857ccfd4dc31b6cd27ae13903f725ff65fdf040cd2138cc4ee962f66728ab4fb46cb#rd)

在不断变化的金融市场中，市场情绪分析已成为交易员和投资者的重要工具。这种分析通常由自然语言处理（NLP）和机器学习提供技术支持，能够提供市场动态的独特视角。最近，网民叫“爱在深秋”的“上海爷叔”，个人因其对中信证券的大胆和夸张的预测而走红，这其实就体现了市场情绪分析的重要性。  

据新浪财经的报道，“上海爷叔”在社交媒体上预测中信证券将连续三天涨停，并将目标价上调至700元左右，认为中信证券将超越茅台成为A股市值最大的股票。这一预测引发了市场的广泛关注，中信证券的股价在7月22日出现了显著上涨，涨幅达到4.13%，收报20.19元/股。尽管中信证券的大涨可能受到多种因素的影响，但“上海爷叔”的言论无疑在一定程度上影响了市场情绪。

市场情绪分析技术的发展，特别是在金融领域的应用，已经引起了学术界和工业界的广泛关注。例如，有研究利用情感分析和深度强化学习相关的特征，设计了一种结合知识图谱的情感分析方法，并在股市数据上进行了模拟实验，结果表明该方法能够取得比传统强化学习算法更好的收益。  

情感分析市场本身也在快速增长。根据Mordor Intelligence的报告，情感分析市场规模预计到2024年将达到39亿美元，并预计在2024-2029年间以15.93%的复合年增长率增长，其中亚太地区预计将是增长最快的市场。

所以，市场情绪分析不仅对交易员和投资者至关重要，而且随着技术的发展，其在金融市场中的应用也越来越广泛和深入。从“上海爷叔”对中信证券的预测事件中可以看出，即使是个人的言论，借助社交媒体的力量，也能在一定程度上影响市场情绪和股价走势。同时，情感分析技术的不断进步和市场规模的扩大，预示着这一领域将在未来发挥更大的作用。

  

一.从情绪到交易：目标‍‍‍‍

**本文为实施情绪分析驱动的交易量化策略提供全面分步骤实践。**

![](assets/001.png)

关键核心组件：

1️⃣数据收集和处理

2️⃣情绪分析引擎

3️⃣交易策略整合

4️⃣实时实施系统

5️⃣监控和报告

  

**🎯目标：一个全自动的交易系统，利用情绪分析做出合理的交易决策。**

  

# 二.数据收集‍‍‍

  

![](assets/002.png)

有效的情绪分析从强大的数据收集开始。我们需要撒下大网来捕捉市场情绪的全方位信息。

**数据来源：**

1.  **社交媒体：**
    

-   Twitter：可使用Twitter API流式传输与特定股票或市场趋势相关的实时推文。
    
-   Reddit：散户投资者的情绪，刮掉相关的子reddits，如r/wallstreetbets或r/investing。
    
-   国内有：微博、雪球、知乎、同花顺、东财股吧等。
    

**2.新闻文章：**

-   RSS提要：设置主要金融新闻机构（如路透社、彭博社、CNBC）的提要。
    
-   网页抓取：对金融网站开发抓取器。
    

**3.财务报告：**

-   SEC EDGAR数据库：访问和解析基本数据的10-K和10-Q报告。
    
-   收益电话记录：获取和分析季度收益电话记录。
    
-   国内有很多数据供应商和网站上都可以抓取。‍‍‍‍‍‍
    

**实施提示：**使用异步编程技术同时从多个来源高效收集数据。简单例子：

import asyncio  
import aiohttp  
  
async def fetch\_data(session, url):  
    async with session.get(url) as response:  
        return await response.text()  
async def main():  
    urls = \['url1', 'url2', 'url3'\]  \# List of data source URLs  
    async with aiohttp.ClientSession() as session:  
        tasks = \[fetch\_data(session, url) for url in urls\]  
        results = await asyncio.gather(\*tasks)  
    \# Process results  
asyncio.run(main())

  

# 三.数据预处理

  

![](assets/003.png)

原始数据很少适合直接分析。预处理对于从我们收集的数据中提取有意义的特征至关重要。

**预处理步骤：**

1.  **文本清理：**
    

-   删除URL、HTML标签和特殊字符
    
-   处理表情符号，如果相关，则转换为文本
    
-   规范化文本（例如，小写转换）
    

**2.令牌化：**

-   将文本分解为单个单词或子单词
    
-   考虑使用WordPiece或SentencePiece等高级标记器，以更好地处理词汇外单词
    

**3.单词处理：**

-   删除不带有重要情感的常用词（例如“the”、“is”、“at”）
    
-   创建针对财务文本的自定义停止单词列表
    

**4.词干化：**

-   将单词简化为基本形式（例如，“交易”、“交易”、“交易”→“交易”）
    
-   更喜欢词干化而不是词干，以获得更准确的结果
    

**代码示例（使用NLTK）：**

import nltk  
from nltk.tokenize import word\_tokenize  
from nltk.corpus import stopwords  
from nltk.stem import WordNetLemmatizer  
  
def preprocess\_text(text):  
    \# Tokenize  
    tokens = word\_tokenize(text.lower())  
      
    \# Remove stop words and non-alphabetic tokens  
    stop\_words = set(stopwords.words('english'))  
    tokens = \[token for token in tokens if token.isalpha() and token not in stop\_words\]  
      
    \# Lemmatize  
    lemmatizer = WordNetLemmatizer()  
    tokens = \[lemmatizer.lemmatize(token) for token in tokens\]  
      
    return tokens  
\# Example usage  
text = "Trading volumes increased significantly as investors reacted to the company's strong earnings report."  
processed\_tokens = preprocess\_text(text)  
print(processed\_tokens)

# 四.情绪分析模型：系统的核心

  

![](assets/004.png)

有了干净的预处理数据，现在可以构建我们的情绪分析模型。这一步涉及选择和培训一个可以准确分类我们财务文本情绪的模型。

**模型选项：**

1.  **传统机器学习：**
    

-   贝叶斯
    
-   SVM
    
-   随机森林
    

**2.深度学习：**

-   LSTM
    
-   transformers（如BERT、FinBERT）
    

**特征提取：**

-   BoW
    
-   TF-IDF
    
-   单词嵌入（Word2Vec，GloVe）
    

**模型培训和评估：**

1.  将数据拆分为训练、验证和测试集（例如，70%、15%、15%）
    
2.  关于训练数据的训练模型
    
3.  使用验证集进行超参数调优
    
4.  评估测试集的最终模型性能
    

**代码示例（使用**Hugging Face Transformers的**BERT模型）：**

from transformers import AutoTokenizer, AutoModelForSequenceClassification  
from torch.utils.data import DataLoader, TensorDataset  
import torch  
  
\# Load pre-trained FinBERT model and tokenizer  
tokenizer = AutoTokenizer.from\_pretrained("ProsusAI/finbert")  
model = AutoModelForSequenceClassification.from\_pretrained("ProsusAI/finbert")  
\# Tokenize and encode the dataset  
encoded\_data = tokenizer(texts, padding=True, truncation=True, return\_tensors="pt")  
labels = torch.tensor(labels)  \# Assuming you have labels  
\# Create DataLoader  
dataset = TensorDataset(encoded\_data\['input\_ids'\], encoded\_data\['attention\_mask'\], labels)  
loader = DataLoader(dataset, batch\_size=16, shuffle=True)  
\# Train the model  
optimizer = torch.optim.AdamW(model.parameters(), lr=2e-5)  
for epoch in range(3):  
    for batch in loader:  
        optimizer.zero\_grad()  
        input\_ids, attention\_mask, labels = batch  
        outputs = model(input\_ids, attention\_mask=attention\_mask, labels=labels)  
        loss = outputs.loss  
        loss.backward()  
        optimizer.step()  
\# Use the trained model for sentiment prediction

# 五.与交易策略的整合：从情绪到行动

  

![](assets/005.png)

现在我们有一个功能良好的情绪分析模型，将其整合到交易策略中。这涉及将情绪分数转化为可操作的交易信号。

**关键组件：**

1.  **情绪评分：**
    

-   单个资产或整体市场的总情绪评分
    
-   考虑使用滚动窗口来了解情绪趋势
    

**2.信号生成：**

-   定义看涨、看跌和中性情绪的门槛
    
-   根据情绪变化创建买入/卖出信号
    

**3.风险管理：**

-   根据情绪强度设置位置大小
    
-   实施止损和获利水平
    

**4.投资组合分配：**

-   根据多个资产的情绪调整投资组合权重
    

**示例策略：**

def generate\_trading\_signal(sentiment\_score, current\_position):  
    if sentiment\_score > 0.6 and current\_position <= 0:  
        return "BUY"  
    elif sentiment\_score < -0.6 and current\_position >= 0:  
        return "SELL"  
    else:  
        return "HOLD"  
  
def calculate\_position\_size(sentiment\_score, max\_position):  
    return abs(sentiment\_score) \* max\_position  
  
def set\_stop\_loss(entry\_price, sentiment\_score):  
    return entry\_price \* (1 - 0.05 \* abs(sentiment\_score))  
  
\# Main trading loop  
for timestamp, data in market\_data.iterrows():  
    sentiment\_score = get\_sentiment\_score(data)  
    signal = generate\_trading\_signal(sentiment\_score, current\_position)  
      
    if signal != "HOLD":  
        position\_size = calculate\_position\_size(sentiment\_score, MAX\_POSITION)  
        stop\_loss = set\_stop\_loss(data\['price'\], sentiment\_score)  
          
        execute\_trade(signal, position\_size, stop\_loss)

# 六.回测和优化

  

![](assets/006.png)

回测是制定任何交易策略的关键一步，包括基于情绪分析的策略。它使我们能够评估我们的战略在过去的表现，并优化其参数，以获得更好的未来绩效。

# 回测过程：

1.  **数据准备：**
    

-   将历史价格数据与情绪分数保持一致
    
-   确保数据干净，没有幸存者偏见
    

**2.战略实施：**

-   将交易规则翻译成代码
    
-   包括交易成本和滑点等
    

**3.绩效指标：**

-   计算关键指标，如夏普比率、最大提款率和总回报率
    
-   可视化净值曲线和回撤
    

**4.参数优化：**

-   使用网格搜索、遗传算法或贝叶斯优化等技术
    
-   小心过度优化
    

  

以下是在Python中使用`backtrader`库的基本回测设置示例：

import backtrader as bt  
import pandas as pd  
  
class SentimentStrategy(bt.Strategy):  
    params = (  
        ('sentiment\_threshold', 0.5),  
        ('position\_size', 100),  
    )  
    def \_\_init\_\_(self):  
        self.sentiment = self.datas\[0\].sentiment  
        self.order = None  
    def next(self):  
        if self.order:  
            return  
        if not self.position:  
            if self.sentiment\[0\] > self.params.sentiment\_threshold:  
                self.order = self.buy(size=self.params.position\_size)  
        elif self.sentiment\[0\] < -self.params.sentiment\_threshold:  
            self.order = self.sell(size=self.position.size)  
\# Load data  
data = pd.read\_csv('stock\_data\_with\_sentiment.csv', parse\_dates=True, index\_col='Date')  
feed = bt.feeds.PandasData(dataname=data, sentiment='Sentiment')  
\# Create a cerebro entity  
cerebro = bt.Cerebro()  
\# Add data feed  
cerebro.adddata(feed)  
\# Add strategy  
cerebro.addstrategy(SentimentStrategy)  
\# Set initial capital  
cerebro.broker.setcash(100000.0)  
\# Run backtest  
print('Starting Portfolio Value: %.2f' % cerebro.broker.getvalue())  
cerebro.run()  
print('Final Portfolio Value: %.2f' % cerebro.broker.getvalue())  
\# Plot results  
cerebro.plot()

# 优化技术：

1.  **网格搜索：**系统地处理多个参数组合，测试每个组合的性能。
    

for sentiment\_threshold in np.arange(0.1, 1.0, 0.1):  
    for position\_size in range(50, 500, 50):  
        cerebro = bt.Cerebro()  
        cerebro.adddata(feed)  
        cerebro.addstrategy(SentimentStrategy,  
                            sentiment\_threshold=sentiment\_threshold,  
                            position\_size=position\_size)  
        cerebro.run()  
        \# Store and compare results

**2.遗传算法：**使用进化算法找到最佳参数。

**3.贝叶斯优化：**通过构建从参数到策略性能的函数映射的概率模型，高效搜索参数空间。

虽然优化很重要，但要警惕过度拟合。始终在样本外数据上验证优化策略。

# 七.实时实现：流数据处理

  

![](assets/007.png)

实时实施基于情绪的交易策略带来了独特的挑战，需要处理流数据，执行实时情绪分析，并快速可靠地执行交易。

# 关键组件：

1.  **数据流：**为市场数据和情绪源设置实时提要。考虑使用Apache Kafka来处理大容量数据流。
    
2.  **实时情绪分析：**实现情绪分析模型，以实时处理传入的数据。这可能涉及使用Apache Flink或Spark Streaming等流处理框架。
    
3.  **交易逻辑：**实施交易策略，根据实时情绪分数生成信号。
    
4.  **订单执行：**连接到委托的API，根据交易信号自动下订单。（国内券商大部分都有量化委托接口）
    

  

以下是使用Alpaca API进行实时交易的简化示例：

import alpaca\_trade\_api as tradeapi  
from textblob import TextBlob  
import tweepy  
  
\# Set up Alpaca API  
api = tradeapi.REST('YOUR\_API\_KEY', 'YOUR\_API\_SECRET', base\_url='https://paper-api.alpaca.markets')  
\# Set up Twitter API  
auth = tweepy.OAuthHandler("CONSUMER\_KEY", "CONSUMER\_SECRET")  
auth.set\_access\_token("ACCESS\_TOKEN", "ACCESS\_TOKEN\_SECRET")  
twitter\_api = tweepy.API(auth)  
  
def get\_sentiment(text):  
    return TextBlob(text).sentiment.polarity  
  
def execute\_trade(symbol, qty, side):  
    api.submit\_order(  
        symbol=symbol,  
        qty=qty,  
        side=side,  
        type\='market',  
        time\_in\_force='gtc'  
    )  
  
class MyStreamListener(tweepy.StreamListener):  
    def on\_status(self, status):  
        if hasattr(status, 'retweeted\_status'):  
            return  
          
        sentiment = get\_sentiment(status.text)  
        print(f"Sentiment: {sentiment}")  
          
        if sentiment > 0.5:  
            execute\_trade('AAPL', 10, 'buy')  
        elif sentiment < -0.5:  
        execute\_trade('AAPL', 10, 'sell')  
  
myStreamListener = MyStreamListener()  
myStream = tweepy.Stream(auth = twitter\_api.auth, listener=myStreamListener)  
myStream.filter(track=\['AAPL'\])

此示例使用Twitter API流式传输有关特定股票（在本例中为AAPL）的推文，对每条推文进行情绪分析，并在情绪超过特定阈值时执行交易。

# 八.监控和报告：保持策略稳定性的关键

  

![](assets/008.png)

基于情绪的交易系统上线后，持续监控其表现和健康状况至关重要。

# 监控的关键指标：

1.  **交易表现：**
    

-   回撤（每日、每周、每月）
    
-   夏普比率
    
-   最大缩减
    
-   胜/亏比
    

**2.情绪指标：**

-   平均情绪得分
    
-   情绪波动
    
-   情绪和价格波动之间的相关性
    

**3.系统健康：**

-   情绪分析的延迟
    
-   交易执行时间
    
-   错误率
    

**4.数据质量：**

-   数据提要正常运行时间
    
-   缺少数据点
    
-   不寻常的情绪分数
    

  

以下是如何使用Dash设置基本监控仪表板的示例：

import dash  
import dash\_core\_components as dcc  
import dash\_html\_components as html  
from dash.dependencies import Input, Output  
import plotly.graph\_objs as go  
import pandas as pd  
  
app = dash.Dash(\_\_name\_\_)  
\# Assume we have functions to fetch the latest data  
from data\_fetchers import get\_latest\_performance, get\_latest\_sentiment  
app.layout = html.Div(\[  
    html.H1('Sentiment Trading Dashboard'),  
    dcc.Graph(id\='performance-graph'),  
    dcc.Graph(id\='sentiment-graph'),  
    dcc.Interval(  
        id\='interval-component',  
        interval=60\*1000, \# update every minute  
        n\_intervals=0  
    )  
\])  
@app.callback(Output('performance-graph', 'figure'),  
              Input('interval-component', 'n\_intervals'))  
def update\_performance\_graph(n):  
    df = get\_latest\_performance()  
    return {  
        'data': \[go.Scatter(x=df\['date'\], y=df\['returns'\], mode='lines')\],  
        'layout': go.Layout(title='Cumulative Returns')  
    }  
@app.callback(Output('sentiment-graph', 'figure'),  
              Input('interval-component', 'n\_intervals'))  
def update\_sentiment\_graph(n):  
    df = get\_latest\_sentiment()  
    return {  
        'data': \[go.Scatter(x=df\['date'\], y=df\['sentiment'\], mode='lines')\],  
        'layout': go.Layout(title='Average Sentiment Score')  
    }  
if \_\_name\_\_ == '\_\_main\_\_':  
    app.run\_server(debug=True)

这创建了一个简单的仪表板，有两个图表：一个显示累积回报，另一个显示一段时间内的平均情绪分数。  

# 九.合规和道德：诚信交易

  

![](assets/009.png)

实施基于情绪的交易策略需要仔细考虑法律和道德问题。

# 关键合规领域：

1.  **数据隐私：**确保您的数据收集和存储实践符合政策等法规。
    
2.  **市场操纵：**策略不应试图影响市场情绪或利用被操纵的情绪。
    
3.  **内幕交易：**在情绪分析中使用非公开信息时要谨慎。
    
4.  **公平交易实践：**确保算法不会参与可能被视为市场滥用的做法。
    

# 道德考虑：

1.  **透明度：**对在交易决策中使用情绪分析持开放态度。
    
2.  **公平性：**确保策略不会不成比例地对任何市场参与者群体有利或不利。
    
3.  **稳健性：**系统应该能够抵御异常，而不是导致市场不稳定。
    

  

实施一些合规性检查的示例：

def compliance\_check(tweet, sentiment\_score, trade\_signal):  
    \# Check for potential insider information  
    insider\_keywords = \['insider', 'nonpublic', 'confidential'\]  
    if any(keyword in tweet.lower() for keyword in insider\_keywords):  
        log\_potential\_issue(tweet, 'Potential insider information')  
        return False  
      
    \# Check for extreme sentiment that could indicate manipulation  
    if abs(sentiment\_score) > 0.9:  
        log\_potential\_issue(tweet, 'Extreme sentiment detected')  
        return False  
      
    \# Check trading frequency to avoid market abuse  
    if trades\_in\_last\_hour > MAX\_TRADES\_PER\_HOUR:  
        log\_potential\_issue(tweet, 'Trading frequency exceeds limit')  
        return False  
      
    return True  
  
\# Use in main trading loop  
if compliance\_check(tweet, sentiment\_score, trade\_signal):  
    execute\_trade(trade\_signal)  
else:  
    log\_skipped\_trade(tweet, sentiment\_score, trade\_signal)

# 十.未来的增强功能

  

![](assets/010.png)

情绪分析领域及其在交易中的应用正在迅速发展。以下是未来需要增强的一些领域：

1.  **先进的NLP技术：**探索BERT或GPT-3等transformer模型，以获得更细致入微的情绪分析。
    
2.  **多模态情绪分析：**将图像和视频的分析与文本结合在一起，以获得更全面的情感视图。
    
3.  **可解释的人工智能：**实施技术，使您的情绪分析更具可解释性，这有助于合规性和策略完善。
    
4.  **替代数据源：**探索新的数据源，如卫星图像或步行交通数据，以补充传统的情绪来源。
    
5.  **强化学习：**使用RL技术根据市场条件和情绪动态调整您的交易策略。
    

以下是如何使用预训练的BERT模型实现更高级情绪分析的概念示例：

from transformers import AutoTokenizer, AutoModelForSequenceClassification  
import torch  
  
tokenizer = AutoTokenizer.from\_pretrained("ProsusAI/finbert")  
model = AutoModelForSequenceClassification.from\_pretrained("ProsusAI/finbert")  
def get\_advanced\_sentiment(text):  
    inputs = tokenizer(text, return\_tensors="pt", truncation=True, max\_length=512)  
    outputs = model(\*\*inputs)  
    probabilities = torch.nn.functional.softmax(outputs.logits, dim=-1)  
    sentiment = probabilities\[0\].tolist()  
    return {  
        'positive': sentiment\[2\],  
        'negative': sentiment\[0\],  
        'neutral': sentiment\[1\]  
    }  
\# Use in main trading loop  
sentiment = get\_advanced\_sentiment(tweet)  
if sentiment\['positive'\] > 0.7:  
    execute\_trade('buy')  
elif sentiment\['negative'\] > 0.7:  
    execute\_trade('sell')

这个例子使用FinBERT模型，该模型是专门针对财务文本进行训练的，以获得更细致入微的情绪分析。  

当增强系统时，请始终彻底反向测试并逐步实施更改，以确保交易策略的稳定性和可靠性。

总之，实施基于情绪的交易策略是一项复杂但可能有价值的努力。通过仔细考虑从数据收集到合规性的每个方面，并不断完善方法，可以开发一个利用情绪分析力量的复杂交易系统。像往常一样，在交易中，记住要仔细管理风险，永远不要停止学习和适应不断变化的市场格局。

  

不过上海爷叔夸张预测的中信证券，今天跌了不少，这可能也与整体的系统性风险有关。今天只有568只上涨，情绪冰点。

![](assets/011.jpg)

  

实践才能出真知！自己写代码实践吧！国内都有相关接口和数据源。

可以用akshare接口：

https://akshare.akfamily.xyz/data/stock/stock.html#id378

可以用tushare的接口：

https://tushare.pro/document/2?doc\_id=143  

**参考资料：**

https://finance.sina.cn/cj/2024-07-22/detail-incezcxz1249840.d.html  

https://www.mordorintelligence.com/zh-CN/industry-reports/emotion-analytics-market  

https://medium.com/@pta.forwork/sentiment-analysis-in-trading-an-in-depth-guide-to-implementation-b212a1df8391