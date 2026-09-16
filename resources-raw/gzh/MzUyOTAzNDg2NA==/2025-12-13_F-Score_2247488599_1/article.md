# F-Score

fintechhaibin FinTechHi 2025-12-13 22:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247488599&idx=1&sn=1800d84c7371c1be016294597010d541&chksm=fbf170116f72b8fbdeea9d5a1e9afec5749fc4e0e55af072788691c38279872dc2ddbe19c10c#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247488599&idx=1&sn=1800d84c7371c1be016294597010d541&chksm=fbf170116f72b8fbdeea9d5a1e9afec5749fc4e0e55af072788691c38279872dc2ddbe19c10c#rd)

说明：F-Score学习记录。

多因子策略是最广泛应用的策略之一。

CAPM模型的提出为股票的收益提供了解释，但随着各种市场异象的出现，使得人们发现股票存在超额收益，这种收益不能为市场因子所解释，因此，出现了多因子模型。

多因子模型最早是由Fama-French提出，包括三因子和五因子模型。

Fama认为，股票的超额收益可以由市场因子、市值因子和账面价值比因子共同解释。

随着市场的发展，出现许多三因子模型难以解释的现象。

因此，Fama又提出了五因子模型，加入了盈利水平、投资水平因子。

此后，陆续出现了六因子模型、八因子模型等，目前多少个因子是合适的尚无定论。

市场上常用的多因子模型包括如下几个。

模型

出处

所含因子

Fama-French三因子

Fama and Farench(1993)

市场、规模、价值

Carhart四因子

Carhart（1997）

市场、规模、价值、动量

Novy-Marx四因子

Novy-Marx（2013）

市场、规模、价值、盈利

Fama-French五因子

Fama and Farench(2015)

市场、规模、价值、盈利、投资

Hou-Xue-Zhang四因子

Hou et al

市场、规模、盈利、投资

Stambaugh-Yuan四因子

Stambaugh and Yuan(2017)

市场、规模、管理、表现

Daniel-Hirshleifer-Sun三因子

Daniel et al（2020）

市场、长周期行为、短周期行为

  

F-Score就是一个利用9个因子对股票基本面进行评分的模型，得分越高，股票就约优质，这9个因子呢，都是可以基于财报数据计算出来的，因子清单和计算方式如下表所示。

![](assets/001.png)

大概浏览一下上表，每个因子的取值只有0或1，当满足条件时，取值为1，反之为0。**每满足一个条件得1分，满足N个条件得N分，因此，F-Score模型的最高评分就是9分。再详细看下每个因子：**

-   **资产收益率**用来衡量这个企业的盈利能力，“扣非”是为了剔除类似于卖房子设备、炒股投资带来的盈利，大于零表示企业处于盈利状态。
    
-   **经营活动产生的现金流量净额比总资产**表示经营业务给企业带来的实际现金流入，因为利润里面是可能包含应收票据或应收账款的，类似于你去小卖部买东西赊账，小卖部账面盈利，但实际没有收到钱，大于零表示有实际的现金流入，企业真金白银的盈利。
    
-   **资产收益率变化**表示企业盈利能力变化，大于零表示企业盈利加速，处于扩张状态。
    
-   **应计收益率**比第二个因子更进一步地衡量企业真金白银的盈利能力，大于零表示企业盈利更为真实。
    
-   **长期负债率变化**用来衡量企业偿债能力的变化，长期负债率=非流动负债/资产总额，小于零表示企业偿债能力增强。
    
-   **流动比率变化**用来衡量企业变现能力的变化，流动比率=流通资产/流动负债，流动比率数值越大，企业的变现能力就越强，流动比率大于零表示企业的变现能力在增强。
    
-   **股票是否增发**表示企业是否向股市再融资圈钱，不融资则表示企业依靠自身可以造血，有健康的现金流。
    
-   **毛利率变化**衡量企业的竞争力变化，众所周知，如果企业没有行业壁垒护城河，则随着竞争者的融入，企业的毛利率会降低，大于零表示企业的竞争力在变强。
    
-   **资产周转率变化**用来衡量企业的营运效率和管理质量，资产周转率=总营业额/总资产，资产周转率越高则表示企业能很好地利用自身资产生产商品/服务并销售出去，大于零则表示企业的营运效率和管理质量在提升。
    

