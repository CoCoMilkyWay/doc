# 利用六因子模型寻找股票Alpha

QuantML QuantML 2025-04-11 19:15 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490016&idx=1&sn=a4e2c0e1a4e539eb4e7fae31da07624b&chksm=cf6a519f603fecab0bc475ea9e48d82210addefb50cbd01ba79b380bf6ef12b5c0b5a041195d#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490016&idx=1&sn=a4e2c0e1a4e539eb4e7fae31da07624b&chksm=cf6a519f603fecab0bc475ea9e48d82210addefb50cbd01ba79b380bf6ef12b5c0b5a041195d#rd)

## 使用Fama-French五因子模型加动量因子识别被低估的股票并分析阿尔法贡献

市场并非总是有效的。股票可能被错误定价，而且这种错误定价可能会持续很长时间。如果你知道在哪里寻找，这就会创造出投资机会。

因子模型可以为我们提供关于这些市场低效现象的洞察，因为它们将预期的股票回报分解为关键驱动因素。

例如，Fama-French五因子模型使用市场风险、规模、价值、盈利能力和投资来解释回报。

但即使有了这些因子，一些回报仍然无法解释。这就是阿尔法，即无法用已知风险因子解释的回报部分。

本文将讨论以下内容：

-   下载并清理Fama-French因子数据
    
-   运行滚动因子回归以解释超额回报
    
-   使用统计测试识别错误定价信号
    
-   跟踪因子敞口和回报贡献随时间的变化
    

### 1\. FF五因子模型 + 动量因子

股票回报受多种因素影响，而不仅仅是整体市场走势。这一点在金融文献中已经得到了明确的阐述。

Fama-French五因子模型通过纳入五个关键回报驱动因素，扩展了传统资产定价理论：

**Ri - Rf = α + βm(Rm - Rf) + βsSMB + βvHML + βpRMW + βiCMA**

Ri 可以是投资组合回报或单个股票回报。

让我们进一步讨论。

#### 1.1 市场风险 (Rm-Rf)

该因子代表市场相对于无风险利率的超额回报。其计算公式为：

`Rm - Rf = 市场指数回报 - 无风险利率   `

具有高贝塔值 (>1) 的股票或投资组合比市场波动更大，而低贝塔值 (<1) 的股票对市场走势的敏感度较低。

#### 1.2 规模因子 (SMB: 小盘股减去大盘股)

该因子捕捉规模溢价，因为小盘股往往在较长时间内跑赢大盘股。

因子构建如下：

-   每个月，将所有股票“宇宙”根据市值分为小盘股 (S) 和大盘股 (B) 组。
    
-   在每个组内，使用账面市值比将股票进一步分为价值、中性和成长型。
    
-   SMB 计算为小盘股投资组合的平均回报减去大盘股投资组合的平均回报：
    

`SMB = 1/3(R_S-V + R_S-N + R_S-G) - 1/3(R_B-V + R_B-N + R_B-G)   `

V、N 和 G 分别代表价值、中性和成长型投资组合。

具有正 SMB 贝塔值的股票意味着其行为类似于小盘股。负 SMB 贝塔值则表明大盘股特征。

#### 1.3 价值因子 (HML: 高减去低)

价值溢价表明，便宜的股票（高账面市值比）往往跑赢昂贵的股票（低账面市值比）。

-   股票按账面市值比排名，并分为高 (H)、中 (N) 和低 (L) 组。
    
-   HML 是价值股票的平均回报减去成长型股票的平均回报：
    

`HML = 1/2(R_S-V + R_B-V) - 1/2(R_S-L + R_B-L)   `

正 HML 贝塔值表明股票的行为类似于价值股，而负 HML 贝塔值则表明成长型特征。

#### 1.4 盈利能力因子 (RMW: 稳健减去弱势)

盈利能力强的公司往往跑赢盈利能力弱的公司。RMW 因子衡量这种效应。

-   股票按营业盈利能力（收入减去销售成本、利息和 SG&A 费用，除以总股本）排名。
    
-   高盈利能力股票的回报与低盈利能力股票的回报进行比较：
    

