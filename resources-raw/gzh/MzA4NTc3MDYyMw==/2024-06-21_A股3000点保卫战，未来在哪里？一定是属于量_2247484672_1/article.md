# A股3000点保卫战，未来在哪里？一定是属于量化的

小燕子 映翡量化 2024-06-21 19:13 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484672&idx=1&sn=b9d757fec756f468143ddd27111f10c9&chksm=9e7ed91fe7fc74b027f0d726793e9cdd05d5ba582b088fd6f89ab8b5c776e7dd8b412505de71#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484672&idx=1&sn=b9d757fec756f468143ddd27111f10c9&chksm=9e7ed91fe7fc74b027f0d726793e9cdd05d5ba582b088fd6f89ab8b5c776e7dd8b412505de71#rd)

![](assets/001.gif)

**一、A股3000点保卫战再度打响**‍

6月21日，上证指数早盘低开，跌穿3000点整数关口，科技股集体回调。

午后，沪指率先翻红在3000点上方反复拉锯。下午2点半前后再度跌至2998点，尾盘失守3000点整数关口。

截至收盘，上证指数微跌0.24%，报2998.14点，深证成指跌0.04%，报9064.84点，创业板指下跌0.39%，报1755.88点。

![](assets/002.jpg)

3000点的历史复盘  

    数据来源于我非常敬重的雪球大V："持有封基"的统计：

    自从2007年2月26日上证指数第一次站上3000点以来，已经进入第18个年头了，已经有58次站上3000点，今日一开盘，直接跌破3000点，历史上第58次跌破3000点了。这个统计只算了收盘点位，盘中跌破站上的更多了。

    3000点上，保持最久时间区间：2020年7月1日站上3000点，2022年4月25日跌破3000点，期间一共是663个自然日，将近2年时间。这也是大部分投资者最大批量的一次入市潮。当时的舆论都说和3000点永远告别了，谁知道到今天又再见了整整10次。

    最短站上3000点就只有1天就下来了，而且历史上数量最多，整整16次。18年来58次上上下下，平均每年3次多。18年来一共6325个自然日，3000点上的有3276天，大概一半多一点时间在3000点上。

![](assets/003.jpg)

![](assets/004.jpg)

  

**二、实盘量化策略三个月不亏不赢**‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍

    量化因子策略整整跑了3个月，期间经历了两次微盘股危机。在国九条出来的时候，及时调整了策略，4月16号的上午拼手速停掉了小票因子策略，随后两天切换成了配合最新国九条的策略，终于最近回本了，跑赢大盘了。🥰

  

![](assets/005.png)

     个人对量化的认知已经从小白升级了不少……

  

**三、量化的未来**  

1.因子策略，比拼的速度、算力和投研能力

 不断的人工和机器挖掘因子、失效、继续挖...‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍‍

![](assets/006.png)

来源《2023年中国量化投资白皮书研讨会暨园游会》      

2.非线性模型可能更适用中国市场

![](assets/007.jpg)

来源《2023年中国量化投资白皮书》‍

这是一个关于有效市场的概念。有效市场（比如美股）一些线性模型可能更合适；而中国A股目前还没有被充分竞争，离有效市场还有距离，也许确实非线性模型这些更合适A股。

  

不管哪种模型，都需要被实践证明。数据+模型，不断挖掘：

![](assets/008.jpg)

来源《2023年中国量化投资白皮书研讨会暨园游会》      

3.未来一定是属于量化

![](assets/009.jpg)

美国在量化之路上也是经历很多监管和救市，国内市场政策会越来越完善。

![](assets/010.jpg)

![](assets/011.jpg)

来源《2023年中国量化投资白皮书研讨会暨园游会》      

**四、学点代码：python统计分析上证指数近24年表现**

（1）2000年1月1日-2024年6月24日，总计交易日：5922天，收盘价小于3000点的天数为3738天，大于等于3000点的天数2184天。‍‍

（2）用pandas的统计了收盘价序列：  

交易天数           count  5922.000000  ‍‍

收盘价均值        mean   2603.867923

标准差               std     861.463476

最小值               min    1011.499023

四分之一分位数  25%    1958.998505

二分之一分位数  50%    2737.666016

四分之三分位数  75%    3179.887939

最大值                max    6092.057129

（3）收盘价直方图和k线，牛市在哪里？  

![](assets/012.png)

![](assets/013.png)

  

python代码，复制可用：

import yfinance as yf

import pandas as pd

import matplotlib.pyplot as plt

import numpy as np

\# Define the ticker symbol for the S&P 500 index

ticker\_symbol = "000001.ss"

\# Fetch daily data for the S&P 500 index

data = yf.download(ticker\_symbol, start='2000-01-01', end='2024-06-22')

\# Create a DataFrame

df = pd.DataFrame(data)

stock = df\[\['Close'\]\]

stock.plot()

plt.title("Closing Price  2000-2024")

plt.xticks(rotation=45)

plt.ylabel("Price")

plt.grid()

plt.show()

plt.hist(stock, bins=20, edgecolor='black')

plt.title('Frequency Distribution Histogram')

plt.xlabel('000001 index 1991-2024')

plt.ylabel('Frequency')

plt.show()

result = stock.value\_counts(stock\['Close'\] < 3000.00)

print(result)

des=stock.describe()

print(des)