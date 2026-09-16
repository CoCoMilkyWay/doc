# 最受欢迎的绘图库Matplotlib

小燕子搬砖 映翡量化 2023-10-12 22:33 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484054&idx=1&sn=d3002cb31305bdc3e0cd05f57c397091&chksm=9e2ee4e7fe9031ecd36281ee5bd963f48bfcc728e794cdc29fb579ece044b3fbe60bd50915cc#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484054&idx=1&sn=d3002cb31305bdc3e0cd05f57c397091&chksm=9e2ee4e7fe9031ecd36281ee5bd963f48bfcc728e794cdc29fb579ece044b3fbe60bd50915cc#rd)

![](assets/001.gif)

​

Matplotlib是一个Python的绘图库，通过Matplotlib，我们可以创建2D、3D的静态、动态的图表，用于数据可视化和分析。  

Matplotlib具有以下特点：

-   优雅简洁的代码实现，可快速实现各类图表，如折线图、散点图、条形图和饼图等。
    
-   支持多种输出格式，如PDF、SVG、PNG和JPG等。
    
-   支持多种系统平台，如Windows、Linux和Mac OS等。
    

  

画图自由，3D曲面投射：‍‍‍‍‍

from mpl\_toolkits.mplot3d import axes3d  
import matplotlib.pyplot as plt  
  
ax \= plt.figure().add\_subplot(projection\='3d')  
X, Y, Z \= axes3d.get\_test\_data(0.05)  
  
\# Plot the 3D surface  
ax.plot\_surface(X, Y, Z, edgecolor\='royalblue', lw\=0.5, rstride\=8, cstride\=8,  
                alpha\=0.3)  
  
\# Plot projections of the contours for each dimension.  By choosing offsets  
\# that match the appropriate axes limits, the projected contours will sit on  
\# the 'walls' of the graph  
ax.contourf(X, Y, Z, zdir\='z', offset\=-100, cmap\='coolwarm')  
ax.contourf(X, Y, Z, zdir\='x', offset\=-40, cmap\='coolwarm')  
ax.contourf(X, Y, Z, zdir\='y', offset\=40, cmap\='coolwarm')  
  
ax.set(xlim\=(\-40, 40), ylim\=(\-40, 40), zlim\=(\-100, 100),  
       xlabel\='X', ylabel\='Y', zlabel\='Z')  
  
plt.show()

![](assets/002.jpg)

  
部分绘图函数

![](assets/003.jpg)

![](assets/004.jpg)

![](assets/005.jpg)

![](assets/006.jpg)

![](assets/007.jpg)