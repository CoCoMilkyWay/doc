# ChatGPT能帮一个quant做什么？

puppy 跟puppy玩量化 2023-04-03 20:15 四川

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg5MzU2MTQ1Mw==&mid=2247484842&idx=1&sn=b6106bf6a26a8f84937c815496eb3a6c&chksm=c1ab9aaa8e00b24614a59ca66037d139f7dbce884441538e8df48a7d8d7d6e36a65605263590#rd](https://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484842&idx=1&sn=b6106bf6a26a8f84937c815496eb3a6c&chksm=c1ab9aaa8e00b24614a59ca66037d139f7dbce884441538e8df48a7d8d7d6e36a65605263590#rd)

最近对ai爱不释手，ChatGPT和Cursor帮我实现了飞速写代码，再也不用CSDN上查半天用法了，3天才能干完的事迅速缩短到了1天，今天来写写这些ai工具是怎么帮助我平时做量化的。

### 

ChatGPT在我的日常工作中扮演了编程助理和读书老师的角色，每个人都可以通过GPT变成超级学习者。

  

编程助理：

用backtesting框架写一段回测代码。

![](assets/001.jpg)

做因子回测分析时，让ChatGPT帮我画图。

![](assets/002.png)

写绘制净值曲线图的代码。

![](assets/003.png)

## 

遇到代码报错，直接问GPT报错的原因，GPT是我手把手的私人老师。

只要你的变量命名合适，他能读懂你每行代码的意图：

![](assets/004.png)

遇到读不懂的代码、找不到的报错都可以问他，每一行代码给讲的清清楚楚。我最喜欢让他举例说明一些函数的用法，这个功能完全取代了CSDN：

![](assets/005.png)

还可以问一些问题：

![](assets/006.png)

非常有道德操守，怎么哄就是死活不写过拟合策略。

经常传言有私募一周内让上交上千个因子，问问有没有快速生成因子的办法：

![](assets/007.png)

后面可以继续追问怎么用这些python库，让他举例说明。

想了解各种策略，找他写。

![](assets/008.png)

## 

读书老师：

还有一个很大的用处，就是让他带着我读各种脑壳疼的英文书，可以用“总结一下，这段讲了什么”，“其中XXX的内容不懂，请再具体讲讲”等prompts让他带你读英文书。

最近在啃Lopez的《Advances in Financial Machine Learning》，读到云里雾里的地方不懂就问,他不仅会讲解书中的知识点，还会对知识点做延伸，GPT是一位耐心博学的助教。

![](assets/009.png)

遗传规划的资料基本都是英文的，也可以让GPT带着你读gplearn。

![](assets/010.png)

读论文可以用chatPDF，帮你总结论文大意和要点，帮你从宏观大意和微观细节上读懂一篇文章，以后再也不怕读英文论文了。

![](assets/011.jpg)

找一些文章，比如让GPT给我一些medium上高频交易的文章：

![](assets/012.png)

然后打开这些链接，全是404...  

![](assets/013.jpg)  

![](assets/014.jpg)

![](assets/015.gif)

[Smart Money Indicator择时因子：跟着聪明钱走！](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484661&idx=1&sn=5663b2b74b6224157219e5b1fdc09950&chksm=c02dbbf7f75a32e1979481fb060273d5129a3743ee85dd1a042e4ef82c75ef0f1a6e145fbbcc&scene=21#wechat_redirect)  

[K线的噪音——“混叠效应”](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484710&idx=1&sn=878b0f42948ef0842e8e681909797780&chksm=c02dba24f75a3332d8635fbe9053cac3eb6fd3b0a661051147bdd78e5774541bd6789008a48c&scene=21#wechat_redirect)  

[我是怎么构建一个高频交易系统的？](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484535&idx=1&sn=792567731545d7267d3204db7bc21a36&chksm=c02dbb75f75a326393e975a2d6e619892fc85df9b9cf55e47af5c49d7a8204783429114f7814&scene=21#wechat_redirect)  

[因子挖掘中的“PJ塔克效应”](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484398&idx=1&sn=605140a12826982dbc1141b9cac15dc1&chksm=c02dbcecf75a35fa7e8aba5a98fd1bd083493ad11e889a5a5b1c962b4991bb55374580b9ad0e&scene=21#wechat_redirect)  

[漫谈期权策略和基础资产策略的结合技巧+心路历程和风控](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484360&idx=1&sn=cc19a5a348d30c45e5ce6f5ab0bd318d&chksm=c02dbccaf75a35dc3e69719118eccc22be7063e076849f454481e361721afa9894439faf79bf&scene=21#wechat_redirect)  

[更高效的因子挖掘方式——遗传规划及其实战运用](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484321&idx=1&sn=cda97bda7ef85db10bd56cd28cd4d5b0&chksm=c02dbca3f75a35b5f6163d31b7375b429641ee6c2dcc274c67a646a3a3257e05cd5d9e366465&scene=21#wechat_redirect)  

[宏观资产因子构建——技巧篇](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484112&idx=1&sn=3206bf42e512bc051ce36e1923951a3c&chksm=c02dbdd2f75a34c44a5e23bcc94a45a2d8bc20fb9780e0641121155191a578a75b4309822385&scene=21#wechat_redirect)  

[带你走一遍量化交易全过程：配对策略的python实现](http://mp.weixin.qq.com/s?__biz=Mzg5MzU2MTQ1Mw==&mid=2247484107&idx=1&sn=e172b7b888d237993bfb4fec46a37fbb&chksm=c02dbdc9f75a34dfefb73b268c274a41a1ac8f38920361507ab0d65787f3f69b2fde90eb808c&scene=21#wechat_redirect)