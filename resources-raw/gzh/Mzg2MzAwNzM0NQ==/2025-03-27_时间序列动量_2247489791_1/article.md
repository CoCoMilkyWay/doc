# 时间序列动量

QuantML QuantML 2025-03-27 20:56 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489791&idx=1&sn=28f2899b8e6182920505993f27caa928&chksm=cfe0e74096ab3e0781b586f1e629b2947ab55dc602d2f26a07e646f7c69926b24190ede0487b#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489791&idx=1&sn=28f2899b8e6182920505993f27caa928&chksm=cfe0e74096ab3e0781b586f1e629b2947ab55dc602d2f26a07e646f7c69926b24190ede0487b#rd)

## 引言

在量化投资策略的领域中，很少有策略能像时间序列动量（TSMOM）那样引起学术界和业界的广泛关注。与传统的横截面动量不同，后者比较不同资产之间的相对回报，TSMOM专注于每个资产回报的自身自相关性。这种微妙但深刻的变化彻底改变了我们对金融市场的理解，并催生了极为稳健的投资策略。

![时间序列动量示意图](assets/001.jpg)

时间序列动量示意图

## 理论基础

### 定义与数学公式

时间序列动量由Moskowitz、Ooi和Pedersen在2012年正式提出，其核心前提是资产过去的回报对其未来回报具有预测能力。其基本的数学公式如下：

**其中：**

-    表示资产  从时间  到  的未来回报。
    
-    表示资产  从时间  到  的过去回报。
    
-    是一个常数。
    
-    捕捉动量关系的强度。
    
-    是误差项。
    

这一公式的革命性在于，它独立地考察了每个资产的回报自相关性，与那些比较不同资产之间回报的策略形成对比。

### 经济与行为学基础

TSMOM具有坚实的经济和行为学基础：

1.  **信息逐渐扩散**：新信息逐渐被纳入价格中，在短期和中期内形成正自相关性。
    
2.  **行为偏差**：锚定效应、初始反应不足和确认偏差等现象导致趋势持续存在。
    
3.  **机构风险管理**：基金经理逐渐调整风险敞口，导致价格持续变动。
    
4.  **分批订单动态**：大型投资者分批执行订单以减少市场影响，延长趋势。
    

## TSMOM的独特特征

### 与横截面动量的区别

TSMOM在几个关键方面与横截面动量（CSMOM）根本不同：

-   TSMOM关注单个资产回报的自相关性，而CSMOM比较不同资产之间的回报。
    
-   TSMOM根据绝对回报的正/负生成信号，而CSMOM依赖于相对表现的优/劣。
    
-   TSMOM可以实施为仅多头、仅空头或长短仓，而CSMOM本质上是长短仓。
    
-   在危机期间，TSMOM可以表现出逆周期性，而CSMOM容易出现动量崩溃。
    
-   重要的是，TSMOM即使在单个资产上也能发挥作用，而CSMOM需要一个广泛的资产池。
    

### 关键统计特性

TSMOM表现出显著的统计特性：

1.  **跨资产类别的稳定性**：它在股票、债券、货币、大宗商品和衍生品中都有效。
    
2.  **最佳时间范围**：信号在3到12个月的时间范围内显示出更强的预测能力。
    
3.  **回报分布的不对称性**：它倾向于产生正偏回报，在市场压力时期有获得收益的潜力。
    
4.  **与传统策略的低相关性**：与标准的60/40（股票/债券）投资组合相比，它提供了巨大的多样化优势。
    

## 策略实施

### 信号构建

有效实施TSMOM需要对构建信号进行仔细考虑。核心要素包括定义适当的动量计算回溯期，估算相关时间范围内的波动性，并根据波动性反向调整头寸以保持一致的风险敞口。这些构建方法确保TSMOM策略能够捕捉趋势持续性，同时在不断变化的市场环境中管理风险。

### 波动性调整

TSMOM的一个关键组成部分是波动性调整。这种技术根据每个资产的估计波动性反向调整头寸：

**其中：**

-    是基于过去回报的方向信号 ( 或 )。
    
-    是资产  的估计波动性。
    
-    是一个常数，用于实现目标波动性。
    

这种方法在时间上保持恒定的稳定风险状况，在波动性较大的时期显著减少回撤。

### 跨资产类别的多样化

典型的TSMOM投资组合跨越多个资产类别：

1.  **股票市场**：全球指数和行业期货。
    
2.  **固定收益**：不同期限的政府债券期货。
    
3.  **大宗商品**：能源、金属、农业。
    
4.  **货币**：G10货币对和新兴市场。
    

这种多样化充分利用了TSMOM回报在不同资产类别之间的低相关性。

## 实证表现与风险特征

### 主要实证发现

