# 开源量化交易机器人

QuantML QuantML 2024-12-25 18:16 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488513&idx=1&sn=9aef1bb284d46745bbe79c3cfeea4f23&chksm=cf4cf444e7b8c41dc4052a84f733f4f1f0b7bbcb632b3ea963e8743329611f4180f76dcd11ad#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488513&idx=1&sn=9aef1bb284d46745bbe79c3cfeea4f23&chksm=cf4cf444e7b8c41dc4052a84f733f4f1f0b7bbcb632b3ea963e8743329611f4180f76dcd11ad#rd)

  

![](assets/001.png)

Freqtrade是一个基于Python开发的开源加密货币交易机器人，专为数字货币交易设计。它提供了一套全面的交易框架，包括策略开发、回测、优化、机器学习数据下载等功能，支持实盘交易模拟和交易平台\[1\]。Freqtrade的主要功能包括但不限于：回测、图表绘制、资金管理、风险控制、策略优化、机器学习应用、数据下载、多语言支持、TG和WebUI交互控制\[2\]\[3\]。

  

并且社区维护了一个策略库，方便用户直接开发策略：

> 策略库地址
> 
> https://github.com/freqtrade/freqtrade-strategies/

  

![](assets/002.png)

文末参考资料提供了代码下载地址以及最全面的文档介绍

## 功能特点

Freqtrade支持多种交易平台，包括Binance、Bitmart、Kraken等，通过与这些交易所的集成，实现了跨平台的兼容性\[2\]。它集成了机器学习算法，如随机森林和神经网络，用于优化交易策略，提高决策效率和准确性\[3\]。Freqtrade还提供了详细的策略开发指南，包括市场数据下载、策略开发、回测优化等步骤\[5\]。此外，Freqtrade还鼓励用户参与社区交流，共同推动技术创新和服务优化\[3\]。核心特点包括：

1.  **策略开发**：用户可以利用 Python 和 pandas 编写自定义交易策略。官方提供了示例策略作为参考，帮助用户快速上手。此外，社区维护了一个策略库，供用户学习和借鉴。
    
2.  **数据下载**：支持从各大交易所下载历史市场数据，为回测和策略优化提供必要的基础。
    
3.  **回测**：允许用户在历史数据上测试其交易策略的有效性，确保策略在实际应用前已经过充分验证。
    
4.  **优化**：通过机器学习技术，帮助用户找到策略的最佳参数设置，包括买入、卖出、止盈（ROI）、止损和跟踪止损等关键参数。
    
5.  **市场选择**：用户可以选择手动指定交易对，或使用基于交易量和价格自动生成的市场列表。同时，也支持排除特定不希望交易的市场。
    
6.  **运行模式**：
    

-   **模拟模式（Dry-Run）**：使用虚拟资金测试策略，避免真实资金的风险。
    
-   **实盘模式（Live-Trade）**：直接用真实资金进行交易。
    

8.  **Edge 模块**：通过分析不同止损参数下的历史交易预期值，帮助用户选择最佳的交易市场，并根据资本风险比例确定交易规模。
    
9.  **监控与控制**：用户可以通过 Telegram 或 Web 界面实时监控和控制机器人，查看盈亏、每日总结及当前未平仓交易结果等信息。
    
10.  **分析工具**：提供了对回测数据和交易历史进行深入分析的功能，包括自动生成图表以及将数据加载到交互式环境中进一步分析。
     

## 技术架构

Freqtrade基于Python 3.6+或更高版本构建，能够在Windows、macOS和Linux操作系统上运行。它通过sqlite实现持久化存储，并采用SQLite进行数据管理\[4\]。软件由两个主要分支组成，分别是develop和stable，分别用于新功能开发和稳定版本发布\[2\]。用户安装过程简单，推荐使用Docker等工具进行便捷安装\[6\]\[4\]。

## 使用体验

使用Freqtrade需要一定的编程和Python知识，适合具备一定技术知识的交易者。Freqtrade提供直观的命令行界面，支持通过API进行灵活扩展，适合新手和经验丰富的交易者自动化交易操作\[7\]。用户可以通过TG或Web界面进行操作，便于监控和调整策略\[3\]\[4\]。![](assets/003.png)

Freqtrade的社区活跃，用户可以加入Discord服务器交流，报告bug或提出新功能请求。同时，Freqtrade鼓励贡献者遵循特定流程，以确保代码质量和服务性能\[2\]。

Freqtrade的成功不仅得益于其强大的功能和社区支持，还因为其开源透明的开发理念，使得用户可以自由地修改和优化代码。尽管存在一定的复杂性，但Freqtrade凭借其丰富的功能和活跃的社区，为加密货币交易者提供了一个强大的自动化交易工具\[7\]\[23\]。

![](assets/004.png)

  

## 社区内容

