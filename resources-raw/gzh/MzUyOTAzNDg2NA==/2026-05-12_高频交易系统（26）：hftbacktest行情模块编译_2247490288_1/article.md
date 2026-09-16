# 高频交易系统（26）：hftbacktest行情模块编译及数据分析

fintechhaibin FinTechHi 2026-05-12 21:38 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247490288&idx=1&sn=9db4a5c91f836639cb4af9743252b5ae&chksm=fb0b8146ddff2485bceaae656c0ec4e0e285ec5816de4ad214a28b788e7bcf6a3d89bf1fb5d1#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247490288&idx=1&sn=9db4a5c91f836639cb4af9743252b5ae&chksm=fb0b8146ddff2485bceaae656c0ec4e0e285ec5816de4ad214a28b788e7bcf6a3d89bf1fb5d1#rd)

![](assets/001.jpg)

hftbacktest是一个开发高频交易和做市策略而设计的开源系统。采用的是rust编程语言，并提供了Python交互接口。

![](assets/002.png)

它专注于考虑行情和订单延迟，以及用于订单成交模拟的订单队列位置。该框架旨在基于完整的订单簿和交易 tick 数据，提供更精准的基于市场回放的回测。

之前学习和借鉴过其架构功能设计。最近因为要跑个新的东西，想着直接用这个看看，懒得造轮子了。折腾了两个晚上，结果啥事都是看着容易做起来难。项目编译起来也是各种问题。今天正好都整好了记录下（特意使用了windows环境）。

1.安装Rust

这一步比较简单：

下载 Rust 安装程序：

```
https://static.rust-lang.org/rustup/dist/x86_64-pc-windows-msvc/rustup-init.exe
```

然后运行安装程序：\\rustup-init.exe

安装完成后会自动配置环境变量，然后验证安装：

```
rustc --version
```

我自己安装后，发现没有配置自动设置好环境变量。所以人工由设置了下。另外，安装后要重新开一个新的shell窗口执行命令。

```
# 设置cargo环境变量
```

  

2.安装Microsoft.VisualStudio.2022.BuildTools并编译行情模块

安装完rust后，就进入行情下载模块编译：

```
D:\hftbacktest\collector> cargo build --release
```

最后发现，为了跑通 hftbacktest，与其折腾各种环境问题，不如直接安装 Visual Studio 一次性解决编译依赖。

以管理员身份运行命令控制台后，执行命令：

```
winget install Microsoft.VisualStudio.2022.BuildTools --override "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
```

安装完成后重启电脑，然后在开始菜单中，以管理员身份打开：Developer PowerShell for VS 2022 命令行，继续执行编译命令：

```
D:\hftbacktest\collector> cargo build --release
```

出现错误：

```

```

然后又重新安装了vs2022:

```
& "C:\Program Files (x86)\Microsoft Visual Studio\Installer\setup.exe" modify --installPath "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools" --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended --passive
```

再次编译：

```
cd D:\hftbacktest\collector
```

这次编译成功了：

```

```

也看到行情读取程序的编译结果：

![](assets/003.png)

  

3.运行行情模块程序同步数据

程序内置了几个加密市场交易所的行情数据接口。

![](assets/004.png)

挨个试泪下，其中hyperliquid可以正常访问，启动程序命令如下：

```
.\collector.exe E:\btc hyperliquid BTC
```

出现如下提示，表示正在同步数据：

```
 INFO collector::hyperliquid::http: Connecting to Hyperliquid WebSocket with 3 subscriptions
```

ctrl + c 结束后，看到了同步到的深度数据（ob）。

![](assets/005.png)

  

4.行情数据转换

为什么要做这一步，往下看。本项目内置了转换工具，可以看这3个代码：

  

```
py-hftbacktest/hftbacktest/data/utils/binancefutures.py 
```

但这个代码中依赖了hftbacktest的Python包，安装方法有两个：

方案1是直接编译源码安装：

```
cd D:\hftbacktest\py-hftbacktest
```

安装前先创建个Python的虚拟环境并激活：

```
.venv\Scripts\activate
```

安装 maturin

```
pip install maturin
```

进入 py-hftbacktest 目录编译安装

```
cd D:\hftbacktest\py-hftbacktest
```

方案2：直接安装hftbacktest

```
pip install hftbacktest
```

我方案1报错了，各种尝试后不想浪费时间，所以选择了方案2。

然后编写了一个程序转换代码，因为我采集的hyperliquid，所以的使用hyperliquid.convert接口，而且需要提供 tick\_size 和 lot\_size 参数。

```
from hftbacktest.data.utils import hyperliquid
```

代码运行结果如下：

```
PS D:\hftbacktest\test> python .\convert_data.py
```

5.行情数据分析

前面通过行情下载器下载了ob数据，然后转换出来两个数据：

