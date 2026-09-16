# Qlib学习分析（三）：数据处理与准备

FinTechHi FinTechHi 2023-07-24 00:10 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247483821&idx=1&sn=5a0c0299ed8f03ff6239653867729411&chksm=fbf9289011b24ca1461859e3c0ebef13be17e7e16ef79549ad84cec482f7423e93f95106a09c#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247483821&idx=1&sn=5a0c0299ed8f03ff6239653867729411&chksm=fbf9289011b24ca1461859e3c0ebef13be17e7e16ef79549ad84cec482f7423e93f95106a09c#rd)

## 

第三章.数据处理与准备

### 

3.1数据模块设计思路

3.1.1金融数据特点

在定量研究中，最常用的数据格式都遵循这样的格式：

![](assets/001.png)

编辑

  

添加图片注释，不超过 140 字（可选）

  

其中：

> xi,t,a为基本类型的值(如:float, int)，

> Inst表示金融工具集(例如:Time表示时间戳集(例如:股票、期权等);

> Attr表示一种工具的可能属性集(如:股票市场的交易日，如:开盘价、成交量、市场价值)，

> T表示数据的最新时间戳

这样的金融数据结构其实要求也比较简单。许多开源的技术解决方案都能支持这样的操作。比较常见的主要技术方案方案选型主要包括：

> •通用数据库：MySQL， MongoDB。

> •时序数据库：InfluxDB、KDB、MatrixDB、DolphinDB、ClickHouse。

> •用于科学计算的数据文件：由Numpy数组或Pandas数据框架组织的数据。

通用数据库和时序数据库各有特点：

> 通用数据库支持多种格式和结构的数据。此外，它还提供了许多复杂的机制，如索引、事务、实体-关系模型等。它们中的大多数都给特定任务增加了沉重的依赖性和不必要的复杂性，而不是解决特定场景中的关键问题。

> 时间序列数据库优化了时间序列数据的数据结构和查询。但它们仍然不是为定量研究而设计的，在定量研究中，数据通常是基于紧凑数组的格式，用于科学计算，以利用硬件加速。如果数据在不进行格式转换的情况下保持基于紧凑数组的格式从磁盘到客户端，将会节省大量的时间。

然而，无论是通用数据库还是时间序列数据库，都是为了通用目的而以不同的格式存储和传输数据，这对于科学计算来说是低效的。

由于数据库的低效率，基于数组的数据在科学界得到了普及。Numpy数组和Pandas数据框架是科学计算中的主流实现，它们通常以HDF5或pickle的形式存储在磁盘上。这种格式的数据具有较轻的依赖性，对于科学计算来说非常高效。然而，这样的数据存储在单个文件中，很难更新或查询。

结合上述问题，Qlib的数据设计架构可以很好地适应定量研究场景。为定量研究设计定制化的解决方案。

3.1.2数据存储设计

Qlib以树状结构存储文件，数据根据不同类型被分成文件夹和文件。左边部分是文件的目录结构；右边部分是文件的内容包括：频率、证券和属性。所有属性的值都以二进制数据的形式存储在一个紧凑的固定宽度format中，这样就可以按字节进行索引。

![](assets/002.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

交易日历单独存储在名为“calendar.txt”的文件中。属性值的数据文件将其前4个字节设置为时间序列的索引值，以指示该系列数据的开始时间戳。使用开始时间索引，Qlib可以对齐时间维度上的所有值。

数据以紧凑的格式存储，可以高效地组合成数组进行科学计算。在科学计算中实现了像基于数组的数据那样的高性能的同时，满足了量化投资场景下的数据更新需求。所有数据都是按照时间的顺序排列的。新数据可以通过ap-pending进行更新，效率相当高。

添加和删除属性或证券也很方便，因为它们存储在单独的文件中。这样的设计非常轻巧。没有数据库的开销，更好的满足了量化投资中对于高性能的要求。

3.1.3表达式引擎

基于基础数据开发新的因子（特征）是量化投资中一项相当常见的任务，这样的任务占用了很多量化研究员大部分时间，因此，Qlib提供了一个表达式引擎，以便帮助研究员可以更简单的进行因子（特征）的研究工作，并提高研究员的效率。

实际上，因子（特征）的本质是一个将基础数据转换为目标值的函数。这个函数可以分解成一系列表达式的组合。表达式引擎就是基于这个想法设计的。有了这个表达式引擎，定量研究人员可以通过编写表达式而不是复杂的代码来实现新的因子/特征。例如，布林格带技术指标是一个广泛使用的技术因子，它的上界在Qlib中可以通过简单的表达式来实现：

“(MEAN($close, N) + 2\*STD($close, N) - $close) / MEAN($close, N)”

这样的实现简单、易读、可重用、可维护。用户只需使用一系列简单的表达式就可以轻松构建一个数据集。

3.1.4缓存系统

为了避免重复计算，Qlib有一个内置的缓存系统。它由内存缓存和磁盘缓存组成。

当Qlib使用表达式引擎计算因子（特征）时，它将表达式解析为语法树。所有节点的计算结果将存储在内存中的LRU(Least Recently Used)缓存中。相同(子)表达式的复制计算可以被保存。

一个典型的量化投资数据处理流程可以分为三个步骤：

-   获取原始数据
    
-   计算表达式
    
-   将数据组合成数组进行科学计算
    

计算表达式和组合数据是非常耗时的，如果可以缓存共享的中间数据，可以节省很多时间。在实际的数据处理任务中，很多中间结果是可以共享的。例如，相同的表达式计算可以被不同的数据处理任务共享。因此，Qlib设计了一个2级磁盘缓存机制。

![](assets/003.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

左边的部分是原始数据。第一层是表达式缓存，它会把所有计算出来的表达式保存到磁盘缓存中。表达式缓存的数据结构和原始数据是一样的。有了表达式缓存，同一个表达式只会被计算一次。表达式缓存之后是数据集缓存，存储组合后的数据，节省组合时间。两个级别的缓存数据都是按时间排列的，在时间维度上是可索引的，所以即使查询时间发生变化，磁盘缓存也可以共享。此外，由于数据按时间排列，Qlib支持通过添加新数据来更新数据。有了这样的机制，数据的维护就容易多了。

3.1.5超参优化

对于大多数机器学习算法来说，超参数优化是实现更好泛化的必要步骤。虽然它很重要，但它需要大量的努力，并且是完全重复。因此，Qlib提供了一个超参数调优引擎(HTE)来简化这样的任务。HTE提供了一个接口来定义一个超参数搜索空间，然后自动搜索最佳超参。

在对时间序列数据建模的典型财务任务中，新数据是按时间顺序出现的。为了利用新数据，模型必须定期对新数据进行重新训练。新的最佳超参会发生变化，但通常与之前的最佳超参数接近。HTE提供了一种机制，致力于对财务任务进行超参数优化。它为超参数搜索空间生成了一个新的分布，从而有更好的机会以更少的试验达到最佳点。

### 

3.2获取金融市场数据

### 

3.2.1下载数据到指定目录

使用Qlib内置的数据源并下载到本地目录，用于后续研究使用：

import qlib

from qlib.contrib.data.handler import Alpha158

from qlib.data.dataset import TSDatasetH

from qlib.contrib.model.pytorch\_alstm\_ts import ALSTM

from qlib.tests.data import GetData

from qlib.constant import REG\_CN

data\_uri = 'E:/qlib/qlib\_data/cn\_data'

qlib.init(provider\_uri=data\_uri, region=REG\_CN)

GetData().qlib\_data(target\_dir=data\_uri, region=REG\_CN)

或者使用源码下面的程序get\_data.py：

python scripts/get\_data.py qlib\_data --target\_dir ~/.qlib/qlib\_data/cn\_data --region cn

下载后的数据目录如下：

![](assets/004.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

其中calendars数据就一列，显示的是交易日：

> 1999-11-10

> 1999-11-11

> 1999-11-12

> ......

features数据如下图，按不同证券代码分类，每个证券代码文件下按不同特征单独存放数据，数据为二进制格式，可以对比着上面理论部分理解。

![](assets/005.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

Instruments目录下为按证券代码存放的文件，其中all.txt中包括所有证券。

![](assets/006.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

文件里面的数据就两列：证券代码和时间周期，如下图：

![](assets/007.png)

编辑

  

添加图片注释，不超过 140 字（可选）

  

### 

3.2.2导入外部数据

Qlib支持用户提供的csv格式数据，需要调用dump\_all指令将csv格式数据转换为bin和txt格式。

python scripts/dump\_bin.py dump\_all 

![](assets/008.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

上述dump\_all指令包含如下参数：

> symbol\_field\_name：csv文件中股票代码列名，此处为stock\_code；

> date\_field\_name：csv文件中日期列名，此处为date；

> include\_fields：其余字段名，注意逗号后不能有空格，否则数据转换将出现错误。

转换后的目录结构及文件格式如下（和上面一致）：

![](assets/009.png)

编辑切换为居中

  

添加图片注释，不超过 140 字（可选）

  

### 

3.2.3数据核心模块类

Qlib中关于数据主要有以下三个模块：

-   Data Loader: 从数据源加载数据，数据源可以是已经转换为qlib内置格式的数据，也可以是其他外部数据；
    
-   Data Handler: 对数据进行预处理，比如常见的缺失值、标准化等；
    
-   Dataset: 为模型的训练准备数据，类似Pytorch中的Dataset。
    

1)QlibDataLoader

> from qlib.data.dataset.loader import QlibDataLoader

> \# 加载原始特征，比如收盘价、最高价

> qdl \= QlibDataLoader(config\=(\['$close', '$high'\],\['close', 'high'\]))

> qdl.load(instruments\=\['SH600519'\], start\_time\='20190101', end\_time\='20191231')

> \# 可以通过freq参数设置周期，默认freq='day'

除了直接加载原始特征，有时我们需要对不同的原始特征做一些运算生成新的特征，比如我们想计算收盘价的均线。这时我们可以使用qlib的算式表达式功能，直接在加载时进行计算，具体请看下面案例。

> \# 这次我们加载沪深300成分股的10日和30日收盘价指数加权均价

> market \= 'sh000300' \# 沪深300股票池代码，在instruments文件夹下有对应的sh000300.txt

> close\_ma \= \['EMA($close, 10)', 'EMA($close, 30)'\] \# EMA($close, 10)表示计算close的10日指数加权均线

> ma\_names \= \['EMA10', 'EMA30'\]

> qdl\_ma \= QlibDataLoader(config\=(close\_ma, ma\_names))

> qdl\_ma.load(instruments\=market, start\_time\='20210101', end\_time\='20210110')

qlib把类似“EMA”称为算子（operator），qlib中全部支持的算子可以在以下源码中找到：/qlib/data/ops.py中，主要有：

> ChangeInstrument, Rolling, Ref, Max, Min, Sum, Mean, Std, Var, Skew, Kurt, Med, Mad, Slope, Rsquare, Resi, Rank, Quantile, Count, EMA, WMA, Corr, Cov, Delta, Abs, Sign, Log, Power, Add, Sub, Mul, Div, Greater, Less, And, Or, Not, Gt, Ge, Lt, Le, Eq, Ne, Mask, IdxMax, IdxMin, If, Feature, PFeature，

有时我们需要对计算的数据进行分组，最常用的是分为特征组“feature”和“label”组，此时我们可以传入dict格式的参数至config中，具体看下面实例：

\# 沪深300股票池代码，在instruments文件夹下有对应的sh000300.txt

market = 'sh000300' 

\# EMA($close, 10)表示计算close的10日指数加权均线

close\_ma = \['EMA($close, 10)', 'EMA($close, 30)'\]ma\_names = \['EMA10', 'EMA30'\]ret = \["Ref($close, -1)/$close-1"\] 

\# 下一日收益率, Ref($close, -1)表示下一日收盘价

ret\_name = \['next\_ret'\]qdl\_ma\_gp = QlibDataLoader(config={'feature':(close\_ma, ma\_names), 'label': (ret, ret\_name)}) 

qdl\_ma\_gp.load(instruments=market, start\_time='20210101', end\_time='20210110')

2）Data Handler

通过Data Loader加载特征后，模型训练前需要对特征数据进行一些预处理，比如缺失值、标准化等处理。这是Data Handler主要任务。我们先看一个案例：

from qlib.data.dataset.handler import DataHandlerLP

from qlib.data.dataset.processor import CSZScoreNorm, DropnaProcessor

qdl = QlibDataLoader(config=(\['$close/Ref($close, 1)-1'\],\['Return'\]))df = qdl.load(instruments='sh000300', start\_time='20210101', end\_time='20210430') 

\# 是否有空值

df.isna().sum()

\# 原始数据分布

df.xs('2021-01-05').hist()

\# 实例化DataHandlerdh = DataHandlerLP(instruments='sh000300', start\_time='20210101', end\_time='20210120',

             learn\_processors=\[DropnaProcessor(), CSZScoreNorm()\],

             data\_loader=qdl)

df\_hdl = dh.fetch(data\_key=DataHandlerLP.DK\_L) # 获取处理后的数据，处理过程为先去空值，再截面标准化。

\# 查看是否还存在空值

df\_hdl.isna().sum()

\# CSZScoreNorm截面标准化处理后的数据分布

df\_hdl.xs('2021-01-05').hist()

从以上的例子可以看出，实例化Data Handler需要以下几个参数：

> 基本信息，如instruments，start\_time，end\_time

> infer\_processors，数据处理器，列表格式。由Dataloader加载的数据会依次经过该列表中的processor进行处理。（后面会详细介绍）

> data\_loader，数据加载器实例。

Data Handler实例化之后，通过fetch方法获取处理后的数据，这里的参数DataHandlerLP.DK\_L会在Learn Processor VS Infer Processor详细介绍。

3）Dataset

Dataset主要是为模型训练注入数据，其中主要的参数有：

-   handler：实例化的Data Handler
    
-   segment：训练、验证、测试数据集的划分
    

一个完整的代码示例如下：

from qlib.data.dataset import DatasetH

\# 沪深300股票池代码，在instruments文件夹下必须有对应的文件

Data Loadermarket = 'sh000300' sh000300.txt

\# EMA($close, 10)表示计算close的10日指数加权均线

close\_ma = \['EMA($close, 10)', 'EMA($close, 30)'\] 

\# 下一日收益率, Ref($close, -1)表示下一日收盘价

ma\_names = \['EMA10', 'EMA30'\]ret = \["Ref($close, -1)/$close-1"\] 

ret\_name = \['next\_ret'\]

qdl\_ma\_gp = QlibDataLoader(config={'feature':(close\_ma, ma\_names), 'label': (ret, ret\_name)}) 

\# 实例化Data Handler

shared\_processors = \[DropnaProcessor()\]

learn\_processors = \[CSZScoreNorm()\]

infer\_processors = \[ZScoreNorm(fit\_start\_time='20190101', fit\_end\_time='20211231')\]

dh\_pr\_test = DataHandlerLP(instruments='sh000300', 

                           start\_time='20190101', 

                           end\_time='20211231',

                           process\_type=DataHandlerLP.PTYPE\_I, 

                           learn\_processors=learn\_processors,

                           shared\_processors=shared\_processors,

                           infer\_processors=infer\_processors,

                           data\_loader=qdl\_ma\_gp)

ds = DatasetH(dh\_pr\_test, segments={"train": ('20190101', '20201231'), "test": ('20210101', '20211231')})

\# 准备训练数据

ds.prepare('train')

\# 准备测试数据

ds.prepare('test')