# 设计高性能中频交易系统（三）

fintechhaibin FinTechHi 2025-04-05 23:51 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzUyOTAzNDg2NA==&mid=2247486095&idx=1&sn=0b3d4c2eef34ff35f95020a9e255f6f7&chksm=fb67d0993025c64c4b0d1f5049363c7d8acdacfa33e7b710b144ed23f7028dc01cdfeaeb8978#rd](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247486095&idx=1&sn=0b3d4c2eef34ff35f95020a9e255f6f7&chksm=fb67d0993025c64c4b0d1f5049363c7d8acdacfa33e7b710b144ed23f7028dc01cdfeaeb8978#rd)

![](assets/001.png)

#   

# 春天，是真的好，红的桃花，绿的柳叶，白的梨花……

#   

# 之前翻译过两篇中频交易系统设计的文章：[设计高性能中频交易系统（一）](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484888&idx=1&sn=f4e2eedbd84e58ba903e11939e44a03b&scene=21#wechat_redirect)[设计高性能中频交易系统（二）](https://mp.weixin.qq.com/s?__biz=MzUyOTAzNDg2NA==&mid=2247484902&idx=1&sn=ae001e2b2c9c661a73caaa397edf5b7c&scene=21#wechat_redirect)，这是第3篇，本篇文章内容也是我最近在深入学习的“量化交易的特征工程”比较相关，即如何对数据做处理。

#   

# 原作者的初衷也是为了做特征功能设计了此模块，但结果不是很满意，于是增加了各种数据校验及分析方法，在这个不断修改完善的过程，把一个“特征工程模块”逐渐演化成了“数据质量检查模块”。最后，删除了所有特征计算，使其成为数据层的一部分，专门用于数据分析和控制，同时也保留了后续再特征工程模块添加新特性的扩展性。该模块有五个类。我们可以把它们分成三组：Initializer类、Auxiliary类和Main类。  

**1.初始化（**Initializers）****  

这是两个名为DataQualityMetrics和ProcessingMetrics的数据类，它们是初始化数据类型的非常短的代码块。它们是不言自明的。

@dataclass  
classDataQualityMetrics:  
    """Store data quality metrics"""  
    missing\_data\_pct: float  
    outlier\_pct: float  
    stale\_data\_pct: float  
    gaps\_detected: Dict  
    gap\_count: int  
    gap\_duration: timedelta  
    data\_freshness: timedelta  
    quality\_score: float  
  
@dataclass  
classProcessingMetrics:  
    """Store processing metrics"""  
    processing\_time: float  
    memory\_usage: float  
    error\_count: int  
    cache\_hit\_rate: float  
    feature\_count: int

  
2.辅助类（**Auxiliaries）**

**在系统初步运行若干次后，观测到存在性能瓶颈以及资源管理方面的问题，遂引入CacheManager类。**

  

CacheManager类的功能为存储高频访问数据，以此降低数据库负载并减少延迟。该类分别针对原始数据与特征数据设置独立缓存，其缓存有效期分别设定为1小时和30分钟。同时，通过设定最大缓存大小限制，对内存使用进行有效管控。

  

在构建CacheManager和MonitoringServer类时，大量借助了Claude 3.5 Sonnet工具。尽管明确需要缓存模块与监控模块，但当前的实现方式在效率方面存在显著不足 。 