-   \- \[**Example freqtrade strategies**\](https://github.com/freqtrade/freqtrade-strategies/)
    
-   \- \[**FrequentHippo - Grafana dashboard with dry/live runs and backtests**\](http://frequenthippo.ddns.net:3000/) (by hippocritical).
    
-   \- \[**Online pairlist generator**\](https://remotepairlist.com/) (by Blood4rc).
    
-   \- \[**Freqtrade Backtesting Project**\](https://strat.ninja/) (by Blood4rc).
    
-   \- \[**Freqtrade analysis notebook**\](https://github.com/froggleston/freqtrade\_analysis\_notebook) (by Froggleston).
    
-   \- \[**TUI for freqtrade**\](https://github.com/froggleston/freqtrade-frogtrade9000) (by Froggleston).
    
-   \- \[**Bot Academy**\](https://botacademy.ddns.net/) (by stash86) - Blog about crypto bot projects
    

## 参考资料

  

\[\[1\] aitrader考虑整合freqtrade(代码下载),2024年11月26日\](https://blog.csdn.net/weixin\_38175458/article/details/144055249)

\[\[2\] GitHub - freqtrade/freqtrade: Free, open source crypto trading bot,2017年05月17日\](https://github.com/freqtrade/freqtrade)

\[\[3\] Freqtrade：Python语言下的加密货币交易机器人解读,2024年10月08日\](https://www.xiaoyizhiqu.com/xyzq\_news/article/670495574ddd79f11a6ad5e9)

\[\[4\] freqtrade-pro,2024年06月01日\](https://pypi.org/project/freqtrade-pro/)

\[\[5\] 用Python打造加密货币算法交易机器人,2024年09月18日\](https://developer.volcengine.com/articles/7415822376757100583)

\[\[6\] Freqtrade算法交易简明教程,2024年03月06日\](http://defiplot.com/blog/freqtradejian-ming-jiao-cheng/)

\[\[7\] Freqtrade Review - The Forex Geek,2024年02月01日\](https://theforexgeek.com/freqtrade-review/)

\[\[8\] freqtrade/freqtrade: Free, open source crypto trading bot,2022年08月13日\](https://jike.in/portal.php?mod=view&aid=321219&mobile=no)

\[\[9\] Freqtrade - Crypto Trading Bot,2024年09月30日\](https://pypi.org/project/freqtrade/)

\[\[10\] Where To Start With Freqtrade,2021年04月20日\](https://brookmiles.github.io/freqtrade-stuff/2021/04/20/where-to-start-with-freqtrade/)

\[\[11\] 如何使用Freqtrade通过Python回测策略并交易加密货币,2020年01月01日\](https://saber2pr.top/zh/posts/3516500479/432783825/)

\[\[12\] 关于加密货币交易，你需要知道的一切,2024年07月03日\](http://www.finacerun.com/index.php/home/news/detail/article\_id/63235.html)

\[\[13\] Freqtrade,2021年01月01日\](https://www.freqtrade.io/en/2021.3/)

\[\[14\] Freqtrade：一个免费开源的加密货币交易机器人\](https://www.wuzao.com/document/freqtrade/?q=)

\[\[15\] 深入剖析NostalgiaForInfinity：Freqtrade加密货币交易机器人的策略精讲,2024年10月09日\](https://www.showapi.com/news/article/670611024ddd79f11a6c994d)

\[\[16\] FreqTrade—又强又简单的Python加密货币自动交易机器人,2022年02月17日\](https://pythondict.com/quant/freqtrade/)

\[\[17\] Freqtrade加密货币算法交易软件,2022年06月06日\](https://www.elecfans.com/soft/Mec/2022/202206061844817.html)

\[\[18\] freqtrade 学习笔记,2023年05月25日\](https://cloud.tencent.com/developer/article/2291287)

\[\[19\] 盘点 GitHub 2月热门加密项目，Dogecoin、Freqtrad、Ethminer位列前三,2021年03月10日\](https://chain-times.cn/news/11810)

\[\[20\] 大数据,2022年08月09日\](https://devpress.csdn.net/bigdata/62f270aa7e668234661852fd.html)

\[\[21\] GitHub - freqtrade/technical: Various indicators developed or collected for the Freqtrade,2018年06月12日\](https://github.com/freqtrade/technical)

\[\[22\] Freqtrade基础知识\](https://www.wuzao.com/document/freqtrade/bot-basics/)

\[\[23\] Freqtrade终极支持中心,2023年12月07日\](https://www.freqtradehub.com/home/resources/support/)

\[\[24\] Freqtrade 基础指南\](https://www.freqtrade.io/en/latest/bot-basics/)

\[\[25\] FreqTrade | 具有现成策略的高频加密交易机器人,2022年10月31日\](https://blog.eswlnk.com/4830.html)

\[\[26\] Freqtrade 开发包,2023年07月21日\](https://download.csdn.net/download/BillyThe/88069463)

\[\[27\] 改造freqtrade交易模块代码后的接针策略,2024年04月15日\](https://zhuanlan.zhihu.com/p/692549395)

\[\[28\] 交易对象与属性详解,2023年01月01日\](https://www.wuzao.com/document/freqtrade/trade-object/)

\[\[29\] freqtrade,2024年01月01日\](https://westack.live/tools/freqtrade)

\[\[30\] How to Make an Algo Trading Crypto Bot with Python (Part 1),2020年01月01日\](https://www.learndatasci.com/tutorials/algo-trading-crypto-bot-python-strategy-backtesting/)

  

![](assets/005.png)