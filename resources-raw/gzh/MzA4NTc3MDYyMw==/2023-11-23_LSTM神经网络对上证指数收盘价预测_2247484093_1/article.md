# LSTM神经网络对上证指数收盘价预测

小燕子 映翡量化 2023-11-23 18:37 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484093&idx=1&sn=3295f0c6b6343886fa0b5d060868749d&chksm=9ecae0f633f6f1d4ba6fa1f103e9d71c60cc1c91eb6cf8842c46ed7cc298d1dcdf5c19e5bcbd#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484093&idx=1&sn=3295f0c6b6343886fa0b5d060868749d&chksm=9ecae0f633f6f1d4ba6fa1f103e9d71c60cc1c91eb6cf8842c46ed7cc298d1dcdf5c19e5bcbd#rd)

![](assets/001.gif)

​

LSTM神经网络预测股价，用2009年至今的上证指数收盘价，使用各种Python库，如Numpy、Pandas、Matplotlib和PyTorch来处理和可视化数据。该方法包括将数据拆分为训练和测试集，以及实施LSTM模型。  

![](assets/002.jpg)

一、LSTM模型

长短期记忆（Long Short-Term Memory，LSTM）是一种时间循环‍神经网络（RNN）论文首次发表于1997年。由于独特的设计结构，LSTM适合于处理和预测时间序列中间隔和延迟非常长的重要事件。

由LSTM单元组成的RNN通常称为LSTM网络（或仅称为LSTM）。公共LSTM单元由单元，输入门，输出门和忘记门组成。该单元记住任意时间间隔内的值，并且三个门控制进出单元的信息流。一个简单的LSTM：

![](assets/003.jpg)

  

二、数据处理‍‍

使用yfinance数据，并用x轴为日期和y轴为收盘价，绘制2009年至今上证指数收盘价图。

![](assets/004.png)

三、基于PyTorch的模型处理  

将数据拆分为训练和测试集。选择80%的训练数据。

使用PyTorch的LSTM神经网络。设置一个简单的循环神经网络RNN：有一个节点输入，一个32节点的两层隐藏部分和一个节点输出，训练1000个周期。

使用nn.MSELoss来衡量模型预测与实际结果的距离。设置了0.01的学习率，通过逐点调整模型的权重来微调模型。

最后，使用torch.optim.Adam优化器，通过最大限度地减少基于学习率的预测错误来帮助模型更快地学习。

三、预测结果‍‍

![](assets/005.png)

![](assets/006.png)

此图直观地比较真实和预测的数据情况。看起来还行。

![](assets/007.png)

其中，红色虚线垂直线显示训练数据在那里结束。

四、代码（可以直接运行）

  

import numpy as np

import pandas as pd

import matplotlib.pyplot as plt

import torch

import torch.nn as nn

from tqdm import tqdm

import datetime as dt

import backtrader as bt

import yfinance as yf 

  

start=dt.datetime(2009, 1, 1)

end=dt.datetime(2023, 11, 22)

stock\_df = yf.download('000001.ss', start=start, end=end)

  

stock\_df\['Close'\].plot()

plt.title("Closing Price  2020-2023")

plt.xticks(rotation=45)

plt.ylabel("Price")

plt.grid()

plt.show()

  

stock = stock\_df\[\['Close'\]\]

min\_val = float(stock.min(axis=0))

max\_val = float(stock.max(axis=0))

stock\_scaled = 2\*((stock-min\_val)/(max\_val-min\_val))-1

  

def split\_train\_test(dataset,percentage,lookback):

    data\_raw = dataset.to\_numpy()

    data = \[\]

    for index in range(len(data\_raw) - lookback): 

        data.append(data\_raw\[index: index + lookback\])

    data = np.array(data);

    train\_size = int(np.round(percentage\*data.shape\[0\]))

    test\_size = data.shape\[0\]-train\_size

    x\_train = data\[:train\_size,:-1,:\]

    y\_train = data\[:train\_size,-1,:\]

    x\_test = data\[train\_size:\]

    y\_test = data\[train\_size:,-1,:\]

    return x\_train, y\_train, x\_test, y\_test

  

