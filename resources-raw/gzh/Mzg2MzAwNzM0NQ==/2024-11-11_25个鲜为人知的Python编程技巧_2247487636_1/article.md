# 25个鲜为人知的Python编程技巧

QuantML QuantML 2024-11-11 20:17 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247487636&idx=1&sn=992b68d14203e24155790dda3e60653e&chksm=cfb727478bd8ee5cb94ca12e947ffdb1e3b6ba5e06b715200ca307f52f923d6f297e111d3a47#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247487636&idx=1&sn=992b68d14203e24155790dda3e60653e&chksm=cfb727478bd8ee5cb94ca12e947ffdb1e3b6ba5e06b715200ca307f52f923d6f297e111d3a47#rd)

#### 

本文旨在向读者介绍25个鲜为人知但非常实用的Python编程技巧，帮助开发者提升编码效率。

### 1\. 使用any()和all()进行快速条件检查

在Python中，编写多个if语句来检查条件会显得冗长且不够优雅。any()和all()函数可以简化这一过程：

-   **any()**:  当传入的可迭代对象中至少有一个元素为真时，返回True。
    
-   **all()**:  当传入的可迭代对象中所有元素都为真时，返回True。
    

例如：

```
data = [0, 1, 2, 3]if any(data):    print("至少有一个真值!")if all(data):    print("所有值都是真值!")
```

**专业提示**: 将any()和all()与列表推导式结合使用，可以使代码更加简洁易读。

### 2\. 使用f"{=}"语法简化变量打印

Python 3.8引入了f字符串的增强功能，允许使用f"{=}"语法来打印变量及其值：

```
name = "Python"print(f"{name=}")# 输出: name= 'Python'
```

这种语法在调试时非常有用，可以避免代码中多余的print语句，使代码更加简洁。

### 3\. 上下文管理器：超越with open()

上下文管理器不仅限于文件操作，还可以用于计时和资源锁定等场景。

-   **计时**:  使用@contextmanager装饰器，可以轻松地为代码块计时。
    

```
from contextlib import contextmanagerimport time@contextmanagerdef timer():    start = time.time()    yield    end = time.time()    print(f"耗时: {end - start:.2f}秒")with timer():    sum([x**2 for x in range(10000)])
```

-   **资源锁定**:  可以使用上下文管理器来锁定资源，确保线程安全。
    

### 4\. 命名元组：字典的增强版

当类显得过于笨重，而字典又不够强大时，命名元组（namedtuple）是一个很好的选择。

```
from collections import namedtupleCar = namedtuple('Car', ['make', 'model', 'year'])my_car = Car(make='Tesla', model='Model S', year=2022)print(my_car.make)  # 输出: Tesla
```

命名元组提供了类似于类的属性访问方式，但更加轻量级。

### 5\. 动态替换函数

Python允许在运行时动态替换函数的行为，例如：

```
def greet():    print("Hello!")greet()  # 输出: Hello!greet = lambda: print("Bonjour!")greet()  # 输出: Bonjour!
```

这种特性在需要根据不同条件改变函数行为时非常有用。

### 6\. 使用下划线变量进入“禅模式”

下划线（\_）在Python中常用于表示不需要使用的变量，例如：

```
_, filename = "/path/to/file.txt".rsplit("/", 1)print(filename)  # 输出: file.txt
```

这种用法可以提高代码的可读性，表明该变量在后续代码中不会被使用。

### 7\. 循环中的else子句

Python的for和while循环支持else子句，该子句仅在循环未被break中断时执行。

```
for num in range(5):    if num == 3:        breakelse:    print("循环正常结束，没有中断!")
```

这种结构在需要根据循环是否正常结束来执行特定逻辑时非常有用。

### 8\. 使用dict.get()代替try-except

当访问字典中的键时，使用get()方法可以避免KeyError异常。

```
data = {'name': 'Python'}print(data.get('age', 'Not Found'))  # 输出: Not Found
```

这种方法使代码更加简洁和安全。

### 9\. 一行代码启动HTTP服务器

Python提供了一种简单的方法来启动本地HTTP服务器：

```
python -m http.server 8080
```

无需任何设置，即可快速共享文件。

### 10\. 使用subprocess自动安装缺失的库

在代码中自动检测并安装缺失的库，可以避免手动中断代码执行。

```
import subprocesstry:    import requestsexcept ImportError:    subprocess.run(["pip", "install", "requests"])
```

### 11\. 专业级JSON美化打印

使用json.dumps()函数可以以可读的格式打印JSON数据。

```
import jsondata = {'name': 'Python', 'age': 30}print(json.dumps(data, indent=4))
```

### 12\. 使用Virtualenv激活检查保护脚本

为了避免全局依赖带来的问题，可以在脚本中添加虚拟环境激活检查。

```
import sysif not hasattr(sys, 'real_prefix'):    raise EnvironmentError("请激活虚拟环境!")
```

### 13\. 使用functools缓存缓存函数调用

当需要缓存函数的结果以提高性能时，可以使用lru\_cache装饰器。

```
from functools import lru_cache@lru_cachedef expensive_function(x):    print("运行中...")    return x * 2print(expensive_function(10))  # 输出: 运行中... 20print(expensive_function(10))  # 输出: 20 (缓存结果)
```

### 14\. 一行代码检测回文

使用lambda表达式可以简洁地检测字符串是否为回文。