`RMW = 1/2(R_S-R + R_B-R) - 1/2(R_S-W + R_B-W)   `

R 代表盈利能力强的公司，W 代表盈利能力弱的公司。

高 RMW 贝塔值表明对盈利能力强公司的敞口，而低或负贝塔值则表明对低盈利能力股票的敏感性。

#### 1.5 投资因子 (CMA: 保守减去激进)

投资激进的公司往往跑输投资保守的公司。CMA 因子捕捉这种效应。

-   股票按其资产增长率（总资产变化除以总资产）排名。
    
-   低投资（保守）公司的回报与高投资（激进）公司进行比较：
    

`CMA = 1/2(R_S-C + R_B-C) - 1/2(R_S-A + R_B-A)   `

C 代表投资保守的公司，A 代表投资激进的公司。

高 CMA 贝塔值表明股票与投资保守的公司保持一致。低或负贝塔值则表明股票具有激进的再投资行为。

#### 1.6 动量因子 (MoM: 赢家减去输家)

动量表明，过去表现良好的股票往往在短期内持续跑赢。

-   股票按过去 12 个月的回报排名（不包括最近一个月）。
    
-   过去赢家（前 30%）的回报与过去输家（后 30%）的回报进行比较：
    

`MoM = R_赢家 - R_输家   `

该因子解释了传统基于估值的因子无法捕捉的股价趋势持续性。

正 MOM 贝塔值表明动量敞口，即股价呈上升趋势。负贝塔值则表明均值回归行为。

### 为什么这很重要

每个因子都隔离了股票/投资组合回报的一个独特驱动因素。如果一只股票的表现与这些因子保持一致，则表明其对已知风险的敞口。

如果它持续跑赢典型的因子预期，则可能表明存在阿尔法——我们在后续框架中将要呈现的潜在错误定价。

接下来，我们将下载真实的因子数据来测试该模型。

### 2\. 下载因子和股票价格数据

#### 2.1 Fama-French 五因子数据

Fama-French 五因子数据托管在达特茅斯大学的肯·弗伦奇数据图书馆。该数据集包含每日（或每月/每周）因子回报。

我们使用以下 Python 代码以编程方式下载此数据：

`import requests   import zipfile   import io   import re   import pandas as pd   import yfinance as yf      class FamaFrenchDownloader:       """下载并处理Fama-French五因子数据（每日）。"""          @staticmethod       def download_ff5():           """从网络获取并提取F-F五因子数据。"""           response = requests.get(FamaFrenchDownloader.FF5_URL)           with zipfile.ZipFile(io.BytesIO(response.content)) as z:               file_name = z.namelist()[0]               with z.open(file_name) as f:                   return f.read().decode("utf-8").splitlines()          @staticmethod       def parse_ff5_data():           """提取并清理F-F五因子数据。"""           lines = FamaFrenchDownloader.download_ff5()           # 仅保留数据行（以8位日期开头）           data_lines = [line for line in lines if re.match(r'^\s*\d{8}', line)]           # 读取到DataFrame           df = pd.read_csv(io.StringIO("\n".join(data_lines)), sep=r"\s*,\s*", header=None)           # 分配列名           df.columns = ["Date", "MKT_RF", "SMB", "HML", "RMW", "CMA", "RF"]           # 转换日期列           df["Date"] = pd.to_datetime(df["Date"], format="%Y%m%d", errors="coerce")           # 转换数值列           df.iloc[:, 1:] = df.iloc[:, 1:].apply(pd.to_numeric, errors="coerce")           return df      # 调用函数   ff5_df = FamaFrenchDownloader.parse_ff5_data()   ff5_df   `

#### 2.2 动量因子

动量因子不包括在标准的Fama-French数据集中，但可以单独获取。

我们可以类似地获取并清理它：