x\_train,y\_train,x\_test,y\_test = split\_train\_test(stock\_scaled,0.8,20)

  

x\_train = torch.from\_numpy(x\_train).type(torch.Tensor)

x\_test = torch.from\_numpy(x\_test).type(torch.Tensor)

y\_train = torch.from\_numpy(y\_train).type(torch.Tensor)

y\_test = torch.from\_numpy(y\_test).type(torch.Tensor)

  

input\_dim = 1

hidden\_dim = 32

num\_layers = 2

output\_dim = 1

num\_epochs = 1000

  

class LSTM(nn.Module):

    def \_\_init\_\_(self,input\_dim,hidden\_dim,num\_layers,output\_dim):

        super(LSTM,self).\_\_init\_\_()

        self.hidden\_dim = hidden\_dim

        self.num\_layers = num\_layers

        self.lstm = nn.LSTM(input\_dim, hidden\_dim, num\_layers, batch\_first=True)

        self.fc = nn.Linear(hidden\_dim, output\_dim)

    def forward(self,x):

        h0 = torch.zeros(self.num\_layers, x.size(0), self.hidden\_dim).requires\_grad\_()

        c0 = torch.zeros(self.num\_layers, x.size(0), self.hidden\_dim).requires\_grad\_()

        out, (hn, cn) = self.lstm(x, (h0.detach(), c0.detach()))

        out = self.fc(out\[:, -1, :\]) 

        return out

model = LSTM(input\_dim=input\_dim,hidden\_dim=hidden\_dim,num\_layers=num\_layers,output\_dim=output\_dim)

criterion = nn.MSELoss()

lr = 0.01

optimiser = torch.optim.Adam(model.parameters(), lr=lr)

  

model.train()

loss\_curve = \[\]

  

for epoch in range(num\_epochs):

    y\_hat = model(x\_train)

    loss = criterion(y\_hat,y\_train)

    loss\_curve += \[loss.item()\]

    optimiser.zero\_grad()

    loss.backward()

    optimiser.step()

    if (epoch % 100 == 0):

        print('--- Iteration {0}: training loss = {1:.4f} ---'.format(epoch + 1, np.array(loss\_curve).mean()))

  

model.eval()

  

train\_pred\_scaled = model(x\_train)

train\_pred\_scaled = train\_pred\_scaled.data.numpy()

train\_pred = 0.5\*((train\_pred\_scaled+1)\*(max\_val-min\_val))+min\_val

y\_train\_orig = 0.5\*((y\_train.data.numpy()+1)\*(max\_val-min\_val))+min\_val

  

pred\_scaled = model(x\_test)

pred\_scaled = pred\_scaled.data.numpy()

  

pred = 0.5\*((pred\_scaled+1)\*(max\_val-min\_val))+min\_val

y\_test\_orig = 0.5\*((y\_test.data.numpy()+1)\*(max\_val-min\_val))+min\_val

  

plt.figure()

plt.plot(y\_train\_orig, label='Actual Data')

plt.plot(train\_pred, label='Predicted Data', linewidth=0.5)

plt.title("Predicted vs Actual on Training Data")

plt.ylabel("Price")

plt.legend()

plt.show() 

  

plt.figure()

plt.plot(y\_test\_orig, label='Actual Data')

plt.plot(pred, label='Predicted Data', linewidth=0.5)

plt.title("Predicted vs Actual on Test Data")

plt.ylabel("Price")

plt.legend()

plt.show() 

  

plt.figure()

plt.plot(np.concatenate(\[y\_train\_orig,y\_test\_orig\]), label='Actual Data')

plt.plot(np.concatenate(\[train\_pred,pred\]), label='Predicted Data', linewidth=0.5)

plt.title("Predicted vs Actual")

plt.ylabel("Price")

plt.axvline(x=x\_train.shape\[0\],color='red',linestyle='--')

plt.legend()

plt.show() 

  

参考资料：

https://medium.com/@matthew1992/enhancing-stock-market-predictions-with-lstm-neural-networks-a-case-study-on-google-stock-4988e7df4c09  

https://en.wikipedia.org/wiki/Long\_short-term\_memory

https://dataaspirant.com/lstm-long-short-term-memory/