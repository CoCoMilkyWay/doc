# 九坤联手亚研院复现DeepSeek-R1

QuantML QuantML 2025-02-25 21:03 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247489459&idx=1&sn=df1570e67f438ce466244624d44d76a8&chksm=cf89b722e5fe606bdc5230ff298bc76ec4f27dce51383d903abb380f050facc1930faa1af35b#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247489459&idx=1&sn=df1570e67f438ce466244624d44d76a8&chksm=cf89b722e5fe606bdc5230ff298bc76ec4f27dce51383d903abb380f050facc1930faa1af35b#rd)

### 

###   

![](assets/001.png)

### 1\. 引言

本论文探讨了基于规则的强化学习（RL）在大型推理模型中的应用潜力，特别是如何通过这种技术提升模型的推理能力。我们受到DeepSeek-R1的启发，尝试在更小的模型规模上复现类似的推理能力，并解决当前研究中存在的可重复性问题。

#### 1.1 研究背景与动机

近年来，大型语言模型（LLMs）的推理能力取得了显著进展。DeepSeek-R1通过一种简单而有效的基于规则的强化学习方法，实现了无需传统搜索技术（如蒙特卡洛树搜索MCTS或过程奖励模型PRM）的推理模式涌现。然而，这些进展在可重复性方面存在不足。DeepSeek-R1虽然开源了模型权重，但未发布相应的训练代码或数据集，这引发了以下关键问题：

1.  **模型规模与推理能力的关系**：是否可以在更小规模的模型中涌现类似的推理能力？
    
2.  **训练数据结构的优化**：什么样的训练数据结构最有利于培养推理能力？
    
3.  **可重复性的方法论**：哪些方法可以可靠地复现这些结果？
    

为了回答这些问题，我们需要一个受控的实验框架来隔离关键变量。数学通常被视为推理的通用测试平台，但像GSM8K和Omini-MATH这样的常用数学数据集由于问题复杂度的不可控性，不适合作为训练数据。因此，我们选择了一种程序生成的“骑士与流氓”（K&K）逻辑谜题数据集，该数据集具有可控的难度级别和易于规则验证的特点，非常适合研究推理动态。

#### 1.2 研究目标与贡献

本论文提出了一种名为Logic-RL的基于规则的强化学习框架，该框架通过在逻辑谜题上进行训练来获得类似R1的推理模式。主要贡献包括：

-   **系统提示设计**：强调思考和回答过程的系统提示。
    
-   **严格的格式奖励函数**：惩罚采取捷径的输出。
    
-   **改进的训练方法**：对REINFORCE++算法进行了一些修改，以实现更稳定的收敛。
    

经过仅5000个逻辑问题的训练，我们的7B模型在AIME和AMC等具有挑战性的数学基准测试中表现出色，展示了强大的泛化能力。

### 2\. 方法

#### 2.1 数据合成

K&K谜题数据集具有以下特点：

1.  **程序化生成**：使用逻辑模板系统地生成谜题，确保一致性和无限的可变性。这些谜题对于原始模型来说是未见过的数据，非常适合测试泛化能力。
    
2.  **可控的难度级别**：通过改变角色数量（2-8人）和逻辑操作的复杂度（1-4个布尔运算符的组合）来精确调整谜题的难度。此外，更复杂的谜题可以作为对在简单案例上训练的模型的分布外测试，提供对其泛化能力的洞察。
    
3.  **易于验证**：每个谜题都有一个明确的、唯一的正确答案，生成算法保证了正确性。解决方案需要严格的演绎推理，允许对模型响应进行准确评估，并最大限度地降低奖励黑客攻击的风险。
    

#### 2.2 基于规则的奖励建模

奖励作为强化学习中的主要训练信号，指导优化过程。我们持续监控模型输出中的黑客行为，并不断改进奖励设计，最终形成了一个几乎无法被黑客攻击的基于规则的奖励系统，该系统仅包含两种类型的奖励：格式奖励和答案奖励。

**系统提示**

系统提示要求模型首先在<think></think>标签内思考推理过程，然后提供答案，并在<answer></answer>标签内给出最终结论。

**格式奖励**

