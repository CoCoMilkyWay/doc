# 基于Akshare与Streamlit构建交易策略回测应用程序

fintechhaibin FinTechHi 2025-04-09 23:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247486158&idx=1&sn=b54c1064d0d5471911721a7ee66ca5b3&chksm=fba618906c30f00489b070ec891f3695bcb48a413952d313b7e180bda19de039f9525398efa1#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486158&idx=1&sn=b54c1064d0d5471911721a7ee66ca5b3&chksm=fba618906c30f00489b070ec891f3695bcb48a413952d313b7e180bda19de039f9525398efa1#rd)

# 最近经常被问：要不要割肉？要不要抄底？我想说：我自己还被套着呢。

# 关税到底有没有影响？到底会激发什么连锁反应？

# 回顾下我们自身这几天的心路历程：老美发布加关税的那天，我们只是观望心态，心里肯定毫无波澜，市场也基本上云淡风轻，而国外不管是媒体还是市场都对关税表现出了极度的关注，所以周一会让我们虎躯一震，开始怀疑自己：是不是被贸易战麻痹了？是不是天真的乐观了？天是不是要塌了，周二，盘面就开始告诉大家：天塌不下来了，今天，可能我们开始冲进去了......

# 就今天来看，老美扔出：104%的数字数，对我们这些普通民众来说，搞不好就成了：狼来了的故事了，至于这个数字是1000、1w，还是多少，至少从意识上可能已经没有意义了。

# 并且这次舆情层面，除了那些阴阳怪气的大V“杨修”，大家出奇的乐观，可能这也是团结的一种体现，我们的骨子内的民族情节越在困难出现的时候往往越会凝聚。至于事情会走向何方，就犹如明天的市场一样：不是低开，就是高开，谁也猜不了。

![](assets/001.png)

#   

#   

![](assets/002.png)

  

  

![](assets/003.png)

#   

* * *

# 宏观的东西太大了，格局完全不够，还是说技术吧。

# 今天写一篇纯技术文章。主要是自己想做一些简单界面，发现Streamlit挺好用。所以就结合之前文章学习的内容，开发一个可以通过用户界面，调用Backtrader完成策略回测，并展示回测结果的例子。若有需要，后台发信息：C20250409。

# 1.导入库

`import streamlit as st   import pandas as pd   import backtrader as bt   import akshare as ak   import matplotlib   # 使用不向用户显示图形的后端   matplotlib.use('Agg')   import matplotlib.pyplot as plt   `

## 2.回测功能实现

回测功能设计思路大概如下：

1.  初始化Backtrader的`Cerebro`引擎。
    
2.  设置交易手续费，这里设置为0（实际应用中可根据具体情况调整）。
    
3.  通过Akshare获取指定股票代码、起始日期和结束日期的日频数据，并将其转换为Backtrader所需的`PandasData`格式。获取到数据后，将其添加到`Cerebro`引擎中。
    
4.  添加通过界面选择的：的交易策略类，并传入相应的参数。
    
5.  添加`TimeReturn`分析器，用于计算策略在不同时间的收益率。设置初始资金为100万元（可根据需求修改）后，运行回测。
    
6.  从回测结果中提取收益率数据，转换为`DataFrame`格式并进行日期格式的处理，方便后续分析。
    
7.  最后，使用`matplotlib`绘制回测结果图表并返回。
    

`def run_backtest(strategy_class, symbol, start_date, end_date, **params):       cerebro = bt.Cerebro()       cerebro.broker.setcommission(commission=0.00)       data = bt.feeds.PandasData(dataname=ak.stock_zh_a_hist(symbol=symbol, period="daily", start_date=start_date.strftime('%Y%m%d'), end_date=end_date.strftime('%Y%m%d'))[['date', 'open', 'high', 'low', 'close', 'volume']])       cerebro.adddata(data)       cerebro.addstrategy(strategy_class, **params)       cerebro.addanalyzer(bt.analyzers.TimeReturn, _name='returns')       cerebro.broker.setcash(100.)       results = cerebro.run()       strat = results[0]       returns = strat.analyzers.returns.get_analysis()       returns_df = pd.DataFrame(list(returns.items()), columns=['日期', '收益率'])       returns_df['日期'] = pd.to_datetime(returns_df['日期'])       returns_df.set_index('日期', inplace=True)       plt.rcParams["figure.figsize"] = (10, 6)       fig = cerebro.plot()       return fig[0][0]   `

## 3.Streamlit界面设计

`在main`函数中构建Streamlit应用程序的用户界面，主要步骤如下：

1.  设置应用程序标题为“交易策略回测”。
    
2.  从自定义的`strategies`模块中获取所有以“Strategy”结尾的策略名称，这些策略名称将显示在下拉菜单中，使用时选择。
    
3.  对于用户选择的策略，获取其所有可配置参数，并通过`text_input`组件让用户输入参数值。为了确保输入值的准确性，将输入值转换为合适的数据类型（整数或浮点数）。
    
4.  输入股票代码、起始日期和结束日期，分别用于指定回测的标的资产和时间范围。
    
5.  点击“运行回测”按钮时，应用程序调用
    

`run_backtest`函数进行回测，并将回测结果以图表的形式展示出来。

`def main():       st.title('交易策略回测')       import strategies       strategy_names = [name for name in dir(strategies) if name.endswith('Strategy')]       selected_strategy = st.selectbox('选择策略', strategy_names)       selected_strategy_class = getattr(strategies, selected_strategy)          def to_number(s):           n = float(s)           return int(n) if n.is_integer() else n          strategy_params = {}       for param_name in dir(selected_strategy_class.params):           ifnot param_name.startswith("_") and param_name notin ['isdefault', 'notdefault']:               param_value = getattr(selected_strategy_class.params, param_name)               strategy_params[param_name] = st.text_input(f'{param_name}', value=param_value)       strategy_params = {param_name: to_number(strategy_params[param_name]) for param_name in strategy_params}          symbol = st.text_input('输入股票代码（例如，600519.SH, 000001.SZ, ...）:', '600519.SH')       start_date = st.date_input('选择起始日期:', pd.to_datetime('2023-01-01'))       end_date = st.date_input('选择结束日期:', pd.to_datetime('2023-12-31'))          if st.button('运行回测'):           st.write(f"正在对{symbol}从{start_date}到{end_date}使用{selected_strategy}策略进行回测")           fig = run_backtest(selected_strategy_class, symbol, start_date, end_date, **strategy_params)           st.pyplot(fig)         if __name__ == '__main__':       main()   `

## 4.运行

## 输入命令：

```
streamlit run streamlitbt.py
```

## 控制台会显示：

```
  You can now view your Streamlit app in your browser.
```

`浏览器打开：`

```
http://localhost:8501
```

## ![](assets/004.png)

## 点击运行回测后，显示了我选择的RSI策略结果

![](assets/005.png)