`import requests   import zipfile   import io   import re   import pandas as pd      class MomentumDownloader:       """下载并处理Fama-French动量因子数据（每日）。"""          MOM_URL = "https://mba.tuck.dartmouth.edu/pages/faculty/ken.french/ftp/F-F_"          @staticmethod       def download_momentum():           """从网络获取并提取动量因子数据。"""           response = requests.get(MomentumDownloader.MOM_URL)           with zipfile.ZipFile(io.BytesIO(response.content)) as z:               file_name = z.namelist()[0]               with z.open(file_name) as f:                   return f.read().decode("utf-8").splitlines()          @staticmethod       def parse_momentum_data():           """提取并清理动量因子数据（每日）。"""           lines = MomentumDownloader.download_momentum()              # 仅保留数据行（以8位日期YYYYMMDD开头）           data_lines = [line for line in lines if re.match(r'^\s*\d{8}', line)]           # 读取到DataFrame           df = pd.read_csv(io.StringIO("\n".join(data_lines)), sep=r"\s*,\s*", header=None)              # 分配列名           df.columns = ["Date", "MOM"]              # 转换日期列           df["Date"] = pd.to_datetime(df["Date"], format="%Y%m%d", errors="coerce")           # 将MoM转换为数值           df["MOM"] = pd.to_numeric(df["mom"], errors="coerce")              # 删除无效行           df.dropna(subset=["Date", "MOM"], inplace=True)              return df      # 调用函数   mom_df = MomentumDownloader.parse_momentum_data()   mom_df   `

![](assets/001.jpg)图2. 动量因子（MoM）数据，它捕捉了过去赢家与输家之间的回报差。这将Fama-French五因子模型扩展为包含趋势持续性。

#### 2.3 下载股票价格数据

因子数据准备就绪后，下一步是收集历史股票价格。

我们将从雅虎财经获取此数据，然后计算每日回报，最后将其与因子回报合并。

我们将使用MSFT和AAPL的投资组合作为示例。请注意，您将能够解释包含更多股票的回报中的更多可变性。

`import yfinance as yf   import pandas as pd      class StockDataFetcher:       """从雅虎财经下载并处理股票数据。"""          @staticmethod       def get_stock_data(tickers, weights, start_date="1990-01-01"):           # 获取多个股票代码的数据并计算加权每日回报              参数:           tickers (list): 股票代码列表（例如，["AAPL", "MSFT"]）           weights (list): 权重列表（例如，[0.3, 0.7]）。必须与tickers长度相同           start_date (str): 历史数据的开始日期。              返回:           DataFrame: 包含日期、股票价格和投资组合每日回报。              if len(tickers) != len(weights):               raise ValueError("股票代码和权重必须具有相同的长度")              # 使用默认的auto_adjust = True获取数据。           raw_df = yf.download(tickers, start=start_date, progress=False, group_by="column")              # 处理多股票代码数据。           if isinstance(raw_df.columns, pd.MultiIndex):               # 如果可能，使用'Adj Close'，否则使用'Close'               level_vals = raw_df.columns.get_level_values(1)               price_col = "Adj Close"if"Adj Close"in level_vals else"Close"               price_cols = [col for col in raw_df.columns if col[1] == price_col]               raw_df = raw_df[price_cols]               raw_df.columns = [col[0] for col in raw_df.columns]           else:               # 对于单个股票代码下载。               price_col = "Adj Close"if"Adj Close"in raw_df.columns else"close"               raw_df = raw_df[[price_col]]               raw_df.columns = tickers              # 确保DataFrame列遵循股票代码的顺序。           raw_df = raw_df[tickers]              # 计算每日回报。           returns_df = raw_df.pct_change() * 100           # 计算加权投资组合回报。           portfolio_return = returns_df.dot(weights)              # 合并数据。           final_df = raw_df.copy()           final_df["Portfolio Return"] = portfolio_return           final_df.reset_index(inplace=True)              return final_df      # 获取股票/投资组合数据   tickers = ["AAPL", "MSFT"]   weights = [0.3, 0.7]  # 这是股票在投资组合中的权重   stock_df = StockDataFetcher.get_stock_data(tickers, weights)   stock_df   `

![](assets/002.jpg)图3. AAPL和MSFT的股票价格数据，以及基于其加权配置计算的投资组合回报。

#### 2.4 将股票回报与因子数据合并

现在我们有了因子数据和股票回报，下一步是将它们合并到一个数据集中。

