# 基于ChatGPT的多因子框架实现

partition QuantSeek 2023-06-11 20:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg3OTk3NDkyMQ==&mid=2247483897&idx=1&sn=2163a2b98a1b26a8f1e7f6478270404b&chksm=ce17d3ed3a9151124e24cdb631b4da75a3b9a037ea06eb1fa078e9ce580f485dd60952f03e32#rd](https://mp.weixin.qq.com/s?__biz=Mzg3OTk3NDkyMQ==&mid=2247483897&idx=1&sn=2163a2b98a1b26a8f1e7f6478270404b&chksm=ce17d3ed3a9151124e24cdb631b4da75a3b9a037ea06eb1fa078e9ce580f485dd60952f03e32#rd)

尝试用ChatGPT完成量化测试中的常用功能，包括**因子构建、因子改进、测试框架，**毕竟如果ChatGPT都会算会改进的因子，如果还不会，就只能去搬砖了，就问你慌不慌  

除了这里展示的这些，还尝试了一些其他的，包括询问特定基金、股票的信息、求导、积分，甚至解偏微分方程，都能实现。测下来的整体感觉是，除了不能保证准确度，其他都挺好的，但毕竟只是3.5，4已经有了相当程度的提升，以后可能还会有5、6...，相信这会是一个新时代的起点

**因子定义及改进**

**动量因子**，代码太长截不下，完整代码放后面了  

![](assets/001.png)

完整代码如下，有点问题，但问题不大

import datetime  
import pandas as pd  
from WindPy import w  
  
\# 初始化Wind API  
w.start()  
  
\# 设置起始日期和结束日期  
start\_date = datetime.date(2022, 3, 1)  
end\_date = datetime.date(2023, 3, 21)  
  
\# 获取股票数据  
code = "000001.SZ"  
data = w.wsd(code, "close", start\_date, end\_date, "Fill=Previous")  
  
\# 将数据转换为DataFrame  
df = pd.DataFrame(data.Data\[0\], index=data.Times, columns=\["close"\])  
  
\# 计算Momentum指标  
df\["Mom12\_1"\] = df\["close"\].pct\_change(periods=12)  
  
\# 输出结果  
print(df.tail())

![](assets/002.png)

**反转因子**

![](assets/003.png)

完整代码附在下面，可以测试一下，甚至会帮忙把因子调整成正向

import numpy as np  
import pandas as pd  
from datetime import datetime, timedelta  
from WindPy import w  
  
\# 连接Wind API  
w.start()  
  
\# 设置计算参数  
start\_date = datetime.now() - timedelta(days=30) \# 计算过去一个月的数据  
end\_date = datetime.now()  
stock\_code = '600000.SH'  
freq = 'M'  
field = 'close'  
  
\# 获取股票收盘价数据  
raw\_data = w.wsd(stock\_code, field, start\_date, end\_date, "")  
  
\# 将数据转换为DataFrame格式  
df = pd.DataFrame(raw\_data.Data\[0\], index=raw\_data.Times, columns=\[stock\_code\])  
df = df.resample(freq).last().ffill()  
  
\# 计算收益率并标准化  
returns = df.pct\_change().dropna()  
z\_scores = (returns - returns.mean()) / returns.std()  
  
\# 计算反转因子并排序  
rev\_factor = -z\_scores  
rev\_factor = rev\_factor.dropna().sort\_values()  
  
\# 输出结果  
print(rev\_factor)

![](assets/004.png)

**超预期因子**  

![](assets/005.png)

完整代码如下，不能说完全错误，至少也是毫不相干吧

import datetime  
import pandas as pd  
from WindPy import w  
  
\# 初始化Wind API  
w.start()  
  
\# 设置起始日期和结束日期  
start\_date = datetime.date(2022, 3, 1)  
end\_date = datetime.date(2023, 3, 21)  
  
\# 获取股票数据  
code = "000001.SZ"  
fields = \["eps\_basic", "eps\_diluted", "oper\_rev", "net\_profit"\]  
data = w.wsd(code, fields, start\_date, end\_date, "Fill=Previous")  
  
\# 将数据转换为DataFrame  
df = pd.DataFrame(data.Data, index=fields, columns=data.Times).T  
  
\# 计算预期收益  
df\["expected\_eps"\] = df\["oper\_rev"\] \* df\["eps\_basic"\] / df\["net\_profit"\]  
  
\# 计算非预期收益  
df\["unexpected\_eps"\] = df\["eps\_basic"\] - df\["expected\_eps"\]  
  
\# 计算标准化非预期收益（SUE）  
df\["SUE"\] = df\["unexpected\_eps"\].rolling(window\=4).std() / df\["eps\_basic"\].rolling(window\=4).std()  
  
\# 输出结果  
print(df.tail())

![](assets/006.png)

![](assets/007.png)

![](assets/008.png)

**测试框架**

**计算IC的函数**

![](assets/009.png)

**分层测试的函数**  

![](assets/010.png)

完整代码如下  

import pandas as pd  
import numpy as np  
import statsmodels.api as sm  
  
  
def factor\_test(factor\_data, ret\_data, num\_groups=5):  
    """  
    进行因子分层测试  
      
    参数：  
    factor\_data : pandas.DataFrame  
        包含因子值的数据框  
    ret\_data : pandas.DataFrame  
        包含股票收益率的数据框  
    num\_groups : int, 可选（默认值为5）  
        分层的组数  
      
    返回：  
    dict  
        包含每个组的平均收益率和t值的字典  
    """  
    \# 确保因子和收益率数据的列名一致  
    factor\_data.columns = ret\_data.columns  
      
    \# 将因子值标准化为z-score  
    factor\_data = (factor\_data - factor\_data.mean()) / factor\_data.std()  
      
    \# 按因子值大小将股票分为不同的组  
    groupings = pd.qcut(factor\_data, num\_groups, labels=False)  
      
    \# 计算每个组的平均收益率和t值  
    group\_ret = ret\_data.groupby(groupings)  
    means = group\_ret.mean()  
    stds = group\_ret.std()  
    t\_values = means / (stds / np.sqrt(group\_ret.count()))  
      
    \# 返回结果  
    return {"mean\_returns": means, "t\_values": t\_values}

**事件测试的函数  
**

![](assets/011.png)

**组合优化的函数**

![](assets/012.png)

代码如下  

import numpy as np  
import pandas as pd  
from scipy.optimize import minimize  
  
def optimize\_portfolio(stocks, start\_date, end\_date):  
    \# 获取股票数据  
    data = get\_stock\_data(stocks, start\_date, end\_date)  
  
    \# 计算日收益率和协方差矩阵  
    returns = data.pct\_change().mean()  
    cov\_matrix = data.pct\_change().cov()  
  
    \# 定义优化函数  
    def portfolio\_variance(weights):  
        return np.dot(weights.T, np.dot(cov\_matrix, weights))  
  
    \# 定义约束条件  
    constraints = ({'type': 'eq', 'fun': lambda x: np.sum(x) - 1})  
  
    \# 设置初始权重  
    num\_stocks = len(stocks)  
    init\_weights = np.array(\[1.0 / num\_stocks\] \* num\_stocks)  
  
    \# 最小化方差  
    result = minimize(portfolio\_variance, init\_weights, method='SLSQP',  
                      constraints=constraints)  
  
    \# 返回最优权重  
    return result.x