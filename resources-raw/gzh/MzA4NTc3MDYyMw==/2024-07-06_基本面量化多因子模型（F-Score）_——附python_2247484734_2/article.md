# 基本面量化多因子模型（F-Score） ——附python代码

小燕子 映翡量化 2024-07-06 22:01 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484734&idx=2&sn=57b72db05c2a8c78a3c177fc0a7b4bb4&chksm=9e403a84fd0adfcb3058d5fb2471f1d6d09d8d144a83a67d5a8d484a89edfc872f352f31aa1b#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484734&idx=2&sn=57b72db05c2a8c78a3c177fc0a7b4bb4&chksm=9e403a84fd0adfcb3058d5fb2471f1d6d09d8d144a83a67d5a8d484a89edfc872f352f31aa1b#rd)

Piotroski F-Score是一种量化多因子选股模型，最早出现在Piotroski于2000年所著的论文《Value Investing: The Use of Historical Financial Statement Information to Separate Winners from Losers》中，此文研究了一个简单的基于会计的基本面分析策略，当应用于一个广泛的高账面市值比公司的投资组合时，是否可以改变投资者的收益分配。  

  

该方法通过9个标准来考察公司的财务状况，每满足一个标准得1分，9项得分加总后得到一个复合得分指标F-Score，通过对比不同公司的F-Score筛选出投资价值比较高的公司。这9个标准具体是：  

-   正的资产回报率（Positive return on assets）
    
-   正的资产回报率同比增长率（Higher return on assets than the previous year）
    
-   正的经营性现金流（Positive cash flow from operations）
    
-   经营性现金流大于净利润（Operating cash flows greater than net income）
    
-   负的杠杆率同比增长率（Lower leverage than the previous year）
    
-   正的流动比率同比增长率（Higher current ratio than previous year）
    
-   相比前一年度更低的股票稀释（Less stock dilution than the previous year）
    
-   正的毛利率同比增长率（Higher gross margin than the previous year）
    
-   正的资产周转率同比增长率（Higher asset turnover than the previous year）
    

  

以上9个标准中，第1-4条评价了公司的盈利能力和现金流量情况，第5-7条显示了公司的长期借债情况（资本结构）和短期偿债能力（流动性），第8-9条则是对公司运营能力的衡量标准。

  

以下来一个代码实现：灵感来自一篇文章https://t.co/WhjHqDqIf5。

分析了200只股票的六年财务数据，以确定表现最好的股票。

下面描述项目的详细步骤，突出关键代码。

**1.获取6年内200只股票的历史价格和财务数据，间隔为1个月**

  

首先，收集200只股票的历史价格和财务数据，历时六年，每月间隔一次。这些数据构成了分析的基础。

\# 1. Get Historical Data of 200 stocks  
import yfinance as yf  
import pandas as pd  
  
def get\_historical\_data(tickers, time\_loop\_back='4y', interval='1mo'):  
    """  
    Retrieve historical price data and financial data for a list of tickers.  
  
    Parameters:  
    tickers (list): List of ticker symbols.  
    time\_loop\_back (str): Period to look back for historical data (default is '4y').  
    interval (str): Interval for historical data (default is '1mo').  
  
    Returns:  
    tuple: A tuple containing two dictionaries:  
        - price\_data: Dictionary with historical price data for each ticker.  
        - financial\_data: Dictionary with financial data (financials, cashflow, balance\_sheet) for each ticker.  
    """  
    import yfinance as yf  
    import pandas as pd  
  
    \# Create a dictionary to store historical data  
    price\_data = {}  
  
    \# Create a dictionary to store financial data (Financials, Cashflow, and Balance Sheet)  
    financial\_data = {}  
  
    \# Create a list to store tickers for which data is not available  
    unavailable\_tickers = \[\]  
  
    \# Retrieve data for each ticker  
    for ticker in tickers:  
        \# Get stock data  
        stock = yf.Ticker(ticker)  
          
        \# Get Historical Price Data  
        hist = stock.history(period=time\_loop\_back, interval=interval)  
        price\_data\[ticker\] = hist  
  
        \# Get historical Financials Data, Cashflow Data, and Balance Sheet Data  
        financials = stock.financials  
        cashflow = stock.cashflow  
        balance\_sheet = stock.balance\_sheet  
  
        \# If no data is returned, add the ticker to the list of unavailable tickers  
        if hist.empty:  
            unavailable\_tickers.append(ticker)  
            continue  
  
        \# handle not matching data   
        if financials.shape\[1\] != cashflow.shape\[1\] or financials.shape\[1\]!= balance\_sheet.shape\[1\]:  
            \# find the minimum shape among financials, cashflow, and balance sheet  
            min\_shape = min(financials.shape\[1\], cashflow.shape\[1\], balance\_sheet.shape\[1\])  
            \# trim the data to match the minimum shape  
            financials = financials.iloc\[:, :min\_shape\]  
            cashflow = cashflow.iloc\[:, :min\_shape\]  
            balance\_sheet = balance\_sheet.iloc\[:, :min\_shape\]  
  
        financial\_data\[ticker\] = {  
            'financials': financials,  
            'cashflow': cashflow,  
            'balance\_sheet': balance\_sheet  
        }  
  
        print('Got data for', ticker)  
      
    \# print the tickers for which data is not available  
    if unavailable\_tickers:  
        print('Data not available for:', unavailable\_tickers)  
  
    return price\_data, financial\_data

  