这将使我们能够分析因子敞口如何解释股票/投资组合的表现。

`# 合并Fama-French五因子和动量因子数据   merged_factors_df = pd.merge(ff5_df, mom_df, on="Date", how="outer")      # 与股票回报合并（使用通用的股票DataFrame，例如stock_df）   final_df = pd.merge(stock_df, merged_factors_df, on="Date", how="inner")   final_df.dropna(inplace=True)   # 显示最终合并的数据集   final_df   `

![](assets/003.jpg)图4. 包含股票回报、因子敞口和用于回归分析的超额回报的合并数据集。

#### 2.5 可视化因子数据和回报

绘制因子回报和投资组合表现随时间变化的图表：

`import numpy as np   import pandas as pd   import matplotlib.pyplot as plt   import matplotlib.dates as mdates      plt.style.use('dark_background')      # 将Date转换为datetime   final_df['Date'] = pd.to_datetime(final_df['Date'])      # 假设股票代码在变量^tickers中定义   try:       stock_ticker_cols = tickers   except NameError:       stock_ticker_cols = []      # 排除股票价格列和任何每日回报列   exclude_cols = ['Date', 'Adj Close'] + stock_ticker_cols   exclude_cols += [col for col in final_df.columns if'Daily Return'in col]   cols_to_plot = [col for col in final_df.columns if col notin exclude_cols]   num_plots = len(cols_to_plot)   fig, axes = plt.subplots(num_plots, 1, figsize=(20, 4 * num_plots), sharex=True)      if num_plots == 1:       axes = [axes]      date_formatter = mdates.DateFormatter("%Y-%m-%d")      for ax in axes:       ax.xaxis.set_major_formatter(date_formatter)       plt.setp(ax.get_xticklabels(), rotation=45, ha='right')       ax.tick_params(labelbottom=True)      for ax, col in zip(axes, cols_to_plot):       pct_series = final_df[col]       log_return = np.log1p(pct_series / 100)       cum_log_return = log_return.cumsum()       level_series = 100 * np.exp(cum_log_return - cum_log_return.iloc[0])          # 剪切以避免对数刻度的零值       level_series = level_series.clip(lower=1e-5)          # 在主y轴上绘制百分比系列（红色）       ax.plot(final_df['Date'], pct_series, color='red', label=f'{col} %', alpha=0.7)       ax.set_ylabel(f'{col} %', color='red')       ax.tick_params(axis='y', labelcolor='red')          # 为标准化的水平系列创建第二个y轴（蓝色）       ax2 = ax.twinx()       ax2.plot(final_df['Date'], level_series, color='blue', label=f'{col} Level')       ax2.set_ylabel(f'{col} Level', color='blue')       ax2.tick_params(axis='y', labelcolor='blue')          # 如果水平值很大，则使用对数刻度       if level_series.max() > 1e6:           ax2.set_yscale('log')      plt.xlabel('Date')   plt.tight_layout()   plt.show()   `

![](assets/004.jpg)

### 3\. 对投资组合回报运行普通最小二乘回归

我们进行普通最小二乘回归，以确定六因子模型在多大程度上解释了投资组合的超额回报。

回归估计因子载荷（贝塔值）和阿尔法。这显示了回报中有多少来自已知风险因子，以及有多少来自无法解释的来源。

统计上显著的阿尔法表明投资组合产生了超出因子预期的超额回报。

贝塔值表明投资组合对市场风险、规模、价值、盈利能力、投资和动量的敏感度。

`import statsmodels.api as sm      # 计算投资组合超额回报   final_df["Excess Return"] = final_df["Portfolio Return"] - final_df["RF"]   # 选择因子回报作为自变量   X = final_df[["MKT_RF", "SMB", "HML", "RMW", "CMA", "MOM"]   X = sm.add_constant(X)  # 添加截距（阿尔法）      # 设置因变量（超额回报）   y = final_df["Excess Return"]      # 运行OLS回归   model = sm.OLS(y, X).fit()      # 打印回归摘要   print(model.summary())   `

