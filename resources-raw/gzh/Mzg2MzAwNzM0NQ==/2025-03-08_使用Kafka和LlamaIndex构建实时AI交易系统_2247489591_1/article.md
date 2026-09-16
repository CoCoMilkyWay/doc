# 使用Kafka和LlamaIndex构建实时AI交易系统

QuantML QuantML 2025-03-08 19:09 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489591&idx=1&sn=826b61575f73a603435c052519d688ef&chksm=cf2d4ab68825268795c03aca5ded7198bb39db4ea3b69df15f1fd7bced0f90f56c6d28d91e58#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489591&idx=1&sn=826b61575f73a603435c052519d688ef&chksm=cf2d4ab68825268795c03aca5ded7198bb39db4ea3b69df15f1fd7bced0f90f56c6d28d91e58#rd)

### 

在当今瞬息万变的金融市场中，自动化交易系统正成为不可或缺的工具。利用人工智能（AI）和机器学习（ML）技术，交易者可以更高效地分析和预测市场趋势，从而做出更明智的决策。本教程将展示如何构建一个基于AI的实时交易系统，通过整合Kafka和LlamaIndex，实现对EUR/USD货币对的实时数据处理和智能决策。

我们将使用Kafka进行实时数据流处理，捕捉EUR/USD的买卖价格；LlamaIndex将协调各个处理步骤，确保数据流和逻辑的顺畅衔接；GPT-4将分析每日EUR/USD图表，提供市场趋势的初步见解；GPT-3.5则整合所有信息，做出买入、卖出或持有的决策。

### 1) 抓取每日EUR/USD图表

我们首先使用Selenium下载每日EUR/USD图像图表，Selenium通常用于网络抓取。这个图像将由GPT-4进行分析，从而为我们的交易机器人提供初步见解。

#### 代码解释

-   **初始化Web驱动程序**：设置并返回一个配置好的Chrome WebDriver实例。
    
    `from selenium import webdriver   from selenium.webdriver.common.by import By   from selenium.webdriver.support.ui import WebDriverWait   from selenium.webdriver.support import expected_conditions as EC   import time      def initialize_web_driver():       """设置并返回一个配置的Chrome WebDriver实例。"""       options = webdriver.ChromeOptions()       options.add_argument('--verbose')       options.add_argument('--no-sandbox')       options.add_argument('--headless')       options.add_argument('--disable-gpu')       options.add_argument('--window-size=1920,1200')       options.add_argument('--disable-dev-shm-usage')       driver = webdriver.Chrome(options=options)       return driver   `
    
-   **抓取图像**：抓取并保存EUR/USD图表的屏幕截图，该图表将由GPT-4进行分析。
    
    `driver = initialize_web_driver()      try:       # 导航到页面       driver.get("https://www.tradingview.com/symbols/EURUSD/")          # 等待几秒钟以确保页面完全加载       time.sleep(4)  # 根据需要调整睡眠持续时间       driver.refresh()       time.sleep(4)          # 使用适当的选择器定位图表       chart_element = WebDriverWait(driver, 10).until(           EC.presence_of_element_located((By.CLASS_NAME, "container-nORFfEfo"))       )       # 抓取图表元素的屏幕截图       time.sleep(4)       chart_element.screenshot("eurusd_chart.png")       print("图表截图已保存为 'eurusd_chart.png'。")   except Exception as e:       print("发生错误:", e)   finally:       # 关闭浏览器       driver.quit()   `
    

脚本将为我们提供每日EUR/USD图表的快照：

![每日EUR/USD图表](assets/001.jpg)_每日EUR/USD图表 \[来源：TradingView\]_

### 2) Kafka设置用于实时数据流

在本节中，我们将建立一个基于Kafka的数据流设置，以近乎实时的方式跟踪EUR/USD的买卖价格。EURUSD价格的数据源将来自流行的提供商Investing.com。为了使系统功能齐全，eurusd\_bidask每5秒更新一次。

核心组件包括：

-   **Kafka生产者**：负责每5秒获取并发布买卖数据到eurusd\_bidask主题。
    
-   **Kafka消费者**：实时消费并处理来自Kafka主题的数据，将其存储以供进一步分析。
    

这个设置为构建动态交易机器人提供了理想的起点，通过模拟实时数据流和处理。尽管由于网络请求，数据略有延迟，但它为更复杂的交易策略奠定了坚实的基础。

#### 设置Kafka配置