那这来自海外的F-Score基本面评分模型在中国A股是否有效呢，华创金工做了一个试验，将F-Score得分在0~3之间的股票归为Low组，4~6分的为Middle组，7~9份的为High组，进行分组回测，结果如下。

![](assets/002.png)

从分组回测结果中看出，净值曲线是明显分层的，说明F-Score模型能起到一定的区分能力。

对于个人而言，不需要投资那么多的股票，那我们就直接筛选F-Score得分为9的股票进行投资。

依照这个简单朴素的思想，回测一下从2014年至今这个策略的绩效，以下是结合AKShare数据源实现的F-Score策略完整代码，策略逻辑为筛选F-Score得分为9的股票并进行定期调仓：

`import akshare as ak   import pandas as pd   import numpy as np   import datetime   from datetime import timedelta   import matplotlib.pyplot as plt      # 设置中文显示   plt.rcParams["font.family"] = ["SimHei", "WenQuanYi Micro Hei", "Heiti TC"]      class FScoreStrategy:       def __init__(self, start_date, end_date, initial_capital=1000000):           """初始化策略参数"""           self.start_date = start_date           self.end_date = end_date           self.initial_capital = initial_capital           self.positions = {}  # 持仓字典           self.history = []    # 历史记录           self.current_date = None          def get_trade_dates(self):           """获取回测期间的交易日历"""           try:               # 获取A股交易日历               trade_dates = ak.tool_trade_date_hist_sina()               trade_dates = pd.to_datetime(trade_dates)               # 筛选回测期间的交易日               mask = (trade_dates >= self.start_date) & (trade_dates <= self.end_date)               return trade_dates[mask].tolist()           except Exception as e:               print(f"获取交易日历失败: {e}")               return []          def get_stock_list(self, date):           """获取指定日期的股票列表（沪深300成分股作为样本）"""           try:               # 转换日期格式               str_date = date.strftime("%Y%m%d")               # 获取沪深300成分股               stock_list = ak.index_stock_cons(symbol="000300")               # 保留股票代码               return stock_list["品种代码"].tolist()           except Exception as e:               print(f"获取股票列表失败: {e}")               return []          def get_financial_data(self, stock_code, end_date):           """获取股票的财务数据"""           try:               # 转换日期格式               str_end_date = end_date.strftime("%Y-%m-%d")               # 获取利润表数据               income_df = ak.stock_financial_report_sina(                   symbol=stock_code,                    symbol_type="income",                    report_type="yearly"               )               # 获取资产负债表数据               balance_df = ak.stock_financial_report_sina(                   symbol=stock_code,                    symbol_type="balance",                    report_type="yearly"               )               # 获取现金流量表数据               cashflow_df = ak.stock_financial_report_sina(                   symbol=stock_code,                    symbol_type="cashflow",                    report_type="yearly"               )                              return {                   "income": income_df,                   "balance": balance_df,                   "cashflow": cashflow_df               }           except Exception as e:               print(f"获取{stock_code}财务数据失败: {e}")               returnNone          def calculate_f_score(self, financial_data):           """计算F-Score得分"""           ifnot financial_data:               return0                          income = financial_data["income"]           balance = financial_data["balance"]           cashflow = financial_data["cashflow"]                      # 确保数据不为空           if income.empty or balance.empty or cashflow.empty:               return0                          score = 0                      try:               # 1. 资产收益率(ROA) > 0               # 扣非净利润/平均总资产               net_profit = float(income[income["项目"] == "归属于母公司所有者的净利润扣除非经常性损益后的净额"].iloc[0, 1])               total_assets = float(balance[balance["项目"] == "资产总计"].iloc[0, 1])               if total_assets != 0and net_profit / total_assets > 0:                   score += 1                                  # 2. 经营活动产生的现金流量净额/总资产 > 0               ocf = float(cashflow[cashflow["项目"] == "经营活动产生的现金流量净额"].iloc[0, 1])               if total_assets != 0and ocf / total_assets > 0:                   score += 1                                  # 3. 资产收益率变化 > 0               if len(income) > 1:                   prev_net_profit = float(income[income["项目"] == "归属于母公司所有者的净利润扣除非经常性损益后的净额"].iloc[0, 2])                   prev_total_assets = float(balance[balance["项目"] == "资产总计"].iloc[0, 2])                   if total_assets != 0and prev_total_assets != 0:                       current_roa = net_profit / total_assets                       prev_roa = prev_net_profit / prev_total_assets                       if current_roa - prev_roa > 0:                           score += 1                              # 4. 应计收益率 > 0 (经营活动现金流/总资产 - ROA)               if total_assets != 0:                   current_roa = net_profit / total_assets if total_assets != 0else0                   ocfoa = ocf / total_assets                   if ocfoa - current_roa > 0:                       score += 1                              # 5. 长期负债率变化 < 0               if len(balance) > 1:                   non_current_liability = float(balance[balance["项目"] == "非流动负债合计"].iloc[0, 1])                   prev_non_current_liability = float(balance[balance["项目"] == "非流动负债合计"].iloc[0, 2])                                      current_ltd_ratio = non_current_liability / total_assets if total_assets != 0else0                   prev_ltd_ratio = prev_non_current_liability / prev_total_assets if prev_total_assets != 0else0                                      if current_ltd_ratio - prev_ltd_ratio < 0:                       score += 1                              # 6. 流动比率变化 > 0               if len(balance) > 1:                   current_assets = float(balance[balance["项目"] == "流动资产合计"].iloc[0, 1])                   current_liability = float(balance[balance["项目"] == "流动负债合计"].iloc[0, 1])                   prev_current_assets = float(balance[balance["项目"] == "流动资产合计"].iloc[0, 2])                   prev_current_liability = float(balance[balance["项目"] == "流动负债合计"].iloc[0, 2])                                      current_cr = current_assets / current_liability if current_liability != 0else0                   prev_cr = prev_current_assets / prev_current_liability if prev_current_liability != 0else0                                      if current_cr - prev_cr > 0:                       score += 1                              # 7. 未进行股票增发               # 这里简化处理，实际需要查询增发记录               score += 1# 假设未增发                              # 8. 毛利率变化 > 0               if len(income) > 1:                   operating_revenue = float(income[income["项目"] == "营业收入"].iloc[0, 1])                   operating_cost = float(income[income["项目"] == "营业成本"].iloc[0, 1])                   prev_operating_revenue = float(income[income["项目"] == "营业收入"].iloc[0, 2])                   prev_operating_cost = float(income[income["项目"] == "营业成本"].iloc[0, 2])                                      current_gpm = (operating_revenue - operating_cost) / operating_revenue if operating_revenue != 0else0                   prev_gpm = (prev_operating_revenue - prev_operating_cost) / prev_operating_revenue if prev_operating_revenue != 0else0                                      if current_gpm - prev_gpm > 0:                       score += 1                              # 9. 资产周转率变化 > 0               if len(income) > 1and len(balance) > 1:                   current_tat = operating_revenue / total_assets if total_assets != 0else0                   prev_tat = prev_operating_revenue / prev_total_assets if prev_total_assets != 0else0                                      if current_tat - prev_tat > 0:                       score += 1                                  except Exception as e:               print(f"计算F-Score失败: {e}")                          return score          def get_stock_price(self, stock_code, date):           """获取股票在指定日期的价格"""           try:               str_date = date.strftime("%Y%m%d")               # 获取股票行情数据               df = ak.stock_zh_a_daily(symbol=stock_code, start_date="20000101", end_date=str_date)               # 找到最近的价格               df["date"] = pd.to_datetime(df["date"])               df = df[df["date"] <= date]               ifnot df.empty:                   return df.iloc[-1]["close"]               returnNone           except Exception as e:               print(f"获取{stock_code}价格失败: {e}")               returnNone          def rebalance(self, date):           """调仓逻辑：筛选F-Score=9的股票"""           self.current_date = date           print(f"开始调仓: {date.strftime('%Y-%m-%d')}")                      # 获取股票列表           stock_list = self.get_stock_list(date)           ifnot stock_list:               return                          # 计算每只股票的F-Score           high_score_stocks = []           for code in stock_list[:50]:  # 为了速度，只取前50只股票               financial_data = self.get_financial_data(code, date)               f_score = self.calculate_f_score(financial_data)               if f_score == 9:                   high_score_stocks.append(code)                   print(f"{code} F-Score=9，加入持仓")                      # 获取当前总资产           total_assets = self.initial_capital           for stock, pos in self.positions.items():               price = self.get_stock_price(stock, date)               if price:                   total_assets += pos * price                      # 等权重分配资金           if high_score_stocks:               weight = 1.0 / len(high_score_stocks)               for stock in high_score_stocks:                   target_value = total_assets * weight                   price = self.get_stock_price(stock, date)                   if price:                       target_shares = int(target_value / price)                       self.positions[stock] = target_shares                      # 记录当前状态           self.history.append({               "date": date,               "positions": self.positions.copy(),               "total_assets": total_assets           })                      print(f"调仓完成，持仓股票数量: {len(self.positions)}")          def run_backtest(self):           """运行回测"""           print("开始回测...")           trade_dates = self.get_trade_dates()           ifnot trade_dates:               print("没有可用的交易日数据")               return                          # 每月第一个交易日调仓           rebalance_dates = []           prev_month = None           for date in trade_dates:               if date.month != prev_month:                   rebalance_dates.append(date)                   prev_month = date.month                      # 执行调仓           for date in rebalance_dates:               self.rebalance(date)                      # 绘制回测结果           self.plot_results()          def plot_results(self):           """绘制回测结果"""           ifnot self.history:               print("没有回测数据可绘制")               return                          dates = [item["date"] for item in self.history]           values = [item["total_assets"] for item in self.history]                      plt.figure(figsize=(12, 6))           plt.plot(dates, values, label="策略净值")           plt.axhline(y=self.initial_capital, color='r', linestyle='--', label="初始资金")           plt.title("F-Score策略回测结果")           plt.xlabel("日期")           plt.ylabel("总资产(元)")           plt.legend()           plt.grid(True)           plt.show()      if __name__ == "__main__":       # 设置回测时间范围       start = datetime.datetime(2018, 1, 1)       end = datetime.datetime(2023, 1, 1)              # 初始化并运行策略       strategy = FScoreStrategy(start, end)       strategy.run_backtest()   `