我们使用正则表达式提取来强制执行结构化响应格式。模型被要求将推理过程放在<think></think>标签内，并将最终结论放在<answer></think>标签内。此外，我们建议在提示末尾直接包含一个<think>标签，这显著降低了基础模型遵循我们指令的难度。

在早期不完善的规则设计下，我们观察到了一些奖励黑客现象，例如：

-   跳过<think></think>过程，直接回答。
    
-   将推理放在<answer></answer>标签内。
    
-   反复猜测答案而不进行适当的推理。
    
-   除了提供答案外，还包含不相关的废话。
    
-   以错误的格式组织正确答案以进行提取。
    
-   在已经输出<answer>后，由于推理不足而重新进入思考阶段。
    
-   重复原始问题或使用“思考过程在这里”等短语来避免真正的推理。
    

我们根据这些现象不断改进规则设计。例如，每个标签应该只出现一次，并且按照正确的顺序出现，思考过程必须包含真正的推理，结论应以可提取和可读的方式呈现。通过强制执行这些约束，我们确保不同的操作根据其对格式的遵守程度获得相应的奖励。格式得分（S\_format）计算如下：

**答案奖励**

第二个组件评估模型响应中内容的正确性。一旦验证了格式，我们检查模型的答案是否与真实答案匹配。答案得分（S\_answer）计算如下：

#### 2.3 RL算法

我们采用了一种改进版的REINFORCE++作为我们的基线算法，与GRPO相比，它在我们的实验设置中表现出更优越的性能。这些算法的详细比较见第4节。

**强化回报计算**

每个轨迹的折扣累积奖励计算如下，其中γ是折扣因子，在我们的实验中设置为1：

根据DeepSeek-Math的建议，我们在PPO的实现中加入了几个小的改进。

**第一次修改：使用KL损失**

计算RL模型和SFT模型的响应分布之间的KL散度，并将其作为PPO奖励函数中的惩罚项纳入训练中。每个令牌的每令牌奖励定义如下：

其中是一个身份函数，当达到令牌时评估为1，β控制KL惩罚的权重。

相比之下，GRPO的实现并没有将KL散度作为奖励函数的一部分。相反，它直接将KL散度纳入损失函数，认为这种方法简化了计算并避免了不必要的复杂性。根据这一原理，我们还像GRPO一样使用KL损失：

**第二次修改：KL估计**

另一个关键区别在于KL散度的估计方式。PPO的默认KL估计器定义如下：

这种方法确保了KL估计值始终为非负，而原始公式可能会产生负值。GRPO的估计器在训练过程中提供了更稳定可靠的散度度量。

在实施这些修改后，我们继续进行实验。

### 3\. 实验

我们首先尝试了Qwen2.5系列中的各种模型作为潜在的基线候选。例如，Qwen2.5-Math-7B表现出强烈的生成Python代码块的倾向，这通常与我们的严格格式要求相冲突。尽管我们通过删除系统提示和惩罚特定的markdown样式来试图缓解这种行为，但仍然很难完全解决。

此外，我们测试了Qwen2.5-7B-Base和Qwen2.5-7B-Instruct作为起点。令人惊讶的是，我们发现基础模型和指令模型在RL训练期间的训练指标几乎相同，包括验证准确率、响应长度增长曲线和奖励曲线。基础模型与指令模型的详细比较见附录7。然而，指令模型在测试准确率上表现出略高的性能，因此成为首选。因此，我们选择了Qwen2.5-7B-Instruct-1M作为我们的基线。

值得注意的是，尽管训练数据集仅限于3到7人的K&K逻辑谜题，样本数量不足5000，但模型表现出显著的泛化能力，能够处理分布外（OOD）场景，例如8人谜题。

### 4\. 研究问题

#### RQ1：GRPO与其他RL算法相比如何？

GRPO是否在训练稳定性、速度和性能准确性方面优于其他强化学习算法，如REINFORCE++和PPO？

结果表明，PPO在准确性和奖励方面具有显著优势。然而，在训练速度方面，它比REINFORCE++慢138%。另一方面，REINFORCE++在稳定性和性能提升以及训练效率方面优于GRPO。总体而言，REINFORCE++在几乎所有指标上都优于GRPO，而GRPO在我们的实验中表现最弱。

