# 订单簿动态分析

QuantML QuantML 2025-05-07 22:00 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490311&idx=1&sn=0de2478fc38be88bd1b4dc5356530244&chksm=cf3f99c041c77c3ad790a6e8461cff9da912e3e1378f4d168ebfd3d12b902b81fbc2c032c5c1#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490311&idx=1&sn=0de2478fc38be88bd1b4dc5356530244&chksm=cf3f99c041c77c3ad790a6e8461cff9da912e3e1378f4d168ebfd3d12b902b81fbc2c032c5c1#rd)

本文旨在深入分析订单簿的动态特性，探讨其内在机制和常见的市场现象。同时，将系统梳理订单簿的各类建模方法，包括传统的随机模型、基于智能体的模型以及新兴的机器学习模型，并评估其各自的优缺点。

## **I. 引言**

### **A. 订单簿的定义与重要性**

订单簿（Order Book）是交易场所（尤其是证券交易所）用来记录特定金融工具买卖双方意愿的订单列表，这些订单可以是人工的，也可以是电子的 。匹配引擎利用订单簿来决定哪些订单可以被全部或部分执行 。订单簿不仅仅是一个静态的列表，更是一个动态的生态系统，实时反映了多样化市场参与者的集体行为和预期。它在现代金融市场中扮演着至关重要的角色，是市场微观结构研究的核心。订单簿的主要功能包括促进价格发现、提供市场流动性指示以及反映市场情绪 。作为一个动态系统，订单簿在交易日内实时更新，不断整合新的买卖订单和已执行的交易信息，因此也被称为“连续簿” 。

订单簿的透明度为交易者提供了宝贵的交易信息，帮助他们做出更明智的决策 。通过分析订单簿的深度和广度，市场参与者可以评估当前市场的供需状况，预测潜在的价格变动，并制定相应的交易策略。例如，订单簿中特定价格水平的大量买单或卖单可以揭示潜在的支撑位和阻力位 。

本报告旨在深入分析订单簿的动态特性，探讨其内在机制和常见的市场现象。同时，报告将系统梳理订单簿的各类建模方法，包括传统的随机模型、基于智能体的模型以及新兴的机器学习模型，并评估其各自的优缺点。

## **II. 订单簿基础**

### **A. 订单簿的构成要素**

理解订单簿的首要步骤是熟悉其基本构成要素。这些要素共同描绘了特定时刻市场供需的全景。

. **买方出价 (Bid Side)** :订单簿的买方一侧列出了所有买方愿意购买某一金融工具的订单，其中出价最高的订单位于最顶端 。这个最高买价代表了当前市场买方愿意支付的最高价格。

. **卖方要价 (Ask Side)** :与买方对应，卖方一侧列出了所有卖方愿意出售该金融工具的订单，其中要价最低的订单位于最顶端 。这个最低卖价代表了当前市场卖方愿意接受的最低价格。通常，最高买价低于最低卖价。

. **价格水平 (Price Levels)** :订单簿展示了多个不同的买价和卖价水平，每个水平代表一个有订单存在的特定价格点 。这些价格水平按优劣排序，最优买价（最高买价）和最优卖价（最低卖价）通常被称为“簿首”（top of the book）。

. **订单数量 (Order Volume/Size)** :在每个价格水平上，订单簿会显示相应的订单数量或总股数 。例如，买方在某个价格的订单数量代表了在该价格上所有买单的总和。买单数量和卖单数量（Bid Size and Ask Size）共同揭示了在特定价格点位的潜在供需规模 。

. **累计订单数量 (Cumulative Order Volume)** :某些订单簿展示还会提供累计订单数量，即在当前价格水平及所有更优价格水平上的订单总量 。例如，在买方一侧，某一价格水平的累计订单数量是指在该价格及所有更高买价上的总买单量。这一指标有助于评估不同价格区间的整体买卖压力。

这些组成部分共同构成了订单簿的核心信息，为市场参与者提供了关于市场深度、流动性和潜在价格变动方向的关键线索。

### **B. 订单簿的运作机制**

订单簿的运作依赖于一套明确的规则和高效的执行系统，其核心是订单匹配引擎，它负责接收订单、维护订单簿的实时状态，并根据既定规则执行交易 。

**订单类型 (Order Types)** ：