对TSMOM的实证研究揭示：

1.  **卓越的风险调整回报**：夏普比率在很长一段时间内持续高于1.0。
    
2.  **在下跌时期的行为**：在最大的股市下跌期间倾向于产生正回报。
    
3.  **持续性**：该策略在超过100年的市场数据中显示出有效性。
    
4.  **对交易成本的稳健性**：即使在考虑现实交易成本后，收益仍然持续。
    

### 独特的风险状况

TSMOM表现出特定的风险回报状况：

**月度回报分布（1985-2020）：**

-   平均回报：1.2%
    
-   波动性：5.8%
    
-   夏普比率：0.92
    
-   索提诺比率：1.45
    
-   最大回撤：23.6%
    
-   正月份百分比：62.3%
    
-   偏度：0.41
    
-   峰度：3.27
    

值得注意的是，这一分布显示出正不对称性（偏度 > 0），表明极端正回报的频率高于负回报，与大多数传统投资策略不同。

## 变体与演变

### 与基本面信号的结合

一个自然的扩展是将TSMOM与基本面因素结合起来：

其中  决定了每个组成部分的相对权重。基本面信号可能包括价值、套利、季节性和宏观经济因素。

### 自适应TSMOM

自适应TSMOM根据市场条件调整回溯期：

其中市场状况可以通过波动性、流动性或宏观经济指标来确定。这种变体显示出对标准TSMOM的重大改进。

### 趋势过滤方法

现代趋势过滤技术减少了TSMOM信号中的噪声：

1.  **小波和频谱分析**：分离高频和低频成分。
    
2.  **卡尔曼滤波器**：估计趋势的潜在状态。
    
3.  **机器学习**：使用学习算法识别复杂的趋势模式。
    

### 高级实施方法

实施TSMOM的更复杂的方法使用高级估计技术。这些方法通常结合多个回溯期，而不是依赖于单一的时间范围，每个回溯期都对最终信号有所贡献。高级实施还使用指数加权移动平均（EWMA）来改进波动性估计，给予近期观察更多权重，使模型对不断变化的市场条件更具适应性。

最复杂的实施可能包括基于检测到的市场状态调整参数的制度转换模型，或使用交叉验证或其他机器学习技术确定的最优加权方案的集成方法。

这种实施结合了多个回溯范围和指数波动性估计，以提高稳健性。

## 实际应用与投资组合管理

### 参数优化

关键参数包括：

1.  **回溯范围**：通常在3-12个月之间，但可能因资产类别而异。
    
2.  **目标波动性**：通常在年化10-20%之间，具体取决于风险状况。
    
3.  **资产之间的权重**：从等权重到更复杂的方法，如风险平价。
    

### 特定风险管理

TSMOM的风险管理技术包括：

1.  **动态止损**：基于实现的波动性。
    
2.  **流动性过滤器**：根据流动性状况调整头寸规模。
    
3.  **相关性控制**：限制对高度相关资产的敞口。
    
4.  **制度监控**：根据制度变化指标调整策略。
    

### 在更广泛的投资组合中的整合

TSMOM可以在多元化投资组合中扮演不同的角色：

1.  **核心组成部分**：将20-40%的资本配置为主要策略。
    
2.  **叠加层**：应用于贝塔投资组合以提高风险调整回报。
    
3.  **动态对冲**：利用其在熊市中表现良好的趋势作为保护。
    

## 挑战与注意事项

### 批评与局限性

TSMOM面临几项批评：

1.  **市场适应**：广泛的知识可能降低其有效性。
    
2.  **无效时期**：在缺乏明确趋势的市场中可能经历糟糕的回报。
    
3.  **运营要求**：需要在多个全球市场运营的能力。
    
4.  **成本敏感性**：高度依赖于执行效率和交易成本。
    

### 实施注意事项

投资者应考虑：

1.  **市场准入**：需要在全球期货和远期市场进行交易。
    
2.  **交易基础设施**：需要强大的系统来跟踪和执行。
    
3.  **容量**：该策略在流动性较低的市场中有容量限制。
    
4.  **监管框架**：关于头寸限制和报告要求的考虑。
    

## 时间序列动量的未来

### 方法创新

当前的研究正在从几个方向扩展TSMOM：

1.  **机器学习**：使用神经网络捕捉动量信号中的非线性模式。
    
2.  **替代数据**：整合来自文本、卫星和交易数据中提取的信号。
    
3.  **制度适应**：系统根据识别的市场条件动态修改策略。
    

### 长期视角

推动TSMOM的行为和结构基础可能会持续存在：

1.  **心理偏差**：即使在更大的算法参与下，人类的认知偏差继续影响市场。
    
2.  **机构限制**：指令、限制和机构资金流动将继续创造可利用的趋势。
    