class CacheManager:  
    """Manages data and feature caching"""  
      
    def\_\_init\_\_(self, cache\_size: int = 100):  
        self.data\_cache = cachetools.TTLCache(  
            maxsize=cache\_size,  
            ttl=3600\# 1 hour TTL  
        )  
        self.feature\_cache = cachetools.TTLCache(  
            maxsize=cache\_size,  
            ttl=1800\# 30 minutes TTL  
        )  
        self.logger = logging.getLogger('CacheManager')  
        self.hits = 0  
        self.misses = 0  
  
    defget\_cache\_key(self, symbol: str, start\_time: datetime, end\_time: datetime) -> str:  
        """Generate cache key"""  
        returnf"{symbol}:{start\_time.isoformat()}:{end\_time.isoformat()}"  
  
    defget\_from\_cache(self, key: str, cache\_type: str = 'data') -> Optional\[pd.DataFrame\]:  
        """Retrieve data from cache"""  
        try:  
            cache = self.data\_cache if cache\_type == 'data'else self.feature\_cache  
            if key in cache:  
                self.hits += 1  
                return cache\[key\]  
            self.misses += 1  
            returnNone  
        except Exception as e:  
            self.logger.error(f"Error retrieving from cache: {e}")  
            returnNone  
  
    defstore\_in\_cache(self, key: str, data: pd.DataFrame, cache\_type: str = 'data'):  
        """Store data in cache"""  
        try:  
            cache = self.data\_cache if cache\_type == 'data'else self.feature\_cache  
            cache\[key\] = data  
        except Exception as e:  
            self.logger.error(f"Error storing in cache: {e}")  
  
    @property  
    defhit\_rate(self) -> float:  
        """Calculate cache hit rate"""  
        total = self.hits + self.misses  
        return self.hits / total if total > 0else 0.0

辅助部分的第二个组件是MonitoringServer类。此为可选类，目前尚未投入使用。它作为一个HTTP接口，具备捕获指标以及监测缓存性能的功能。该类对中频交易（MFT）系统的影响极小，仅使处理时间增加了0.14秒。鉴于不希望仅通过文本输出方式进行全面监控，后续有计划启用该类。 

class MonitoringServer:  
    """Handles monitoring endpoints and metrics collection"""  
      
    def\_\_init\_\_(self, host: str = 'localhost', starting\_port: int = 8080):  
        self.host = host  
        self.starting\_port = starting\_port  
        self.port = None  
        self.app = web.Application()  
        self.metrics = {}  
        self.logger = logging.getLogger('MonitoringServer')  
  
    asyncdeffind\_free\_port(self) -> int:  
        """Find a free port starting from self.starting\_port"""  
        port = self.starting\_port  
        while port < self.starting\_port + 100:  \# Try 100 ports  
            try:  
                sock = socket.socket(socket.AF\_INET, socket.SOCK\_STREAM)  
                sock.bind((self.host, port))  
                sock.close()  
                return port  
            except OSError:  
                port += 1  
        raise OSError("Could not find a free port")  
  
    asyncdefstart(self):  
        """Start monitoring server"""  
        self.app.router.add\_get('/metrics', self.get\_metrics)  
        self.app.router.add\_get('/health', self.health\_check)  
          
        runner = web.AppRunner(self.app)  
        await runner.setup()  
        site = web.TCPSite(runner, self.host, self.port)  
        await site.start()  
          
        self.logger.info(f"Monitoring server started at http://{self.host}:{self.port}")  
  
    asyncdefget\_metrics(self, request: web.Request) -> web.Response:  
        """Endpoint for getting current metrics"""  
        return web.json\_response(self.metrics)  
  
    asyncdefhealth\_check(self, request: web.Request) -> web.Response:  
        """Basic health check endpoint"""  
        return web.Response(text='healthy')  
  
    defupdate\_metrics(self, new\_metrics: Dict):  
        """Update current metrics"""  
        self.metrics.update(new\_metrics)

**3.主类（**Main Classes）****

  

本代码旨在解决核心问题，即处理数据与市场差距相关的难题。经过约10 - 12次迭代优化，最终取得了较为理想的结果，具体前后输出情况可在结果部分查看。

  

在该模块中，DataQualityChecker和DataMonitor这两个主类发挥着关键作用。DataQualityChecker主要负责验证市场数据的质量，会对市场交易时间段内的数据进行检查，排查数据差距、缺失值以及异常值等问题。该类会设定市场交易时间（美国东部时间上午9:30至下午4:00），并计算相应的质量指标和分数。 