-   **限价单 (Limit Orders)** :交易者指定愿意买入的最高价格或愿意卖出的最低价格 。如果订单不能立即执行，它将被存入订单簿中，等待价格条件满足。限价单是订单簿流动性的主要提供者。
    
-   **市价单 (Market Orders)** :交易者不指定价格，要求以当前市场上最优的可成交价格立即执行 。市价单具有最高的执行优先权，它们消耗订单簿中的流动性。然而，市价单存在滑点风险，即实际成交价格可能与预期价格不同，尤其是在市场快速波动或流动性不足时 。
    
-   **其他订单类型 (Other Order Types)** :还存在多种特殊订单类型，如止损单（Stop Orders，在市场价格达到特定水平时激活）和冰山订单（Iceberg Orders，大额订单被部分隐藏以减少市场冲击）。这些复杂订单类型为交易者提供了更灵活的风险管理和交易执行工具，但也对订单簿模型的复杂性提出了更高要求。
    

**订单匹配规则 (Order Matching Rules)** ：订单匹配引擎遵循严格的规则来决定订单的执行顺序。

-   **价格优先 (Price Priority)** :最优价格的订单优先匹配。即买单中出价最高者优先，卖单中要价最低者优先 。这是订单匹配最核心的原则。
    
-   **时间优先 (Time Priority)** :在同一价格水平上，先提交的订单优先于后提交的订单执行 。这确保了订单处理的公平性。
    
-   **比例分配 (Pro-rata Matching)** :在某些市场或特定情况下，如果一个大额市价单需要匹配多个同价位的限价单，成交量可能会按这些限价单的比例进行分配 。这种机制在处理大额订单时，平衡了大小订单的执行机会。
    

**订单匹配引擎 (Order Matching Engine)** ：作为电子交易系统的核心，订单匹配引擎执行多项关键功能：持续更新和组织挂单（订单簿维护），确保公平的订单执行序列（价格-时间优先原则的执行），匹配兼容的订单并生成交易（交易执行），以及创建和分发订单簿更新（市场数据生成）。现代匹配引擎必须具备超低延迟（微秒级或更低）、高吞吐量（每秒数百万条消息）、确定性行为和容错能力等性能特征 。匹配引擎的行为通过价格形成过程、市场冲击成本、流动性提供和市场深度维护直接影响市场质量 。

订单簿的运作机制是一个高度复杂但有序的过程，旨在高效、公平地撮合买卖双方的交易意愿。理解这一机制是分析订单簿动态和构建有效模型的基础。

### **C. 关键订单簿指标**

从订单簿数据中可以提取多种量化指标，用以衡量市场状态和动态。这些指标对于交易决策、风险管理和市场微观结构分析至关重要。

. **买卖价差 (Bid-Ask Spread)** ：定义为最低卖方要价（Best Ask）与最高买方出价（Best Bid）之差 。它是衡量市场流动性的一个核心指标，也是交易成本的直接体现 。较窄的价差通常意味着较高的流动性和较低的交易成本，而较宽的价差则相反 。价差可以反映显性成本（如交易和订单处理成本）和隐性成本（如逆向选择和等待成本）。相对价差（价差除以中间价）可被视为投资者为立即执行订单而必须支付的流动性溢价 。

. **市场深度 (Market Depth)** :指订单簿在不同价格水平上累积的订单数量或金额 。通常，市场深度可以指最佳买卖价位上的订单量之和 ，也可以指从最优价位到特定深度水平的价格与数量乘积之和 。市场深度越大，市场在不引起价格大幅波动的情况下吸收大额交易的能力就越强 。深度信息对于评估大额订单的潜在价格影响至关重要。围绕最优价格的更大深度反映了对真实价格的更强共识 。

. **订单失衡 (Order Imbalance, OBI)** :指在选定的订单簿深度水平上，买方深度与卖方深度之间的差异 。计算公式为：OBIL=∑l=L(Pask,l⋅Qask,l−Pbid,l⋅Qbid,l)，即卖方深度减去买方深度 。订单失衡提供了超越深度本身的额外有价值信息，揭示了买卖双方流动性的不平衡状态。较高的订单失衡可能与较高的交易成本相关，并且是订单流的有力预测指标 。为了跨市场比较，通常使用标准化订单簿失衡（NOBI），其值域为 \[−,\] 。