![](assets/005.jpg)图6. OLS回归结果估计投资组合超额回报作为因子敞口的函数。主要系数包括市场贝塔值（1.09）、规模（-0.21）、价值（-0.35）、盈利能力（0.13）、投资（-0.63）和动量（0.02，不显著）。

这只投资组合的波动性大于市场。市场贝塔值为1.09，即它会放大市场波动——在牛市上涨更多，在熊市下跌更猛。

它偏爱大盘成长股。负的SMB贝塔值（-0.21）表明它避开了小盘股，而负的HML贝塔值（-0.35）证实了其对成长型股票而非价值型股票的偏好。

正的RMW贝塔值（0.13）表明其倾向于高盈利能力公司。但它倾向于激进的再投资策略，如强烈的负CMA贝塔值（-0.63）所示。这表明其偏好于那些大量再投资而不是将资本返还给股东的公司。

动量没有真正的作用。MOM贝塔值（0.02，p=0.117）统计上不显著，意味着投资组合不会追逐过去的赢家。

最后，阿尔法值是正的，并且统计上显著（每天0.059%）。这表明投资组合获得了超出因子解释的额外回报。

这是否是真正的错误定价还是未考虑的风险，需要进一步测试。

接下来，我们将运行滚动回归，以查看这些因子敞口如何随时间演变。

### 4\. 跟踪因子敞口随时间的变化

因子敞口会发生变化。静态回归捕捉的是平均关系，但市场在不断演变。滚动回归显示了因子敏感性如何随时间变化。

#### 4.1 运行滚动回归

我们使用252天的滚动窗口（大约1年）来估计时变的贝塔值和阿尔法。每个窗口计算一个新的回归，逐日向前移动。

`import numpy as np   import pandas as pd   import statsmodels.api as sm   import matplotlib.pyplot as plt   import matplotlib.dates as mdates      # 设置滚动窗口（252个交易日，大约1年）   window = 252      # 存储滚动估计   rolling_dates = []   rolling_alphas = []   rolling_residuals = []   rolling_betas = {"MKT_RF": [], "SMB": [], "HML": [], "RMW": [], "CMA": [], "MOM": []}      # 执行滚动回归   for i in range(window, len(final_df)):       subset = final_df.iloc[i - window: i]  # 1年窗口       # 计算投资组合超额回报       y = subset["Portfolio Return"] - subset["RF"]       X = subset[["MKT_RF", "SMB", "HML", "RMW", "CMA", "MOM"]       X = sm.add_constant(X)       # 运行回归       model = sm.OLS(y, X).fit()       # 存储结果       rolling_dates.append(final_df.iloc[i]["Date"])       rolling_alphas.append(model.params["const"])       rolling_residuals.append(np.mean(np.abs(model.resid)))       for factor in rolling_betas.keys():           rolling_betas[factor].append(model.params[factor])      # 将滚动结果转换为DataFrame   rolling_results = pd.DataFrame({       "Date": rolling_dates,       "Alpha": rolling_alphas,       "Error": rolling_residuals   })   for factor in rolling_betas.keys():       rolling_results[f"{factor} Beta"] = rolling_betas[factor]   rolling_results["Date"] = pd.to_datetime(rolling_results["Date"])   rolling_results.set_index("Date", inplace=True)   rolling_results   `

![](assets/006.jpg)图7. 滚动回归结果，显示因子敞口随时间的变化。阿尔法值的变化表明存在错误定价的时期。

#### 4.2 运行滚动回归

此代码绘制了滚动回归分析的结果，以显示因子贝塔值和阿尔法值如何随时间演变。

-   因子贝塔值和阿尔法值——跟踪敞口随时间的变化
    
-   投资组合价值和回报——显示高估/低估的时期
    
-   回归误差——衡量模型在多大程度上解释了回报
    

