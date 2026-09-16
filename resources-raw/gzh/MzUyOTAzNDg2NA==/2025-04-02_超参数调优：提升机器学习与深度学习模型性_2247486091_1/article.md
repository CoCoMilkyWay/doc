# 超参数调优：提升机器学习与深度学习模型性能的关键

fintechhaibin FinTechHi 2025-04-02 21:52 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247486091&idx=1&sn=b756c4f922cfe40b1d691cbf0c2e4459&chksm=fb90cb705ab1c75e69230c0e840adf70f23a4085acf0a1b9bca8bbf3ce56001fde66a71e86cc#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486091&idx=1&sn=b756c4f922cfe40b1d691cbf0c2e4459&chksm=fb90cb705ab1c75e69230c0e840adf70f23a4085acf0a1b9bca8bbf3ce56001fde66a71e86cc#rd)

在机器学习和深度学习中，超参数是指在模型训练之前需要人工手动设置的参数。

这些参数无法从数据中学习得到，而是需要通过调优方法来确定最优值，以便提高模型性能和泛化能力，一般把这个过程称为“超参调优”。

超参调优的方法主要包括：网格搜索、随机搜索、遗传算法、贝叶斯优化等等。

网格搜索（Grid Search）：是超参数调优里比较基础但常用的方法，网格搜索的核心是将每个超参数可能的取值进行排列组合，形成一个 “网格” 状的参数组合集合。然后针对集合里的每一组超参数，都使用它们来训练模型，再用验证集对模型性能进行评估，最后选出在验证集上表现最佳的那组超参数作为最优解。

随机搜索：与网格搜索类似，随机搜索也是在参数空间中进行搜索。不同的是，它不是遍历所有可能的参数组合，而是随机生成一定数量的参数组合进行评估。这种方法可以在一定程度上避免网格搜索的局限性，尤其是在参数空间较大时，能够更有效地探索参数空间。

遗传算法：借鉴了生物进化中的遗传和自然选择原理。首先，随机生成一个初始种群，每个个体代表一组超参数。然后根据个体的适应度（即模型在验证集上的性能）对种群进行选择、交叉和变异操作，生成新的种群。经过多代的进化，种群中的个体逐渐适应环境，即找到更优的超参数组合。

贝叶斯优化算法：基于贝叶斯统计理论，通过构建一个代理模型来近似目标函数。该模型根据已有的采样点来预测未知点的函数值，并根据预测结果选择下一个采样点，以最大化获取最优解的概率。贝叶斯优化算法能够利用历史信息来指导搜索方向，在处理高维参数空间和复杂目标函数时具有较好的性能。

梯度下降法：对于一些可微的目标函数，可以通过计算目标函数关于超参数的梯度，然后沿着梯度的反方向更新超参数，以逐步减小目标函数的值，从而找到最优的超参数。这种方法通常用于深度学习中的神经网络训练，通过调整网络的权重和偏置等超参数来最小化损失函数。

手动调优：凭借领域知识和经验，手动选择不同的超参数组合进行试验和评估。这种方法需要调优者对问题有深入的理解和丰富的经验，能够根据模型的表现和数据特点来合理地调整超参数。虽然手动调优比较耗时，但在某些情况下，可以根据具体问题的特点快速找到较好的超参数组合。

实际操作中，如果使用网格搜索（Grid Search）进行超参数调优时， 可以使用scikit-learn库中用于生成参数网格的工具类ParameterGrid （sklearn.model\_selection模块），它可以将用户提供的参数设置转换为一系列的参数组合，从而在超参数调优时，方便对不同的参数组合进行遍历评估。

### 1\. 导入 `ParameterGrid`

从 `sklearn.model_selection` 模块中导入 `ParameterGrid` 类：

`from sklearn.model_selection import ParameterGrid   `

### 2\. 定义参数网格

参数网格是一个字典，其中每个键代表一个超参数，对应的值是一个列表，包含该超参数的所有可能取值。例如，假设要调优一个简单的线性回归模型的 `alpha`（正则化强度）和 `max_iter`（最大迭代次数）这两个超参数，可以这样定义参数网格：

`param_grid = {       'alpha': [0.1, 1.0, 10.0],       'max_iter': [100, 500, 1000]   }   `

### 3\. 使用 `ParameterGrid` 生成参数组合

创建 `ParameterGrid` 对象，并将参数网格作为参数传递给它。就可以像遍历列表一样遍历 `ParameterGrid` 对象，获取所有可能的参数组合：

`for params in ParameterGrid(param_grid):       print(params)   `

上述代码会输出所有可能的参数组合，例如：

`{'alpha': 0.1, 'max_iter': 100}   {'alpha': 0.1, 'max_iter': 500}   {'alpha': 0.1, 'max_iter': 1000}   {'alpha': 1.0, 'max_iter': 100}   {'alpha': 1.0, 'max_iter': 500}   {'alpha': 1.0, 'max_iter': 1000}   {'alpha': 10.0, 'max_iter': 100}   {'alpha': 10.0, 'max_iter': 500}   {'alpha': 10.0, 'max_iter': 1000}   `

### 4\. 结合模型进行超参数调优

在实际应用中，通常会使用 `ParameterGrid` 生成的参数组合来训练和评估模型，找到最优的参数配置。下面的代码示例，是使用 `ParameterGrid` 对 `Ridge` 回归模型进行超参数调优：

