# 使用Google ADK以及MCP构建AI代理

QuantML QuantML 2025-04-16 21:37 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490078&idx=1&sn=d91358eab443c08a81635243c14dad5e&chksm=cf6aeade7e0eed65c25c8eebfae4fed73a10b7b5eb4a2c4715c36f950485f01f6cc4fd7ef4af#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490078&idx=1&sn=d91358eab443c08a81635243c14dad5e&chksm=cf6aeade7e0eed65c25c8eebfae4fed73a10b7b5eb4a2c4715c36f950485f01f6cc4fd7ef4af#rd)

## 什么是ADK——代理开发工具包？

Google代理开发工具包（ADK）是一个开源的、代码优先的Python工具包，用于构建、评估和部署智能AI代理。

ADK使开发者能够创建代理工作流程——从简单的单代理任务到复杂的多代理编排——所有这些都在一个模块化的框架内完成。

## ADK中的代理是什么？

代理是一个自主的、自包含的执行单元，旨在实现特定目标。代理可以：

1.  执行任务，
    
2.  与用户互动，
    
3.  利用外部工具，
    
4.  与其他代理协作以完成复杂的工作流程。![](assets/001.png)
    

## 核心代理类别

ADK提供三种主要的代理类型来支持：

-   **LLM代理**（例如，LlmAgent, Agent）：使用大型语言模型（LLM）来理解、推理、规划和行动——非常适合动态、语言驱动的任务。
    
-   **工作流代理**（例如，SequentialAgent, ParallelAgent, LoopAgent）：以可预测的模式编排其他代理，不依赖于LLM。
    
-   **自定义代理**：通过扩展BaseAgent来构建，以实现自定义逻辑、专门的工作流程或独特的工具集成——非常适合特定需求。
    

在本文中，我们将使用LLM代理类型，并结合MCPTools使用。

## 什么是工具（Tools）？

工具代表赋予AI代理的特定能力，使其能够执行操作并与外部世界互动。工具通常是一个模块化的代码组件——如Python函数、类方法，甚至是另一个代理——旨在执行定义好的任务。

## 代理如何使用工具？

代理通过函数调用机制动态地利用工具，LLM在此过程中对上下文进行推理，选择并调用适当的工具。

## ADK中的工具类型

ADK支持多种工具类型：

1.  **函数工具**：为应用程序的独特逻辑和工作流程专门构建的自定义工具。
    

-   **函数/方法**：标准的同步Python函数（def）或类方法，注册为工具。
    
-   **代理作为工具**：使用专门的代理作为父代理中的可调用工具，以实现模块化行为。
    
-   **长时间运行的函数工具**：设计用于异步或时间密集型操作的工具。
    

3.  **内置工具**：框架中预定义的工具，用于执行网络搜索、代码执行或RAG等任务。
    
4.  **第三方工具**：轻松集成来自流行生态系统（如LangChain或CrewAI）的工具。
    

## 架构

我们将使用与之前文章相同的架构，此外，我们还将在这里使用ADK。![](assets/002.png)

## 实现

让我们通过将实现过程分解为关键步骤来构建这个基于ADK + MCP + Gemini AI的管道。

## 先决条件

1.  安装Python 3.8或更高版本。
    
2.  通过API密钥访问Google Gemini生成式AI。
    
3.  一个有效的SerpAPI密钥（用于获取实时航班数据）。
    

## 步骤1：设置虚拟环境

使用以下命令安装依赖项：

`# 设置虚拟环境（mac或Unix）   python -m venv venv && source venv/bin/activate   # 安装代理开发工具包   pip install google-adk   # 安装MCP服务器   pip install mcp-flight-search   # 安装GenAI Python SDK   pip install google-genai   `

-   `google-sdk`：Google的代理开发工具包，用于构建代理。
    
-   `google-genai`：Google的库，用于与生成式AI模型（如Gemini）交互。
    