`import matplotlib.ticker as ticker   import matplotlib.dates as mdates   import matplotlib.pyplot as plt   import numpy as np   import pandas as pd      # 确保final_df的Date是datetime索引。   final_df_date = final_df.copy()   final_df_date["Date"] = pd.to_datetime(final_df_date["Date"])   final_df_date.set_index("Date", inplace=True)      # 从投资组合回报计算投资组合价值系列。   portfolio_pct_series = final_df_date["Portfolio Return"]   log_return = np.log1p(portfolio_pct_series / 100)   cum_log_return = log_return.cumsum()   portfolio_prices = 100 * np.exp(cum_log_return - cum_log_return.iloc[0])   portfolio_returns = final_df_date["Portfolio Return"]      # 将投资组合系列重新索引以匹配滚动回归结果。   portfolio_prices_rolling = portfolio_prices.reindex(rolling_results.index)   portfolio_returns_rolling = portfolio_returns.reindex(rolling_results.index)      # 创建3个子图，共享x轴。   fig, axes = plt.subplots(3, 1, figsize=(20,12), sharex=True)      # 绘制滚动因子贝塔值和阿尔法值。   ax = axes[0]      for factor in rolling_betas.keys():       ax.plot(rolling_results.index, rolling_results[f"{factor} Beta"], label=f"{factor} Beta")   ax.plot(rolling_results.index, rolling_results["Alpha"], color="darkgray", linewidth=0.8, label="Alpha")   ax.set_title("滚动因子贝塔值和阿尔法值（1年窗口）")   ax.axhline(0, color="darkgray", linewidth=0.8, linestyle="dotted")   ax.legend()      # 在单独的轴上绘制投资组合价值和每日回报。   ax2 = axes[1]   ax3 = ax2.twinx()  # 次级y轴。   ax2.plot(portfolio_prices_rolling.index, portfolio_prices_rolling, label="Portfolio Value")   ax3.plot(portfolio_returns_rolling.index, portfolio_returns_rolling, label="Portfolio Return")      # 根据滚动回归中的阿尔法值填充区域。   undervalued = rolling_results["Alpha"] > 0   min_val = portfolio_prices_rolling.min()   max_val = portfolio_prices_rolling.max()   ax2.fill_between(rolling_results.index, min_val, max_val, where=undervalued, color="green", alpha=0.2, label="Undervalued")   ax2.fill_between(rolling_results.index, min_val, max_val, where=~undervalued, color="red", alpha=0.2, label="Overvalued")   ax2.set_title("投资组合价值与回报以及高估/低估区域")   ax2.legend(loc="upper left")   ax3.legend(loc="lower left")      # 绘制滚动回归误差（平均绝对残差）。   ax4 = axes[2]   ax4.plot(rolling_results.index, rolling_results["Error"], color="darkred", linewidth=0.8)   ax4.set_title("滚动回归误差（平均绝对残差）")   ax4.axhline(rolling_results["Error"].mean(), color="darkgray", linestyle="dotted")   ax4.set_ylabel("平均绝对误差")      # 设置x轴刻度每3个月一次，并格式化日期。   ax4.xaxis.set_major_locator(mdates.MonthLocator(interval=3))   ax4.xaxis.set_major_formatter(mdates.DateFormatter("%Y-%m"))   plt.tight_layout()   plt.show()   `

![](assets/007.jpg)图8. 投资组合估值随时间的变化，突出显示了基于滚动阿尔法的低估（绿色）和高估（红色）区域。底部面板显示了回归误差。

### 5\. 测试阿尔法

#### 5.1 均值回归

只有当阿尔法值持续存在时，它才有用。如果它迅速地均值回归，任何错误定价都会“太快”地得到纠正，以至于无法进行交易（我们将在下一节中探讨这一点）。

为了分析这一点，我们应用了4种统计测试：

-   使用ADF测试检查阿尔法值是否平稳（均值回归）还是遵循随机游走。p值低于0.05表示均值回归。
    
-   AR(1)模型估计阿尔法的持续性。p值低于1表示均值回归。如果p值接近1，则阿尔法表现出强烈的持续性，意味着
    
-   半衰期计算衡量阿尔法值回归的速度。短半衰期（<20个周期）表明低效现象很快得到纠正。较长的半衰期表明持续的错误定价。
    
-   方差比测试比较短期和长期方差。如果比率低于1，则阿尔法值是均值回归的。如果它高于1，则阿尔法值遵循随机游走。
    

如果阿尔法值是均值回归的，则短期存在低效现象。如果它遵循随机游走，则可能是不明风险而非真正的错误定价。接下来，我们分析阿尔法的半衰期随时间的变化。