3.  **流动性动态**：市场结构继续倾向于对新信息进行逐步价格调整。
    

## 安装与代码示例

首先，确保安装了必要的Python库：

`pip install pandas numpy yfinance matplotlib seaborn finvizfinance   `

以下是一个使用TSMOM策略筛选纳斯达克大型股并生成交易信号的示例代码：

`import yfinance as yf   import pandas as pd   import numpy as np   import matplotlib.pyplot as plt   from datetime import datetime, timedelta   import seaborn as sns   from finvizfinance.screener.overview import Overview   import time      def get_nasdaq_large_caps():       """获取所有市值超过100亿美元的所有纳斯达克股票"""       print("从Finviz获取市值超过100亿美元的纳斯达克股票...")       overview = Overview()       filters_dict = {           'Exchange': 'NASDAQ',           'Market Cap.': 'Large (over $10bln)'       }       overview.set_filter(filters_dict=filters_dict)       try:           df = overview.screener_view()           tickers = df['Ticker'].tolist()           print(f"找到 {len(tickers)} 个市值超过100亿美元的纳斯达克股票")           return tickers       except Exception as e:           print(f"从Finviz获取数据时出错: {e}")           default_tickers = ['AAPL', 'MSFT', 'AMZN', 'GOOGL', 'META', 'TSLA', 'NVDA']           print(f"使用默认股票: {default_tickers}")           return default_tickers      def run_robust_tsmom_screener(tickers=None, lookback_months=[1, 3, 6], history_years=1):       """在给定的股票或纳斯达克大型股上运行稳健的TSMOM筛选器，并提供改进的错误处理和调试信息。"""       # 获取股票代码（如果未提供）       if tickers isNone:           tickers = get_nasdaq_large_caps()           tickers.extend(['QQQ', 'SPY'])  # 添加主要指数进行比较           print(f"在 {len(tickers)} 个股票上运行TSMOM筛选器...")          # 下载历史数据       end_date = datetime.now()       start_date = end_date - timedelta(days=365 * history_years)          print(f"从 {start_date.strftime('%Y-%m-%d')} 到 {end_date.strftime('%Y-%m-%d')} 下载数据...")          # 分批下载以避免大列表出错       batch_size = 50       all_data = {}       for i in range(0, len(tickers), batch_size):           batch_tickers = tickers[i:i+batch_size]           print(f"下载批次 {i//batch_size + 1}/{int(np.ceil(len(tickers)/batch_size))}...")           try:               batch_data = yf.download(batch_tickers, start=start_date, end=end_date)               # 处理数据格式基于股票数量               if len(batch_tickers) == 1:                   batch_df = pd.DataFrame(batch_data['Close'])                   batch_df.columns = batch_tickers                   for ticker in batch_tickers:                       all_data[ticker] = batch_df[ticker]               else:                   for ticker in batch_tickers:                       if ticker in batch_data['Close'].columns:                           all_data[ticker] = batch_data['Close'][ticker]               time.sleep(1)  # 避免速率限制           except Exception as e:               print(f"下载批次时出错: {e}")          # 创建价格数据框并计算回报       print("创建价格数据框并计算回报...")       price_data = pd.DataFrame(all_data)          # 过滤掉有太多NaN值的列       valid_cols = price_data.columns[price_data.isnull().mean() < 0.2]       price_data = price_data[valid_cols]       # 检查是否还有数据       if price_data.empty:           print("清理后没有有效的价格数据!")           returnNone          # 计算回报       returns = price_data.pct_change().dropna()          print("计算TSMOM信号...")       signals_dict = {}          # 基本版本 - 使用简单动量而不进行波动性调整       for months in lookback_months:           days = int(months * 21)  # 一个月大约21个交易日           # 确保我们有足够的数据           if days >= len(price_data):               print(f"警告: 没有足够的数据用于 {months} 个月的回溯期。跳过...")               continue           # 计算动量作为百分比变化           try:               # 检查日期是否存在以避免IndexError               end_idx = price_data.index[-1]               start_idx = price_data.index[-days-1]               momentum = price_data.shift(1).pct_change(periods=days)               signals_dict[months] = momentum.apply(lambda x: 1if x > 0else-1)           except Exception as e:               print(f"计算 {months} 个月的动量时出错: {e}")               continue          # 组合信号       ifnot signals_dict:           print("无法生成有效的信号!")           returnNone          # 从信号创建数据框       signals_df = pd.DataFrame(signals_dict)          # 对各时期求和以获得最终信号       final_signal = signals_df.sum(axis=1)          # 输出一些信号统计信息       print(f"\n最终信号统计信息:")       print(f"均值: {final_signal.mean():.4f}")       print(f"标准差: {final_signal.std():.4f}")       print(f"最小值: {final_signal.min():.4f}")       print(f"最大值: {final_signal.max():.4f}")       print(f"正信号数量: {(final_signal > 0).sum()}")       print(f"负信号数量: {(final_signal < 0).sum()}")          # 按信号强度从最正面到最负面排序       sorted_signals = final_signal.sort_values(ascending=False)          # 输出结果 - 无阈值过滤，仅显示顶部/底部股票       print("\n=== TSMOM筛选结果 ===\n")          print("\n前10个多头机会:")       for i, (ticker, signal) in enumerate(sorted_signals.head(10).items(), 1):           print(f"{i}. {ticker}: {signal:.4f}")          print("\n前10个空头机会:")       for i, (ticker, signal) in enumerate(sorted_signals.tail(10).iloc[::-1].items(), 1):           print(f"{i}. {ticker}: {signal:.4f}")          # 可视化信号       plt.figure(figsize=(14, 10))          # 按绝对值获取顶部信号       top_by_abs = sorted_signals.abs().nlargest(30)       selected = sorted_signals[top_by_abs.index]          # 创建水平条形图       bars = plt.barh(y=selected.index, width=selected.values, color=['green'if x > 0else'red'for x in selected.values])          plt.title('TSMOM信号（前30名按强度）')       plt.xlabel('信号强度')       plt.axvline(x=0, color='black', linestyle='-', alpha=0.3)       plt.grid(axis='x', alpha=0.3)       plt.tight_layout()       plt.show()          return sorted_signals      # 运行稳健的筛选器   if __name__ == "__main__":       signals = run_robust_tsmom_screener()   `