-   `mcp-flight-search`：一个使用SerpAPI通过MCP库获取航班的MCP服务器。
    

注意：在ADK中，API密钥变量将是`GOOGLE_API_KEY`，而不是`GEMINI_API_KEY`。

`export GOOGLE_API_KEY="your-google-api-key"   export SERP_API_KEY="your-serpapi-key"   `

## 步骤2：安装MCP服务器——mcp-flight-search

为了使Gemini能够与现实世界的API进行交互，我们将使用一个符合MCP规范的服务器。

在本文中，我们将使用`mcp-flight-search`——一个使用FastMCP构建的轻量级MCP服务器，它公开了一个用于实时搜索航班的工具。

验证已安装的MCP服务器包：https://pypi.org/project/mcp-flight-search/

`# 从PyPI安装（已在步骤1中安装）   pip install mcp-flight-search   `

## 步骤3：理解ADK作为MCP客户端

`from google.adk.agents.llm_agent import LlmAgent   from google.adk.runners import Runner   from google.adk.sessions import InMemorySessionService   from google.adk.tools.mcp_tool.mcp_toolset import MCPToolset, StdioServerParameters   `

-   `LlmAgent`是ADK中的一个核心组件，充当我们应用程序的“思考”部分，它利用大型语言模型的力量。
    
-   `Runner`负责在代理的生命周期内协调各个组件之间的交互。`Runner`使用内存中的会话服务。
    
-   `InMemorySessionService`是ADK的`SessionService`接口的实现，它存储所有会话数据——例如对话。
    
-   当用户与AI代理交互时，会创建一个`Session`对象来跟踪对话。
    
-   `StdioServerParameters`是一个配置类，用于指定代理应如何通过标准输入/输出连接到MCP服务器。
    

当结合使用时，`MCPToolset`和`StdioServerParameters`允许ADK代理：

1.  **建立连接**：使用`StdioServerParameters`，定义启动MCP服务器进程所需的命令和参数。
    
2.  **发现可用工具**：`MCPToolset`连接到MCP服务器并检索代理可以使用的可用工具列表。
    
3.  **将工具集成到代理中**：将发现的工具适配为与ADK代理兼容的格式，从而实现无缝集成。
    
4.  **管理连接生命周期**：`MCPToolset`处理与MCP服务器的连接设置和拆除，确保资源得到正确管理。
    

## 步骤4：连接到MCP服务器

`StdioServerParameters`定义了使用`MCPToolSet`进行异步列表和监听的MCP配置。

`# --- 步骤1：从MCP服务器获取工具   async def get_tools_async():       """从航班搜索MCP服务器获取工具。"""       print("尝试连接到MCP航班搜索服务器...")       server_params = StdioServerParameters(           command="mcp-flight-search",           args=["--connection_type", "stdio"],           env={"SERP_API_KEY": os.getenv("SERP_API_KEY")},       )       tools, exit_stack = await MCPToolset.from_server(           connection_params=server_params       )       print("MCP工具集创建成功。")       return tools, exit_stack   `

## 步骤5：使用ADK创建代理

如上所述，我们使用的是作为应用程序思考部分的Llm代理。

`# --- 步骤2：定义ADK代理创建   async def get_agent_async():       """创建一个配备MCP服务器工具的ADK代理。"""       tools, exit_stack = await get_tools_async()       print(f"从MCP服务器获取了{len(tools)}个工具。")       # 创建与示例结构匹配的LlmAgent       root_agent = LlmAgent(           mode=os.getenv("GEMINI_MODEL", "gemini-2.5-pro-preview-03-25"),           name="flight_search_assistant",           instruction="根据提示使用可用工具帮助用户搜索航班。如果未指定返回日期，则使用当前日期。",           tools=tools,       )       return root_agent, exit_stack   `

## 步骤6：将代理创建、会话管理和编排与Runner集成

