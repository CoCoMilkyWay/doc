# QuantML-Qlib/Qlib 教程及常见问题

QuantML QuantML 2024-07-28 22:20 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247485579&idx=1&sn=2a1609fddd5f18ac770266da91048667&chksm=cf3ec88487ef871a7f7152dfb83887f85961d74b5617935e9bb06374502b8ac066e4942ce2e7#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485579&idx=1&sn=2a1609fddd5f18ac770266da91048667&chksm=cf3ec88487ef871a7f7152dfb83887f85961d74b5617935e9bb06374502b8ac066e4942ce2e7#rd)

Content

  

本文主要是对群友在使用QuantML-Qlib中的常见问题做一个汇总解答。首先QuantML-Qlib是基于Qlib开发的，所有Qlib的功能都能够兼容。Qlib的原始教程可以参考以下文档：

-   github：https://github.com/microsoft/qlib/tree/main
    
-   英文文档：https://qlib.readthedocs.io/en/latest/
    
-   中文文档：wuzao.com/document/qlib/index.htm
    
-   华泰qlib教程：https://mp.weixin.qq.com/s/Brcd7im4NibJOJzZfMn6tQ
    

  

**安装：**

qlib的安装有以下几种方案，除了第一种外，其他几种方案也适用于quantml-qlib

**1.直接安装**

  pip install pyqlib （注意是pyqlib, 不是qlib）

**2\. 本地安装**

git clone https://github.com/microsoft/qlib.git && cd qlib  
pip install .

**3\. 本地安装（不推荐）**

git clone https://github.com/microsoft/qlib.git && cd qlib  
python setup.py install

将2和3中的地址改为quantml-qlib的文件路径，同样的方法即可安装。安装之后，qlib相关的代码会copy到系统路径之中，在任意位置都可调用qlib。

但是由于quantml-qlib不断更新，不建议采用安装的方式使用，可以直接编译代码，然后在目录中调用相关代码比较方便，具体操作如下：

下载quantml-qlib代码之后，编译代码：

python setup.py build\_ext --inplace

  

目的是将data/\_lib中的cython代码进行编译，编译完成之后即可在quantml-qlib的目录下调用相关对象。

  

**数据：**

数据可采用外部数据或者本地数据源导入qlib两种方案

**1.外部数据：**

之前qlib提供的数据下载方案已经不可再用：

```
# get 1d datapython -m qlib.run.get_data qlib_data --target_dir ~/.qlib/qlib_data/cn_data --region cn# get 1min datapython -m qlib.run.get_data qlib_data --target_dir ~/.qlib/qlib_data/cn_data_1min --region cn --interval 1min
```

目前qlib使用的三方维护的qlib数据，数据每日更新，修改地址中的日期即可获取最新数据，有兴趣可以看一下investment\_data这个开源项目

wget https://github.com/chenditc/investment\_data/releases/download/20220720/qlib\_bin.tar.gz  
mkdir -p ~/.qlib/qlib\_data/cn\_data  
tar -zxvf qlib\_bin.tar.gz -C ~/.qlib/qlib\_data/cn\_data --strip-components=2  
rm -f qlib\_bin.tar.gz

  

**2.本地数据：**

在quantml-qlib中，提供了一系列将本地数据导入qlib的方案，包括数据库导为qlib bin格式数据以及qlib直接读取mysql/pg/mongo/clickhouse等数据库，参考以下链接：

[QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)  

[QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)  

[QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  

  

**运行：**

运行代码首先参考qlib中的教程：  

examples/workflow\_by\_code.ipynb

examples/tutorial/detailed\_workflow.ipynb

运行quantml-qlib中的模型可以使用模型目录下的run.py代码。

  

在运行模型时，经常会遇到以下报错：

![](assets/001.png)

这是由于panda版本问题导致fillna没有生效，建议安装官方推荐的版本：

numpy\>=1.23  
pandas\>=0.25.1

或者修改qlib/data/dataset/processor.py中的代码：  

![](assets/002.png)

  

**其他常见问题后续会不断补充。其他问题也欢迎去qlib项目查找或者提交相关issue。**

**如果有其他问题欢迎留言讨论。**

  

  

**加星球请扫我，某书购买加入有优惠活动：**

![](assets/003.jpg)

  

  

**入群交流请扫我：**

![](assets/004.jpg)

  

  

**点击蓝字**

![](assets/005.png)

**关注我们**

  

**关于QuantML**

我们致力于机器学习量化模型最深度研究，每天分享前沿论文，策略模型代码，alpha因子等信息。

  

  

![](assets/006.jpg)