`import numpy as np   import pandas as pd   from statsmodels.tsa.stattools import adfuller   from statsmodels.tsa.ar_model import AutoReg      # 创建滚动结果DataFrame的副本   df_copy = rolling_results.copy()      # 删除阿尔法值的NaN值以进行分析   df_copy = df_copy.dropna(subset=["Alpha"])      # 1. 增广迪基-福勒（ADF）测试   adf_result = adfuller(df_copy["Alpha"])   print(f"ADF Statistic: {adf_result[0]}")   print(f"p-value: {adf_result[1]}")   if adf_result[1] < 0.05:       print("阿尔法值是均值回归（平稳的）")   else:       print("阿尔法值遵循随机游走（不是均值回归）")      # 2. 自回归模型（AR-1）      ar_model = AutoReg(df_copy["Alpha"], lags=1).fit()   rho = ar_model.params[1]  # AR(1)系数      print(f"AR(1)系数 (rho): {rho}")   if rho < 1:       print("阿尔法值是均值回归")   else:       print("阿尔法值遵循随机游走")      # 3. 半衰期计算   half_life = np.log(0.5) / np.log(abs(rho))      print(f"阿尔法值的半衰期: {half_life} 个周期")   if half_life < 20:       print("阿尔法值迅速回归（短期低效现象）")   else:       print("阿尔法值需要更长的时间回归（持续的错误定价）")      # 4. 自定义方差比测试   def variance_ratio_test(series, lag=4):       series = series.dropna()       # 计算方差       var_1 = np.var(series.diff(1).dropna(), ddof=1)       var_k = np.var(series.diff(lag).dropna(), ddof=1)       # 方差比       vr_stat = var_k / (var_1 * lag)       return vr_stat      vr_stat = variance_ratio_test(df_copy["Alpha"], lag=4)   print(f"方差比: {vr_stat}")   if vr_stat < 1:       print("阿尔法值是均值回归")   else:       print("阿尔法值遵循随机游走")   `

`ADF Statistic: -4.85362763884568   p-value: 4.2895579677989856e-05   阿尔法值是均值回归（平稳的）   AR(1)系数 (rho): 0.9950044098509443   阿尔法值是均值回归   阿尔法值的半衰期: 138.4049482030796 个周期   阿尔法值需要更长的时间回归（持续的错误定价）   方差比: 0.9462945734354862   阿尔法值是均值回归   `

结果表明，阿尔法值并非随机。它会漂移，但总是会回归。

ADF测试证实了这一点——阿尔法值均值回归，具有强烈的统计信号。它不会不可预测地漂移；它遵循一个模式。但这个模式移动缓慢。

AR(1)系数（0.995）几乎等于1，意味着阿尔法值会保持其偏差一段时间，然后才进行纠正。半衰期为138天，所以当错误定价发生时，它不会一夜之间消失。它会持续存在。

方差比（0.95）支持这一点。阿尔法值会回归，但不会急剧地——它会逐渐消退。

这不是一个短期的低效现象。这是一个持久的异常现象，这种现象需要耐心。机会是存在的，但只有那些愿意等待的人才能把握。

#### 5.2 跟踪阿尔法的持续性随时间的变化

阿尔法值并不总是以相同的速度回归。有时，低效现象很快得到纠正。其他时候，它们会持续存在。

此分析在126天的窗口内跟踪阿尔法的滚动半衰期。在每个步骤中，AR(1)模型估计错误定价需要多长时间才能消失。

