# Riskfolio-Lib实现投资组合优化

大顺 量化前沿速递 2023-12-04 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487204&idx=1&sn=1992762e83a58bf6194a9c85b5394e59&chksm=c3a27028d826e5bcc4e1d7fa43c1b15ebce5bc301fd994aed79bcead1b1217ac2299a0b5792b#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487204&idx=1&sn=1992762e83a58bf6194a9c85b5394e59&chksm=c3a27028d826e5bcc4e1d7fa43c1b15ebce5bc301fd994aed79bcead1b1217ac2299a0b5792b#rd)

Riskfolio-Lib 是一个开源的 Python 库，其目标是帮助大家轻松构建基于数学复杂模型的投资组合，它基于 cvxpy 构建，并且兼容pandas的 数据结构。与基于方差的投资组合优化模型相比;Riskfolio-Lib 允许用户探索基于多种风险度量的投资组合模型，例如风险条件值、风险熵值、风险条件回撤等。可以帮助用户构建复杂约束，如线性约束、风险度量约束、资产数量约束等。

![](assets/001.png)

安装和使用

安装非常简单：

```
pip install Riskfolio-Lib
```

使用 yfinace 下载一些案例数据，A股数据下载可参考小海豹前面系列文章提到的方法。

```
import numpy as np
```

![](assets/002.png)

然后我们需要构建投资组合对象，这个对象包含了所有基于凸规划的投资组合模型。

```
import riskfolio.Portfolio as pf
```

![](assets/003.png)

通过几个步骤获得了最大化夏普比率的最佳投资组合。如果我们想查看投资组合的结构，我们可以绘制一个饼图：

```
import riskfolio.PlotFunctions as plf
```

![](assets/004.png)

此外，有时我们想看看边界在哪。Riskfolio-Lib 允许使用几行代码来计算它：

```
points = 50 # Number of points of the frontier
```

![](assets/005.png)

如果我们想在平面风险回报中绘制边界，我们必须运行以下代码：

```
# Plotting the efficient frontier
```

![](assets/006.png)

如果我们想绘制资产的边界构成，我们运行代码：

```
# Plotting efficient frontier composition
```

![](assets/007.png)

到目前为止，我们一直使用方差作为风险度量，但是 Riskfolio-Lib 有 13 个风险度量可用，要根据 13 个风险度量以回报/风险比率为目标函数来比较资产配置，我们必须运行以下代码：

```
# Risk Measures available:
```

![](assets/008.png)

我们可以制作一个条形图来比较每个风险指标的资产配置。

```
import matplotlib.pyplot as plt
```

![](assets/009.png)

GitHub：https://github.com/dcajasn/Riskfolio-Lib