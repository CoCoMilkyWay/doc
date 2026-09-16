# 用 Python 轻松实现动量策略逻辑

fintechhaibin FinTechHi 2025-04-08 22:52 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247486141&idx=1&sn=1935e30ac57c939a5586d85a8b0699e5&chksm=fb5863fc5ba43f834f59b1f81b2a2806968e3c9034567290acf543aa721f3a0241b4059efaed#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486141&idx=1&sn=1935e30ac57c939a5586d85a8b0699e5&chksm=fb5863fc5ba43f834f59b1f81b2a2806968e3c9034567290acf543aa721f3a0241b4059efaed#rd)

动量投资(Momentum Investing)是一种基于"强者恒强"理念的投资策略，它认为过去表现优异的股票在未来一段时间内仍将保持相对优势。这种策略源于行为金融学中的投资者心理偏差，如反应不足和羊群效应。

动量效应在学术研究中已被广泛证实，最早由Jegadeesh和Titman(1993)提出。他们认为3-12个月的价格动量具有持续性。

在中国A股市场，由于散户占比较高，动量效应可能更为显著。但同时，涨跌停板限制影响动量连续性、政策因素对市场的影响、年报披露期等特殊时点等都可能是影响动量策略的“失真”的事件，需要关注。

## 1.准备工作

配置好Python环境并导入必要的库。

`# 完整导入清单   import numpy as np  # 数值计算基础   import pandas as pd  # 数据处理核心   import akshare as ak  # 财经数据接口   import math  # 数学运算   from scipy import stats  # 统计计算   from statistics import mean  # 平均值计算   import xlsxwriter  # Excel报告生成   `

## 2.获取A股股票列表

使用akshare的`ak.stock_info_a_code_name()`获取全部A股代码和名称，注意处理可能的异常情况(网络问题、数据缺失等)，以及考虑过滤ST/\*ST等特殊股票。

`# 获取A股所有股票列表   try:       stock_list = ak.stock_info_a_code_name()       print(f"共获取到{len(stock_list)}只A股股票")       # 示例输出：共获取到4231只A股股票   except Exception as e:       print(f"获取股票列表失败: {str(e)}")       # 在实际应用中应添加重试逻辑或使用备用数据源   `

**数据预处理**：

1.  检查数据完整性(是否有缺失代码或名称)
    
2.  考虑排除上市不满一年的新股(价格可能不稳定)
    
3.  可以添加行业分类信息用于后续分析
    

## 3.获取股票价格数据

获取准确的历史价格数据是计算动量指标的前提，考虑点如下：

-   时间范围：至少1年数据(计算年化动量)
    
-   异常处理：网络请求失败、数据格式变化等
    
-   性能优化：批量请求、异步获取等(对于全市场扫描)
    

`def get_stock_data(stock_code):       """       获取单只股票历史数据       参数:           stock_code: 股票代码(带市场前缀，如sh600000)       返回:           DataFrame: 包含日期、开盘价、收盘价等数据           None: 获取失败时返回       """       try:           # 获取近一年的日线数据           # adjust参数设置为'hfq'获取后复权价格，更准确反映真实收益           df = ak.stock_zh_a_hist(symbol=stock_code, period="daily",                                   start_date="20230101", end_date="20231231",                                  adjust="hfq")           return df       except Exception as e:           print(f"获取{stock_code}数据失败: {str(e)}")           return None   `

**动量计算逻辑**：

`def calculate_momentum(df):       """       计算各时间段的动量指标       参数:           df: 包含历史价格数据的DataFrame       返回:           dict: 包含各动量指标的计算结果       """       if df isNoneor len(df) < 2:           returnNone              latest_price = df['收盘'].iloc[-1]              # 计算不同时间段的收益率       returns = {           'code': df['代码'].iloc[0],           'name': df['名称'].iloc[0],           'price': latest_price       }              # 1个月收益率(20个交易日)       if len(df) >= 20:           returns['month1_return'] = (latest_price - df['收盘'].iloc[-20]) / df['收盘'].iloc[-20]              # 3个月收益率(60个交易日)       if len(df) >= 60:           returns['month3_return'] = (latest_price - df['收盘'].iloc[-60]) / df['收盘'].iloc[-60]              # 6个月收益率(120个交易日)       if len(df) >= 120:           returns['month6_return'] = (latest_price - df['收盘'].iloc[-120]) / df['收盘'].iloc[-120]              # 1年收益率       returns['year1_return'] = (latest_price - df['收盘'].iloc[0]) / df['收盘'].iloc[0]              return returns   `