. **成交量加权平均价 (Volume-Weighted Average Price, VWAP)** :VWAP是一种考虑了交易量的平均价格，常用于评估交易执行质量或作为交易基准。从订单簿数据计算特定深度 L 层的VWAP，其公式为：PLVWAP=∑l=LQl∑l=L(Pl⋅Ql)，其中 Pl 和 Ql 分别是第 l 层的价格和数量 。通过计算买方和卖方各自的VWAP，可以得到VWAP价差，这提供了超越最优价差的更全面的流动性衡量。

这些关键指标为理解订单簿状态和预测短期市场行为提供了定量工具。它们之间的相互作用和时序演变构成了订单簿动态分析的核心内容。

## **III. 订单簿动态性分析**

订单簿并非静止不变，而是随着新订单的提交、现有订单的取消或修改以及交易的执行而不断演变。这种动态性是市场价格形成和流动性变化的核心驱动力。

### **A. 订单簿动态性的常见现象**

对高频订单簿数据的观察揭示了一系列具有统计规律性的现象，这些现象反映了市场参与者的集体行为和市场微观结构的特性。

. **流动性聚集 (Liquidity Clustering)** :订单簿中的限价订单并非均匀分布在所有价格水平，而是倾向于在某些特定价格点（通常是整数价位或重要的技术水平）附近聚集，形成所谓的“流动性区域”或“订单墙” 。这些聚集的买单构成了潜在的支撑位，而聚集的卖单则形成潜在的阻力位 。流动性区域会像磁石一样吸引价格向其移动，并在价格接近时引发显著的交易活动 。

. **订单流的持续性与反转 (Order Flow Persistence and Reversal)** :订单流（新订单的到达序列）在短期内可能表现出持续性，即买单（卖单）的到来倾向于跟随更多的买单（卖单）。然而，在某些条件下，订单流也可能发生反转。这些模式与市场情绪和短期交易策略密切相关。例如，订单簿失衡的变化可以预测订单流的方向 。

. **价格发现过程中的反馈效应 (Feedback Effects in Price Discovery)** :订单簿的状态变化（如价差扩大、深度减少）会反过来影响后续市场参与者的决策。例如，流动性提供者可能会根据订单簿的变化调整其报价策略。这种反馈机制是价格发现过程的重要组成部分，使得订单簿的演化具有内生动态性 。

. **流动性冲击的影响 (Impact of Liquidity Shocks)** :当市场遭遇流动性冲击（例如，大量投资者因突发事件改变其持有资产的意愿或能力）时，订单簿会经历剧烈变化 。典型表现包括：交易价格在冲击发生时急剧下跌，随后缓慢恢复至长期均衡水平；买卖价差在冲击后先扩大，然后随着新的限价单进入而逐渐收窄；市场深度在冲击初期显著降低，之后逐步重建 。这种动态调整过程反映了市场在信息不对称和参与者行为约束下的适应性。

. **日内模式 (Intraday Patterns)** :订单簿的各项指标（如交易量、波动率、价差、订单到达率）在交易日内常常呈现出可预测的模式，最典型的是U型或J型模式 。即在开盘和收盘时段，市场活动更为活跃，价差可能收窄，深度增加；而在午盘时段，活动相对平缓。这些日内模式与交易者的作息习惯、信息发布时间以及机构投资者的交易行为有关。

理解这些常见现象对于构建更符合实际的订单簿模型至关重要，因为它们代表了模型需要捕捉和解释的关键市场行为。

### **B. 订单簿动态性的统计特征**

除了宏观现象，订单簿的微观动态也展现出一些稳定的统计特征，这些特征为量化建模提供了经验基础。

. **订单到达率 (Order Arrival Rates)** :新订单（包括限价单、市价单和取消单）的到达并非完全随机。研究表明，订单到达的频率与当前买卖价差的距离有关，越靠近价差的价位，订单到达越频繁 。泊松过程常被用作订单到达的基础模型，其强度参数（到达率）可以设定为价差距离的函数，例如幂律函数 λ(i)=k⋅i−α，其中 i 是与最优报价的距离 。此外，订单流在时间上存在聚集现象，即订单的到达在时间上并非独立，而是呈现短期内的集中爆发 。

. **订单规模分布 (Order Size Distribution)** :提交到订单簿的订单规模（即股数或合约数）的分布通常是重尾的（heavy-tailed），意味着大额订单虽然不频繁，但时有发生，并且对市场有显著影响 。幂律分布常被用来描述订单规模的尾部特征。