### 策略为每月第一个交易日调仓一次，筛选F-Score得分为9的股票进行等权重配置模拟交易。其中F-Score严格按照9个因子进行评分，每个因子满足条件得1分，满分为9分计算，最后绘制策略净值曲线，与初始资金对比。

  

  

附1：F-Score因子计算

因子序号

因子名称

计算方式/判断条件

1

资产收益率（ROA）

扣非净利润 ÷ 平均总资产 ＞ 0

2

经营活动现金流/总资产

经营活动产生的现金流量净额 ÷ 总资产 ＞ 0

3

资产收益率变化

当期ROA - 上期ROA ＞ 0

4

应计收益率

（经营活动现金流/总资产） - ROA ＞ 0

5

长期负债率变化

（当期非流动负债/总资产） - （上期非流动负债/总资产） ＜ 0

6

流动比率变化

（当期流动资产/流动负债） - （上期流动资产/流动负债） ＞ 0

7

股票是否增发

近1年未进行股票增发（通过增发记录查询）

8

毛利率变化

（当期毛利率） - （上期毛利率） ＞ 0 （毛利率=（营业收入-营业成本）÷营业收入）

9

资产周转率变化

（当期总资产周转率） - （上期总资产周转率） ＞ 0 （总资产周转率=营业收入÷总资产）