class DataQualityChecker:  
    """Handles data quality validation"""  
      
    def\_\_init\_\_(self, max\_missing\_pct: float = 0.1,  
                max\_outlier\_std: float = 3.0,  
                max\_stale\_minutes: int = 5,  
                min\_gap\_minutes: float = 1.0):  \# Changed to minutes and default to 1.0  
        self.max\_missing\_pct = max\_missing\_pct  
        self.max\_outlier\_std = max\_outlier\_std  
        self.max\_stale\_minutes = max\_stale\_minutes  
        self.min\_gap\_minutes = min\_gap\_minutes  \# Store as minutes  
        self.logger = logging.getLogger('DataQualityChecker')  
          
        \# Define market hours in UTC (corrected times)  
        self.MARKET\_OPEN\_UTC = 14\# 14:30 UTC = 9:30 AM ET  
        self.MARKET\_OPEN\_MIN = 30\# Market opens at 14:30  
        self.MARKET\_CLOSE\_UTC = 21\# 21:00 UTC = 4:00 PM ET  
        self.MARKET\_CLOSE\_MIN = 0   \# Market closes at 21:00  
      
    defis\_market\_hours(self, dt: datetime) -> bool:  
        """Check if a given datetime is within market hours"""  
        ifisinstance(dt, pd.Timestamp):  
            dt = dt.to\_pydatetime()  
          
        \# Check if it's a weekday (Monday = 0, Sunday = 6)  
        if dt.weekday() >= 5:  \# Saturday or Sunday  
            returnFalse  
              
        \# Convert to UTC if needed  
        if dt.tzinfo isNone:  
            dt = dt.replace(tzinfo=pytz.UTC)  
        elif dt.tzinfo != pytz.UTC:  
            dt = dt.astimezone(pytz.UTC)  
              
        \# Check if within market hours  
        if dt.hour == self.MARKET\_OPEN\_UTC:  
            return dt.minute >= self.MARKET\_OPEN\_MIN  
        elif dt.hour == self.MARKET\_CLOSE\_UTC:  
            return dt.minute < self.MARKET\_CLOSE\_MIN  
        else:  
            return self.MARKET\_OPEN\_UTC < dt.hour < self.MARKET\_CLOSE\_UTC  
  
    defis\_same\_trading\_day(self, dt1: datetime, dt2: datetime) -> bool:  
        """Check if two timestamps belong to the same trading day"""  
        ifisinstance(dt1, pd.Timestamp):  
            dt1 = dt1.to\_pydatetime()  
        ifisinstance(dt2, pd.Timestamp):  
            dt2 = dt2.to\_pydatetime()  
              
        return (dt1.date() == dt2.date() and  
                self.is\_market\_hours(dt1) and  
                self.is\_market\_hours(dt2))  
  
    defanalyze\_gaps(self, df: pd.DataFrame) -> Tuple\[Dict, timedelta\]:  
        """Analyze data gaps with detailed statistics and consistent metrics"""  
        try:  
            gap\_info = {}  
            total\_gap\_duration = timedelta(0)  
              
            \# Filter for market hours  
            market\_hours\_mask = df.index.map(self.is\_market\_hours)  
            df\_market = df\[market\_hours\_mask\].copy()  
              
            \# Calculate missing values per column for market hours only  
            missing\_values = df\_market.isnull().sum()  
            gap\_info\['missing\_values'\] = missing\_values\[missing\_values > 0\]  
              
            \# Time gap analysis within market hours  
            time\_diffs = df\_market.index.to\_series().diff()  
            min\_gap = pd.Timedelta(minutes=self.min\_gap\_minutes)  \# Convert to Timedelta with minutes  
              
            \# Filter gaps and handle trading day boundaries  
            market\_gaps = {}  
            for time, gap in time\_diffs\[time\_diffs > min\_gap\].items():  
                start\_time = time - gap  
                  
                \# Only count gap if both times are in the same trading day  
                if self.is\_same\_trading\_day(start\_time, time):  
                    market\_gaps\[time\] = gap  
              
            gaps = pd.Series(market\_gaps)  
              
            \# Calculate total gap duration (market hours only)  
            ifnot gaps.empty:  
                total\_gap\_duration = pd.Timedelta(gaps.sum())  
              
            \# Sort gaps by duration and get largest ones using sort\_values and head instead of nlargest  
            sorted\_gaps = gaps.sort\_values(ascending=False)  
              
            gap\_info\['gap\_count'\] = len(gaps)  
            gap\_info\['first\_few\_gaps'\] = gaps.head().to\_dict()  
            gap\_info\['largest\_gaps'\] = sorted\_gaps.head(5).to\_dict()  
              
            \# Calculate average sampling frequency for market hours  
            iflen(df\_market) > 1:  
                trading\_day\_diffs = \[\]  
                current\_day = None  
                last\_time = None  
                  
                for idx in df\_market.index:  
                    if current\_day != idx.date():  
                        current\_day = idx.date()  
                        last\_time = None  
                          
                    if last\_time isnotNone:  
                        diff = idx - last\_time  
                        if diff <= pd.Timedelta(minutes=5):  \# Only include reasonable gaps  
                            trading\_day\_diffs.append(diff)  
                    last\_time = idx  
                  
                if trading\_day\_diffs:  
                    gap\_info\['avg\_sampling\_freq'\] = pd.Timedelta(sum(trading\_day\_diffs, pd.Timedelta(0)) / len(trading\_day\_diffs))  
                else:  
                    gap\_info\['avg\_sampling\_freq'\] = pd.Timedelta(0)  
            else:  
                gap\_info\['avg\_sampling\_freq'\] = pd.Timedelta(0)  
              
            \# Data ranges for market hours only  
            ranges = {}  
            for col in df\_market.columns:  
                if df\_market\[col\].dtype in \[np.float64, np.int64\]:  
                    ranges\[col\] = {  
                        'min': df\_market\[col\].min(),  
                        'max': df\_market\[col\].max()  
                    }  
            gap\_info\['data\_ranges'\] = ranges  
              
            \# Special spread statistics for market hours if available  
            if'spread'in df\_market.columns:  
                gap\_info\['spread\_stats'\] = df\_market\['spread'\].describe()  
              
            return gap\_info, total\_gap\_duration  
              
        except Exception as e:  
            self.logger.error(f"Error in gap analysis: {e}")  
            raise  
  
    defcheck\_data\_quality(self, df: pd.DataFrame) -> DataQualityMetrics:  
        """Perform comprehensive data quality checks"""  
        try:  
            \# Filter for market hours  
            market\_hours\_mask = df.index.map(self.is\_market\_hours)  
            df\_market = df\[market\_hours\_mask\]  
              
            \# Skip quality check if no market hours data  
            iflen(df\_market) == 0:  
                return DataQualityMetrics(  
                    missing\_data\_pct=1.0,  
                    outlier\_pct=0.0,  
                    stale\_data\_pct=0.0,  
                    gaps\_detected={},  
                    gap\_count=0,  
                    gap\_duration=timedelta(0),  
                    data\_freshness=timedelta.max,  
                    quality\_score=0.0  
                )  
              
            \# Missing data analysis for market hours  
            missing\_pct = df\_market.isnull().mean()  
              
            \# Outlier detection for market hours  
            outliers = {}  
            for col in df\_market.select\_dtypes(include=\[np.number\]).columns:  
                mean = df\_market\[col\].mean()  
                std = df\_market\[col\].std()  
                outliers\[col\] = df\_market\[col\]\[abs(df\_market\[col\] - mean) > self.max\_outlier\_std \* std\]  
              
            outlier\_pct = sum(len(v) for v in outliers.values()) / len(df\_market)  
              
            \# Stale data detection for market hours only  
            stale\_data = pd.Series(False, index=df\_market.index)  
            last\_update = None  
            current\_day = None  
              
            for idx in df\_market.index:  
                if current\_day != idx.date():  
                    current\_day = idx.date()  
                    last\_update = None  
                  
                if last\_update isnotNone:  
                    time\_diff = idx - last\_update  
                    if time\_diff > pd.Timedelta(minutes=self.max\_stale\_minutes):  
                        stale\_data\[idx\] = True  
                last\_update = idx  
              
            stale\_pct = stale\_data.mean()  
              
            \# Enhanced gap detection for market hours  
            gaps, total\_gap\_duration = self.analyze\_gaps(df)  
              
            \# Data freshness (use last market hours data point)  
            current\_time = datetime.now(pytz.UTC)  
            if self.is\_market\_hours(current\_time):  
                freshness = current\_time - df\_market.index\[-1\]  
            else:  
                \# Find the last market close time  
                last\_market\_close = current\_time.replace(  
                    hour=self.MARKET\_CLOSE\_UTC,  
                    minute=0,  
                    second=0,  
                    microsecond=0  
                )  
                ifnot self.is\_market\_hours(last\_market\_close):  
                    last\_market\_close -= timedelta(days=1)  
                freshness = last\_market\_close - df\_market.index\[-1\]  
              
            \# Calculate overall quality score (0-1) with adjusted gap penalty  
            expected\_samples = len(pd.date\_range(  
                df\_market.index\[0\],  
                df\_market.index\[-1\],  
                freq='1min'  
            ))  
            gap\_ratio = gaps\['gap\_count'\] / expected\_samples  
            gap\_penalty = min(0.5, gap\_ratio)  \# Cap gap penalty at 0.5  
              
            quality\_score = 1.0 - (  
                0.3 \* missing\_pct.mean() +  
                0.2 \* outlier\_pct +  
                0.2 \* stale\_pct +  
                0.3 \* gap\_penalty  
            )  
              
            return DataQualityMetrics(  
                missing\_data\_pct=missing\_pct.mean(),  
                outlier\_pct=outlier\_pct,  
                stale\_data\_pct=stale\_pct,  
                gaps\_detected=gaps,  
                gap\_count=gaps\['gap\_count'\],  
                gap\_duration=total\_gap\_duration,  
                data\_freshness=freshness,  
                quality\_score=quality\_score  
            )  
              
        except Exception as e:  
            self.logger.error(f"Error in data quality check: {e}")  
            raise

  