. **订单生命周期 (Order Lifetimes)** :限价单在订单簿中停留的时间（从提交到被执行或取消）被称为其生命周期。实证研究发现，已取消限价单和已执行限价单的生命周期分布均近似服从幂律分布，但指数可能有所不同 。这表明大部分限价单的生命周期很短，但也有少数订单会在簿中停留较长时间。

. **平均订单簿形态 (Average Order Book Shape)** :对订单簿在一段时间内的快照进行平均，可以得到平均订单簿形态，即在不同价格水平（相对于中间价或最优报价）的平均订单量。研究发现，平均订单簿通常呈现出一种“驼峰状”（humped shape） 。即最大量的订单并非堆积在最优买卖价位，而是在离最优价位有一定距离的地方。这种形态的产生是由于最优价位附近的订单更容易被快速执行，而稍远价位的订单则相对稳定。这种形态在不同股票和市场中具有一定的普适性，可以通过“零智能”模型（即假设交易者行为随机）在一定程度上复现 。

这些统计特征是订单簿动态性的微观体现，任何旨在真实模拟市场行为的订单簿模型都应力求再现这些“风格化事实”（stylized facts）。

## **IV. 订单簿建模方法**

为了理解和预测订单簿的复杂动态，研究人员和从业者开发了多种建模方法。这些方法可以大致分为随机模型、基于智能体的模型和机器学习模型三大类 。每种方法都有其独特的视角和适用范围，同时也面临各自的挑战。

一个简化的订单簿可以用两个字典来表示买方（bids）和卖方（asks），其中键是价格，值是该价格上的订单列表或总数量。为了高效查找最优买卖价和按价格排序，可以使用有序字典（如Python的collections.OrderedDict或第三方库如sortedcontainers.SortedDict）或平衡二叉树等数据结构 。