### 附2：计算单个因子得分

以单只股票为例，从财报中提取所需指标，逐一判断是否满足因子条件：

`import akshare as ak   import pandas as pd      def calculate_f_score(stock_code, end_date):       # 获取利润表、资产负债表、现金流量表（以akshare为例）       income = ak.stock_financial_report_sina(symbol=stock_code, symbol_type="income", report_type="yearly")       balance = ak.stock_financial_report_sina(symbol=stock_code, symbol_type="balance", report_type="yearly")       cashflow = ak.stock_financial_report_sina(symbol=stock_code, symbol_type="cashflow", report_type="yearly")              score = 0       # 因子1：ROA > 0       net_profit = income[income["项目"] == "归属于母公司所有者的净利润扣除非经常性损益后的净额"].iloc[0, 1]       total_assets = balance[balance["项目"] == "资产总计"].iloc[0, 1]       if (net_profit / total_assets) > 0:           score += 1              # 因子2：经营活动现金流/总资产 > 0       ocf = cashflow[cashflow["项目"] == "经营活动产生的现金流量净额"].iloc[0, 1]       if (ocf / total_assets) > 0:           score += 1              # 因子3：ROA变化 > 0（需对比上期数据）       if len(income) > 1and len(balance) > 1:           prev_net_profit = income[income["项目"] == "归属于母公司所有者的净利润扣除非经常性损益后的净额"].iloc[0, 2]           prev_total_assets = balance[balance["项目"] == "资产总计"].iloc[0, 2]           current_roa = net_profit / total_assets           prev_roa = prev_net_profit / prev_total_assets           if (current_roa - prev_roa) > 0:               score += 1              # 因子4：应计收益率 > 0       if (ocf / total_assets) - (net_profit / total_assets) > 0:           score += 1              # 因子5：长期负债率变化 < 0       non_current_liability = balance[balance["项目"] == "非流动负债合计"].iloc[0, 1]       prev_non_current_liability = balance[balance["项目"] == "非流动负债合计"].iloc[0, 2]       current_ltd = non_current_liability / total_assets       prev_ltd = prev_non_current_liability / prev_total_assets       if (current_ltd - prev_ltd) < 0:           score += 1              # 因子6：流动比率变化 > 0       current_assets = balance[balance["项目"] == "流动资产合计"].iloc[0, 1]       current_liability = balance[balance["项目"] == "流动负债合计"].iloc[0, 1]       prev_current_assets = balance[balance["项目"] == "流动资产合计"].iloc[0, 2]       prev_current_liability = balance[balance["项目"] == "流动负债合计"].iloc[0, 2]       current_cr = current_assets / current_liability if current_liability != 0else0       prev_cr = prev_current_assets / prev_current_liability if prev_current_liability != 0else0       if (current_cr - prev_cr) > 0:           score += 1              # 因子7：未增发（简化处理，实际需查增发记录）       score += 1# 假设未增发              # 因子8：毛利率变化 > 0       operating_rev = income[income["项目"] == "营业收入"].iloc[0, 1]       operating_cost = income[income["项目"] == "营业成本"].iloc[0, 1]       prev_operating_rev = income[income["项目"] == "营业收入"].iloc[0, 2]       prev_operating_cost = income[income["项目"] == "营业成本"].iloc[0, 2]       current_gpm = (operating_rev - operating_cost) / operating_rev if operating_rev != 0else0       prev_gpm = (prev_operating_rev - prev_operating_cost) / prev_operating_rev if prev_operating_rev != 0else0       if (current_gpm - prev_gpm) > 0:           score += 1              # 因子9：资产周转率变化 > 0       current_tat = operating_rev / total_assets if total_assets != 0else0       prev_tat = prev_operating_rev / prev_total_assets if prev_total_assets != 0else0       if (current_tat - prev_tat) > 0:           score += 1              return score   `

