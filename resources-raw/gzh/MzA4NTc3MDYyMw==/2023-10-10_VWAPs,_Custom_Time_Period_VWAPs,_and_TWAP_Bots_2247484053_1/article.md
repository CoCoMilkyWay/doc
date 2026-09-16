# VWAPs, Custom Time Period VWAPs, and TWAP Bots

来自转载 映翡量化 2023-10-10 17:35 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzA4NTc3MDYyMw==&mid=2247484053&idx=1&sn=357806f9b52457f61efe8bfc5ee5f20f&chksm=9e74ca6f322291e879d68aafff680b6507de05984e0f7e29047b506bd082a293c725eaeedb7c#rd](https://mp.weixin.qq.com/s?__biz=MzA4NTc3MDYyMw==&mid=2247484053&idx=1&sn=357806f9b52457f61efe8bfc5ee5f20f&chksm=9e74ca6f322291e879d68aafff680b6507de05984e0f7e29047b506bd082a293c725eaeedb7c#rd)

需要一点点逆向思维！

VWAPs:

![](assets/001.png)

Source: What Are Common Strategies for Using Volume Weighted Average Price? (investopedia.com)

To put simply, VWAP is the fair price or value of an asset. Most day traders use daily VWAP as it comes as default with most exchanges and charting softwares.

![](assets/002.png)

-   If price above VWAP = considered bullish
    
-   If price below VWAP = considered bearish
    
-   Best entry always below VWAP if you are anticipating a bullish day
    
-   Best entry above VWAP if you are anticipating a bearish day
    

Entry Methods:

1.  Price hugs above/below VWAP, first retest.
    

![](assets/003.png)

2) Break of previous low, and first break of structure above/below VWAP

![](assets/004.png)

That’s it tbh. Most think of VWAP as a magic indicator but reality is sometimes price moves a long distance from VWAP and never retests VWAP line. This brings us to VWAP Standard Deviation.

VWAP Standard Deviation:

![](assets/005.png)

It’s a VWAP with more lines equidistance from current VWAP. It can be 0.5, 1, 2, and 3 standard deviation. The trend becomes stronger as price breaks the deviations.

In a strong trend, Price will often retest these deviations rather than retracing to fair value, VWAP value. So, it becomes a double edged sword. So, how do I know which level price will retrace to? You can’t, so don’t do it and lose money. Rather identify which deviation level price was accepting or rejecting previously.

![](assets/006.png)

Price respecting 2nd and 3rd levels

![](assets/007.png)

Price respecting 1st and second levels

> Use deviations as a benchmark to identify strength and weakness of trend.

Deviation retracement strategy:

1.  Wait for price to break above/below third standard deviation.
    
2.  Price fails to break above/below third Stdev and breaks down below 2nd stDev.
    
3.  Entry retest of 2nd stDev or swing low.
    

![](assets/008.png)

![](assets/009.png)

Previous VWAP close:

The fair value of previous day VWAP if it isn’t tested, it will get tested. This is where market makers have lot of orders waiting to get filled.

![](assets/010.png)

Custom time period VWAP:

Now, wouldn’t it be awesome if it was possible to plot vwap from closing of 12 hour candle or after 4hour candle close. Yes there is, it’s called rolling VWAP or RVWAP. Search on tradingview for RVWAP.

![](assets/011.png)

4 hours rolling VWAP

Also you can anchor the VWAP from any trading session using this tradingview tool:

![](assets/012.png)

![](assets/013.png)

Just drop is to any point in time and it will extrapolate as price moves

Alternative to VWAP:

![](assets/014.png)

Retail uses VWAP, while instituions use TWAP bots to run their orders. Often times at specific time of the day, market makers run their twap bots to take out liquidity before making their big moves.

![](assets/015.png)

Indicators recommended:

![](assets/016.png)

![](assets/017.png)

You can also use Sigmabasis Indicators for free:

Sigmabais TWAP:

![](assets/018.png)

Sigmabasis Deviation VWAP Bands:

![](assets/019.png)

  

资料来源：https://medium.com/coinmonks/a-no-bs-guide-to-using-vwaps-custom-time-period-vwaps-and-twap-bots-3cceb13b1d7d  
​