其中DataMonitor类具有收集、处理和更新指标的核心功能。它连接到TimeScaleDb，检索数据并同时处理多个符号。最后，它打印有关差距分析、监控指标、统计数据和错误日志的详细信息。

class DataMonitor:  
    """Data quality checks and monitoring"""  
      
    def\_\_init\_\_(self,   
                db\_config: Dict\[str, str\],  
                cache\_size: int = 100,  
                enable\_monitoring: bool = False,  
                monitoring\_port: int = 8080):  
        self.db\_config = db\_config  
        self.pool = None  
        self.logger = logging.getLogger('DataMonitor')  
          
        \# Initialize components  
        self.quality\_checker = DataQualityChecker()  
        self.cache\_manager = CacheManager(cache\_size=cache\_size)  
        self.enable\_monitoring = enable\_monitoring  
          
          
        \# Initialize metrics  
        self.current\_metrics = {  
            'processing\_metrics': {},  
            'quality\_metrics': {},  
            'error\_metrics': {}  
        }  
  
    asyncdefinitialize(self):  
        """Initialize system components"""  
        try:  
            \# Initialize database pool  
            self.pool = await asyncpg.create\_pool(\*\*self.db\_config)  
            self.logger.info("Database connection pool initialized")  
              
              
              
        except Exception as e:  
            self.logger.error(f"Error initializing system: {e}")  
            raise  
  
    deflog\_error(func):  
        """Decorator for error logging and monitoring"""  
        @wraps(func)  
        asyncdefwrapper(self, \*args, \*\*kwargs):  
            try:  
                returnawait func(self, \*args, \*\*kwargs)  
            except Exception as e:  
                error\_info = {  
                    'error': str(e),  
                    'traceback': traceback.format\_exc(),  
                    'timestamp': datetime.now(pytz.UTC).isoformat()  
                }  
                  
                \# Update error metrics  
                self.current\_metrics\['error\_metrics'\]\[func.\_\_name\_\_\] = error\_info  
                  
                \# Log error  
                self.logger.error(f"Error in {func.\_\_name\_\_}: {e}")  
                self.logger.error(traceback.format\_exc())  
                  
                raise  
        return wrapper  
  
    @log\_error  
    asyncdefget\_market\_data(self,  
                           symbol: str,  
                           start\_time: datetime,  
                           end\_time: datetime) -> pd.DataFrame:  
        """Get market data with caching and quality checks"""  
        try:  
            \# Check cache first  
            cache\_key = self.cache\_manager.get\_cache\_key(symbol, start\_time, end\_time)  
            cached\_data = self.cache\_manager.get\_from\_cache(cache\_key)  
              
            if cached\_data isnotNone:  
                return cached\_data  
              
            \# Fetch from database  
            asyncwith self.pool.acquire() as conn:  
                query = """  
                SELECT time, price, volume, bid, ask, vwap, spread,  
                       trades\_count, microstructure\_imbalance  
                FROM market\_data  
                WHERE symbol = $1  
                AND time >= $2  
                AND time < $3  
                ORDER BY time;  
                """  
                  
                records = await conn.fetch(query, symbol, start\_time, end\_time)  
                  
                \# Convert to DataFrame  
                df = pd.DataFrame(records, columns=\[  
                    'time', 'price', 'volume', 'bid', 'ask', 'vwap',  
                    'spread', 'trades\_count', 'microstructure\_imbalance'  
                \])  
                  
                if df.empty:  
                    self.logger.warning(f"No data found for {symbol}")  
                    returnNone  
                  
                \# Set time as index and rename price to close  
                df.set\_index('time', inplace=True)  
                df.rename(columns={'price': 'close'}, inplace=True)  
                  
                \# Check data quality  
                quality\_metrics = self.quality\_checker.check\_data\_quality(df)  
  
                \# Print detailed gap analysis  
                print(f"\\nAnalyzing data quality for {symbol}:")  
                print("\\nMissing values per column:")  
                print(quality\_metrics.gaps\_detected\['missing\_values'\])  
              
                print(f"\\nFound {quality\_metrics.gaps\_detected\['gap\_count'\]} time gaps larger than 5 seconds:")  
                print("First few gaps:")  
                for time, gap in quality\_metrics.gaps\_detected\['first\_few\_gaps'\].items():  
                    print(f"{time}: {gap}")  
              
                print("\\nLargest gaps:")  
                for time, gap in quality\_metrics.gaps\_detected\['largest\_gaps'\].items():  
                    print(f"{time}: {gap}")  
              
                print(f"\\nAverage sampling frequency: {quality\_metrics.gaps\_detected\['avg\_sampling\_freq'\]}")  
              
                print("\\nData ranges:")  
                for col, range\_info in quality\_metrics.gaps\_detected\['data\_ranges'\].items():  
                    print(f"{col}: {range\_info\['min'\]:.2f} to {range\_info\['max'\]:.2f}")  
              
                if'spread\_stats'in quality\_metrics.gaps\_detected:  
                    print("\\nSpread statistics:")  
                    print(quality\_metrics.gaps\_detected\['spread\_stats'\])  
                  
                \# Update monitoring metrics  
                self.current\_metrics\['quality\_metrics'\]\[symbol\] = {  
                    'quality\_score': quality\_metrics.quality\_score,  
                    'missing\_data\_pct': quality\_metrics.missing\_data\_pct,  
                    'data\_freshness': quality\_metrics.data\_freshness.total\_seconds(),  
                    'gap\_count': quality\_metrics.gap\_count,  
                    'avg\_sampling\_freq': str(quality\_metrics.gap\_duration)  
                }  
                  
                \# Cache if quality is good  
                if quality\_metrics.quality\_score >= 0.8:  
                    self.cache\_manager.store\_in\_cache(cache\_key, df)  
                  
                return df  
                  
        except Exception as e:  
            self.logger.error(f"Error fetching market data: {e}")  
            raise  
  
    @log\_error  
    asyncdefprocess\_symbol(self,  
                          symbol: str,  
                          start\_time: datetime,  
                          end\_time: datetime) -> pd.DataFrame:  
        """Process symbol with monitoring"""  
        start\_processing = datetime.now()  
          
        try:  
            \# Get market data  
            df = await self.get\_market\_data(symbol, start\_time, end\_time)  
            if df isNone:  
                returnNone  
              
            \# Calculate processing metrics  
            end\_processing = datetime.now()  
            processing\_time = (end\_processing - start\_processing).total\_seconds()  
              
            metrics = ProcessingMetrics(  
                processing\_time=processing\_time,  
                memory\_usage=df.memory\_usage().sum(),  
                error\_count=0,  
                cache\_hit\_rate=self.cache\_manager.hit\_rate,  
                feature\_count=len(df.columns)  
            )  
              
            \# Update monitoring metrics  
            self.current\_metrics\['processing\_metrics'\]\[symbol\] = {  
                'processing\_time': float(metrics.processing\_time),  
                'memory\_usage': int(metrics.memory\_usage),  
                'feature\_count': int(metrics.feature\_count),  
                'gap\_analysis\_time': float(processing\_time),  
                'top\_features': {},  
                'gap\_metrics': {  
                    'gap\_count': len(df.index.to\_series().diff()\[df.index.to\_series().diff() > pd.Timedelta(seconds=5)\]),  
                    'total\_gap\_duration': float(df.index.to\_series().diff().sum().total\_seconds())  
                }  
            }  
              
            return df  
              
        except Exception as e:  
            self.logger.error(f"Error processing symbol {symbol}: {e}")  
            self.current\_metrics\['error\_metrics'\]\[symbol\] = {  
                'error': str(e),  
                'traceback': traceback.format\_exc(),  
                'timestamp': datetime.now(pytz.UTC).isoformat()  
            }  
            raise  
  
    @log\_error  
    asyncdefprocess\_multiple\_symbols(self,  
                                   symbols: List\[str\],  
                                   start\_time: datetime,  
                                   end\_time: datetime) -> Dict\[str, pd.DataFrame\]:  
        """Process multiple symbols concurrently"""  
        try:  
            tasks = \[\]  
            for symbol in symbols:  
                task = asyncio.create\_task(  
                    self.process\_symbol(symbol, start\_time, end\_time)  
                )  
                tasks.append(task)  
              
            results = await asyncio.gather(\*tasks, return\_exceptions=True)  
              
            \# Process results  
            processed\_results = {}  
            for symbol, result inzip(symbols, results):  
                ifisinstance(result, Exception):  
                    self.logger.error(f"Error processing {symbol}: {result}")  
                    continue  
                if result isnotNone:  
                    processed\_results\[symbol\] = result  
              
            return processed\_results  
              
        except Exception as e:  
            self.logger.error(f"Error in parallel processing: {e}")  
            raise  
  
    asyncdefcleanup(self):  
        """Cleanup resources"""  
        if self.pool:  
            await self.pool.close()  
            self.logger.info("Database connection pool closed")

