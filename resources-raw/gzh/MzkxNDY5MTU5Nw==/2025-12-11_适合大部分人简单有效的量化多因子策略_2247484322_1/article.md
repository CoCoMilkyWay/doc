# 适合大部分人简单有效的量化多因子策略

蝴蝶量化 随率而动的因子工厂 2025-12-11 18:08 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkxNDY5MTU5Nw==&mid=2247484322&idx=1&sn=2d3f11fe2424e8ac98365ab09c5d2b94&chksm=c0875e52076f8b4f0662f3bfa0fcbe09130afa91ee51ec7efeb851c11e54ef7a6c4cffe95a70#rd](https://mp.weixin.qq.com/s?__biz=MzkxNDY5MTU5Nw==&mid=2247484322&idx=1&sn=2d3f11fe2424e8ac98365ab09c5d2b94&chksm=c0875e52076f8b4f0662f3bfa0fcbe09130afa91ee51ec7efeb851c11e54ef7a6c4cffe95a70#rd)

## 技术背景

很多小伙伴都觉得量化是一个遥不可及的事情。但是10年的经验告诉你，有一些量化策略普通人也能掌握，比如本期介绍的一个策略，关键的逻辑也就只有三个因子，分层进行筛选。就可以轻松实现年化41.59%，201901~202512总收益达到940%的多因子策略。

![](assets/001.png)

首先，本文的意义不在于宣传这个策略有多牛，本身这是一个略带瑕疵的策略（回撤较大），但仅仅需要增加一些大盘的择时系统，就可以将整体的回撤控制在20%左右。之前的文章：择时系统在多因子策略中的应用，介绍过类似的技术。

其次，本文的主要目的在于：用一个简单的量化多因子策略，明确的告诉大家，没有量化编程基础的小伙伴也可以拥抱量化。

量化交易优势有两个：**1、大量的数据验证。2、执行。**个人认为第二个的重要性远远大于第一个。大部分小伙伴其实都倒在了执行力上。量化的自动交易天然规避了这个问题。

很多小伙伴可能会问，你怎么知道用策略中的一些因子呢？接下来就是策略分析。

## 策略、因子分析

在之前的文章中：因子选股策略的基本框架1.0，我们有所介绍。无非几个要点：**选好的、买小的、买估值低的、不买有问题的、买在低点（无人问津）的。** 具体可以参考那篇文章。

当然，我们怎么知道策略是否符合上面的条件呢？**答案就是各类因子啦。** 后期，我们会推出自己的因子库，并且会对因子进行打标签、打分，方便小伙伴们进行调用、学习。

至于因子分析，也可以看之前的文章，数据处理、因子分析、因子合成等等。

当然，**对于一般没有基础小伙伴，如果没有学习的欲望，可以不用学习这些基础的分析工具，学习结论我们直接算好给到各位。** 各位小伙伴，只需要自己组合，构造自己的策略即可。也就是点击几次鼠标的问题。

## 详细步骤

-   1、**股票初步筛选**：剔除ST股、未满一年的新股、北交所、科创板股票、过滤停牌的股票。
    
-   2、**PEG排序**：选择PEG最小的前10%的股票。
    
-   3、**EBIT排序**：选择EBIT最小的前25%的股票。
    
-   4、**流通市值排序**：去流通市值最小的前N只股票，作为调仓标的，本文中的策略为5只。
    
-   5、**每周一调仓**：每周一轮动调仓一次，等市值调仓，盘中不管。
    

## 优化与改进

-   1、增加择时控制回撤
    
-   2、个股仓位配比，不为等仓
    
-   3、盘中的卖点优化等等
    

## python代码

`def get_stock_list(context):       # 获取所有股票       initial_list = get_all_securities().index.tolist()       # 过滤掉新股（上市未满一年）       initial_list = filter_new_stock(context,initial_list)       # 过滤掉科创板股票       initial_list = filter_kcb_stock(context, initial_list)       # 过滤掉ST股票。       initial_list = filter_st_stock(initial_list)              peg_list = get_factor_filter_list(context, initial_list, 'PEG', True, 0.1)  # 所以时越小越好       ebit_list = get_factor_filter_list(context, peg_list, 'EBIT', True, 0.25)  # 同样时越小越好       test_list = get_factor_filter_list(context, ebit_list, 'turnover_volatility', True, 0.5)       q = query(valuation.code,valuation.circulating_market_cap).filter(valuation.code.in_(test_list)).order_by(valuation.circulating_market_cap.asc())       df = get_fundamentals(q)       final_list = list(df.code)       return final_list         #过滤停牌股票   def filter_paused_stock(stock_list):       current_data = get_current_data()       return [stock for stock in stock_list if not current_data[stock].paused]      #过滤ST及其他具有退市标签的股票   def filter_st_stock(stock_list):       current_data = get_current_data()       return [stock for stock in stock_list               if not current_data[stock].is_st               and 'ST' not in current_data[stock].name               and '*' not in current_data[stock].name               and '退' not in current_data[stock].name]      #过滤涨停的股票   def filter_limitup_stock(context, stock_list):       last_prices = history(1, unit='1m', field='close', security_list=stock_list)       current_data = get_current_data()       # 已存在于持仓的股票即使涨停也不过滤，避免此股票再次可买，但因被过滤而导致选择别的股票       return [stock for stock in stock_list if stock in context.portfolio.positions.keys()               or last_prices[stock][-1] < current_data[stock].high_limit]   #过滤跌停的股票   def filter_limitdown_stock(context, stock_list):       last_prices = history(1, unit='1m', field='close', security_list=stock_list)       current_data = get_current_data()       return [stock for stock in stock_list if stock in context.portfolio.positions.keys()               or last_prices[stock][-1] > current_data[stock].low_limit]      #过滤科创板   def filter_kcb_stock(context, stock_list):       return [stock for stock in stock_list  if stock[0:3] != '688']      #过滤次新股   def filter_new_stock(context,stock_list):       yesterday = context.previous_date       return [stock for stock in stock_list if not yesterday - get_security_info(stock).start_date < datetime.timedelta(days=365)]   `

## 总结

本文通过一个简单的量化多因子策略，告诉绝大部分交易者，其实量化没有那么难。普通人以后就可以通过简单的因子组合、分层筛选就能实现量化策略。

如果这过程有专业的人加以辅助，那么策略肯定更加优秀，希望每一位关注的小伙伴，都能够找到适合自己的策略。