`# Conceptual Python class for LOB   # [60, 83]   from sortedcontainers import SortedDict      class LimitOrderBook:       def __init__(self):           # Bids: price -> list of [order_id, quantity, timestamp]           # Prices are positive, volumes are positive           # For bids, higher price is better. SortedDict stores keys in ascending order.           # To get best bid (highest price), we'll access the end of the SortedDict.           self.bids = SortedDict()           # Asks: price -> list of [order_id, quantity, timestamp]           # For asks, lower price is better. SortedDict stores keys in ascending order.           # To get best ask (lowest price), we'll access the beginning of the SortedDict.           self.asks = SortedDict()           self.order_map = {} # order_id -> {price, quantity, side} for quick cancellation          def add_order(self, order_id, price, quantity, side, timestamp):           if quantity <= 0 or price <= 0:               print(f"Error: Order {order_id} has invalid price or quantity.")               return              order_details = {'id': order_id, 'price': price, 'quantity': quantity, 'side': side, 'timestamp': timestamp}              if side == 'bid':               if price not in self.bids:                   self.bids[price] =               self.bids[price].append([order_id, quantity, timestamp])               # Sort by timestamp for time priority if multiple orders at same price               self.bids[price].sort(key=lambda x: x)               self.order_map[order_id] = order_details           elif side == 'ask':               if price not in self.asks:                   self.asks[price] =               self.asks[price].append([order_id, quantity, timestamp])               self.asks[price].sort(key=lambda x: x)               self.order_map[order_id] = order_details           else:               print(f"Error: Order {order_id} has invalid side {side}.")          def cancel_order(self, order_id):           if order_id not in self.order_map:               print(f"Error: Order {order_id} not found for cancellation.")               return              order = self.order_map.pop(order_id)           price = order['price']           side = order['side']              if side == 'bid':               if price in self.bids:                   self.bids[price] = [o for o in self.bids[price] if o!= order_id]                   if not self.bids[price]:                       del self.bids[price]           elif side == 'ask':               if price in self.asks:                   self.asks[price] = [o for o in self.asks[price] if o!= order_id]                   if not self.asks[price]:                       del self.asks[price]           print(f"Order {order_id} cancelled.")          def _match_orders(self, aggressing_order_quantity, aggressing_order_price, aggressing_side):           trades =           remaining_quantity = aggressing_order_quantity              if aggressing_side == 'buy': # Market buy order or limit buy order crossing the spread               book_to_match = self.asks               # Iterate through ask prices from lowest to highest               for price_level in list(book_to_match.keys()): # list() to allow modification during iteration                   if remaining_quantity == 0: break                   # If limit buy, only match if ask price <= limit price                   if aggressing_order_price is not None and price_level > aggressing_order_price:                       break                      orders_at_level = book_to_match[price_level]                   for order_idx in range(len(orders_at_level)):                       if remaining_quantity == 0: break                       resting_order_id, resting_order_quantity, _ = orders_at_level[order_idx]                          trade_quantity = min(remaining_quantity, resting_order_quantity)                       trades.append({'price': price_level, 'quantity': trade_quantity, 'resting_order_id': resting_order_id})                          remaining_quantity -= trade_quantity                       orders_at_level[order_idx] -= trade_quantity # Update resting order quantity                      # Remove fully filled orders and empty price levels                   book_to_match[price_level] = [o for o in orders_at_level if o > 0]                   if not book_to_match[price_level]:                       del book_to_match[price_level]              elif aggressing_side == 'sell': # Market sell order or limit sell order crossing the spread               book_to_match = self.bids               # Iterate through bid prices from highest to lowest               for price_level in reversed(list(book_to_match.keys())): # list() for modification                   if remaining_quantity == 0: break                   # If limit sell, only match if bid price >= limit price                   if aggressing_order_price is not None and price_level < aggressing_order_price:                       break                      orders_at_level = book_to_match[price_level]                   for order_idx in range(len(orders_at_level)):                       if remaining_quantity == 0: break                       resting_order_id, resting_order_quantity, _ = orders_at_level[order_idx]                          trade_quantity = min(remaining_quantity, resting_order_quantity)                       trades.append({'price': price_level, 'quantity': trade_quantity, 'resting_order_id': resting_order_id})                          remaining_quantity -= trade_quantity                       orders_at_level[order_idx] -= trade_quantity                      book_to_match[price_level] = [o for o in orders_at_level if o > 0]                   if not book_to_match[price_level]:                       del book_to_match[price_level]              # Update order_map for partially filled orders or remove fully filled           for trade in trades:               if trade['resting_order_id'] in self.order_map:                   self.order_map[trade['resting_order_id']]['quantity'] -= trade['quantity']                   if self.order_map[trade['resting_order_id']]['quantity'] <= 0:                       self.order_map.pop(trade['resting_order_id'])              return trades, remaining_quantity          def process_market_order(self, order_id, quantity, side, timestamp):           if quantity <= 0:               print(f"Error: Market order {order_id} has invalid quantity.")               return, quantity              trades, remaining_quantity = self._match_orders(quantity, None, side) # None for price indicates market order              if trades:               print(f"Market order {order_id} ({side} {quantity}) executed: {trades}")           if remaining_quantity > 0:               print(f"Market order {order_id} partially unfilled, remaining: {remaining_quantity}")           return trades, remaining_quantity          def process_limit_order(self, order_id, price, quantity, side, timestamp):           if quantity <= 0 or price <= 0:               print(f"Error: Limit order {order_id} has invalid price or quantity.")               return, quantity              # Attempt to match immediately           aggressing_price = price           trades, remaining_quantity = self._match_orders(quantity, aggressing_price, side)              if trades:               print(f"Limit order {order_id} ({side} {price}@{quantity}) partially matched on entry: {trades}")              if remaining_quantity > 0:               # Add remaining quantity to the book               self.add_order(order_id, price, remaining_quantity, side, timestamp)               print(f"Limit order {order_id} (remaining {remaining_quantity}) added to book at price {price}.")              return trades, remaining_quantity             def get_best_bid(self):           if not self.bids:               return None           return self.bids.peekitem(-1) # Highest price          def get_best_ask(self):           if not self.asks:               return None           return self.asks.peekitem(0) # Lowest price          def display_book(self, levels=5):           print("\n--- Order Book ---")           # Display Asks (from lowest price up)           print("Asks (Price: Quantity):")           ask_count = 0           for price, orders in self.asks.items():               if ask_count >= levels: break               total_quantity = sum(o for o in orders)               print(f"  {price:.2f}: {total_quantity}")               ask_count += 1              print("------------------")           # Display Bids (from highest price down)           print("Bids (Price: Quantity):")           bid_count = 0           for price, orders in reversed(self.bids.items()):               if bid_count >= levels: break               total_quantity = sum(o for o in orders)               print(f"  {price:.2f}: {total_quantity}")               bid_count += 1           print("------------------\n")   `