```
is_palindrome = lambda s: s == s[::-1]print(is_palindrome('racecar'))  # 输出: True
```

### 15\. 使用dataclass简化数据类定义

dataclass装饰器可以自动生成特殊方法，减少样板代码。

```
from dataclasses import dataclass@dataclassclass Book:    title: str    author: strb = Book(title="Python Tricks", author="Dan Bader")print(b)  # 输出: Book(title='Python Tricks', author='Dan Bader')
```

### 16\. 使用memory\_profiler测量内存使用

memory\_profiler库可以帮助开发者监控代码的内存使用情况。

```
pip install memory-profilermprof run your_script.py
```

### 17\. 猴子补丁：自定义模块行为

猴子补丁允许在不修改模块源代码的情况下改变其行为。

```
import randomrandom.randint = lambda a, b: 42  # 总是返回42print(random.randint(1, 100))  # 输出: 42
```

### 18\. 使用match语句简化复杂条件逻辑

Python 3.10引入了match-case语句，可以使条件判断更加清晰。

```
command = 'start'match command:    case 'start':        print("启动中...")    case 'stop':        print("停止中...")
```

### 19\. 使用threading.Lock()锁定线程

当多个线程同时访问共享资源时，可以使用锁来保证线程安全。

```
from threading import Locklock = Lock()with lock:    print("线程安全区域")
```

### 20\. 使用 `zip()` 遍历多个列表

当需要同时遍历多个列表时，`zip()` 函数可以简化代码结构，避免使用嵌套循环。

```
names = ['Alice', 'Bob']ages = [24, 27]for name, age in zip(names, ages):    print(f"{name} is {age} years old.")# 输出:# Alice is 24 years old.# Bob is 27 years old.
```

`zip()` 函数将多个可迭代对象“压缩”在一起，生成一个元组的迭代器，每个元组包含来自每个输入可迭代对象的对应元素。这种方法不仅使代码更简洁，还提高了可读性。

### 21\. 使用 `tempfile` 进行临时文件存储

在处理需要临时存储数据的场景时，`tempfile` 模块可以避免手动管理临时文件，避免系统文件混乱。

```
import tempfilewith tempfile.TemporaryFile() as temp:    temp.write(b'Some data')    temp.seek(0)    data = temp.read()    print(data)  # 输出: b'Some data'
```

`tempfile.TemporaryFile()` 创建一个临时文件对象，当文件对象被垃圾回收或显式关闭时，临时文件会被自动删除。这种方法适用于需要临时存储数据的场景，如文件处理、数据缓存等。

### 22\. 快速交换变量

Python 提供了一种简洁的语法来交换变量的值，无需使用临时变量。

```
a, b = 5, 10a, b = b, aprint(a, b)  # 输出: 10 5
```

这种语法利用了元组解包（tuple unpacking）的特性，使代码更加简洁和易读。

### 23\. 使用 `enum` 定义更清晰的常量

在代码中使用魔法数字（magic numbers）会使代码难以理解和维护。使用 `enum` 模块可以定义一组具有明确含义的常量。

```
from enum import Enumclass Status(Enum):    PENDING = 1    APPROVED = 2    REJECTED = 3print(Status.PENDING)  # 输出: Status.PENDINGprint(Status.PENDING.value)  # 输出: 1
```

`enum.Enum` 类允许定义一组符号常量，每个常量都有一个名称和一个值。使用枚举可以提高代码的可读性和可维护性，避免使用魔法数字带来的混淆。

### 24\. 获取明天的日期

使用 `datetime` 模块可以轻松地获取当前日期和时间的各种信息，包括明天的日期。

```
from datetime import datetime, timedeltatomorrow = datetime.now() + timedelta(days=1)print(tomorrow)  # 输出类似: 2024-11-12 12:34:56.789012
```

`datetime.now()` 返回当前的日期和时间，`timedelta` 对象表示时间间隔。通过将 `timedelta(days=1)` 加到当前日期上，可以得到明天的日期。

### 25\. 使用 `cProfile` 轻松分析代码性能

`cProfile` 是Python内置的性能分析工具，可以帮助开发者识别代码中的性能瓶颈。

```
python -m cProfile your_script.py
```

运行上述命令后，`cProfile` 会生成一份详细的性能报告，包括每个函数被调用的次数和执行时间等信息。通过分析这份报告，可以找到代码中需要优化的部分，从而提高代码性能。

## 总结

本文介绍了25个鲜为人知但非常实用的Python编程技巧，涵盖了从基础语法到高级功能的各个方面。这些技巧可以帮助开发者：

-   提高代码简洁性和可读性
    
-   简化常见任务的实现方式
    
-   优化代码性能
    
-   增强代码的可维护性和可扩展性
    

  

  

  

  

  

QuantML星球内有各类丰富的量化资源，包括数百篇论文代码，QuantML-Qlib框架，研报复现，研报分享项目等，星球群内有许多大佬，包括量化私募创始人，公募jjjl，券商研究员，顶会论文作者，github千星项目作者等，星球人数已经500+，欢迎加入交流

  

我们的愿景是搭建最全面的量化知识库，无论你希望查找任何量化资料，都能够高效的查找到相关的论文代码以及复现结果，期待您的加入。

QuantML知识星球双十一优惠活动即将结束，欢迎加入

  

![](assets/001.png)