#### 

附3：关于阈值

F-Score的提出者（Joseph D. Piotroski）在原始研究中采用了“三分法”阈值，适用于大多数基础场景：

  

-   Low组：0~3分（基本面较差，存在财务风险）；
    
-   Middle组：4~6分（基本面中等，稳定性一般）；
    
-   High组：7~9分（基本面优质，财务健康度高）。
    

  

实际使用中，若追求“基本面安全边际”，可直接选择High组（7~9分）

作为候选池，这也是多数研究和实际应用中的默认阈值。

原因是7分以上的股票在9个因子中满足了大部分财务健康条件（如盈利、现金流、偿债能力等核心指标均向好），长期来看表现往往优于低分组。

若投资策略要求“极致的财务安全性”（如防御型投资），可进一步提高阈值，仅保留全部9个因子均满足条件的股票（满分）。  

这类股票在盈利能力、现金流、负债管理、运营效率等维度均表现优异，基本面几乎无明显瑕疵。

这样做的好处是筛选出的股票财务质量极高，踩雷风险低；但现实问题是全市场中9分股票数量极少（尤其在熊市或行业下行期可能为空），可能导致无股可投或过度集中。

### 当然，也可以结合市场环境、**市场整体估值、行业周期**动态灵活的调整阈值。

1.  **牛市/高估值阶段**：提高阈值（如8~9分），因为此时市场情绪高涨，低质量股票可能被高估，需更严格筛选以规避泡沫；
    
