# 大模型量化应用2:机器学习从市场新闻中预测股票交易信号

小燕子搬砖 映翡量化 2024-05-16 20:04 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484327&idx=1&sn=9a689e5e0bb0d845b999546fda1f5d12&chksm=9e81dd4de7d65276a6c6d91ab439349c192507399e77045977df4a377393171b45ec3030a43d#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484327&idx=1&sn=9a689e5e0bb0d845b999546fda1f5d12&chksm=9e81dd4de7d65276a6c6d91ab439349c192507399e77045977df4a377393171b45ec3030a43d#rd)

![](assets/001.gif)

介绍一种使用机器学习方法从市场新闻生成交易信号模型策略。包括，市场新闻的分类、模板的创建、合成数据的生成、模型的训练以及使用实时新闻源预测信号。

![](assets/002.jpg)

**市场新闻分类**

分为六种类型，每种类型都有特定的权重，反映了其重要性：

-   分析师意见（权重：0.10）
    
-   外部因素（权重：0.10）
    
-   财务指标（权重：0.30）
    
-   内部人士活动（权重：0.05）
    
-   市场环境（权重：0.20）
    
-   发展战略（权重：0.25）
    

**每种新闻类型创建模板**

1.  分析师意见： 模板：“分析师\[姓名\]来自\[公司\]，已将\[公司\]从\[之前评级\]上调/下调至\[新评级\]，目标价格为\[目标价格\]。” 示例：“来自XYZ证券的分析师John Doe已将ABC公司从持有上调至买入，目标价格为150美元。”
    
2.  外部因素： 模板：“\[外部事件\]已影响\[市场/行业\]，导致对\[公司/行业\]的\[正面/负面\]预期。” 示例：“最近的利率上调已影响了科技行业，导致对软件公司的负面预期。”
    
3.  财务指标： 模板：“\[公司\]报告\[财务指标\]为\[值\]，\[高于/低于\]分析师预期的\[预期值\]。” 示例：“ABC公司报告第一季度每股收益为2.50美元，高于分析师预期的2.30美元。”
    
4.  内部人士活动： 模板：“\[内部人士姓名\]，\[公司\]的\[职位\]，已以每股\[价格\]的价格\[购买/出售\]了\[数量\]股份。” 示例：“ABC公司的首席财务官Jane Smith以每股145美元的价格出售了10,000股股份。”
    
5.  市场环境： 模板：“在当前市场环境下，由于\[原因\]，预计\[公司/行业\]将\[改善/下降\]。” 示例：“在当前市场环境下，由于政府支持的增加，预计可再生能源公司将改善。”
    
6.  发展战略： 模板：“\[公司\]已宣布\[发展战略\]，预计将\[影响\]公司的\[方面\]。” 示例：“ABC公司已宣布收购XYZ有限公司，预计将显著增强其市场份额。”
    

**生成合成数据**

使用模板，生成合成数据来训练模型。以下是如何为“分析师意见”新闻类型生成合成数据的示例：

import random  
from sklearn.feature\_extraction.text import TfidfVectorizer  
synthetic\_data =\[\]  
output=\[\]  
group\_index=0  
for group in combined\_text:  
 lines = group.split('\\n')  
 current\_group = groups\[group\_index\]  
 group\_index+=1  
 \# Generate synthetic data  
 for line in lines:  
     template = line  
     if line != '':  
         try:  
             for \_ inrange(3):  
                 text = template.format(  
                     name=random.choice(names),  
                     eps=round(random.uniform(1.5, 3.5), 2),  
                     change=random.choice(changes),  
                     revenue=random.randint(100, 200),  
                     percent=random.randint(10, 50),  
                     income=random.randint(20, 50),  
                     quantity=random.randint(20, 50),  
                     sector=random.choice(sectors),  
                     trend=random.choice(trends),  
                     economic\_indicator=random.choice(economic\_indicators),  
                     movement=random.choice(movements),  
                     area=random.choice(areas),  
                     factor=random.choice(factors),  
                     company=random.choice(names),  
                     insider=random.choice(executives),  
                     effect=random.choice(effects),  
                     region=random.choice(regions),  
                     product= random.choice(products),  
                     stock=random.choice(stocks),  
                     rating=random.choice(ratings),  
                     target=round(random.uniform(30, 70), 2),  
                     executive=random.choice(executives),  
                     action=random.choice(actions),  
                     amount=random.randint(5000, 15000),  
                     price=round(random.uniform(20, 60), 2),  
                     sentiment=random.choice(sentiments),  
                     country=random.choice(countries),  
                     industry= random.choice(industries)  
                 )  
                 print(text)  
                 synthetic\_data.append(text)  
                 output.append(current\_group)  
         except Exception as e:  
             continue

**训练模型**

使用随机森林分类器，以文本向量化作为特征，新闻类型作为输出。

  

**文本向量化**

TfidfVectorizer 将文本数据转换为数值特征。

max\_features=10000 限制特征数量为10,000，减少计算复杂性。