### **A. 概述与分类**

**随机模型 (Stochastic Models)** : 这类模型通常从宏观层面描述订单流（如限价单、市价单、取消单的到达）和价格动态的随机过程。它们的目标是捕捉订单簿的关键统计特性和动态规律。常见的随机模型包括基于泊松过程和排队论的模型、霍克斯过程模型以及随机微分方程模型。这类模型的优势在于数学上的严谨性和可分析性，但可能难以完全捕捉市场参与者的复杂异质行为。

**基于智能体的模型 (Agent-Based Models, ABMs)** : ABMs 从微观层面构建市场，通过模拟大量具有不同目标、信息和交易策略的“智能体”（agents）的交互行为，来观察订单簿动态和价格形成的涌现现象 。ABMs 的优势在于能够灵活地设定智能体的行为规则，从而研究特定市场机制或交易策略的影响。然而，ABMs 的校准和验证通常非常复杂，且模型结果可能对智能体的行为假设高度敏感 。

**机器学习模型 (Machine Learning Models)** : 随着大数据和计算能力的进步，机器学习方法在订单簿建模领域得到了广泛应用。这类模型，特别是深度学习模型，能够从高频订单簿数据中自动学习复杂的非线性模式，用于预测价格变动、订单流强度或识别交易信号 。监督学习模型（如LSTM、CNN）常用于预测任务，而强化学习则用于优化交易策略，生成模型（如GANs、扩散模型）则用于生成逼真的合成订单簿数据 。机器学习模型的强大拟合能力是其主要优势，但其“黑箱”特性和过拟合风险是需要关注的问题 。

不同类型的模型在解释能力、预测精度、计算成本和数据需求方面各有侧重。例如，随机模型通常更具解释性但可能牺牲部分预测精度，而复杂的机器学习模型可能预测能力很强但难以解释其决策过程。ABMs 则在模拟市场参与者互动和市场机制方面表现出色，但其构建和校准成本较高。实践中，选择何种模型取决于具体的研究目标和应用场景。一个新兴的趋势是发展混合模型，例如将数据驱动的随机组件嵌入到ABM框架中，以期结合不同方法的优点 。

### **B. 随机模型**

随机模型是订单簿建模的重要分支，它们试图用概率过程来描述订单簿的演化。

. 基于泊松过程和排队论的模型 (Poisson Process and Queueing Theory Models)：

这类模型将订单簿的动态类比为一个排队系统 。限价订单在队列中等待被市价单执行或被取消。订单的到达（限价单、市价单）和离开（取消单、执行单）被建模为独立的泊松过程 。泊松过程的到达率（强度）通常被设定为依赖于订单价格与当前最优买卖价的距离，经验研究表明，订单更频繁地出现在当前价差附近 。例如，距离最优相反报价 i 个价位（ticks）的限价单到达率可设为 λ(i) 。取消率则可能与该价位上已有的订单数量成正比 。 在这些假设下，订单簿在每个价格水平上的订单数量可以被追踪为一个连续时间马尔可夫过程 。这类模型的优点在于其数学上的可处理性，允许研究者使用拉普拉斯变换等方法解析地计算各种条件概率，如中间价变动的概率、特定订单在价格变动前被执行的概率等，而无需完全依赖模拟 。然而，简单的泊松过程假设（如事件间的独立性）可能无法完全捕捉真实市场中订单流的聚集（clustering）和自相关等复杂特性。

. 霍克斯过程模型 (Hawkes Process Models)：

为了克服泊松过程在描述订单流聚集性和相互激发效应方面的不足，霍克斯过程被引入到订单簿建模中 。霍克斯过程是一种自激励点过程，其当前的事件发生强度不仅取决于一个基础强度，还受到过去事件历史的影响 。这意味着一个订单的到来可能会增加后续订单（同类型或不同类型）在短期内到来的概率，从而能够更好地捕捉订单流的时间聚集性、波动率聚集以及不同订单类型之间的交叉相关性 。 与泊松过程相比，霍克斯过程能够内生地产生订单流的内源性激发和隐含的市场冲击效应，而无需显式地对市场中个体交易者的行为进行建模 。多维霍克斯过程可以用来分别建模买卖双方不同事件类型（如限价单提交、市价单成交、订单取消）的到达过程 。研究还关注于选择合适的核函数（kernel function）来描述历史事件对当前强度的影响，例如幂律核函数可能比指数衰减核函数更符合经验数据 。最近的研究还提出了复合霍克斯过程（Compound Hawkes Process），其中每个事件不仅有到达时间，还有一个从校准分布中抽样的订单规模，使得模型更加逼真 。

