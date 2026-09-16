# Qlib学习分析（二）：Qlib的安装和设置

FinTechHi FinTechHi 2023-07-23 21:25 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247483808&idx=1&sn=18a1487cbbbce90c159f0da8055ba64c&chksm=fb92503223485b1150c7609d4d297949123b970d9ad9dc4288a2fd57c6ce75cdf0bdc3f2eb14#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247483808&idx=1&sn=18a1487cbbbce90c159f0da8055ba64c&chksm=fb92503223485b1150c7609d4d297949123b970d9ad9dc4288a2fd57c6ce75cdf0bdc3f2eb14#rd)

本篇直接引用一些官方的说明，就不做撇脚的翻译了。

在准备Qlib环境之前，需要先确定好是操作系统版本，比如是Windows还是Linux，并确定好Python 、Conda两个基础环境对应的版本。

如果是windows电脑，必须要安装VC相关的组件和Win10sdk包，最简单粗暴的方式，直接安装Visual Studio，但动辄几个G的空间占用一般很不情愿安装这个，所以如果可能，推荐大家使用linux操作系统。

![](assets/001.png)

下面就是官方的原文。

* * *

This table demonstrates the supported Python version of Qlib:

  

install with pip

install from source

plot

Python 3.7

✔️

✔️

✔️

Python 3.8

✔️

✔️

✔️

Python 3.9

❌

✔️

❌

Note:

1.  Conda is suggested for managing your Python environment.
    
2.  Please pay attention that installing cython in Python 3.6 will raise some error when installing Qlib from source. If users use Python 3.6 on their machines, it is recommended to upgrade Python to version 3.7 or use conda's Python to install Qlib from source.
    
3.  For Python 3.9, Qlib supports running workflows such as training models, doing backtest and plot most of the related figures (those included in notebook). **However, plotting for the model performance is not supported for now and we will fix this when the dependent packages are upgraded in the future.**
    
4.  QlibRequires tables package, hdf5 in tables does not support python3.9.
    

### Install with pip

Users can easily install Qlib by pip according to the following command.

```
  pip install pyqlib
```

Note: pip will install the latest stable qlib. However, the main branch of qlib is in active development. If you want to test the latest scripts or functions in the main branch. Please install qlib with the methods below.

### Install from source

Also, users can install the latest dev version Qlib by the source code according to the following steps:

Before installing Qlib from source, users need to install some dependencies:

```
pip install numpypip install --upgrade  cython
```

Clone the repository and install Qlib as follows.

```
git clone https://github.com/microsoft/qlib.git && cd qlibpip install .
```

Note: You can install Qlib with python setup.py install as well. But it is not the recommended approach. It will skip pip and cause obscure problems. For example, only the command pip install . can overwrite the stable version installed by pip install pyqlib, while the command python setup.py install can't.

Tips: If you fail to install Qlib or run the examples in your environment, comparing your steps and the CI workflow may help you find the problem.

* * *

  

  

理想情况按照官方的命令直接run就好了，但事实上还是需要折腾几下的，不管是安装时的各项依赖问题需要逐个解决，在跑代码时依然可能需要手动安装一些依赖包。  

我先在Windows下跑了遍，后面换成了Mac上，其中Windows下遇到问题仅供参考：

![](assets/002.png)

解决办法：

> https://blog.csdn.net/m0\_56190554/article/details/129296269

遇到问题：

![](assets/003.png)

解决办法：

> conda install libpython m2w64-toolchain -c msys2