**2\. 计算 Piotroski F 分数的函数**

  

定义了一个函数来计算每只股票的 Piotroski F 分数。该分数根据盈利能力、杠杆率和运营效率等各种标准评估公司的财务健康状况。

def calculate\_piotroski\_f\_score(financials, cashflow, balance\_sheet):  
    """  
    Calculate the Piotroski F-Score for a given company's financial data.  
  
    Parameters:  
    financials (pd.DataFrame): The financials data.  
    cashflow (pd.DataFrame): The cashflow data.  
    balance\_sheet (pd.DataFrame): The balance sheet data.  
  
    Returns:  
    pd.Series: The Piotroski F-Score for each period.  
    """  
      
    \# 1. Positive net income  
    positive\_net\_income = financials.loc\['Net Income'\] > 0   
  
    \# 2. Positive operating cash flow  
    positive\_operating\_cashflow = cashflow.loc\['Operating Cash Flow'\] > 0  
  
    \# 3. Positive return on assets (ROA)  
    net\_income = financials.loc\['Net Income'\]  
    total\_assets = balance\_sheet.loc\['Total Assets'\]  
    average\_assets = (total\_assets + total\_assets.shift(1)) / 2  
    return\_on\_assets = net\_income / average\_assets  
    positive\_roa = return\_on\_assets > 0  
  
    \# 4. Operating cash flow > Net income (đồng bộ nhãn trước khi so sánh)  
    net\_income\_aligned = net\_income.reindex(cashflow.columns)  
    operating\_cash\_flow\_greater\_than\_net\_income = cashflow.loc\['Operating Cash Flow'\] > net\_income\_aligned  
  
    \# 5. Increasing ROA  
    increasing\_roa = return\_on\_assets.diff() > 0  
  
    \# 6. Positive change in long-term debt ratio  
    long\_term\_debt = balance\_sheet.loc\['Long Term Debt'\]  
    previous\_long\_term\_debt = long\_term\_debt.shift(1)  
    positive\_change\_long\_term\_debt\_ratio = (long\_term\_debt < previous\_long\_term\_debt)  
  
    \# 7. Increasing current ratio  
    \# current\_assets = balance\_sheet.loc\['Total Current Assets'\]  
    current\_assets = balance\_sheet.loc\['Current Assets'\]  
    \# current\_liabilities = balance\_sheet.loc\['Total Current Liabilities'\]  
    current\_liabilities = balance\_sheet.loc\['Current Liabilities'\]  
    previous\_current\_assets = current\_assets.shift(1)  
    previous\_current\_liabilities = current\_liabilities.shift(1)  
    increasing\_current\_ratio = (current\_assets / current\_liabilities) > (previous\_current\_assets / previous\_current\_liabilities)  
  
    \# 8. No new shares issued  
    new\_shares\_issued = balance\_sheet.loc\['Issuance of Capital Stock', :\] if 'Issuance of Capital Stock' in balance\_sheet.index else pd.Series(\[0\]\*len(balance\_sheet.columns), index=balance\_sheet.columns)  
    no\_new\_shares\_issued = new\_shares\_issued == 0  
  
    \# 9. Higher gross margin  
    gross\_margin = (financials.loc\['Gross Profit'\] / financials.loc\['Total Revenue'\])  
    previous\_gross\_margin = gross\_margin.shift(1)  
    higher\_gross\_margin = gross\_margin > previous\_gross\_margin  
  
    \# Calculate Piotroski F-Score  
    piotroski\_f\_score = positive\_net\_income.astype(int) + positive\_operating\_cashflow.astype(int) + positive\_roa.astype(int) + operating\_cash\_flow\_greater\_than\_net\_income.astype(int) + increasing\_roa.astype(int) + positive\_change\_long\_term\_debt\_ratio.astype(int) + increasing\_current\_ratio.astype(int) + no\_new\_shares\_issued.astype(int) + higher\_gross\_margin.astype(int)  
  
    \# drop NaN values  
    piotroski\_f\_score = piotroski\_f\_score.dropna()  
  
    return piotroski\_f\_score  

  