`!wget https://downloads.apache.org/kafka/3.8.1/kafka_2.13-3.8.1.tgz   !tar -xzf kafka_2.13-3.8.1.tgz   !./kafka_2.13-3.8.1/bin/zookeeper-server-start.sh -daemon ./kafka_2.13-3.8.1/config/zookeeper.properties   !./kafka_2.13-3.8.1/bin/kafka-server-start.sh -daemon ./kafka_2.13-3.8.1/config/server.properties   !sleep 10   # 删除主题   !./kafka_2.13-3.8.1/bin/kafka-topics.sh --delete --topic eurusd_bidask --bootstrap-server localhost:9092   !./kafka_2.13-3.8.1/bin/kafka-topics.sh --create --bootstrap-server localhost:9092 --topic eurusd_bidask --partitions 1 --replication-factor 1   `

在整合整个工作流程之前，我们首先测试eurusd抓取器，以确保它每5秒获取数据一次，使用Beautifulsoup库。此外，我们将检查Kafka队列是否正常工作，以确保数据流的无缝性。

`!pip install kafka-python nest_asyncio      import json   import requests   import time   import pandas as pd   from kafka import KafkaProducer, KafkaConsumer   from bs4 import BeautifulSoup   import asyncio   import nest_asyncio   import threading      # 应用 nest_asyncio 以在已经运行的事件循环的环境中运行（例如，nest_asyncio.apply()）      # 控制变量以停止循环   stop_flag = False      # Kafka生产者配置   asyncdef kafka_producer():       producer = KafkaProducer(           bootstrap_servers=['localhost:9092'],           value_serializer=lambda v: json.dumps(v).encode('utf-8')       )          asyncdef fetch_and_send_bid_ask():           url = 'https://www.investing.com/currencies/eur-usd-spreads'           headers = {"User-Agent": "Mozilla/5.0"}           response = requests.get(url, headers=headers)              # 检查响应是否成功           if response.status_code == 200:               soup = BeautifulSoup(response.text, 'html.parser')               bid_element = soup.find("span", class_="inlineblock pid-1-bid")               ask_element = soup.find("span", class_="inlineblock pid-1-ask")               # 检查是否找到买卖元素               if bid_element and ask_element:                   bid_value = float(bid_element.text.replace(',', ''))                   ask_value = float(ask_element.text.replace(',', ''))                   message = {'bid': bid_value, 'ask': ask_value}                   # 发送消息到Kafka                   producer.send('eurusd_bidask', value=message)                   producer.flush()                   print(f"生产者发送的买价: {bid_value}, 卖价: {ask_value}")               else:                   print("错误: 无法在页面上找到买价/卖价元素。")           else:               print(f"获取数据时出错: 状态码 {response.status_code}")          # 无限循环以每5秒捕获并发送数据       whilenot stop_flag:           await fetch_and_send_bid_ask()           await asyncio.sleep(5)          producer.close()      # Kafka消费者配置   def kafka_consumer_bot():       consumer = KafkaConsumer(           'eurusd_bidask',           bootstrap_servers=['localhost:9092'],           value_deserializer=lambda x: json.loads(x.decode('utf-8')),           auto_offset_reset='latest',           enable_auto_commit=False,           group_id='my-group'       )          df = pd.DataFrame(columns=['Bid','Ask','Mid_Price'], dtype=float)          print("启动Kafka消费者... 监听 'eurusd_bidask' 主题的消息。")          for msg in consumer:           if stop_flag:               break              # 调试消息以显示已接收到消息           # 提取买价和卖价           bid = float(msg.value['bid'])           ask = float(msg.value['ask'])           mid_price = (bid + ask) / 2              # 将新行添加到DataFrame并打印更新的DataFrame           new_row = pd.DataFrame({'Bid': [bid], 'Ask': [ask], 'Mid_Price': [mid_price]})           df = pd.concat([df, new_row], ignore_index=True)              print(f"消费者处理的买价: {bid:.4f}, 卖价: {ask:.4f}, 中间价: {mid_price:.4f}")           print("更新的DataFrame:")           print(df)              # 只保留最后50行           if len(df) > 50:               df = df.iloc[-50:].reset_index(drop=True)              # 为了避免在这个例子中快速轮询，稍微休眠一下           time.sleep(5)      # 主函数以同时运行生产者和消费者   asyncdef main():       # 在事件循环中启动生产者       producer_task = asyncio.create_task(kafka_producer())          # 在单独的线程中启动消费者       consumer_thread = threading.Thread(target=kafka_consumer_bot, daemon=True)       consumer_thread.start()          try:           await producer_task       except asyncio.CancelledError:           pass       finally:           consumer_thread.join()      # 运行主函数      try:       asyncio.run(main())   except KeyboardInterrupt:       print("程序被用户终止。")   `