#### RQ2：某些思考令牌和语言混合现象是否改善了推理？

包含复杂推理行为（如探索、验证、总结和回溯）和语言切换是否提高了模型的推理能力？

我们观察到：

1.  语言混合显著降低了推理能力。
    
2.  虽然像“wait”、“verify”、“yet”和“re-evaluate”这样的术语显示出显著的性能提升，但并非所有复杂的思考令牌都能增强推理能力，例如“recheck”。
    
3.  复杂的推理行为“recheck”明显降低了推理能力，可能是因为它的使用表明模型对其答案的不确定性。
    
4.  “re-evaluate”和“reevaluate”之间存在明显区别：前者导致答案得分高得多，而后者则降低了得分。当我们检查其原始响应时，“reevaluate”几乎从未出现过，而“re-evaluate”却经常出现。这可能表明模型对在预训练语料库中更频繁出现的单词更感到舒适。
    

#### RQ3：训练过程中是否会出现“Aha时刻”？

在RL过程中，是否存在一个可观察到的“Aha时刻”，即模型在推理能力上表现出显著的飞跃，例如在RL过程中出现多步骤验证或反思？

随着性能的增长，复杂行为的出现变得越来越明显。这些行为包括反思行为——模型重新审视和重新评估之前的步骤——以及自发探索替代问题解决策略。这些行为并非明确地植入训练语料库中，而是通过模型与强化学习环境的交互自然涌现，与Ye等人的发现一致。

R1报告中提到的“Aha时刻”主要是指模型突然获得复杂推理行为。另一种解释是模型自发地说出“Aha时刻”，例如在短语中“等等，等等。等等。这是我可以标记的Aha时刻”。虽然我们的模型没有表现出这种具体的言语化，但图4显示，即使在第10步，它也表现出一些复杂的推理行为（例如自我反思、探索、验证、总结）。

因此，我们得出结论，RL过程可能缺乏突然的“Aha时刻”——也就是说，复杂推理行为不会在特定的训练步骤突然出现，这与Liu等人的观点一致。

#### RQ4：模型能否泛化到分布外（OOD）任务？

训练有素的模型在多大程度上能够处理与其训练数据不同的任务，特别是那些分布外的数据？

模型超越其训练分布的能力是人工智能研究的核心。我们调查了在RL过程中自然出现的复杂推理能力（例如探索、验证、总结和回溯）是否可以转移到高度具有挑战性的数学推理场景中，我们称之为超级OOD。

这一评估利用了广泛采用的美美国邀请数学考试（AIME）2021-2024和美国数学竞赛（AMC）2022-2023基准测试，这两个测试以其严格多样的问题集而闻名。

从图5中我们可以看出，模型的超级OOD泛化能力非常强，在AIME数据集上总体提升了125%，在AMC数据集上提升了38%。这种同步提升表明，强化学习过程不仅提高了模型在分布内任务的性能，还促进了强大且可转移的推理策略的出现。

这些发现表明，在RL训练期间学习的推理技能超越了K&K数据集的特定模式。这突出了RL在超越其训练环境方面的潜力。

#### RQ5：SFT还是RL的泛化能力更好？

后训练方法能否实现不仅仅是表面的对齐，即只学习格式模式？SFT或RL能否真正学会学习，有效泛化到其他领域？

我们调查了模型是仅仅记忆训练数据还是真正学会推理技能。根据\[17\]中的设置，我们通过比较对熟悉问题的表现与稍微改变的问题的表现来测试这一点。记忆的两个迹象：对已见问题的准确率高，对稍微扰动的版本准确率低。因此，我们使用两个指标来衡量，模型表示为f，数据集表示为D。

1.  对观察到的问题的准确率：Acc(f;D)，模型在训练集（Tr）上的准确率。
    
2.  一致性比率：CR(f;D)，在小的变化（扰动）后正确解决方案与未变化时解决的比率。扰动保留了谜题的核心原则和难度。
    

本地不一致性记忆得分定义为：