`from sklearn.model_selection import ParameterGrid   from sklearn.datasets import make_regression   from sklearn.linear_model import Ridge   from sklearn.metrics import mean_squared_error   from sklearn.model_selection import train_test_split      # 生成示例数据   X, y = make_regression(n_samples=100, n_features=10, noise=0.5, random_state=42)   X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)      # 定义参数网格   param_grid = {       'alpha': [0.1, 1.0, 10.0],       'max_iter': [100, 500, 1000]   }      best_mse = float('inf')   best_params = None      # 遍历所有参数组合   for params in ParameterGrid(param_grid):       # 创建模型并使用当前参数组合进行训练       model = Ridge(**params)       model.fit(X_train, y_train)              # 在测试集上进行预测       y_pred = model.predict(X_test)              # 计算均方误差       mse = mean_squared_error(y_test, y_pred)              # 更新最佳参数和最佳均方误差       if mse < best_mse:           best_mse = mse           best_params = params      print("Best parameters:", best_params)   print("Best mean squared error:", best_mse)   `

代码中使用 `make_regression` 生成了一个示例回归数据集，然后使用 `ParameterGrid` 生成所有可能的参数组合。对于每个参数组合，创建了一个 `Ridge` 回归模型并进行训练，然后在测试集上进行预测，计算均方误差。最后选择均方误差最小的参数组合作为最佳参数配置。

  

需要注意的是：基于网格搜索的ParameterGrid并非适合任何超参寻优的过程。

当模型的超参数数量不多，且每个超参数的取值范围较窄时，ParameterGrid非常适用。因为它会穷举所有可能的参数组合，因为在小参数空间下，计算量是可以接受的。例如，对于一个简单的决策树模型，可能只需要调整 max\_depth（树的最大深度）和 min\_samples\_split（拆分内部节点所需的最小样本数）这两个超参数，且每个超参数只有少数几个取值，此时使用ParameterGrid可以全面、系统地评估所有组合，找到最优的超参数设置。

另外，如果想要对参数空间进行全面的搜索，确保不遗漏任何可能的最优参数组合，ParameterGrid也是一个不错的选择。比如在对模型性能要求极高，不容错过任何可能的优化机会的情况下，使用ParameterGrid进行网格搜索可以保证对所有参数组合进行评估。

但是如果超参数数量较多，且每个超参数有大量可能的取值时，\`ParameterGrid\` 会生成极其庞大的参数组合数量。

例如，在深度学习模型中，可能有学习率、批量大小、隐藏层神经元数量等多个超参数，每个超参数又有很多可能的值，使用ParameterGrid进行搜索会导致计算量呈指数级增长，需要耗费大量的时间和计算资源，如果没有足够的计算资源（如 CPU、GPU、内存等）来支持对大量参数组合的评估，使用ParameterGrid可能会导致程序运行缓慢甚至无法完成，这种场景下，一般则需要使用随机搜索、贝叶斯优化等方法，这些方法可以在较少的评估次数内找到较优的参数组合。 

当然还有一些第3方参数调优工具，比如：Optuna和Hyperopt。Optuna和Hyperopt主要目标都是自动化超参数调优过程，通过搜索不同的超参数组合，找到能使目标函数（如模型在验证集上的准确率、损失函数值等）达到最优的参数配置，以提高机器学习和深度学习模型的性能；二者都支持多种超参数搜索算法，如随机搜索、遗传算法等，并且都可以方便地集成和扩展自定义的搜索算法；都能与常见的机器学习和深度学习框架（如 TensorFlow、PyTorch、Scikit - learn 等）很好地集成，方便在不同的模型中进行超参数调优。除了这些相同点，二者也存在一些异同，主要如下表所示：

比较维度

Optuna

Hyperopt

搜索算法侧重点

侧重于基于采样的搜索算法，如树结构 Parzen 估计器（TPE），是基于贝叶斯优化的算法，能根据已有采样结果智能选下一个采样点，高效搜索超参数空间

更侧重于基于随机搜索和模拟退火等算法，实际应用中随机搜索及其改进版本使用较广泛，虽也支持其他算法

参数空间定义

用 Python 的函数和类定义参数空间，通过装饰器或上下文管理器声明超参数，代码风格 Pythonic，直观且易理解扩展

用 `hp` 对象定义参数空间，参数定义语法灵活，但不熟悉特定语法的用户需一定学习成本

可视化和跟踪

提供丰富可视化工具和跟踪功能，可查看超参数调优过程，如绘制目标函数随迭代次数变化曲线、超参数间关系图等，助于理解过程和分析结果

有基本跟踪功能，但可视化方面不如 Optuna 强大直观

分布式训练支持

对分布式训练支持好，能方便地在多节点或 GPU 上并行运行超参数调优任务以提高效率

分布式训练配置较复杂，需用户手动做更多设置和管理

  

在实际应用中，可以根据具体的需求和偏好选择适合的工具。如果注重贝叶斯优化和可视化功能，Optuna 可能是一个较好的选择；如果对随机搜索和灵活的参数空间定义有较高要求，Hyperopt 则更具优势。

Optuna的简单代码示例：

```
import optuna
```

Hyperopt的简单代码示例：

```
from hyperopt import fmin, tpe, hp, STATUS_OK
```