**3\. 创建包含所有股票的 Piotroski F 分数的 DataFrame**

  

创建一个 DataFrame 来存储所有 200 只股票的 Piotroski F 分数。这使我们能够轻松访问和分析分数以及其他财务数据。

def create\_piotroski\_f\_score\_dataframe(tickers, financial\_data):  
    """  
    Create a DataFrame containing the Piotroski F-Score for all given tickers.  
  
    Parameters:  
    tickers (list): List of ticker symbols.  
    financial\_data (dict): Dictionary containing financial data for each ticker.  
  
    Returns:  
    pd.DataFrame: DataFrame containing the Piotroski F-Score for each ticker.  
    """  
  
    \# Create a dictionary to store Piotroski F-Scores  
    piotroski\_f\_scores = {}  
  
    \# Calculate Piotroski F-Score for each ticker  
    for ticker in tickers:  
        financials = financial\_data\[ticker\]\['financials'\]  
        cashflow = financial\_data\[ticker\]\['cashflow'\]  
        balance\_sheet = financial\_data\[ticker\]\['balance\_sheet'\]  
          
        piotroski\_f\_score = calculate\_piotroski\_f\_score(financials, cashflow, balance\_sheet)  
        piotroski\_f\_scores\[ticker\] = piotroski\_f\_score  
  
    \# Convert the dictionary to a DataFrame  
    piotroski\_f\_score\_df = pd.DataFrame(piotroski\_f\_scores)  
  
    return piotroski\_f\_score\_df

  

**4.创建 DataFrame 来存储每年每只股票的利润和亏损**

  

根据历史价格数据计算每只股票的年度利润和亏损。这一步对于评估每只股票的长期表现至关重要。

\# ignore the warning  
import warnings  
warnings.filterwarnings('ignore')  
  
\# use with price\_data  
\# only keep row month = 1 of each year  
price\_data\_month\_1 = {}  
for ticker in tickers:  
    price\_data\_month\_1\[ticker\] = price\_data\[ticker\]\[price\_data\[ticker\].index.month == 1\]  
  
\# rewrite index to keep only year  
for ticker in tickers:  
    price\_data\_month\_1\[ticker\].index = price\_data\_month\_1\[ticker\].index.year  
  
\# loop through each ticker to calculate the return of price\_data\_month\_1  
for ticker in tickers:  
    price\_data\_month\_1\[ticker\]\['Return\_next\_1\_year'\] = price\_data\_month\_1\[ticker\]\['Close'\].pct\_change()  
  
\# display(price\_data\_month\_1\['AAPL'\].head())  
  
\# shift the return\_next\_1\_year +2  
for ticker in tickers:  
    price\_data\_month\_1\[ticker\]\['Return\_next\_1\_year'\] = price\_data\_month\_1\[ticker\]\['Return\_next\_1\_year'\].shift(-2)  
  
\# drop 1st & last row ( only keep data corresponding with DataFrame of top 10 stocks with Piotroski F-Score)  
for ticker in tickers:  
    price\_data\_month\_1\[ticker\] = price\_data\_month\_1\[ticker\].iloc\[1:-2\]  
  