2.  **熊市/低估值阶段**：降低阈值（如6~9分），因为此时优质股票可能被错杀，适当放宽标准可捕捉更多低估标的；
    
3.  **行业特性**：对强周期行业（如地产、能源）可提高阈值（7~9分），因为其财务波动大，需更严格筛选；对弱周期行业（如消费、医药）可适当放宽（6~9分）。
    

最科学的方式是基于历史数据回测，找到适合自身策略的阈值：

1.  **回测步骤**：
    

-   选取样本区间（如近10年）和股票池（如沪深300）；
    
-   按不同阈值（如5分、6分、7分、8分）分组，计算各组的年化收益、夏普比率、最大回撤等指标；
    
-   选择“收益较高且标的数量适中”的阈值（例如回测显示7分以上组收益显著高于市场，且每年有10~30只股票可供选择）。
    

3.  **示例结论**：  
    若回测发现：
    

-   7分以上组年化收益15%，最大回撤20%，平均每年有20只股票；
    
-   8分以上组年化收益16%，但最大回撤25%，平均每年仅5只股票；  
    则可优先选择7分作为阈值（平衡收益与稳定性）。
    

###   

在F-Score模型中，默认所有9个因子均为**等权重（每个因子1分）**，但在实际应用中，可根据投资目标、市场特性或数据验证结果调整因子权重，以增强策略的针对性。确定因子权重的核心逻辑是：**让对投资回报影响更大的因子拥有更高权重**，常见方法如下：

### 附4：通过回测计算最优权重

### F-Score模型默认9个因子等权重（各1分），但实际应用中可依投资目标、市场特性或数据验证调整权重，核心逻辑是让对投资回报影响更大的因子获更高权重，具体方法小结如下：  等权重法适合入门，无需数据验证，认为9个因子在衡量财务健康度上同等重要，其逻辑简单、易理解、计算方便，但未区分因子对股价影响的差异。  理论驱动法基于因子经济意义和对企业价值的核心影响主观赋值，高权重（如2分）给ROA、经营活动现金流/总资产等核心指标，中等权重（如1.5分）给盈利增长与竞争力相关因子，低权重（如1分）给偿债能力等辅助指标，符合商业常识、避免数据过拟合，但主观判断可能与市场实际不符。所以利用历史数据量化各因子对股票收益的影响，用统计方法确定权重更科学。

#### 方法1：因子收益率回归

-   **逻辑**：计算每个因子单独对股票未来收益的解释力（如因子得分每提高1分，股票下月收益平均增加多少），影响力越大的因子权重越高。
    
-   **步骤**：
    

1.  选取历史样本（如近10年A股数据），每月计算所有股票的9个因子得分；
    
2.  以“股票下月收益率”为因变量，以9个因子得分为自变量，做线性回归；
    
3.  回归系数的绝对值大小反映因子对收益的影响程度，将系数归一化后作为权重（如系数总和为1）。  
    例：若“ROA”的回归系数为0.02（每提高1分得，下月收益平均+2%），“增发情况”的系数为0.005，则ROA权重更高。
    

#### 方法2：因子IC值排序

-   **逻辑**：用“信息系数（IC）”衡量因子对收益的预测能力，IC绝对值越大，因子越有效，权重越高。
    

-   IC值：某因子当月得分与股票下月收益率的相关系数（范围-1~1），绝对值越大，预测能力越强。
    

-   **步骤**：
    

1.  计算每个因子在历史上每月的IC值，取平均值（如“ROA”的平均IC为0.08，“流动比率变化”为0.03）；
    
2.  按IC绝对值大小分配权重（如IC最高的因子权重为2，最低为1，或按比例分配）。
    

#### 方法3：机器学习优化

-   **逻辑**：用算法（如线性回归、随机森林）自动学习因子权重，最大化策略收益或夏普比率。
    
-   **步骤**：
    

1.  将历史数据分为训练集和测试集；
    