这个得分同时捕捉了记忆和对变化的敏感性。如果模型在问题格式改变时的表现显著下降，那么它可能没有学会解决类似但修改过的谜题的真正推理技能。我们研究了两种类型的扰动：（i）将一个人的陈述改为另一个布尔逻辑表达式，（ii）重新排序不同人之间的陈述。扰动的例子如下：

原始问题：

Zoey说：“Oliver不是骑士”。Oliver说：“Oliver是骑士当且仅当Zoey是流氓”。那么谁是骑士，谁是流氓？

陈述扰动：

Zoey说：“Oliver是骑士或Zoey是骑士”。Oliver说：“Oliver是骑士当且仅当Zoey是流氓”。

重新排序扰动：

Oliver说：“Oliver是骑士当且仅当Zoey是流氓”。Zoey说：“Oliver不是骑士”。

虽然收集合适的SFT数据集具有挑战性，但我们采用拒绝抽样来收集地面真值数据，称为RFT方法。

为了探索哪种训练范式提供更好的泛化性能，我们对训练数据集应用两种类型的扰动，然后比较RFT和RL与测试acc - Mem得分曲线。对于RFT设置，我们使用拒绝抽样对原始模型，然后使用基于规则的Best-of-N方法收集正确但最短的响应以进行进一步微调。结果，我们得到了图6所示的曲线，它显示了未测试准确率和训练数据集记忆随训练过程的变化。

RFT记忆而RL泛化。RFT（拒绝抽样微调）在略微提高测试准确率的同时，迅速增加了LiMem(𝑓;𝑇𝑟¯)，表明它主要学习表面答案格式而不是真正的推理。相比之下，RL在LiMem(𝑓;𝑇𝑟)几乎没有甚至负增长的情况下，实现了更高的测试准确率。在相同的LiMem区间内，RL在测试acc方面大大优于RFT，表明更好的泛化能力。

较高的记忆得分表明，由于训练造成的扰动，原本正确的更多问题变得不正确，反映了更大的记忆程度。SFT倾向于表面对齐，通常变得过于依赖原始数据的表达格式。另一方面，RL鼓励模型独立探索，培养源于增强推理能力的泛化能力，这与\[1\]中的发现一致。

### 5\. 讨论与未来工作

虽然我们的研究证明了Logic-RL在开发复杂推理技能方面的潜力，但重要的是要注意，我们的发现是基于一个小规模的逻辑数据集。我们的结果对大规模现实世界的数学或编码场景的普遍性仍有待探索。未来的工作应侧重于将我们的方法扩展到更多样化和复杂的数据集，以进一步验证其有效性和稳健性。我们的工作将继续作为一个开放的研究项目，以造福于社区。

链式思维长到短方法。尽管我们的初始提示简洁明了，但在强化学习训练后，响应的长度可以增加到四倍。为了提高令牌效率并适应长上下文友好的训练范式，我们发现探索将长响应转换为更短、更易消化的格式的方法特别有价值。这一调查旨在提高处理长输出的整体效率和效果，从而优化训练过程以获得更好的可扩展性和性能。

稳定RL训练。我们发现，在某些情况下，消除KL约束是有益的，特别是当从强大的基础模型开始时。此外，在训练开始时引入更高的温度似乎为模型提供了一个更多样化的起点。我们计划进一步研究SFT阶段如何影响RL训练的效果和效率。

混合语言推理。一个有趣的现象是，尽管训练数据完全是英语，但模型在<think>部分频繁使用中文标记。一个假设是，中文词汇向量中的某些标记可能会产生在我们的RL方案下“有利的”隐藏状态。调查代码切换甚至随机标记切换是否能够系统地帮助内部推理是一个令人兴奋的方向。

放宽格式限制。虽然<think>... </think>有效地组织了思维链，但它仍然是一个开放的问题，一个完全不受约束或潜在的方法是否可能产生更好的结果。如果给予正确的激励，模型最终可能会“发明”自己的内部表示来进行推理。

  

加入LLM交流群，与论文作者一起交流

![](assets/002.jpg)

  

  

加入QuantML星球，与750+专业人士一起交流学习：

![](assets/003.png)

  

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