\# display shape of price\_data\_month\_1  
display(price\_data\_month\_1\['AAPL'\].head())  
display(price\_data\_month\_1\['AMZN'\].head())

  

**5\. DataFrame 回测策略**

  

为了测试策略，建立一个回测框架。这涉及根据预定义规则模拟交易，并通过累计回报和夏普比率等指标衡量我们策略的表现。

def calculate\_returns\_of\_strategy(df\_top\_10, price\_data, n\_top\_stocks):  
    df\_backtest = df\_top\_10.copy()  
  
    \# map return of each stock to the DataFrame of top 10 stocks  
    for index, row in df\_top\_10.iterrows():  
        \# get the year  
        year = index.year  
        \# loop through the top 10 stocks  
        for i in range(1, n\_top\_stocks+1):  
            \# get the ticker  
            ticker = row\[f'Top\_{i}\_Stock'\]  
            \# get the return of the stock in the next year  
            return\_next\_1\_year = price\_data\[ticker\].loc\[year, 'Return\_next\_1\_year'\]  
            \# update the DataFrame  
            df\_backtest.at\[index, f'Top\_{i}\_Return'\] = return\_next\_1\_year  
  
    \# calculate the average return of the top 10 stocks  
    df\_backtest\['Average\_Return'\] = df\_backtest\[\[f'Top\_{i}\_Return' for i in range(1, n\_top\_stocks+1)\]\].mean(axis=1)  
  
    \# calculate the cumulative return  
    df\_backtest\['Cumulative\_Return'\] = (1 + df\_backtest\['Average\_Return'\]).cumprod()  
  
    \# print final cumulative return  
    print('\*'\*50)  
    print('Pick the top', n\_top\_stocks, 'stocks based on Piotroski F-Score')  
    print('Final Cumulative Return:', df\_backtest\['Cumulative\_Return'\].iloc\[-1\] \* 100 - 100, '%')  
    print('\*'\*50)  
  
    \# metrics  
    metrics= {  
        'Cumulative\_Return\_%': df\_backtest\['Cumulative\_Return'\].iloc\[-1\] \* 100 - 100,  
        'Average\_Return\_%': df\_backtest\['Average\_Return'\].mean() \* 100,  
        'Standard\_Deviation\_%': df\_backtest\['Average\_Return'\].std() \* 100,  
        'Sharpe\_Ratio': df\_backtest\['Average\_Return'\].mean() / df\_backtest\['Average\_Return'\].std()  
    }  
  
    return df\_backtest, metrics

df\_backtest,metrics = calculate\_returns\_of\_strategy(df\_top\_10\_piostroski\_f\_score, price\_data\_month\_1, n\_top\_stocks)  
display(metrics)  
  
\# define the range of top stocks  
range\_of\_n\_top\_stocks = range(1, 11)  
  
\# run the backtest for each range of top stocks  
results = \[\]  
for \_ in range\_of\_n\_top\_stocks:  
    temp\_df\_backtest, temp\_metrics = calculate\_returns\_of\_strategy(df\_top\_10\_piostroski\_f\_score, price\_data\_month\_1, \_)  
    results.append(temp\_metrics)  
  
\# create a DataFrame from the results  
df\_results = pd.DataFrame(results, index=range\_of\_n\_top\_stocks)  
  
\# create columns containing the range of top stocks  
df\_results\['Pick\_Top\_Stocks'\] = df\_results.index  
  
\# sort the DataFrame by Sharpe Ratio  
df\_results = df\_results.sort\_values(by='Sharpe\_Ratio', ascending=False)  
  
\# put the 'Pick\_Top\_Stocks' column in the first position  
cols = df\_results.columns.tolist()  
cols = cols\[-1:\] + cols\[:-1\]  
df\_results = df\_results\[cols\]  
  
\# display the results  
display(df\_results)  
  
import matplotlib.pyplot as plt  
import seaborn as sns  
  