btc\_20260512.npz：采集的原始ob数据转换成hftbacktest自己的数据格式；

btc\_20260512\_eod.npz：基于ob数据生成快照数据。这一步后面详细会讲。

先看原始数据，代码如下：

```
import gzip
```

打印的数据第一个令牌是本地程序接收行情数据的时间戳。时间戳是以纳秒为单位。

```
b'1778572373496874200 {"channel":"trades","data":[
```

再看下转换后的数据：

```
import numpy as np
```

转换后的数据字段如下：

英文列名

中文释义

字段类型

业务含义说明

ev

事件类型编号

u64

行情 / 订单事件唯一标识、事件类型编码

exch\_ts

交易所时间戳

i64

交易所撮合纳秒级时间戳

local\_ts

本地时间戳

i64

程序本地接收纳秒级时间戳

px

价格

f64

盘口挂单 / 成交价格

qty

数量

f64

挂单量 / 成交量

order\_id

订单编号

u64

交易所原始订单 ID

ival

整型扩展字段

i64

预留整型自定义扩展字段

fval

浮点扩展字段

f64

预留浮点型自定义扩展字段

其中ev定义中可以区分买卖，这个设计地方做高频的可以参考下：

```
BUY_EVENT = 536870912   # 1 << 29 买/买盘
```

原始ob数据样例如下：

ev

exch\_ts

local\_ts

px

qty

order\_id

ival

fval

3489660930

1.77857E+18

1.77857E+18

80904

0.07352

0

0

0

3489660930

1.77857E+18

1.77857E+18

80904

0.12648

0

0

0

3758096386

1.77857E+18

1.77857E+18

80905

0.02746

0

0

0

3758096386

1.77857E+18

1.77857E+18

80905

0.00017

0

0

0

3758096386

1.77857E+18

1.77857E+18

80906

0.00017

0

0

0

3758096386

1.77857E+18

1.77857E+18

80907

0.00017

0

0

0

3758096386

1.77857E+18

1.77857E+18

80908

0.00017

0

0

0

3758096386

1.77857E+18

1.77857E+18

80909

0.00013

0

0

0

3758096386

1.77857E+18

1.77857E+18

80909

0.00017

0

0

0

3758096386

1.77857E+18

1.77857E+18

80910

0.00014

0

0

0

原始ob数据统计结果如下：

statistic

ev

exch\_ts

local\_ts

qty

order\_id

ival

fval

count

83254

83254

83254

83254

83254

83254

83254

null\_count

0

0

0

0

0

0

0

mean

3621500000

1.7786E+18

1.7786E+18

2.780774

0

0

0

std

134200000

553980000000

553980000000

5.304707

0

0

0

min

3489700000

1.7786E+18

1.7786E+18

0

0

0

0

25%

3489700000

1.7786E+18

1.7786E+18

0.19889

0

0

0

50%

3489700000

1.7786E+18

1.7786E+18

1.31828

0

0

0

75%

3758100000

1.7786E+18

1.7786E+18

3.00993

0

0

0

max

3758100000

1.7786E+18

1.7786E+18

120.86414

0

0

0

转换的快照数据如下：

![](assets/006.png)

快照数据（eod.npz）中：exch\_ts = 0, local\_ts = 0 - 时间戳为0，表示这是初始状态快照，只包含某一时刻的订单簿完整状态，用于回测开始时初始化订单簿。

再看下快照的px列，通过深度订单薄数据转换后的快照数据中，每个价格档位一行。一条快照记录 = 订单簿中的一个价格档位。

```
买盘快照（EV=3758096388）:
```

快照数据中的qty表示该价格档位上的挂单数量（订单簿深度），就是这个价格上有多少人在排队等着买/卖。原始ob中的qty就是这次交易/更新了多少数量

  

6.为什么要生成快照数据？

因为加密币市场是24\*7全天运行，没有"开盘"和"收盘"时间，collector 启动时只获取当前时刻的订单簿快照，比如如果从晚上9:00点开始采集，就只有晚上9点之后的数据。

而回测时需要完整的订单簿（买卖盘深度），没有初始快照，回测开始时订单簿是空的，无法正确模拟交易。逻辑是：

```
第一天采集 → 转换数据 → 创建"日末快照"
```

对应代码如下：

```
# 创建第一天的日末快照（作为第二天的初始状态）
```

回测时数据流是：

```
回测开始 → 加载快照 → 订单簿有完整深度 → 开始模拟交易
```

官方文档中提供了几种场景代码：

场景 1：当天数据

```
create_last_snapshot(
```

场景 2：连续多天回测

```
# 先创建第一天的快照
```

场景 3：从多天数据合并快照

```
create_last_snapshot(
```

至此，hftbacktest的数据就就绪了。