2.  以“因子得分”为特征，“未来收益”为目标，训练模型，输出各因子的权重参数；
    
3.  在测试集验证权重有效性，避免过拟合。
    

### 实操上，新手优先F-Score模型等权重法，避免主观误判影响策略稳定。需结合市场特性调整：牛市提“资产周转率变化”权重，熊市抬高“流动比率变化”权重，且单因子权重建议控制在其他因子的2-3倍内，避免极端依赖。同时每半年或一年重估权重，适配市场结构变化。  权重合理性需经逻辑校验与实证检验：从经济逻辑判断因子与企业价值的关联性、行业适配性，避免极端权重。核心是让有效因子更重要，通过回测验证适用性，兼顾收益与稳定性，规避过拟合。

### 附5：策略表现

通过回测对比不同权重下的策略表现，核心是验证“该权重是否能提升策略的收益风险比”。

#### 步骤1：设定对比基准

-   **基准1**：等权重模型（原始F-Score，每个因子1分），作为最基础的参照；
    
-   **基准2**：市场指数（如沪深300），验证策略是否跑赢大盘；
    
-   **基准3**：随机权重模型（随机分配权重），排除“运气因素”。
    

#### 步骤2：核心评价指标

回测时需关注以下指标，综合判断权重有效性：

指标类型

具体指标

含义

**收益能力**

年化收益率

权重调整后是否提高了长期收益？

  

超额收益率（相对基准）

是否跑赢等权重模型或市场指数？

**风险控制**

最大回撤

权重调整后是否降低了极端亏损？

  

波动率（年化标准差）

收益波动是否更小（更稳定）？

**风险收益比**

夏普比率（收益/波动率）

每承担1单位风险获得的收益是否更高（核心指标，优先选择夏普比率更高的）

**稳定性**

胜率（盈利月份占比）

策略在多数时间是否有效，而非仅靠少数月份表现？

#### 步骤3：分组回测对比

例如，验证“提高ROA权重”是否合理：

-   测试组A：ROA权重2分，其他因子1分；
    
-   对照组B：所有因子1分（等权重）；
    
-   若A组的年化收益高于B组，且夏普比率更高、最大回撤更小，则说明提高ROA权重是合理的。
    

#### 步骤4：样本外验证（关键步骤）

避免“过拟合”（权重仅在历史数据中有效，未来失效）：

1.  将历史数据分为**训练集**（如2013~2018年）和**样本外测试集**（如2019~2023年）；
    
2.  在训练集中优化因子权重（如通过回归或IC值确定权重）；
    
3.  在测试集中验证该权重的表现：若测试集表现与训练集接近（如夏普比率下降不超过20%），则权重具有稳定性；若测试集表现大幅下滑，则可能过拟合，需调整权重。
    

### 步骤5：敏感性分析（验证权重的稳健性）

检验权重微小变动是否会导致策略表现大幅波动（波动越小，权重越稳健）：

1.  对目标权重进行微调（如某因子权重从2分±0.2分）；
    
2.  观察策略指标（如夏普比率、收益率）的变化幅度：
    

-   若指标变化小于5%，说明权重稳健（微小误差不影响效果）；
    
-   若指标变化超过20%，说明权重过于敏感（实际应用中易受数据误差影响，需简化或调整）。
    

### 步骤6：因子独立性检验（避免权重冗余）

若两个因子高度相关（如“资产收益率”和“资产收益率变化”），高权重可能导致重复计算，需验证：

1.  计算因子间的相关性（如皮尔逊相关系数）：若相关系数＞0.7，说明因子信息重叠；
    
2.  若因子高度相关，需降低其中一个的权重（避免重复赋予重要性）。例如，“ROA”和“ROA变化”相关度高，可将两者权重之和控制在与其他独立因子相当的水平。
    

### 假设通过回测得到两组权重：

方案

年化收益

夏普比率

最大回撤

样本外夏普比率

等权重

12%

1.5

25%

1.4

优化权重A

15%

1.8

22%

1.6

优化权重B

18%

2.0

30%

1.0

**可以看到，优化权重A相对更合理，收益、夏普比率均高于等权重，且样本外表现稳定（未大幅下滑）；权重B虽收益更高，但样本外夏普比率骤降，可能过拟合。**