## 4.构建动量数据框架

将分散的股票数据整合为结构化表格，便于后续分析和筛选,逻辑如下：

1.  初始化空列表存储各股票数据
    
2.  循环处理每只股票(实际应用中应考虑并行处理)
    
3.  过滤无效数据(None或缺失关键指标)
    
4.  转换为DataFrame并添加衍生指标
    

`# 初始化数据收集器   momentum_data = []      # 示例只处理前100只(实际应用应处理全市场)   for i, row in stock_list.head(100).iterrows():       stock_code = row['code']       print(f"正在处理 {i+1}/{len(stock_list)}: {stock_code} {row['name']}")              # 获取数据并计算动量       df = get_stock_data(stock_code)       stock_momentum = calculate_momentum(df)              # 有效数据才保存       if stock_momentum and all(k in stock_momentum for k in ['month1_return', 'year1_return']):           momentum_data.append(stock_momentum)      # 转换为DataFrame   momentum_df = pd.DataFrame(momentum_data)      # 添加其他有用信息   momentum_df['market'] = momentum_df['code'].apply(lambda x: '沪'if x.startswith('sh') else'深')   `

## 5.计算动量百分位数

百分位数排名可以帮助识别相对强弱，避免绝对阈值带来的问题，比如：

-   市场整体上涨时，绝对收益率可能都高
    
-   百分位数反映股票在同类中的相对位置
    
-   更稳定的比较基准，适应不同市场环境
    

`# 定义分析的时间段   time_periods = ['year1', 'month6', 'month3', 'month1']      for period in time_periods:       col_name = f'{period}_return'       percentile_col = f'{period}_percentile'              # 过滤有效数据       valid_returns = momentum_df[col_name].dropna()              # 计算百分位数(0-1范围)       momentum_df[percentile_col] = momentum_df[col_name].apply(           lambda x: stats.percentileofscore(valid_returns, x)/100if pd.notnull(x) elseNone       )      # 计算综合HQM得分(高质量动量)   momentum_df['hqm_score'] = momentum_df[[f'{period}_percentile'for period in time_periods]].mean(axis=1)      # 清理数据 - 删除含有缺失值的行   momentum_df = momentum_df.dropna(subset=['hqm_score'])      # 添加排名信息   momentum_df['rank'] = momentum_df['hqm_score'].rank(ascending=False)   `

## 6.筛选高动量股票

通过综合评分选出真正的"高质量动量"股票，而不仅仅是短期暴涨的股票，筛选逻辑如下：

1.  按HQM得分降序排序
    
2.  选择前50名(可根据资金规模调整)
    
3.  重置索引便于后续处理
    

`# 选择前50名动量股   top_count = 50   top_momentum = momentum_df.sort_values('hqm_score', ascending=False).head(top_count)      # 重置索引(保持整洁)   top_momentum.reset_index(drop=True, inplace=True)      # 添加选择理由   top_momentum['selection_reason'] = "高质量动量股票"      # 示例输出   print(f"筛选出{len(top_momentum)}只动量股票，HQM得分范围: {top_momentum['hqm_score'].min():.2f}-{top_momentum['hqm_score'].max():.2f}")   `

**筛选后的分析建议**：

1.  检查行业分布(避免过度集中)
    
2.  查看市值分布(大/中/小盘股比例)
    
3.  分析各时间段动量的一致性
    
4.  可以考虑波动率过滤(剔除异常波动股票)
    

## 7.计算确定交易指令

采用等权重分配资金的方式，计算篮子中个股的具体交易指令：确定委托数量，资金分配逻辑如下：

1.  获取用户输入的总投资金额
    
2.  计算每只股票分配金额(总金额/股票数量)
    
3.  根据股价计算应买股数(向下取整)
    
4.  考虑A股交易规则(100股整数倍)
    

