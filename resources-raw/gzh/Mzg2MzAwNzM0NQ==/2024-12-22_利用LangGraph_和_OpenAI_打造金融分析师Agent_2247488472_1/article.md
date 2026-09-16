# 利用LangGraph 和 OpenAI 打造金融分析师Agent

QuantML QuantML 2024-12-22 21:29 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247488472&idx=1&sn=6cecc6526303edde77b934ebce979495&chksm=cf96a0f38c887a94f3695a76de326e8d0ce63c3cce575df5f19c4b1f565949215560fdcee4d7#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247488472&idx=1&sn=6cecc6526303edde77b934ebce979495&chksm=cf96a0f38c887a94f3695a76de326e8d0ce63c3cce575df5f19c4b1f565949215560fdcee4d7#rd)

### 引言

在股票交易的世界中，投资者依赖各种工具和方法来做出明智的决策。基本面分析是一种常见的方法，它通过评估公司的财务健康状况和股票表现来提供可操作的见解。随着人工智能和机器学习的进步，股票分析现在可以高度自动化。在这篇文章中，我们将探索如何使用 LangChain、LangGraph 和 Yahoo Finance 来创建一个股票表现分析Agent，充分利用实时股票数据和关键的技术指标。

无论你是金融爱好者、开发者还是数据科学家，这篇逐步教程都将帮助你创建自己的智能代理。让我们深入了解！

### 这个具有自主性的金融分析师Agent将做什么？

-   **使用 Yahoo Finance 获取股票价格数据**。
    
-   **计算技术指标，如 RSI、MACD、VWAP 等**。
    
-   **评估财务指标，如市盈率、债务股本比率和利润率**。
    
-   **利用 OpenAI 强大的语言模型提供结构化的、基于 AI 的分析**。
    

### 我们将使用的工具

1.  **LangGraph**：一个用于编排工具和构建对话代理的库。
    
2.  **OpenAI GPT-4**：用于生成智能且结构化的金融见解。
    
3.  **yfinance**：用于检索股票价格和财务比率。
    
4.  **ta（技术分析库）**：用于计算关键的技术指标。
    
5.  **Python 库**：pandas、dotenv 和 datetime 用于数据操作和环境设置。
    

### 第一步：设置环境

首先，安装所需的库：

```
pip install -U langgraph langchain langchain_openai pandas ta python-dotenv yfinance
```

设置一个 `.env` 文件以安全地存储你的 OpenAI API 密钥：

```
OPENAI_API_KEY=your_openai_api_key
```

### 第二步：为分析师准备工具

### 获取股票价格

这个工具获取股票的历史数据并计算几个技术指标。

```
from typing import Union, Dict, Set, List, TypedDict, Annotatedimport pandas as pdfrom langchain_core.tools import toolimport yfinance as yffrom ta.momentum import RSIIndicator, StochasticOscillatorfrom ta.trend import SMAIndicator, EMAIndicator, MACDfrom ta.volume import volume_weighted_average_priceimport datetime as dt@tooldef get_stock_prices(ticker: str) -> Union[Dict, str]:    """    获取给定股票的历史价格数据和所有技术指标。    """    try:        data = yf.download(            ticker,            start=dt.datetime.now() - dt.timedelta(weeks=24*3),            end=dt.datetime.now(),            interval='1wk'        )        df = data.copy()        data.reset_index(inplace=True)        data.Date = data.Date.astype(str)        indicators = {}        rsi_series = RSIIndicator(df['Close'], window=14).rsi().iloc[-12:]        indicators["RSI"] = {date.strftime('%Y-%m-%d'): int(value) for date, value in rsi_series.dropna().to_dict().items()}        sto_series = StochasticOscillator(df['High'], df['Low'], df['Close'], window=14).stoch().iloc[-12:]        indicators["Stochastic_Oscillator"] = {date.strftime('%Y-%m-%d'): int(value) for date, value in sto_series.dropna().to_dict().items()}        macd = MACD(df['Close'])        macd_series = macd.macd().iloc[-12:]        indicators["MACD"] = {date.strftime('%Y-%m-%d'): int(value) for date, value in macd_series.to_dict().items()}        macd_signal_series = macd.macd_signal().iloc[-12:]        indicators["MACD_Signal"] = {date.strftime('%Y-%m-%d'): int(value) for date, value in macd_signal_series.to_dict().items()}        vwap_series = volume_weighted_average_price(            high=df['High'],            low=df['Low'],            close=df['Close'],            volume=df['Volume'],        ).iloc[-12:]        indicators["vwap"] = {date.strftime('%Y-%m-%d'): int(value) for date, value in vwap_series.to_dict().items()}        return {'stock_price': data.to_dict(orient='records'), 'indicators': indicators}    except Exception as e:        return f"Error fetching price data: {str(e)}"
```

