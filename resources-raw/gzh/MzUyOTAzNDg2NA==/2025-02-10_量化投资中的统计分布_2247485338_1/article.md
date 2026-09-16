# 量化投资中的统计分布

fintechhaibin FinTechHi 2025-02-10 06:27 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247485338&idx=1&sn=ff439e0ef786333643cf54f3ac6e1ac6&chksm=fb334568a3c65d6eb56137aa00a7c5a18353fa6b54b551b2c5b0c712af1f8222fe6bf64f8cc6#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247485338&idx=1&sn=ff439e0ef786333643cf54f3ac6e1ac6&chksm=fb334568a3c65d6eb56137aa00a7c5a18353fa6b54b551b2c5b0c712af1f8222fe6bf64f8cc6#rd)

# 量化投资中需要对数据做各种分析，自然少不了对数据分布情况进行多维统计，以便更一步分析。有人列出了常用的分析方法。下面纯概念的角度一一介绍下。

![](assets/001.png)

#   

#### 1\. 均匀分布（Uniform Distribution）

-   **特性**：等概率分布
    
-   **应用场景**：随机数生成、蒙特卡洛模拟
    
-   **代码演示**：生成均匀分布数据并绘制直方图
    
    `import numpy as np   import matplotlib.pyplot as plt      data = np.random.uniform(0, 1, 1000)   plt.hist(data, bins=10, density=True)   plt.title("均匀分布")   plt.show()   `
    

####   

![](assets/002.png)

####   

#### 2.正态分布（Normal Distribution）

-   **特性**：钟形曲线，对称分布
    
-   **应用场景**：资产收益率建模、Black-Scholes期权定价
    
-   **代码演示**：生成正态分布数据并绘制直方图
    
    `data = np.random.normal(0, 1, 1000)   plt.hist(data, bins=30, density=True)   plt.title("正态分布")   plt.show()   `
    

####   

![](assets/003.png)

#### 3.二项分布（Binomial Distribution）

-   **特性**：离散分布，描述成功次数
    
-   **应用场景**：事件发生概率建模（如违约概率）
    
-   **代码演示**：计算二项分布概率并绘制条形图
    
    `from scipy.stats import binom      n, p = 10, 0.5   x = np.arange(0, n+1)   pmf = binom.pmf(x, n, p)   plt.bar(x, pmf)   plt.title("二项分布")   plt.show()   `
    

####   

![](assets/004.png)

####   

#### 4\. 泊松分布（Poisson Distribution）

-   **特性**：稀有事件发生次数的分布
    
-   **应用场景**：高频交易中的订单到达频率、市场冲击事件
    
-   **代码演示**：计算泊松分布概率并绘制条形图
    
    `from scipy.stats import poisson      lam = 3   x = np.arange(0, 10)   pmf = poisson.pmf(x, lam)   plt.bar(x, pmf)   plt.title("泊松分布")   plt.show()   `
    

####   

![](assets/005.png)

#### 5\. 对数正态分布（Log-Normal Distribution）

-   **特性**：右偏分布，适用于正数数据
    
-   **应用场景**：股票价格建模、波动率分析
    
-   **代码演示**：生成对数正态分布数据并绘制直方图
    
    `data = np.random.lognormal(mean=0, sigma=1, size=1000)   plt.hist(data, bins=30, density=True)   plt.title("对数正态分布")   plt.show()   `
    

#### ![](assets/006.png)

#### 6\. 伽马分布（Gamma Distribution）

-   **特性**：右偏分布，适用于等待时间数据
    
-   **应用场景**：期权定价中的时间衰减、风险事件间隔
    
-   **代码演示**：生成伽马分布数据并绘制直方图
    
    `from scipy.stats import gamma      shape, scale = 2, 2   data = gamma.rvs(a=shape, scale=scale, size=1000)   plt.hist(data, bins=30, density=True)   plt.title("伽马分布")   plt.show()   `
    

#### ![](assets/007.png)

#### 7\. 几何分布（Geometric Distribution）

-   **特性**：首次成功所需的试验次数
    
-   **应用场景**：策略失效前的交易次数、风险事件发生时间
    
-   **代码演示**：计算几何分布概率并绘制条形图
    
    `from scipy.stats import geom      p = 0.5   x = np.arange(1, 11)   pmf = geom.pmf(x, p)   plt.bar(x, pmf)   plt.title("几何分布")   plt.show()   `
    

#### ![](assets/008.png)

#### 8\. 贝塔分布（Beta Distribution）

-   **特性**：灵活的概率分布，适用于比例数据
    
-   **应用场景**：A/B测试、投资组合权重优化
    
-   **代码演示**：生成贝塔分布数据并绘制直方图
    
    `from scipy.stats import beta      a, b = 2, 5   data = beta.rvs(a, b, size=1000)   plt.hist(data, bins=30, density=True)   plt.title("贝塔分布")   plt.show()   `
    

### ![](assets/009.png)

### 统计分布在量化投资中的应用案例

-   **资产收益率建模**
    

-   使用正态分布和对数正态分布建模股票收益率
    
-   案例分析：标普500指数收益率分布
    

-   **风险管理**
    

-   使用泊松分布建模极端事件（如市场崩盘）
    
-   案例分析：VaR（风险价值）计算
    

-    **期权定价**
    

-   使用正态分布和伽马分布构建期权定价模型
    
-   案例分析：Black-Scholes模型与波动率曲面
    

-   **投资策略优化**
    

-   使用贝塔分布优化投资组合权重
    
-   案例分析：多资产组合的风险调整收益
    

### 工具与资源

-   **Python库推荐**
    

-   NumPy：数值计算
    
-   SciPy：统计分布与科学计算
    
-   Matplotlib：数据可视化
    

-   **学习资源**
    

-   书籍推荐：《统计学习方法》、《Python金融大数据分析》
    
-   在线课程：Coursera、QuantConnect
    

### 对上面的内容，做了一个PPT，若有需要可用于自己学习和团队交流参考，下面是PPT部分内容。需要完整的后台留言即可。

![](assets/010.png)

![](assets/011.png)

![](assets/012.png)

![](assets/013.png)

![](assets/014.png)

![](assets/015.png)

![](assets/016.png)