import joblib  
from sklearn.feature\_extraction.text import TfidfVectorizer  
from sklearn.model\_selection import train\_test\_split  
from sklearn.ensemble import RandomForestClassifier  
from sklearn.metrics import accuracy\_score  
  
\# Load and preprocess the dataset  
X = synthetic\_data  
y = output  
  
\# Split the dataset into training and validation sets  
X\_train, X\_valid, y\_train, y\_valid = train\_test\_split(X, y, test\_size=0.2, random\_state=42)  
  
\# Filter out empty strings from labels and map labels to indices  
context = groups  
y\_train\_indices = \[context.index(label) for label in y\_train if label != ''\]  
y\_valid\_indices = \[context.index(label) for label in y\_valid if label != ''\]  
  
\# Convert text data into numerical features using TF-IDF vectorization  
vectorizer = TfidfVectorizer(max\_features=10000)  
X\_train\_vect = vectorizer.fit\_transform(X\_train)  
X\_valid\_vect = vectorizer.transform(X\_valid)  
  
\# Train a logistic regression model  
model =  RandomForestClassifier(n\_estimators=100, random\_state=42)  
model.fit(X\_train\_vect, y\_train\_indices)  
  
\# Save the trained model and vectorizer for future use  
joblib.dump(model, "model.pkl")  
joblib.dump(vectorizer, "vectorizer.pkl")  
  
\# Evaluate the model on the validation set  
y\_pred = model.predict(X\_valid\_vect)  
accuracy = accuracy\_score(y\_valid\_indices, y\_pred)  
print("Validation Accuracy:", accuracy)

  

**使用实时新闻源预测信号**

实例里使用 Investing.com  RSS 订阅源来获取实时新闻，并根据训练好的模型来预测信号。

import joblib  
import nltk  
nltk.download('vader\_lexicon')  
from nltk.sentiment import SentimentIntensityAnalyzer  
import requests  
from xml.etree import ElementTree as ET  
import requests  
from bs4 import BeautifulSoup  
  
import spacy  
  
\# Load the spaCy model  
nlp = spacy.load('en\_core\_web\_sm')  
  
\# Initialize SentimentIntensityAnalyzer  
sentiment\_analyzer = SentimentIntensityAnalyzer()  
  
hold\_max=0.3  
hold\_min=-0.3  
  
\# Load the trained model and vectorizer  
model = joblib.load("model.pkl")  
vectorizer = joblib.load("vectorizer.pkl")  
  
\# URL of the RSS feed  
rss\_url = "https://investing.com/rss/news.rss"  
  
\# Fetch the RSS feed content  
response = requests.get(rss\_url, headers={'User-Agent': 'Mozilla/5.0'})  
rss\_content = response.text  
  
\# Parse the XML content  
root = ET.fromstring(rss\_content)  
  
\# Extract news items (title and link)  
news\_items = \[\]  
for item in root.findall('.//item'):  
   title = item.find('title').text  
   link = item.find('link').text  
   news\_items.append((title, link))  
  
print("Buy if final score is greater than",hold\_max)  
print("Sell if final score is less than",hold\_min)  
print("Hold if final score is between",hold\_min,"and",hold\_max)  
  
\# Assuming \`news\_items\` contains your extracted links  
for title, link in news\_items:  
   page\_response = requests.get(link, headers={'User-Agent': 'Mozilla/5.0'})  
   soup = BeautifulSoup(page\_response.content, 'html.parser')  
   paragraphs = \[p.get\_text() for p in soup.find\_all('p')\]  
   main\_text = ' '.join(paragraphs)  
   new\_texts = main\_text  
   new\_texts\_vect = vectorizer.transform(new\_texts.split('.'))  
   score\_weight = \[0.10,0.10,0.30,0.05,0.20,0.25\]  
         
   \# Make predictions  
   predictions = model.predict(new\_texts\_vect)  
   idx=0  
   sentiment\_scores = \[\]  
   b=0  
   s=0  
   h=0  
   cs =\[0,0,0,0,0,0\]  
   csc =\[0,0,0,0,0,0\]  
   for text in new\_texts.split('.'):  
       if(len(text)>4):  
           sentiment\_score = sentiment\_analyzer.polarity\_scores(text)  
           cs\[predictions\[idx\]\]+=sentiment\_score\['compound'\]  
           csc\[predictions\[idx\]\]+=1  
           idx+=1  
   fs=0  
   for us inrange(len(csc)):  
       if csc\[us\]==0:  
           continue  
       fs+=score\_weight\[us\]\* cs\[us\]/csc\[us\]  
  
   result="hold"  
   final\_score = "{0:.2f}".format(fs)  
   if fs>hold\_max:  
       result="buy"  
       print(final\_score,result, title)  
   elif fs<hold\_min:  
       result="sell"  
       print(final\_score,result, title)  
   else:  
       result="hold"  
       print(final\_score,result, title)

  

**结论‍‍**

模型步骤：对新闻类型进行分类、创建模板、生成合成数据、训练模型以及使用实时新闻源进行预测。

貌似可以开发出一个强大的系统，从市场新闻中生成交易信号。

  

参考资料：https://github.com/pkr-peasy/news-based-signal/blob/main/signal\_generator.ipynb