### 获取财务指标

这个工具获取关键的财务健康比率。

```
@tooldef get_financial_metrics(ticker: str) -> Union[Dict, str]:    """    获取给定股票的关键财务比率。    """    try:        stock = yf.Ticker(ticker)        info = stock.info        return {            'pe_ratio': info.get('forwardPE'),            'price_to_book': info.get('priceToBook'),            'debt_to_equity': info.get('debtToEquity'),            'profit_margins': info.get('profitMargins')        }    except Exception as e:        return f"Error fetching ratios: {str(e)}"
```

### 第三步：构建 LangGraph

LangGraph 允许我们高效地编排工具和管理对话逻辑。

### 1\. 定义图

我们首先定义一个 StateGraph 来管理流程：

```
from langgraph.graph import StateGraph, START, ENDfrom langchain_core.messages import SystemMessagefrom langchain_core.messages import HumanMessagefrom langchain_core.messages import AIMessageclass State(TypedDict):    messages: List    stock: strgraph_builder = StateGraph(State)
```

### 2\. 定义 OpenAI 并绑定工具

我们将工具集成到 LangGraph 中，并创建一个反馈循环进行分析。

```
import dotenvdotenv.load_dotenv()from langchain_openai import ChatOpenAIllm = ChatOpenAI(model='gpt-4')tools = [get_stock_prices, get_financial_metrics]llm_with_tools = llm.bind_tools(tools)
```

### 3\. 分析师节点

提示确保 AI 理解其角色并提供结构化的输出。

```
FUNDAMENTAL_ANALYST_PROMPT = """ 你是一个专门评估公司（其股票代码为 {company}）的基本面分析师。你有权使用以下工具：Medium Q Search### 你的任务：1. ** 输入股票代码 **：使用提供的股票代码查询工具并获取数据。2. ** 分析数据 **：评估工具返回的结果，并识别潜在的趋势。3. ** 提供总结 **：编写一个简洁、结构良好的总结，突出以下内容：- 近期股票价格走势、趋势和潜在阻力位。- 技术指标的关键见解（例如，股票是否超买或超卖）。- 基于财务指标的财务健康状况和表现。### 限制：- 仅使用工具提供的数据。- 避免使用推测性语言；专注于可观察的数据和趋势。- 如果任何工具未能提供数据，请在总结中明确说明。### 输出格式：以以下格式回复：“stock”: “<股票代码>”,“price_analysis”: “<股票价格趋势的详细分析>”,“technical_analysis”: “<所有技术指标的详细时间序列分析>”,“financial_analysis”: “<财务指标的详细分析>”,“final Summary”: “<基于上述分析的完整结论>”请确保你的回答客观、简洁且具有可操作性。"""def fundamental_analyst(state: State):    messages = [        SystemMessage(content=FUNDAMENTAL_ANALYST_PROMPT.format(company=state['stock'])),        HumanMessage(content="请分析这个股票。")    ] + state['messages']    return {'messages': llm_with_tools.invoke(messages)}
```

### 4\. 将工具添加到图中并编译

```
graph_builder.add_node('fundamental_analyst', fundamental_analyst)graph_builder.add_edge(START, 'fundamental_analyst')graph_builder.add_node(ToolNode(tools))graph_builder.add_conditional_edges('fundamental_analyst', tools_condition)graph_builder.add_edge('tools', 'fundamental_analyst')graph = graph_builder.compile()
```

### 5\. 执行图

```
events = graph.stream({'messages': [('user', '我应该购买这只股票吗?')], 'stock': 'TSLA'}, stream_mode='values')for event in events:    if 'messages' in event:        event['messages'][-1].pretty_print()
```

### 示例输出

```
{  "stock": "TSLA",  "price_analysis": "TSLA 的近期股票价格显示出波动性，...",  "technical_analysis": "技术指标呈现出混合的前景。RSI 指标显示超买状态，...",  "financial_analysis": "TSLA 的财务指标表明估值较高，...",  "final Summary": "总之，TSLA 显示出强劲的近期价格恢复潜力，但也有高估值和超买指标，...",  "Asked Question Answer": "鉴于当前的超买指标和高估值，..."}
```

  

  

  

完整代码见星球：![](assets/001.png)