. 随机微分方程模型 (Stochastic Differential Equation, SDE Models)：

SDE模型通常对订单簿状态（如价格、深度）的演化进行连续时间近似，关注其长期动态和稳态行为 。这些模型常包含扩散项（diffusion）来表示随机波动，以及对流项（convection）来表示确定性趋势或订单的迁移 。 一种常见的SDE建模思路是将点过程模型（如泊松过程）在特定标度极限下（scaling limits）近似为SDEs。例如，订单流不平衡或价格过程在重交易极限（heavy-traffic limits）下可能收敛于布朗运动或其他扩散过程 。另一种方法是将订单簿在每个价格水平的量视为一个连续的密度函数，其演化由随机偏微分方程（SPDE）描述，其中订单的取消和修改可能被建模为扩散和对流过程 。 SDE/SPDE模型的优势在于其数学上的优雅和分析的便利性，特别是在进行渐近分析和解决最优控制问题（如最优执行、做市策略）时 。然而，这些模型往往难以获得显式解，需要依赖数值近似，并且校准到真实市场数据可能非常复杂。它们通常需要大量的计算资源进行模拟 。

随机模型为理解订单簿的宏观统计行为提供了有力的工具，但它们在捕捉微观层面交易者异质性和策略互动方面存在局限性。

### **C. 基于智能体模型 (Agent-Based Models - ABMs)**

基于智能体的模型（ABMs）采用自下而上的方法来模拟订单簿动态，通过构建一个包含多个异质性交易智能体的虚拟市场环境，观察其交互行为如何共同塑造市场微观结构 。

ABMs的核心思想是，市场的宏观现象（如价格波动、流动性变化、风格化事实）是微观层面众多智能体决策和互动的结果。这些智能体被赋予不同的特征，例如：

-   **交易策略** :如趋势跟踪、均值回归、做市策略、套利策略等。
    
-   **信息水平** :知情交易者、不知情交易者、噪音交易者。
    
-   **风险偏好** :风险厌恶、风险中性、风险寻求。
    
-   **行为规则** :例如，智能体如何根据市场信息（如当前价格、深度、波动率）决定提交限价单、市价单或取消订单。
    

在ABM模拟中，每个智能体根据其内部逻辑和对市场状态的感知独立做出决策。这些决策（即订单）被提交到模拟的订单簿中，并按照预设的匹配规则进行撮合。通过模拟大量智能体在一段时间内的持续互动，ABMs能够再现许多在真实市场中观察到的复杂动态和经验特征，例如价格的波动聚集、肥尾收益率分布、订单簿的驼峰形态等 。

ABMs的一个主要优势在于其灵活性和解释能力。研究者可以精确控制智能体的设计和市场环境的参数，从而研究特定因素（如某种交易行为、市场机制改革、信息不对称程度）对市场动态的影响 。例如，可以通过引入不同类型的智能体（如高频交易者）来分析其对市场流动性和稳定性的贡献。

然而，ABMs也面临一些显著挑战：

-   **校准 (Calibration)** :如何将模型中的众多参数（如智能体的策略参数、数量比例等）校准到与真实市场数据相符，是一个非常困难的问题 。这通常需要复杂的优化算法和大量的计算资源 。
    
-   **验证 (Validation)** :验证ABM能否真实反映现实市场行为是一个持续的挑战。由于模型的复杂性，很难确保其预测能力或结论的普适性。
    
-   **智能体设计的客观性/主观性 (Agent Design Subjectivity)** :智能体的行为规则往往基于研究者的假设，这可能引入主观性，使得模型结果依赖于这些特定的假设 。
    

