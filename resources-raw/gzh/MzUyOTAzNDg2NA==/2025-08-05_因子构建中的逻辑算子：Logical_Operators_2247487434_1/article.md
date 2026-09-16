# 因子构建中的逻辑算子：Logical Operators

fintechhaibin FinTechHi 2025-08-05 08:26 甘肃

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247487434&idx=1&sn=be8245aebab9d82a47576b2dd3d04a8a&chksm=fb304a353d0f1e68bc3f74d379e85a4d6dc07a4f2a08001040edeab86bccce3f5563b170dab8#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247487434&idx=1&sn=be8245aebab9d82a47576b2dd3d04a8a&chksm=fb304a353d0f1e68bc3f74d379e85a4d6dc07a4f2a08001040edeab86bccce3f5563b170dab8#rd)

> worldquant官方对因子所需的基础算子（Operators）的分类和解释，以及通过DeepSeek的解释。

![](assets/001.png)

#### **1. `and(input1, input2)`**

**解释**：逻辑与运算。当 `input1` 和 `input2` 均为 `true` 时返回 `true`，否则返回 `false`。  
**示例**：

-   `and(1, 1) = true`
    
-   `and(1, 0) = false`
    

#### **2. `if_else(input1, input2, input3)`**

**解释**：

### **if\_else(event\_condition, Alpha\_expression\_1, Alpha\_expression\_2)** 

`if_else` 是一个条件选择算子，根据 `event_condition` 的真假返回不同的 Alpha 表达式，event\_condition通常是逻辑表达式（如 `volume > adv20` 或 `returns > 0`）。

-   若 `event_condition` 为 `true`，执行 `Alpha_expression_1`；
    
-   若 `event_condition` 为 `false`，执行 `Alpha_expression_2`。
    

**其中Alpha 表达式**可以是任意复杂因子（如动量、反转、成交量加权等）。主要可用于动态调整策略参数（如波动率自适应、条件止损）。

场景：

-   如果某公司股价在过去 2 天上涨，未来可能下跌（均值回归效应）。
    
-   如果当日成交量高于月均成交量，均值回归效应会更显著。
    

**逻辑**：

-   **Alpha\_expression\_1**（成交量较高时）：  
    使用 `ts_delta(close, 3)` 计算当前收盘价与 3 天前的差值，并乘以 2 放大头寸。
    
-   **Alpha\_expression\_2**（成交量正常时）：  
    直接使用 `ts_delta(close, 3)` 计算差值，不放大头寸。
    

```
if_else(
```

#### **3. `input1 < input2`**

**解释**：小于比较。若 `input1` 小于 `input2` 返回 `true`，否则返回 `false`。  
**示例**：

-   `3 < 5 = true`
    
-   `5 < 3 = false`
    

#### **4. `input1 <= input2`**

**解释**：小于等于比较。若 `input1` 小于或等于 `input2` 返回 `true`。  
**示例**：

-   `3 <= 3 = true`
    
-   `4 <= 3 = false`
    

#### **5. `input1 == input2`**

**解释**：等于比较。若 `input1` 和 `input2` 完全相同（值或逻辑状态）返回 `true`。  
**示例**：

-   `5 == 5 = true`
    
-   `"A" == "B" = false`
    

#### **6. `input1 > input2`**

**解释**：大于比较。若 `input1` 大于 `input2` 返回 `true`。  
**示例**：

-   `10 > 5 = true`
    
-   `2 > 3 = false`
    

#### **7. `input1 >= input2`**

**解释**：大于等于比较。若 `input1` 大于或等于 `input2` 返回 `true`。  
**示例**：

-   `5 >= 5 = true`
    
-   `4 >= 5 = false`
    

#### **8. `input1 != input2`**

**解释**：不等于比较。若 `input1` 和 `input2` 不同返回 `true`。  
**示例**：

-   `5 != 3 = true`
    
-   `"A" != "A" = false`
    

#### **9. `is_nan(input)`**

**解释**：检查输入是否为 `NaN（非数字）`。通过用于在因子计算前预处理缺失值。若是返回 `1`（`true`），否则返回 `0`（`false`）。通常结合 `if_else` 算子，**将 `NaN` 替换为默认值**，避免计算错误或数据污染。根据场景选择替换值（如 `0`、`均值`、`前值填充`等）。

假设有一列股票收益率数据 **`returns`，其中包含 `NaN`，需要将 `NaN` 替换为 `0` 以进行后续计算。**

```
if_else(
```

代码示例：

```
import numpy as np
```

#### **10. `not(x)`**

**解释**：逻辑非运算。若 `x` 为 `true`（`1`）返回 `false`（`0`），反之亦然。  
**示例**：

-   `not(1) = 0`
    
-   `not(0) = 1`
    

`   `

#### **11. `or(input1, input2)`**

**解释**：逻辑或运算。若 `input1` 或 `input2` 至少一个为 `true` 返回 `true`。  
**示例**：

-   `or(1, 0) = true`
    
-   `or(0, 0) = false`