以下展示的是修改前的初始输出。可以观察到，在相近时间点出现了连续两天的数据间隔，同时存在6516个缺失值。实际上，这些情况属于正常现象，其根源在于代码中未纳入任何关于市场交易时间的实现逻辑。其中，65小时的时间间隔涵盖了周末闭市（周五闭市至周一开市）以及因圣诞节假期闭市导致的12月26日交易时段缩短。

  

在此详细阐述这些情况，是因为对于任何缺乏经验、处理原始数据的量化交易从业者而言，这类问题具有一定的普遍性。一旦对其有了深入理解并掌握相应处理方法，后续在面对类似情况时，便会将其视为常规操作，无需投入过多额外思考。 

![](assets/002.png)

  

以下呈现的是初始运行的质量及处理指标。质量得分仅为65%，而缺失数据比例高达10%，这一数据偏差程度较为显著。可以注意到，此次初始运行涵盖了131个特征，同时还包含了部分特征相关的指标。而最终版本将仅以市场数据作为特征进行考量 。 

![](assets/003.png)

  

下面是数据的最终输出。这考虑了市场时间和市场收盘时1分钟的差距，这解决了整个差距问题。质量评分现在是%97，没有缺失的数据，没有差距。

![](assets/004.png)

![](assets/005.png)

从上面分析可以看出，数据质量由65%提高到97%。