### 3) LlamaIndex工作流程用于交易决策

使用llama-index、kafka-python进行Kafka交互，以及pandas\_ta进行技术分析。

#### 安装必要的包

`!pip install llama-index-core llama-index-llms-openai llama-index-multi-modal-llms-openai   !pip install llama_index.readers.file   !pip install pandas_ta   !pip install kafka-python   `

-   **图像分析步骤**：使用GPT-4分析抓取的EUR/USD图表。该分析的见解将指导机器人的初始行为。
    
-   **数据分析步骤**：此步骤利用EMA、RSI和Bollinger Bands等技术指标对实时买卖数据进行技术分析。基于这些指标，GPT-3.5被提示提供买入、卖出或持有的决策，并附有选择理由。
    
-   **停止命令监听器**：监听“停止”命令，当需要时停止程序。
    

#### 安装必要的包

`!pip install llama-index-core llama-index-llms-openai llama-index-multi-modal-llms-openai   !pip install llama_index.readers.file   !pip install pandas_ta   !pip install kafka-python   `

#### 完整的交易工作流程

`import requests   from bs4 import BeautifulSoup   import json   import pandas as pd   import pandas_ta as ta   import asyncio   import threading   import nest_asyncio   import time   import os   from kafka import KafkaProducer, KafkaConsumer   from llama_index.core.program import LLMTextCompletionProgram   from llama_index.multi_modal_llms.openai import OpenAIMultiModal   from llama_index.core import SimpleDirectoryReader   from llama_index.core.workflow import Workflow, step, Event, Context   from llama_index.core.bridge.pydantic import BaseModel, Field   from llama_index.llms.openai import OpenAI   from typing import Optional, Any      # 设置Colab环境兼容性   nest_asyncio.apply()      # 在环境中设置OpenAI API密钥   os.environ["OPENAI_API_KEY"] = 'YOUR_OPENAI_API_KEY'      # 控制变量以停止循环   stop_flag = False      def stop_listener():       global stop_flag       whileTrue:           user_input = input("输入 'stop' 以停止:")           if user_input.lower() == 'stop':               stop_flag = True               print("正在停止程序...")               break      # 启动一个单独的线程以监听停止命令   threading.Thread(target=stop_listener, daemon=True).start()      class TradingDecisionResult(BaseModel):       """       模型用于存储交易决策的结果。       """       decision: str = Field(description="交易决策: 'buy', 'sell' 或 'hold'")       reasoning: str = Field(description="决策背后的理由。")      # 初始化工作流程   class InvestmentBotWorkflow(Workflow):       def __init__(self, **kwargs):           super().__init__(**kwargs)           self.image_analysis_done = False# 指示是否已完成图像分析          asyncdef analyze_image(self, ctx: Context, ev: Event) -> None:           # 跟踪图像分析是否已经完成           ifnot self.image_analysis_done:               print("正在进行图像分析...")               openai_mm_llm = OpenAIMultiModal(                   model="gpt-4o",                   api_key=os.environ["OPENAI_API_KEY"],                   max_new_tokens=512               )               image_path = "/content/eurusd_chart.png"               image_documents = SimpleDirectoryReader(input_files=[image_path]).load()               response = openai_mm_llm.complete(                   prompt="分析以下EUR/USD（每日）图表。提供您的见解。",                   documents=image_documents               )               response_text = response[0].text               await ctx.set("image_analysis", response_text)               self.image_analysis_done = True               print("图像分析完成:", response_text)          @step       asyncdef analyze_data(self, ctx: Context, ev: Event) -> None:           """           执行数据分析并基于技术指标生成交易决策。           """           df = await ctx.get('df')           if df isNoneor df.empty:               print("DataFrame 'df' 不可用或为空。")               return              # 获取存储的图像分析           image_analysis = await ctx.get("image_analysis", "图像分析不可用")              # 确保有足够的数据用于技术指标           if len(df) < 6:               print("数据不足以计算技术指标。")               return              # 根据可用数据调整指标周期           ema_period = min(5, len(df))           rsi_period = min(5, len(df))           bb_period = min(5, len(df))              # 计算技术指标           df['EMA_5'] = ta.ema(df['Mid_Price'], length=ema_period)           df['RSI'] = ta.rsi(df['Mid_Price'], length=rsi_period)           bb = ta.bbands(df['Mid_Price'], length=bb_period, std=2)              if bb isnotNoneandnot bb.empty:               # 获取生成的列名               bb_columns = bb.columns.tolist()                  # 过滤所需的列               bbl_column = [col for col in bb_columns if col.startswith('BBL')]               bbm_column = [col for col in bb_columns if col.startswith('BBM')]               bbu_column = [col for col in bb_columns if col.startswith('BBU')]                  # 选择并重命名列               bb_selected = bb[[bbl_column[0], bbm_column[0], bbu_column[0]]]               bb_selected.columns = ['BBL', 'BBM', 'BBU']                  # 与原始DataFrame连接               df = pd.concat([df, bb_selected], axis=1)           else:               # 获取最后5个价格               last_prices = df['Mid_Price'].tail(5).tolist()              # 获取最新的技术指标           latest_data = df.iloc[-1]              # 处理指标中的NaN值           indicators = {}           indicators['EMA_5'] = latest_data.get('EMA_5', 'Not available')           indicators['RSI'] = latest_data.get('RSI', 'Not available')           indicators['BBL'] = latest_data.get('BBL', 'Not available')           indicators['BBM'] = latest_data.get('BBM', 'Not available')           indicators['BBU'] = latest_data.get('BBU', 'Not available')              for key, value in indicators.items():               if pd.isna(value):                   indicators[key] = 'Not available'              # 为GPT-3准备提示           prompt = (               f"最新价格分析: {last_prices}\n"               f"最新的技术指标:\n"               f"EMA_5: {indicators['EMA_5']}\n"               f"RSI: {indicators['RSI']}\n"               f"BBL: {indicators['BBL']}\n"               f"BBM: {indicators['BBM']}\n"               f"BBU: {indicators['BBU']}\n\n"               f"EURUSD每日图表分析:\n{image_analysis}\n\n"               "基于以上分析，请提供交易决策:('buy', 'sell' 或 'hold') 并简洁地解释您的理由。"           )              # 使用GPT-3.5获得决策           try:               llm_gpt3 = OpenAI(model="gpt-3.5-turbo", max_new_tokens=512)               program = LLMTextCompletionProgram.from_defaults(                   output_cls=TradingDecisionResult,                   prompt_template_str=prompt,                   llm=llm_gpt3               )               trading_decision_result = program()               decision = trading_decision_result.decision               reasoning = trading_decision_result.reasoning               print(f"交易决策: {decision}")               print(f"理由: {reasoning}")           except Exception as e:               print(f"发生错误: {e}")      # Kafka生产者配置   asyncdef kafka_producer():       producer = KafkaProducer(           bootstrap_servers=['localhost:9092'],           value_serializer=lambda v: json.dumps(v).encode('utf-8')       )          asyncdef fetch_and_send_bid_ask():           url = 'https://www.investing.com/currencies/eur-usd-spreads'           headers = {"User-Agent": "Mozilla/5.0"}           response = requests.get(url, headers=headers)           if response.status_code == 200:               soup = BeautifulSoup(response.text, 'html.parser')               bid_element = soup.find("span", class_="inlineblock pid-1-bid")               ask_element = soup.find("span", class_="inlineblock pid-1-ask")               if bid_element and ask_element:                   bid_value = float(bid_element.text.replace(',', ''))                   ask_value = float(ask_element.text.replace(',', ''))                   message = {'bid': bid_value, 'ask': ask_value}                   producer.send('eurusd_bidask', value=message)                   producer.flush()                   print(f"生产者发送的买价: {bid_value}, 卖价: {ask_value}")               else:                   print(f"错误: {response.status_code}")           else:               print(f"获取数据时出错: 状态码 {response.status_code}")          # 无限循环以每5秒捕获并发送数据       whilenot stop_flag:           await fetch_and_send_bid_ask()           await asyncio.sleep(5)          producer.close()      # Kafka消费者配置   def kafka_consumer_bot():       consumer = KafkaConsumer(           'eurusd_bidask',           bootstrap_servers=['localhost:9092'],           value_deserializer=lambda x: json.loads(x.decode('utf-8')),           auto_offset_reset='latest',           enable_auto_commit=False,           group_id='my-group'       )          df = pd.DataFrame(columns=['Bid','Ask','Mid_Price'], dtype=float)          # 初始化工作流程       bot_workflow = InvestmentBotWorkflow()       context = Context(workflow=bot_workflow)          # 在开始循环之前进行图像分析       loop = asyncio.new_event_loop()       asyncio.set_event_loop(loop)       loop.run_until_complete(bot_workflow.analyze_image(context, Event()))       loop.close()          # 变量以控制开始时间       data_collection_start_time = time.time()       data_collection_duration = 30          for msg in consumer:           if stop_flag:               break           bid = float(msg.value['bid'])           ask = float(msg.value['ask'])           mid_price = (bid + ask) / 2           new_row = pd.DataFrame({'Bid': [bid], 'Ask': [ask], 'Mid_Price': [mid_price]})           df = pd.concat([df, new_row], ignore_index=True)              # 只保留最后50行           if len(df) > 50:               df = df.iloc[-50:].reset_index(drop=True)              # 等待直到有足够的数据可用           if time.time() - data_collection_start_time < data_collection_duration:               print("正在收集数据... 等待开始分析。")               time.sleep(5)               continue# 在有足够的数据之前不要运行分析              # 每30秒执行一次分析           if len(df) > 4:  # 确保有足够的数据用于指标               # 将DataFrame传递给上下文并运行分析               loop = asyncio.new_event_loop()               asyncio.set_event_loop(loop)               loop.run_until_complete(context.set('df', df.copy()))               loop.run_until_complete(bot_workflow.analyze_data(context, Event()))               loop.close()               # 重置计时器以进行下一次分析               data_collection_start_time = time.time()           else:               print("没有足够的数据用于分析")           time.sleep(5)      # 执行生产者和消费者一起   def main():       # 在事件循环中执行生产者       loop = asyncio.get_event_loop()       producer_task = loop.create_task(kafka_producer())          # 在单独的线程中启动消费者       consumer_thread = threading.Thread(target=kafka_consumer_bot, daemon=True)       consumer_thread.start()          try:           loop.run_until_complete(producer_task)       except KeyboardInterrupt:           print("程序被用户完成。")      # 执行主函数   try:       main()   except KeyboardInterrupt:       print("程序被用户终止。")   `