`def portfolio_input():       """       获取用户输入的投资金额并进行验证       """       global portfolio_size       whileTrue:           portfolio_size = input("请输入您的投资组合金额(元): ")           try:               val = float(portfolio_size)               if val <= 0:                   print("金额必须大于0")                   continue               return val           except ValueError:               print("请输入有效数字!")      # 获取投资金额   print("=== 投资组合配置 ===")   portfolio_input()      # 计算每只股票分配金额   position_size = float(portfolio_size) / len(top_momentum)   print(f"每只股票分配金额: ¥{position_size:,.2f}")      # 计算购买股数(考虑A股100股整数倍)   top_momentum['shares_to_buy'] = (position_size / top_momentum['price']).apply(       lambda x: math.floor(x/100)*100ifnot pd.isna(x) else0# A股最小100股   )      # 计算实际投资金额   top_momentum['actual_investment'] = top_momentum['shares_to_buy'] * top_momentum['price']      # 显示汇总信息   total_investment = top_momentum['actual_investment'].sum()   cash_remaining = float(portfolio_size) - total_investment   print(f"\n实际总投资: ¥{total_investment:,.2f}")   print(f"剩余现金: ¥{cash_remaining:,.2f} ({cash_remaining/float(portfolio_size):.1%})")   `

## 8.导出Excel报告

专业的报告输出便于存档、分享和后续跟踪，报告设计要点如下：

-   清晰的格式和布局
    
-   合理的数字格式(货币、百分比等)
    
-   视觉强调重要信息
    
-   自动化生成，减少手工操作
    

`# 创建Excel写入器   report_file = 'A股动量策略投资组合.xlsx'   writer = pd.ExcelWriter(report_file, engine='xlsxwriter')      # 写入数据   top_momentum.to_excel(writer, sheet_name='动量组合', index=False)      # 获取工作簿和工作表对象   workbook = writer.book   worksheet = writer.sheets['动量组合']      # 定义专业格式   format_dict = {       'font_name': '微软雅黑',       'border': 1   }      header_format = workbook.add_format({       **format_dict,       'bold': True,       'font_color': '#FFFFFF',       'bg_color': '#1F497D',       'align': 'center',       'valign': 'vcenter'   })      # 数字格式   price_format = workbook.add_format({       **format_dict,       'num_format': '¥#,##0.00',       'align': 'right'   })      percent_format = workbook.add_format({       **format_dict,       'num_format': '0.0%',       'align': 'right'   })      int_format = workbook.add_format({       **format_dict,       'num_format': '#,##0',       'align': 'right'   })      # 设置列宽和格式   columns_config = [       ('代码', 10, header_format),       ('名称', 16, header_format),       ('价格', 12, price_format),       ('分配股数', 12, int_format),       ('1年收益率', 12, percent_format),       ('1年百分位', 12, percent_format),       ('6月收益率', 12, percent_format),       ('6月百分位', 12, percent_format),       ('3月收益率', 12, percent_format),       ('3月百分位', 12, percent_format),       ('1月收益率', 12, percent_format),       ('1月百分位', 12, percent_format),       ('HQM得分', 12, percent_format),       ('实际投资额', 14, price_format)   ]      for idx, (col_name, width, fmt) in enumerate(columns_config):       # 设置列宽       worksheet.set_column(idx, idx, width, fmt)       # 重写标题(中文)       worksheet.write(0, idx, col_name, header_format)      # 添加摘要信息   summary_text = [       f"报告生成日期: {pd.Timestamp.now().strftime('%Y-%m-%d')}",       f"投资组合总金额: ¥{float(portfolio_size):,.2f}",       f"实际投资金额: ¥{total_investment:,.2f}",       f"现金余额: ¥{cash_remaining:,.2f}",       f"包含股票数量: {len(top_momentum)}只"   ]      for row, text in enumerate(summary_text, start=len(top_momentum)+3):       worksheet.write(row, 0, text)      # 保存Excel文件   writer.save()   print(f"\n投资组合报告已生成: {report_file}")   `

## 9.策略执行

有了这样一个策略，大概需要做的事情包括：

-   调仓频率：建议每季度调整一次
    
-   资金管理：保留5-10%现金应对补仓机会
    
-   风险控制：设置7-10%的止损位
    
-   组合监控：定期检查行业分布和相关性
    
-   不断优化：通过实际运行的分析，可结合基本面过滤(如ROE、营收增长等)、添加波动率调整(避免高风险股票)、考虑市场状态(牛市/熊市不同参数)、加入交易量筛选(确保流动性)等方面调整和优化策略。
    

通过这个完整的A股动量策略实现，可以获得一个系统化的投资方法。该策略结合了A股市场特点给出了一个实现思路，在实际应用中可根据按个人目标做出适当调整。

  

* * *

  

文末彩蛋：

![](assets/001.png)

  

川大爷曰：China also wants to make a deal, badly, but they don’t know how to get it started. We are waiting for their call. 

  

![](assets/002.jpg)

![](assets/003.jpg)

![](assets/004.png)