`async def async_main():       # 创建服务       session_service = InMemorySessionService()       # 创建一个会话       session = session_service.create_session(           state={},           app_name="flight_search_app",           user_id="user_flights"       )       # 定义用户提示       query = "查找2025年5月5日从亚特兰大飞往拉斯维加斯的航班"       print(f"用户查询: '{query}'")       # 将输入格式化为types.Content       content = types.Content(role="user", parts=[types.Part(text=query)])       # 获取代理和退出堆栈       root_agent, exit_stack = await get_agent_async()       # 创建Runner       runner = Runner(           app_name="flight_search_app",           agent=root_agent,           session_service=session_service,       )       print("运行代理...")       events_async = runner.run_async(           session_id=session.id,           user_id=session.user_id,           new_message=content       )       # 处理事件       final_content = None       asyncfor event in events_async:           print(f"收到事件: {event}")       # 始终清理资源       print("关闭MCP服务器连接...")       await exit_stack.aclose()       print("清理完成。")   `

## 步骤7：演示

用户查询在MCP客户端：

-   使用标准日志记录进行演示
    
-   使用调试日志记录进行演示
    

## 将MCP与ADK集成的关键注意事项

### 1\. MCP与ADK

-   MCP是一个开放协议，它标准化了AI模型与外部工具和数据源的交互方式。
    
-   ADK是一个基于Python的框架，用于构建和部署AI代理。
    
-   `MCPToolset`：通过使ADK代理能够使用MCP服务器公开的工具，在MCP和ADK之间架起桥梁。
    

要在Python中构建一个MCP服务器，请使用`model-context-protocol`库。

### 2\. 工具类型和集成

-   **ADK工具**：设计用于在ADK代理中直接使用的Python对象（例如，BaseTool, FunctionTool）。
    
-   **MCP工具**：MCP服务器公开的功能，`MCPToolset`将其适配为ADK代理中可用的工具。
    
-   **第三方工具**：像LangChain和CrewAI这样的库提供了可以通过LangChain等包装器集成到ADK中的工具。
    

### 3\. 异步架构

-   ADK和MCP Python库都构建在Python的`asyncio`框架之上。
    
-   工具实现和服务器处理程序应该是异步的（`async def`），以确保非阻塞操作。
    

### 4\. MCP中的状态会话

-   MCP在客户端和服务器之间建立持久的、有状态的连接，这与典型的无状态REST API不同。
    
-   这种状态性允许在交互中保留上下文，但需要仔细的会话管理。
    

### 5\. 部署注意事项

-   MCP连接的持久性可能对扩展和部署构成挑战，尤其是对于处理远程服务器的连接。
    
-   基础设施方面的考虑包括负载平衡和会话亲和性，以保持连接稳定性。
    

### 6\. 在ADK中管理MCP连接

-   `MCPToolset`管理ADK内MCP连接的生命周期。使用`exit_stack`确保在代理执行完成时正确终止连接。
    

## 故障排除

1.  \*\*默认情况下，adk库期望使用GCP项目Vertex AI、位置和VertexAI配置。确保使用`GOOGLE_API_KEY`而不是`GEMINI_API_KEY`\*\*。
    
    `ValueError: Missing key inputs argument! To use the Google AI API, provide ('api_key') arguments. To use the Google Cloud API,   `
    

-   **解决方案**：确保将变量设置为`GOOGLE_API_KEY`。
    

3.  **频繁的429速率限制错误和500内部服务器错误**。
    
    `google.genai.errors.ClientError: 429 RESOURCE_EXHAUSTED. {'error': {'code': 429, 'message': 'You exceeded your current quota, An error occurred during execution: 500 INTERNAL. {'error': {'code': 500, 'message': 'An internal error has occurred. Please try again later.'}   `
    

-   **解决方案**：切换到Gemini 2 Flash，因为“Gemini API的‘免费层’是通过API服务提供的，具有较低的速率限制，用于测试目的”。
    

  

  

  

  

  

完整代码见星球，加入QuantML星球，与800+专业人士一起交流学习：

![](assets/003.png)