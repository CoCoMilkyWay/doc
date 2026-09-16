# 热力图谁家强？python轻松实现

小燕子 映翡量化 2023-07-22 00:47 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247483717&idx=1&sn=2df10bcfe82e4fa6d490fd88b76b7aeb&chksm=9ecbbc7c15a063ba779cf86cf60b3d6275442a0232714feb16fd0f843a4685b20502e344868b#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247483717&idx=1&sn=2df10bcfe82e4fa6d490fd88b76b7aeb&chksm=9ecbbc7c15a063ba779cf86cf60b3d6275442a0232714feb16fd0f843a4685b20502e344868b#rd)

Tradingview：实力派选手

![](assets/001.jpg)

​

![](assets/002.jpg)

​

![](assets/003.jpg)

​

  

同花顺：

![](assets/004.jpg)

​

![](assets/005.jpg)

​

万得：

![](assets/006.jpg)

​

小燕子搬砖：

![](assets/007.jpg)

​

小燕子搬砖的python代码，欢迎copy：

@author: Shenxiaoyan  
"""  
  
import pandas as pd  
import yfinance as yf  
  
\# sp500 = pd.read\_html(r'https://en.wikipedia.org/wiki/List\_of\_S%26P\_500\_companies')\[0\]\['Symbol'\]  
sp500 = \["603799.ss", "603986.ss", "603501.ss", "603288.ss", "603259.ss", "601995.ss", "601919.ss",  
"601899.ss", "601888.ss", "601857.ss", "601728.ss", "601688.ss", "601668.ss", "601633.ss",  
"601628.ss", "601601.ss", "601398.ss", "601318.ss", "601288.ss", "601211.ss", "601166.ss",  
"601088.ss", "601066.ss", "601012.ss", "600905.ss", "600900.ss", "600893.ss", "600887.ss",  
"600837.ss", "600809.ss", "600745.ss", "600690.ss", "600588.ss", "600585.ss", "600570.ss",  
"600519.ss", "600438.ss", "600436.ss", "600346.ss", "600309.ss", "600276.ss", "600196.ss",  
"600111.ss", "600104.ss", "600048.ss", "600036.ss", "600031.ss", "600030.ss", "600028.ss", "600010.ss"\]  
tickers = \[\]  
deltas = \[\]  
sectors =\[\]  
market\_caps = \[\]  
  
\# sp500 = sp500.sample(20)  
  
for ticker in sp500:  
  
try:  
\## create Ticker object  
stock = yf.Ticker(ticker)  
tickers.append(ticker)  
  
\## download info  
info = stock.info  
  
\## download sector  
sectors.append(info\['sector'\])  
  
\## download daily stock prices for 2 days  
hist = stock.history('2d')  
  
\## calculate change in stock price (from a trading day ago)  
deltas.append((hist\['Close'\]\[1\]-hist\['Close'\]\[0\])/hist\['Close'\]\[0\])  
  
\## calculate market cap  
market\_caps.append(info\['sharesOutstanding'\] \* info\['previousClose'\])  
  
\## add print statement to ensure code is running  
print(f'downloaded {ticker}')  
except Exception as e:  
print(e)  
  
  
df = pd.DataFrame({'ticker':tickers,  
'sector': sectors,  
'delta': deltas,  
'market\_cap': market\_caps,  
})  
  
color\_bin = \[-1,-0.02,-0.01,0, 0.01, 0.02,1\]  
df\['colors'\] = pd.cut(df\['delta'\], bins=color\_bin, labels=\['red','indianred','lightpink','lightgreen','lime','green'\])  
  
import plotly.express as px  
from plotly.offline import plot  
fig = px.treemap(df, path=\[px.Constant("all"), 'sector','ticker'\], values = 'market\_cap', color='colors',  
color\_discrete\_map ={'(?)':'#262931', 'red':'red', 'indianred':'indianred','lightpink':'lightpink', 'lightgreen':'lightgreen','lime':'lime','green':'green'},  
  
hover\_data = {'delta':':.2p'}  
)  
plot(fig)

  

有没有华尔街的感觉

![](assets/008.jpg)

​