## 结论

时间序列动量代表了量化投资的重大创新，为如何利用市场无效提供了不同的视角。其坚实的理论基础、强大的实证证据和多样化特性使其成为精明的投资者工具箱中的宝贵工具。

随着市场的演变，我们对TSMOM的理解也在不断深化。持续的方法创新有望进一步改进这一策略，可能使其在不断变化的金融环境中保持相关性。

对于研究人员和投资者来说，TSMOM仍然是一个引人入胜的研究领域，它连接了金融理论、行为心理学和投资管理的实际应用。

  

  

  

  

  

  

更多代码见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/002.jpg)

  

往期回顾

       QuantML-Qlib开发版：

  

-   [QuantML-Qlib重磅更新：DeepSeek核心模型结构用于选股](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489025&idx=1&sn=35941156783794d719e6ff891ce720c3&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Factor | 融合TA-Lib100+技术指标，自定义构建AlphaZoo](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488425&idx=1&sn=a071798fdcc183b3d630e8bc0d637adf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 还在使用MSE？试试这些更加适合金融预测的损失函数](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487997&idx=1&sn=e05e8e0dafa605615d425ff1f0702c4b&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 如何运行日内中高频模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487722&idx=1&sn=4597316f8066c31d4bbf34226d888ef4&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 超越GRU，液态神经网络LNN用于股票预测](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487291&idx=1&sn=ba0c7cb11cbe247900fa326a50dd5dd9&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰SAM：提升AI量化模型的泛化性能 研报复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487238&idx=1&sn=41cbb5b3bb3e5a277c9175ba64642259&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 华泰AlphaNet模型复现](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485666&idx=1&sn=d9a7ec92f3f93d44d4620bb56ab0d620&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Model | 清华大学&华泰证券 在高胜率时交易](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485500&idx=1&sn=b29e1d2efe2482165245ab6add4af051&scene=21#wechat_redirect)
    
-   [QuantML-Qlib Factor | 高效优雅的因子构建方法：以开源金工切割动量因子为例](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485016&idx=1&sn=17598e7dbdfcb7e908b2a393c5dd28ad&chksm=ce7e6146f909e85067dd7de6ca5f02c12afb9f195f92871c87b0daed0153b1ea04f3057d9683&scene=21#wechat_redirect)
    
-   [](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)[QuantML-Qlib Model | 滚动模型训练](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485371&idx=1&sn=37b9d5c40f9b08244fd68ee73991218f&chksm=ce7e60a5f909e9b373b4b850300768fd2dbe0250e1237e11132f3af9d54f9bde97ba84c47766&scene=21#wechat_redirect)  
    
-   [QuantML-QlibModel | KAN + GRU 时序模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484511&idx=1&sn=bb9168cb75b1b31fea0b8a5c3ce61d84&chksm=ce7e6341f909ea5755b03dec3d0407d15ac38b60a573cd5517a8a51ba047b1d630c7a15972cb&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 蚂蚁&清华 TimeMixer：可分解多尺度融合的时间序列模型用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484961&idx=1&sn=c5acb48d3c063c0a69d6566817875aee&chksm=ce7e613ff909e8290602d7d0c32fd7d764fb25660956fbfc3238a7df3d41d5f7e0ffaa2cb6a8&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib Model | Kansformer：KAN+Transformer时序模型用于股票收益率预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484779&idx=1&sn=f417e4ef37562e22fa592ca280fe5a43&chksm=ce7e6275f909eb63cf3410377b0c40a033fb2788b342665c3b266ecbfb426465dcf241bb847d&scene=21#wechat_redirect)
    
-   [QuantML-QlibModel | 使用OPTUNA优化模型超参](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484466&idx=1&sn=8c6a69a98e64eeba373b1042d276fb81&chksm=ce7e632cf909ea3ae70af5b1acee4163c7b85cb8170a0ef6a999130d05bdb5a54b89a895a0d8&scene=21#wechat_redirect)
    
-   [QuantML-QlibDB | Clickhouse 行情存储与读取方案](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484391&idx=1&sn=b56d54740da5d77bef608d787033e321&chksm=ce7e64f9f909edef46da039efbeaf07b636ef08477a3f4ba2b49dea329d2c29b71635a809aca&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib LLM | GPT-4o复现因子计算代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484355&idx=1&sn=0e2e068277314d93d0373ad5e1b0da82&chksm=ce7e64ddf909edcb0f2894f353b26825800a7862dfb6a53b692b212ae5e93e43c0d7b1ee71cf&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 最新xLSTM用于股票市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484305&idx=1&sn=deac6944b376b2e7d7cdb552b2bcc0b4&chksm=ce7e648ff909ed99d80c0a73506003b9afbb1e414e748bb91e5b36e7ecb737ded8745d183518&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 强化学习因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484272&idx=1&sn=0b9b53150500d4c77f6afc3267b1313f&chksm=ce7e646ef909ed78bb3216dd647872ffc47fafc116021b34caef842d6b78c1cbf98c343e3fd2&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 清华大学时序SOTA模型iTransformer用于股票市场预测QuantML-Qlib开发版 | 最新神经网络结构KAN用于因子挖掘](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484235&idx=1&sn=5f8f21ad605eee4a9152954164b9b441&chksm=ce7e6455f909ed43d8e4c8d964b5d2d02ed448e8530f6bed0bce00fc8c5d823a82184af1e5c7&scene=21#wechat_redirect)  
    
-   [QuantML-Qlib开发版 | 直接读取pg/mysql/mongodb数据库](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=2&sn=69ca761ab7d152740a3058b86ed02e6c&chksm=ce7e640af909ed1cc246be0a4e683a9b45e8bf256cc034cba0a6d316f6e62f9858d4e75e4efb&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | MoE混合专家系统用于提升Transformer表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484124&idx=1&sn=735f6f9488e202679ad96b3d19329673&chksm=ce7e65c2f909ecd438e908babf20726acc73162f9a5198c445f5bf3b1bc8ed6ed16474cbecfd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一键数据更新](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=2&sn=b2ad5cf74fcc452e49f7e4c4ec07439b&chksm=ce7e65bff909eca9c28072649b39e7ad08b9db4a71e5d5d492bfca04ac6b720ca368a665257a&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | AAAI最佳论文Informer用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484065&idx=1&sn=d666c3cd759ceffbdb304c1097a4ebb8&chksm=ce7e65bff909eca9a4fedaef3b9edabf3d4d65c11f38d6edc80e973a9cc6d4c9944944666071&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 取代Transformer的下一代神经网络结构Mamba用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483988&idx=1&sn=214bf5cd0739cb26c4af3a56252a99eb&chksm=ce7e654af909ec5cba364d5fea1cb170d9a5a7181b5ed063b97e2dbdff3a7a1fdfd587aafffd&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 时序SOTA模型PatchTST用于金融市场预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483873&idx=1&sn=c2376b203dc69fc2b8df1db00c5246a0&chksm=ce7e66fff909efe99c0f61c17f6226e7e310c8c0fbe900bb7bdad4aafece8aa85e98348297f7&scene=21#wechat_redirect)
    
-   [QuantML-Qlib开发版 | 一行代码运行DLinear模型用于股票预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483796&idx=1&sn=c10f4d766eb52e8dee53ffb954beeafc&chksm=ce7e668af909ef9c5a1a8c6ebc29566475af184ffdf503a0fda308f896eaf42272c6dd591fd2&scene=21#wechat_redirect)
    
      
    研报复现：
    
      
    
-   [重磅更新！80+量化策略复现（持续更新中）](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488528&idx=1&sn=f9c98f60baca2b690956ff6b56a2553f&scene=21#wechat_redirect)
    
-   [BARRA CNE6模型复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484419&idx=1&sn=ec71d0938e90e65145742754ddc4e6d9&chksm=ce7e631df909ea0b60b8a41c67f03e193aff17c556ef30f83528d354e3256402a12205f40b91&scene=21#wechat_redirect)
    
-   [研报复现 | QRS择时信号及改进](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487334&idx=1&sn=110ef4c3ae5dce77260eab213d6163ac&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-下](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486787&idx=1&sn=bfe98c0b8d331027191761df3b85ea8c&scene=21#wechat_redirect)
    
-   [研报复现 | 跳跃因子系列-上](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486761&idx=1&sn=84a2de96dd3bc7a7fb38386684b3eec4&scene=21#wechat_redirect)
    
-   [研报复现 | 锚定反转因子](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247486379&idx=1&sn=d6763bb198d0706c101f2544aa752b4f&scene=21#wechat_redirect)
    
-   [研报复现 | 另类ETF交易策略：日内动量](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485900&idx=1&sn=c7facdbd47ebc0161839fbea1def4ecc&scene=21#wechat_redirect)
    
-   [研报复现 | 国盛金工：如何将隔夜涨跌变为有效的选股因子？——基于对知情交易者信息优势的刻画](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485766&idx=1&sn=89d4060fb135105b969c0ef2f145a7e0&scene=21#wechat_redirect)
    
-   [研报复现 | 招商证券：基于鳄鱼线的指数择时及轮动策略](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485702&idx=1&sn=2b0ed284177a66ee9d0e8623cd9cb1b4&scene=21#wechat_redirect)
    
-   [研报复现 | 华西金工-股票网络与网络中心度因子研究](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484829&idx=1&sn=3da8197374301bab9610f7ed5d4b715b&chksm=ce7e6283f909eb9509b3ebc9989fe9d140d5ee663ac8749aeb608833ff37544421d0dcd0fa9c&scene=21#wechat_redirect)  
    
-   [研报复现 | 基于筹码分布的选股策略](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485327&idx=1&sn=260ff24d4fde6fa394f989b23488780f&chksm=ce7e6091f909e987086ba01ad8df6f3dd8ef0fa63fe41930e784f2648066e44bad6c24b02a91&scene=21#wechat_redirect)
    
-   [研报复现 | 开源金工-高频追涨杀跌因子复现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484915&idx=1&sn=a7279f3516c0998cd6c3e6fddec017a9&chksm=ce7e62edf909ebfb211722e6bb19b4a43243c4751dd6e4143249b04afe3bed980ffb0ce68ff3&scene=21#wechat_redirect)  
    
-   [研报复现 | 开源证券 ：形态识别，均线的](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484616&idx=1&sn=cbf8bf6df9906603258516c808e45b94&chksm=ce7e63d6f909eac044db7ca34624d21c241c485bce4450e1ea23ccf4463414638c52cae5cbea&scene=21#wechat_redirect)
    
-   [券商研报因子复现及表现研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484329&idx=1&sn=24f18ad20fc0a44ba09a19d43becf651&scene=21#wechat_redirect)
    
      
      
    前沿论文代码：
    
      
    
-   [DeepSeek-TS+: MLA-Mamba及GRPO用于多序列预测统一框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489198&idx=1&sn=4ea3856dcf099493c2ba6db7cf0e23a2&scene=21#wechat_redirect)  
    
-   [Hummingbot：开源加密货币做市机器人框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489153&idx=1&sn=98198f6cca4aa5bc5646e926c358f01d&scene=21#wechat_redirect)  
    
-   [FinRLlama：基于强化学习和市场反馈的金融情感分析LLM优化方案](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489127&idx=1&sn=faad16c8ac3ca02dcb982837d03b21ab&scene=21#wechat_redirect)  
    
-   [端到端基于LLM的增强型交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489113&idx=1&sn=b145d87e23cfa5c9e780099fc7c1136c&scene=21#wechat_redirect)
    
-   [基于分层强化学习的日内风险因子挖掘](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489104&idx=1&sn=c0b6938ebcf0cbd8244f87abe609798e&scene=21#wechat_redirect)
    
-   [DeepScalper：深度强化学习捕捉日内交易的短暂机会](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489018&idx=1&sn=1ea12b6de5e28e2700b4947081a32b7b&scene=21#wechat_redirect)
    
-   [TradingAgents：基于多智能体LLM的金融交易框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488712&idx=1&sn=daa7fb4a9d49a621f9f54579dda4a184&scene=21#wechat_redirect)  
    
-   [Kaggle - Optiver trading at the close第一名解决方案及部分代码](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484474&idx=1&sn=d7cb587cd3604299930006e2f0dd54cf&chksm=ce7e6324f909ea320e815af314efc2f2eb4dd944ca56e0fccaf0990e099b001610461a1e798d&scene=21#wechat_redirect)
    
-   [量化交易全攻略：从入门到精通的终极指南](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247485434&idx=1&sn=9ea5dd98ac51fa0eb0381d97fa2d2b78&scene=21#wechat_redirect)
    
-   [普林斯顿&牛津大学 | 大模型在金融领域的应用、前景和挑战](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484935&idx=1&sn=c04614316ebaaf46fe0ef35b88aba330&chksm=ce7e6119f909e80fcc08f835d91cdddeb1e3dacf3bd924fcd5958381f13eaace114139af909b&scene=21#wechat_redirect)
    
-   [Style Miner：基于强化学习算法的风格因子构造](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488487&idx=1&sn=82c708030492662f4bd958c09cd6ad35&scene=21#wechat_redirect)
    
-   [AQR创始人Cliff Asness：市场效率下降假说](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488456&idx=1&sn=7014a441007cd69045f69cfada3f64fd&scene=21#wechat_redirect)
    
-   [增强动量策略：动量Transformer模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488434&idx=1&sn=e8431bb689e27562a620cdb6cf3c6d31&scene=21#wechat_redirect)
    
-   [XGBoost 2.0 ：提升时间序列预测能力](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488387&idx=1&sn=d123dcfc4c74e13b7bfd10a707eab81f&scene=21#wechat_redirect)
    
-   [NIPS 24 | FinCon: 基于LLM的多智能体交易及组合管理框架](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488353&idx=1&sn=f6684d1c9788e0f9dcd09b781cbd619a&scene=21#wechat_redirect)
    
-   [NIPS 24 | CausalStock : 基于端到端因果发现的新闻驱动股价预测模型](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488342&idx=1&sn=4793d31201295e14a5978556f449adca&scene=21#wechat_redirect)
    
-   [JFE | 高效估计买卖价差的模型、实证与应用](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488303&idx=1&sn=60ab39ed1be0a71185396aadfa33aeee&scene=21#wechat_redirect)
    
-   [超越传统网格交易：新型网格交易系统](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488269&idx=1&sn=7b9a60116d5c65278e6894ded1ce79aa&scene=21#wechat_redirect)
    
-   [JFE | ETF日内套利研究](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488257&idx=1&sn=9eb00eade68c4f6816916330b859adb0&scene=21#wechat_redirect)
    
-   [NIPS 24 | 超越CVXPY,新型端到端优化器](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488193&idx=1&sn=a91d10d06dca7a988dda550ccaaa9941&scene=21#wechat_redirect)
    
-   [揭秘Jane Street低延迟系统的优化技巧——减少系统抖动](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487942&idx=1&sn=834867f33667a640961b34756c730ca9&scene=21#wechat_redirect)
    
-   [南京大学LAMDA-强化学习DRL挖掘逻辑公式型Alpha因子](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484882&idx=1&sn=e4fee58dd1ca85b6469e3803be5e97a5&chksm=ce7e62ccf909ebdaa93ae29cef9c59c7f889d784b1c774014b339dc55a375d03443d61b48037&scene=21#wechat_redirect)
    
-   [3万个因子，数据挖掘能超越同行审议的因子吗？](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484872&idx=1&sn=2f420bd9522473ad83dc6f825c421e5c&chksm=ce7e62d6f909ebc05b45a79d8d6e96cac7910b7509ef168a2a7349f29a4c63dbbf7bb9b3ba11&scene=21#wechat_redirect)
    
-   [KDD 24 | 基于增强记忆的上下文感知强化学习的高频交易框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484852&idx=1&sn=612490637ac96cfa86d829e9ed665c2b&chksm=ce7e62aaf909ebbc864a29a4af3cc6db60eb2930f7dade6882515a61d46222e8877e8018fd07&scene=21#wechat_redirect)
    
-   [FinRobot：用于金融领域的大模型AI平台](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484560&idx=1&sn=689e9b1ec3bf370e7332b538f3060ca1&chksm=ce7e638ef909ea989847e2b1501d17f9524808ad0544ccceaba918b8fda7c13556522b740647&scene=21#wechat_redirect)
    
-   [KDD 23 | DoubleAdapt: 显著提升各类模型表现的元学习模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484726&idx=1&sn=68a12011fce4197b96d2f67b92f7b5c2&chksm=ce7e6228f909eb3e3ca1504f4b29adc1986cdb1bd451f73049077b864be1999d3b3fdcb860ad&scene=21#wechat_redirect)
    
-   [市场微观结构教程：深度订单簿预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484660&idx=1&sn=fc191107da65068ab9a5cd01135a5f1d&chksm=ce7e63eaf909eafcc529fa1a5b07985b5b1e3a548c363134f0cc0ee57a5463ceaf91a2946af0&scene=21#wechat_redirect)
    
-   [基于高频和日频因子的端到端直接排序组合构建模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484549&idx=1&sn=347c69bb297aef162bb364a1e68e9e72&chksm=ce7e639bf909ea8d632046f8f9acac70209067aa1f4c142f3a26733262d298b097041744f92d&scene=21#wechat_redirect)
    
-   [BOA 312页报告：Everything you wanted to know about quant](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484528&idx=1&sn=01c2c5c1be9c62ee11936badd36aca81&chksm=ce7e636ef909ea7896cac5c96c66a9ec1c2626d68e67fcd52632aea20683643d2191d043f0a8&scene=21#wechat_redirect)
    
-   [深度学习模型DeepLOB用于订单簿价格预测](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484318&idx=1&sn=ce53c0720707138434d539bf1fd265cc&chksm=ce7e6480f909ed96c06a8a6caae8a38d312b9539364cca2570524f184f68d54783cf35a18b37&scene=21#wechat_redirect)
    
-   [What KAN I say？KAN代码全解析](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484285&idx=1&sn=14a024ba53e87188e7f4eb5a6658744c&chksm=ce7e6463f909ed75d6c00d19f0e5468b58fa19c8ac5e067bbd84111d4df8213a01b8d2cde5b0&scene=21#wechat_redirect)
    
-   [取代MLP？MIT全新神经网络结构KAN,3天1.4k star](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484180&idx=1&sn=97c579083e1c9fa93e5c6b0310ddc306&chksm=ce7e640af909ed1cf2718c8db750f10afbca50ab7d93cd4537547d8958db0c305b255a1f7e6d&scene=21#wechat_redirect)
    
-   [WWW'24 | FinReport: 结合新闻语义信息的多因子模型显著提升预测准确性](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484046&idx=1&sn=bcb0fff3bdf5f7b44f11200a6618ac01&chksm=ce7e6590f909ec86a6c81cde08dd6cc7f45f40bda780014f9e19fa498b7b1e5f7111c2b28e0b&scene=21#wechat_redirect)
    
-   [WWW'24 | UniTime: 融合文本信息的时间序列预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484032&idx=1&sn=604d6ba7bcd2fa070bc73909484b621d&chksm=ce7e659ef909ec880ec0c0c1c9fb685b992e1ac84367e89d736578c665022d0bcf7bc14c7cd8&scene=21#wechat_redirect)
    
-   [WWW'24 | EarnMore: 如何利用强化学习来处理可定制股票池中的投资组合管理问题](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483897&idx=1&sn=00d406b6b8475c6e453e8cef837a5733&chksm=ce7e66e7f909eff1a4b6347d4e21f8263962ec99207a3514f5f76f3747a533a2360b4fb7aa0d&scene=21#wechat_redirect)
    
-   [KDD'23 | AlphaMix: 高效专家混合框架（MoE）显著提高上证50选股表现](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483915&idx=1&sn=2dc8f2ceffdd225bd3b8ed70385a4a3a&chksm=ce7e6515f909ec03ecdbf9258f1e73972e98229da395c79c7dd533d56455612ab248fc879ff6&scene=21#wechat_redirect)
    
-   [IJCAI'23 | StockFormer: RL+Self-Attention优化摆动交易提高股票预测精度](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484098&idx=1&sn=40d40326f9a703296115e9720d776f48&chksm=ce7e65dcf909ecca166614ff70d12bdcfb0265b99e8dddfeec75e579a1d3c6e62e5ae9446924&scene=21#wechat_redirect)
    
-   [AAAI-24 | EarnHFT:针对高频交易的分层强化学习（RL）框架](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483884&idx=1&sn=b6cde76f0cecd07f19179fce94b67922&chksm=ce7e66f2f909efe4a8e9dcae71358111132135ba8f36bbe40faa5e0a2f42c2291f6ebbe9e4c6&scene=21#wechat_redirect)
    
-   [AAAI-24 | MASTER 结合市场信息的自动特征选择的股票预测模型，25%年化收益](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247483818&idx=1&sn=8f17951f57c801a612c7d47f3e1c3a77&chksm=ce7e66b4f909efa2a462cb0640427342a98fe733beeb3e275b1625b9e6f72dcd29a5adb196f6&scene=21#wechat_redirect)
    
-   [COLING 2024 | AlphaFin: 结合深度学习及大模型用于股票预测和金融问答，击败现有预测模型](http://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247484079&idx=1&sn=8459f251f43c453415a615c353c427d2&chksm=ce7e65b1f909eca7fa00766474ddc207110b158528b6da2f6ec96a91a7fbb66727ea5e2a77f2&scene=21#wechat_redirect)