`import numpy as np   import pandas as pd   import matplotlib.pyplot as plt   from statsmodels.tsa.ar_model import AutoReg      # 创建rolling_results DataFrame的副本   df_copy = rolling_results.copy()      # 删除阿尔法值的NaN值   df_copy = df_copy.dropna(subset=["Alpha"])      # 定义滚动窗口大小（例如，126个交易日）   rolling_window = 126      # 计算滚动AR(1)系数（rho）和半衰期   rolling_half_life = []      for i in range(len(df_copy) - rolling_window):       window_data = df_copy["Alpha"].iloc[i:i+rolling_window]       # 拟合AR(1)模型       try:           ar_model = AutoReg(window_data, lags=1).fit()           rho = ar_model.params[1]  # AR(1)系数           # 计算半衰期           if abs(rho) < 1:               half_life = np.log(0.5) / np.log(abs(rho))           else:               half_life = np.nan       except:           half_life = np.nan       rolling_half_life.append(half_life)      # 将结果与原始索引对齐   df_copy = df_copy.iloc[rolling_window:].copy()   df_copy["Rolling_Half_Life"] = rolling_half_life      # 绘制滚动半衰期   plt.figure(figsize=(12,5))   plt.plot(df_copy.index, df_copy["Rolling_Half_Life"], color="red", label="Rolling Half-Life")   plt.axhline(y=145, color="darkgray", linestyle="dashed", label="Reference Half-Life")   plt.xlabel("Time")   plt.ylabel("Half-Life (Periods)")   plt.title("滚动投资组合阿尔法半衰期随时间的变化")   plt.legend()   plt.grid(True)   plt.show()   `

线条的长度代表不同时间点的阿尔法半衰期。较短的线条意味着阿尔法迅速回归，使得低效现象短暂。

![](assets/008.jpg)图9. 阿尔法的滚动半衰期。较短的周期表明快速纠正，而较长的半衰期则表明持续的低效现象。

较长的线条表明阿尔法持续数千个交易日。

半衰期的峰值显示了市场条件下，低效现象需要更长的时间才能得到纠正，而靠近参考线的时期则表明价格调整更快。

### 6\. 投资组合回报的回报归因

本节将投资组合回报分解为因子驱动的和无法解释的部分。它回答了两个关键问题：

-   投资组合的表现有多少是由已知因子解释的？
    
-   实际投资组合回报与因子敞口的预期回报相比如何？
    

代码通过将滚动贝塔值与因子回报相乘来计算因子贡献。然后，它将无法解释的回报（残差阿尔法），即无法由已知风险因子解释的部分分开。

三种可视化结果总结了结果：

-   复合因子贡献：显示不同因子如何驱动长期回报。
    
-   算术因子贡献：跟踪每个因子的原始累积影响。
    
-   实际与预期回报：比较投资组合表现与其基于因子的归因。
    

如果实际回报超过基于因子的归因，则投资组合可能正在捕捉额外的阿尔法来源。如果它落后，则因子高估了表现。

![](assets/009.jpg)图10. 因子回报归因。第一面板显示了复合因子贡献，第二面板显示了算术归因，第三面板将实际投资组合回报与预期因子驱动的表现进行比较。在复合和算术贡献中，对规模、价值、盈利能力、投资和动量的敞口所起的作用较小。

### 7\. 限制和改进

该方法提供了一种结构化的方法来识别错误定价，但存在限制：

-   因子模型假设：Fama-French框架假设线性关系，这可能无法完全捕捉非线性和制度转变。
    
-   阿尔法可能不是真正的错误定价：无法解释的回报可能是由于未建模的风险而非实际低效现象。
    
-   缓慢移动的低效现象：模型识别长期趋势，但短期交易机会可能需要其他信号。
    
-   有限的因子集：添加流动性、波动性或宏观经济因子等变量可以提高解释力。
    

改进：

-   纳入替代数据（例如，情感、新闻或宏观指标）。
    
-   测试非线性模型，如机器学习，以处理更复杂的关系。
    
-   使用高频数据来识别短期错误定价。
    
-   将因子集扩展到传统风险溢价之外。
    

### 结论

当我们结合Fama-French五因子模型和动量因子时，我们识别出了持续的阿尔法，即无法完全用已知风险解释的回报。

滚动分析显示了因子敞口如何随时间变化，而统计测试证实了一些错误定价持续数月。这表明了长期策略而非短期套利的机会。

然而，没有模型是完美的。一些超额回报可能反映了隐藏的风险而非真正的错误定价。扩展因子集、纳入替代数据以及测试非线性模型将提高准确性。

**作者：Cristian Velasquez**

  

  

  

  

  

代码见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/010.png)