\# plot the results ( cumulative return with number of top stocks)  
plt.figure(figsize=(12, 6))  
sns.lineplot(data=df\_results, x='Pick\_Top\_Stocks', y='Cumulative\_Return\_%', marker='o')  
plt.title('Cumulative Return vs Number of Top Stocks')  
plt.xlabel('Number of Top Stocks')  
plt.ylabel('Cumulative Return (%)')  
plt.grid(True)  
plt.show()  
  
  
\# plot the results ( sharpe ratio with number of top stocks)  
plt.figure(figsize=(12, 6))  
sns.lineplot(data=df\_results, x='Pick\_Top\_Stocks', y='Sharpe\_Ratio', marker='o')  
plt.title('Sharpe Ratio vs Number of Top Stocks')  
plt.xlabel('Number of Top Stocks')  
plt.ylabel('Sharpe Ratio')  
plt.grid(True)  
plt.show()

![](assets/001.jpg)

![](assets/002.jpg)

![](assets/003.jpg)

6.局限性

  

•**缺失数据**：由于数据缺失，处理后股票数量从200 只减少到约100 只。  

•**日期选择**：所选的后续发布日期是次年1月，可能与某些股票的官方财务报告发布日期不完全一致。

•**适用性**：研究表明，Piotroski F-Score 对中小型公司更有效。但由于数据限制，本分析中的股票类型多样，可能会降低策略的有效性。

•**成本排除**：该分析未考虑交易成本和其他相关费用。

**7.结论**

  

项目展示了基于 Piotroski F-score的股票选择策略的实施。通过分析历史数据、计算财务健康指标和对我们的策略进行回测。无论您是经验丰富的投资者还是好奇的学习者，都可以尝试一下。

  

-   **原始研究论文：**https://t.co/WhjHqDqIf5。
-   **Github 代码**：https://t.co/QtgdzS5q0O。

原始论文的核心思想：

  

这篇文章《An Emerging Markets Analysis of the Piotroski F Score》由Charles Hyde撰写，发表于2013年3月28日，主要探讨了Piotroski F -score在全球新兴市场中的应用和效果。以下是文章的核心思想概述：  
  
1\. \*\*F-score的背景与重要性\*\*：  
  - F-score是由Piotroski在2000年开发的一种财务分析工具，用以区分高回报和低回报的股票。  
  - 新兴市场在全球股市中的重要性日益增加，预计到2030年将占全球市值的30%以上。  
  
2\. \*\*F-score的定义与计算\*\*：  
  - F分数由九个财务指标组成，每个指标根据其对公司财务状况的积极影响赋予1分或0分，总分范围从0到9。  
  - 这些指标包括盈利能力、盈利增长、现金流、利润率增长、资产周转率增长、财务杠杆减少、财务流动性增加等。

  
  
3\. \*\*F-score在新兴市场的表现\*\*：  
  - 高F-score的股票在新兴市场中表现出显著的超额回报，这一回报与市值、价值和动量溢价无关。  
  - 该溢价在高价值股票中更大，在高动量股票中适度更高，与股票规模无关。  
  
4\. \*\*市场效率与信息传播\*\*：  
  - 新兴市场相比于发达市场，在信息效率方面可能较低，这可能导致F-score在新兴市场中的预测能力更强。  
  - 文章提出，F-score的有效性可能受到市场对新信息反应速度的影响，即市场对高F-score股票的忽视。  
  
5\. \*\*确认偏误（Confirmation Bias）\*\*：  
  - 作者提出确认偏误可能是影响高F-score股票溢价的另一个因素。这指的是投资者和分析师可能只关注那些符合他们预期的信息，从而对好消息反应过度。  
  
6\. \*\*实证分析\*\*：  
  - 研究使用了2000年1月至2011年12月的数据，涵盖了MSCI新兴市场指数的组成股票。  
  - 实证结果表明，高F-score股票相对于低F-score股票在6个月和12个月的持有期内都有显著的超额回报。  
  
7\. \*\*溢价的稳健性\*\*：  
  - 高F-score股票的溢价在不同国家/地区和不同年份都相对稳健，除了巴西市场表现出与预期相反的结果。  
  
8\. \*\*策略建议\*\*：  
  - 文章建议将Piotroski F-score纳入价值和/或动量投资策略中，尤其是在新兴市场。  
  
9\. \*\*进一步研究\*\*：  
  - 尽管文章提供了对F-score有效性的有力证据，但仍有一些问题需要进一步研究，例如为什么低价值/低动量股票的溢价高于其他组合，以及确认偏误在发达市场中的作用。