### 交易机器人输出

`正在进行图像分析...   生产者发送的买价: 1.0625, 卖价: 1.0626   生产者发送的买价: 1.0625, 卖价: 1.0626   图像分析完成: EUR/USD每日图表显示了以下模式和趋势:   1. **下降趋势**: 整体趋势是下降的，有一系列较低的高点和较低的低点。这表明在观察期间内，市场情绪是看跌的。   2. **关键阻力位**:      - 大约1.057e: 价格多次测试了这个水平，但未能突破，表明存在强大的阻力。   3. **关键支撑位**:      - 大约1.450: 价格从这一水平反弹，表明这是一个重要的支撑区域。   4. **最近的反弹**: 从支撑位大约1.450的反弹是显著的，表明在大趋势中可能存在短期的看涨修正。   5. **波动性**: 图表显示波动性增加，特别是在反弹期间出现急剧的价格变动。   6. **潜在模式**: 可能形成下降通道，价格在阻力位和支撑位之间波动。对于算法捕捉买卖数据，关注这些关键水平对于潜在的突破或逆转信号以及任何波动性变化都是有益的，这将影响决策。   `

`消费者接收到的买价: 1.0625, 卖价: 1.0626, 中间价: 1.06255   生产者发送的买价: 1.0625, 卖价: 1.0626   `

### 交易决策

`交易决策: hold   理由: EUR/USD每日图表显示强烈的下降趋势，关键阻力位保持不变。尽管从重要的支撑位有所反弹，但整体市场情绪仍然看跌。   `

`消费者接收到的买价: 1.0626, 卖价: 1.0627, 中间价: 1.0627   生产者发送的买价: 1.0626, 卖价: 1.0627   `

`交易决策: hold   理由: The EUR/USD daily chart indicates a strong downtrend with key resistance levels holding. Although there is a recent rebound from a significant support level, the overall market sentiment remains bearish.   `

* * *

## 未来扩展 — 投资再平衡

在未来的教程中，我们将添加一个功能，根据机器人生成的交易建议动态调整投资金额。这一增强将使机器人更加适应和响应市场趋势，从而实现更战略性和高效的决定。

  

  

  

  

  

  

完整代码见星球，加入QuantML星球，与750+专业人士一起交流学习：

![](assets/002.png)

  

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