为了克服部分局限性，研究者们也在探索混合模型。例如，神经随机基于智能体的模型（NS-ABM）尝试将数据驱动的随机模型（如基于神经网络的霍克斯过程，用于模拟“背景交易者”或市场整体行为）与传统的、具有明确策略的智能体相结合 。这种方法旨在利用真实数据的统计特性来约束模型的整体行为，同时保留ABM在模拟策略互动方面的优势。开源的ABM模拟平台（如ABIDES ）也为研究者提供了构建和测试复杂市场模型的工具。

### **D. 机器学习模型**

机器学习（ML）方法，特别是深度学习（DL）技术，已成为分析和建模订单簿动态的强大工具。这些方法能够从大规模、高维度、高频率的订单簿数据中自动提取复杂模式和非线性关系，用于预测、分类或生成任务。

**特征工程 (Feature Engineering)** ： 尽管深度学习模型可以直接处理原始数据，但精心设计的特征工程往往能显著提升模型性能和可解释性。从原始订单簿数据（通常是多层次的价格和量信息）中，可以构建多种有意义的特征 ，例如：

-   **价差相关特征** :当前买卖价差、相对价差、VWAP价差。
    
-   **深度相关特征** :各级深度、累计深度、深度斜率。
    
-   **失衡特征** :订单簿失衡（OBI）、标准化OBI（NOBI）、量价加权失衡。
    
-   **价格变动特征** :近期中间价变动、价格波动率。
    
-   **时间相关特征** :订单到达间隔时间、订单持续时间。
    
-   **订单流特征** :近期市价单/限价单/取消单的数量和方向。 数学上，例如，一个简单的失衡指数 It 可以定义为 It=(Vtb−Vta)/(Vtb+Vta)，其中 Vtb 和 Vta 分别是加权的买方和卖方量 。这些特征为后续的ML模型提供了更结构化和信息更密集的输入。
    

**监督学习 (Supervised Learning - LSTM, CNN)** ： 监督学习模型常用于预测任务，如预测未来短期内的中间价变动方向（上涨、下跌、平稳）或订单流强度。

-   \*\*循环神经网络 (Recurrent Neural Networks, RNNs)\*\*，特别是长短期记忆网络 (Long Short-Term Memory, LSTM)，非常适合处理订单簿数据的时间序列特性 。LSTM能够捕捉数据中的长期依赖关系，这对于理解订单簿的演化历史和当前状态至关重要。
    
-   **卷积神经网络 (Convolutional Neural Networks, CNNs)** 也被成功应用于订单簿分析 。一种常见的做法是将订单簿快照（即特定时刻的多级买卖价格和量）视为二维图像，其中价格水平和订单类型（买/卖）构成图像的维度，订单量则对应像素强度 。CNN能够有效地从这种“图像化”的订单簿表示中提取空间特征（如不同价格水平之间的关系）和局部模式。混合CNN-LSTM模型也常被用于结合两者的优势 。
    

.**强化学习 (Reinforcement Learning, RL)** ： 强化学习为学习最优交易策略提供了一个强大的框架 。在RL中，一个智能体（交易算法）通过与环境（订单簿或其模拟器）交互来学习。智能体在每个时间步观察市场状态（如订单簿特征），执行一个动作（如下单、取消订单、持仓），并接收一个奖励（如利润或损失）。通过最大化累积奖励，智能体可以学习到在不同市场条件下如何做出最优决策。RL在最优执行、做市和高频交易策略的自动发现方面显示出巨大潜力。

**生成模型 (Generative Models - GANs, Diffusion Models)** ： 生成模型旨在学习真实订单簿数据的分布，并生成具有相似统计特性的合成订单簿数据 。这对于扩充训练数据集、进行更稳健的策略回测（因为可以生成历史未曾出现但可能发生的市场情景）以及理解市场生成机制非常有价值。生成对抗网络（GANs）和最近兴起的扩散模型（Diffusion Models）已被用于生成逼真的订单簿快照序列或订单流事件 。评估这些生成模型的质量是一个重要的研究课题，通常涉及比较生成数据与真实数据在各种风格化事实和分布特性上的一致性 。

机器学习模型为订单簿分析和建模开辟了新的途径，但也带来了挑战，如模型的可解释性、过拟合的风险、对数据质量的高度敏感性以及模型校准的复杂性 。

  

  

  

  

  

更多代码及资源见星球，加入QuantML星球，与星主和800+专业人士一起交流学习：

![](assets/001.jpg)