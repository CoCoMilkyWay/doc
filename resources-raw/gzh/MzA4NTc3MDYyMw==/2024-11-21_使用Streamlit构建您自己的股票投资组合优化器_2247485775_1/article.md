# 使用Streamlit构建您自己的股票投资组合优化器Web应用程序

InfinityQuant 映翡量化 2024-11-21 23:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247485775&idx=1&sn=2ea9c80273c7d1e82058dbfbcb6c43de&chksm=9ed3f7f5613f37bf5ffedfa4ab6da1cf661598c52accfbf0e4e70ee90364fa0473936e38bd3e#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247485775&idx=1&sn=2ea9c80273c7d1e82058dbfbcb6c43de&chksm=9ed3f7f5613f37bf5ffedfa4ab6da1cf661598c52accfbf0e4e70ee90364fa0473936e38bd3e#rd)

使用Streamlit从用户的输入股票代码中构建一个投资组合优化器Web应用程序,同时可以显示其性能。

![](assets/001.png)

![](assets/002.png)

![](assets/003.png)

![](assets/004.png)

# 1.库函数‍‍‍‍

首先，需要创建一个app.py文件，并添加到导入中。在这样做之前，请为PyPortfolioOpt库进行pip安装：pip install PyPortfolioOpt库用于处理股票数据或在Web应用程序上显示数据。例如，pandas\_datareader库提取股价数据；PyPortfolioOpt库（导入为pypfopt）优化股票投资组合并执行数据可视化；Plotly创建交互式图表以放入我们的应用程序中。

```

```

```

```

# 2.用户输入

代码的下一部分设置用户输入字段。允许用户输入投资组合中要包含的股票代码列表，以及分析投资组合的开始和结束日期。

![](assets/005.png)

开始日期和结束日期的输入字段分为2列，默认开始日期为2013/01/01（随意更改），默认结束日期为当前日期。这些分别存储在变量start\_date和end\_date。用户输入一串用逗号分隔的股票代码，然后将其存储在tickers\_string中并将其拆分为tickers列表。

```

```

# 3.错误处理

代码的下一部分是try, except处理错误的循环。如果用户输入了错误的股票代码符号，或以错误的格式输入符号（不用逗号等分隔），则try循环中的代码将不会运行。最不希望的就是在页面上显示一大块python错误输出。

```
except:
```

相反，显示一个漂亮的小提示，让用户以正确的格式输入正确的股票代码。这是在下面的except循环中完成的，如果在try循环的任何部分遇到错误，则运行该循环。

# 4.获取股价并生成信息图‍‍

该应用程序的主要功能在try循环中。首先，我们获取股价，并生成信息图，以显示单个股票的表现。

```
# Get Stock Prices using pandas_datareader Library  
```

-   代码的第2行使用pandas\_datareader库从网络上方便地获取相关股价。
    
-   第4行负责绘制每只股票的价格与时间。
    
-   第6行绘制了每只股票的累计回报，这提供了随着时间的推移对股票之间的公平比较。
    
-   然后，第8行和第9行计算并绘制所有股票之间的相关矩阵。
    

# 5.优化投资组合

这就是PyPortfolioOpt库的魔力。下一段代码优化投资组合，获得每个组成股票的权重，并在图表上可视化其风险和回报。足以知道优化的投资组合是将预期回报与风险比率最大化的投资组合。

```
# Calculate expected returns and sample covariance matrix for portfolio optimization later
```

代码第2行计算了每只股票的平均年回报率，而第3行计算了股票的协方差矩阵。不要太担心数学，这2个变量只是作为以后投资组合优化函数的输入所需要的。

与其他随机生成的投资组合相比，第6行生成沿着高效的边界曲线绘制和可视化我们投资组合的风险和回报。

第7行和第8行将上面的图块保存为png图像，供Web应用程序稍后显示。

第11行和第12行展示了使用PyPortfolioOpt api找到优化的投资组合是多么容易。 只需创建一个EfficientFrontier对象，并应用max\_sharpe方法来找到具有最佳风险回报率的投资组合。 我们还通过了无风险利率，这对应于我们可以在没有任何风险的情况下获得的回报率。 我们通常使用国债收益率，目前约为2%。 请查看PyPortfolioOpt文档中的其他优化方法。

第13行至第16行允许我们提取单个股票的权重并将其存储在数据框架中，以及投资组合表现的衡量标准，如平均年回报、波动率和夏普比率。

# 6.生成优化的投资组合

既然有了投资组合权重，将每个权重与其相应的股价相乘，并将优化的投资组合作为附加列存储在之前创建的股价数据框架中。这给了投资组合在这段时间内的历史表现。这是在以下代码的第2行至第4行完成的。

```
# Calculate returns of portfolio with optimized weights
```

如果我们一开始就投资了100美元，第7行会随着时间的推移，优化投资组合的回报表现。

7.在Streamlit上显示所有内容

在这里，我们将所有图和信息显示到Web应用程序中。下面的代码几乎是不言自明的。然而，我们反过来做，因为用户可能希望先看到最终结果（即优化的投资组合回报和权重），然后再深入研究其他细节（股票之间的相关性和每只股票的表现）。

```
# Display everything on Streamlit
```

测试Streamlit应用程序

只需使用app.py文件，您就可以在终端（相关文件夹中）中运行此命令，在浏览器上本地启动Streamlit应用程序。

```
streamlit run app.py
```

  

https://medium.datadriveninvestor.com/build-your-own-stock-portfolio-optimizer-web-app-with-streamlit-be8654ef8c65