# 高效存储与极速分析：基于 Parquet + DuckDB 的 A 股数据解决方案

QuantML QuantML 2025-05-14 18:23 上海

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=Mzg2MzAwNzM0NQ==&mid=2247490367&idx=1&sn=bfeb014f173e3dbd59d165c17b69cc39&chksm=cfc4fdd338cd53bcac6d08dc075a8c6d9d6dbd77d3c0a478e7e7989c0ecdf5e8ceeee5812a63#rd](https://mp.weixin.qq.com/s?__biz=Mzg2MzAwNzM0NQ==&mid=2247490367&idx=1&sn=bfeb014f173e3dbd59d165c17b69cc39&chksm=cfc4fdd338cd53bcac6d08dc075a8c6d9d6dbd77d3c0a478e7e7989c0ecdf5e8ceeee5812a63#rd)

DuckDB+Parquet是一种专为分析型负载设计的本地化数据存储解决方案，完美适配股票数据的存储与计算需求。该方案以DuckDB为计算引擎、Parquet为存储格式，形成"嵌入式数据库+列式存储"的高效组合。其核心特点包括：1）**极致性能**，通过列式存储减少I/O消耗，配合向量化引擎实现秒级处理千万级因子数据；2）**高效存储**，ZSTD压缩下数据体积仅为CSV的1/8；3）**零运维**，单文件架构支持即插即用，无需数据库服务；4）**量化友好**，原生支持时间序列操作、横截面分析和因子IC计算等场景。相比传统方案，其在10年全市场数据回测中可实现20倍加速，同时保持Python/R的无缝对接，是个人研投与机构本地化部署的理想选择。![How to use DuckDB to query Parquet file? | Ahmad Rosid](assets/001.png)

**关键词:** A股数据, Parquet, DuckDB, AKShare, 数据存储, 数据分析, 量化交易, Python

**1\. 引言**

A 股市场数据量庞大，包含股票日线、分钟线、财务数据、指数行情等多种类型。传统的关系型数据库在处理海量金融时间序列数据时，可能面临存储成本高、查询速度慢等问题。文本文件（如 CSV）虽然简单，但在I/O效率和数据类型保真方面存在不足。因此，选择合适的存储格式和分析引擎至关重要。

Parquet 是一种高效的列式存储格式，具有高压缩比和查询性能优势，特别适合分析型工作负载。DuckDB 是一个嵌入式的分析型数据库，可以直接对 Parquet 等多种格式文件进行高速 SQL 查询，无需数据导入和服务器部署。

![](assets/002.png)

与其他方案相比，DuckDB+Parquet的优势在于：

对比维度

DuckDB+Parquet

SQLite

CSV+HDF5

传统关系型数据库(MySQL)

**写入吞吐**

150K rows/sec (批处理模式)

50K rows/sec (无事务)

20K rows/sec

10K rows/sec (需索引维护)

**存储效率**

列式压缩后体积为CSV的1/8

行式存储，体积为CSV的1.2倍

HDF5专业压缩达CSV的1/10

行式存储+索引，体积膨胀3-5倍

**复杂查询**

向量化引擎支持SIMD加速

单线程执行，无优化

需全量加载到内存

依赖B+树索引效率

**维护成本**

零运维，单文件管理

需手动VACUUM

版本兼容性问题

需专业DBA优化

**多语言支持**

Python/R/Java等嵌入式调用

仅基础C接口

科学计算生态专用

需ODBC驱动

**2\. 核心技术优势**

-   **Parquet 文件格式:**
    

-   **列式存储:** 相同类型的数据连续存储，带来极高的压缩比，节省存储空间。
    
-   **查询高效:** 只需读取查询涉及的列，大幅减少 I/O 开销，提升查询速度，尤其适合 OLAP 场景。
    
-   **模式演进:** 支持 Schema 结构的变化，方便添加新列。
    
-   **生态广泛:** 被 Spark, Hive, Presto, Dremio, DuckDB 等众多大数据和分析工具支持。
    

-   **DuckDB:**
    

-   **嵌入式OLAP:** 无需复杂的服务器安装和配置，直接在应用程序中运行。
    
-   **极速查询:** 专为分析型查询优化，支持向量化执行引擎，查询速度远超传统行式数据库和 Pandas 等库。
    
-   **直接操作 Parquet:** 可以直接对本地或远程（如 S3）的 Parquet 文件执行 SQL 查询，无需预先导入数据。
    
-   **标准 SQL 支持:** 支持丰富的 SQL 语法和函数，易于上手。
    
-   **Python 友好:** 提供完善的 Python API，与 Pandas 等库无缝集成。
    

**3\. 方案实施步骤**

本方案主要包括以下步骤：

1.  安装必要的 Python 库。
    
2.  使用 AKShare 获取 A 股数据。
    
3.  将数据存储为 Parquet 格式（可按需进行分区）。
    
4.  使用 DuckDB 对 Parquet 文件进行 SQL 查询和分析。
    

**3.1. 环境准备与库安装**

首先，确保已安装 Python 环境。然后通过 pip 安装所需的库：

Python

`# 建议在终端或命令行中运行此命令   # pip install akshare pandas pyarrow duckdb   `

运行上述命令后，您就可以在 Python 脚本中导入并使用这些库了。

**3.2. 使用 AKShare 获取 A 股数据并存储为 Parquet**

以获取 A 股“平安银行”的历史日线行情数据为例。

Python

`import akshare as ak   import pandas as pd   import os   import datetime      # --- 数据获取参数 ---   stock_code = "000001"# 股票代码，例如：平安银行   start_date = "20200101"# 获取数据的起始日期   # 获取数据的结束日期 (建议使用当前日期或稍早的有效交易日期)   # end_date = datetime.date.today().strftime("%Y%m%d")   end_date = "20250514"# 使用一个固定的近期日期作为示例      # --- 数据存储设置 ---   data_dir = "ashare_daily_data_parquet"# Parquet 文件存储目录   os.makedirs(data_dir, exist_ok=True) # 创建目录，如果不存在的话      print(f"准备获取股票 {stock_code} 从 {start_date} 到 {end_date} 的日线数据...")      try:       # 获取后复权日K线数据       # AKShare 的 stock_zh_a_hist 函数用于获取A股历史行情数据       # symbol: 股票代码       # period: 数据周期，"daily" 表示日线       # start_date: 开始日期       # end_date: 结束日期       # adjust: 复权类型, "hfq" 表示后复权, "qfq" 表示前复权, "" 或 None 表示不复权       stock_hist_df = ak.stock_zh_a_hist(symbol=stock_code,                                         period="daily",                                         start_date=start_date,                                         end_date=end_date,                                         adjust="hfq")          if not stock_hist_df.empty:           print(f"成功获取到股票 {stock_code} 的 {len(stock_hist_df)} 条数据。")              # 重命名列名，以便于后续处理和SQL查询           # AKShare 返回的列名是中文，建议转换为英文或更规范的名称           column_mapping = {               '日期': 'date',               '开盘': 'open',               '收盘': 'close',               '最高': 'high',               '最低': 'low',               '成交量': 'volume',       # 注意：单位是“股”               '成交额': 'turnover',     # 注意：单位是“元”               '振幅': 'amplitude',               '涨跌幅': 'pct_change',               '涨跌额': 'change',               '换手率': 'turnover_rate'           }           stock_hist_df.rename(columns=column_mapping, inplace=True)              # 将 'date' 列转换为 datetime 类型，确保日期格式正确           stock_hist_df['date'] = pd.to_datetime(stock_hist_df['date'])              # 筛选掉不必要的列（如果存在且不需要的话），例如 '振幅', '涨跌额' 等           # 这里我们保留所有重命名后的列           # selected_columns = ['date', 'open', 'close', 'high', 'low', 'volume', 'turnover', 'pct_change', 'turnover_rate']           # stock_hist_df = stock_hist_df[selected_columns]              # 构建 Parquet 文件路径           parquet_file_name = f"{stock_code}_daily_hfq_{start_date}_{end_date}.parquet"           parquet_file_path = os.path.join(data_dir, parquet_file_name)              # 将 DataFrame 保存为 Parquet 文件           # engine='pyarrow' 指定使用 PyArrow 引擎           # index=False 表示不将 DataFrame 的索引写入 Parquet 文件           stock_hist_df.to_parquet(parquet_file_path, engine='pyarrow', index=False)           print(f"股票 {stock_code} 数据已保存到: {parquet_file_path}")           print("\n数据预览 (前5行):")           print(stock_hist_df.head())          else:           print(f"未能获取到股票 {stock_code} 在指定日期范围的数据。")      except Exception as e:       print(f"获取或处理股票 {stock_code} 数据时发生错误: {e}")   `

**3.3. （可选）数据分区存储**

当数据量非常大时（例如，全市场所有股票多年的数据），将数据按特定维度（如股票代码、年份、月份）分区存储可以显著提升查询性能，因为查询时可以跳过不相关的分区（分区裁剪）。这通常采用 Hive 风格的分区。

**目录结构示例 (Hive 风格分区):**

`ashare_data_partitioned/   ├── stock_code=000001/   │   ├── year=2020/   │   │   └── data.parquet  // 存储000001在2020年的数据   │   ├── year=2021/   │   │   └── data.parquet   │   └── ...   ├── stock_code=000002/   │   ├── year=2020/   │   │   └── data.parquet   │   └── ...   └── ...   `

**保存分区数据的概念性 Python 代码:**

Python

`# 这是一个概念性的示例，说明如何按股票代码和年份分区存储   # 实际应用中需要循环获取所有股票数据，并按需切分      # 假设 all_stock_codes 是一个包含所有A股代码的列表   # all_stock_codes = ['000001', '000002', ...] # 实际应通过 ak.stock_zh_a_spot_em() 获取      # partitioned_data_base_dir = "ashare_data_partitioned"   # os.makedirs(partitioned_data_base_dir, exist_ok=True)      # for stock_code_to_save in all_stock_codes:   #     print(f"正在处理股票: {stock_code_to_save}")   #     try:   #         # 假设 df_full_history 是获取到的该股票的完整历史数据 DataFrame   #         # df_full_history = ak.stock_zh_a_hist(symbol=stock_code_to_save, period="daily", adjust="hfq", ...)   #         # df_full_history.rename(columns=column_mapping, inplace=True)   #         # df_full_history['date'] = pd.to_datetime(df_full_history['date'])      #         if df_full_history.empty:   #             print(f"股票 {stock_code_to_save} 数据为空，跳过。")   #             continue      #         df_full_history['year'] = df_full_history['date'].dt.year      #         for year, group_df in df_full_history.groupby('year'):   #             # 构建分区路径   #             year_partition_dir = os.path.join(partitioned_data_base_dir,   #                                               f"stock_code={stock_code_to_save}",   #                                               f"year={year}")   #             os.makedirs(year_partition_dir, exist_ok=True)      #             # Parquet 文件名在每个最内层目录中可以固定，如 data.parquet   #             file_path = os.path.join(year_partition_dir, "data.parquet")      #             # 保存时移除用于分区的列，因为它们的信息已在目录结构中   #             group_df_to_save = group_df.drop(columns=['year']) # 如果 'stock_code' 列也存在于df中，且用于分区，也应考虑移除                  #             group_df_to_save.to_parquet(file_path, engine='pyarrow', index=False)   #             print(f"已保存 {stock_code_to_save} 在 {year} 年的数据到 {file_path}")      #     except Exception as e:   #         print(f"处理或保存股票 {stock_code_to_save} 分区数据时出错: {e}")   `

**注意:** 上述分区存储代码是概念性的。实际操作中，全市场数据的下载和处理需要较长时间，并需考虑错误处理和增量更新机制。

**3.4. 使用 DuckDB 查询 Parquet 数据**

DuckDB 可以直接对本地的 Parquet 文件执行 SQL 查询，无需预先加载整个文件到内存或导入到数据库。

**示例 1: 使用 DuckDB 查询单个 Parquet 文件**

Python

`import duckdb   import os   import pandas as pd # 仅用于打印DataFrame      # --- DuckDB 查询参数 ---   # 使用之前保存的 Parquet 文件路径   # 请确保已成功运行 3.2 节的代码并生成了相应的 Parquet 文件   data_dir = "ashare_daily_data_parquet"   stock_code_queried = "000001"   start_date_queried = "20200101"   end_date_queried = "20250514"   parquet_file_name_queried = f"{stock_code_queried}_daily_hfq_{start_date_queried}_{end_date_queried}.parquet"   single_parquet_file_path = os.path.join(data_dir, parquet_file_name_queried)      if not os.path.exists(single_parquet_file_path):       print(f"错误: Parquet 文件 {single_parquet_file_path} 不存在。请先运行 3.2 节的数据获取和存储脚本。")   else:       print(f"\n--- 开始使用 DuckDB 查询单个 Parquet 文件: {single_parquet_file_path} ---")       # 连接到 DuckDB       # :memory: 表示创建一个内存数据库，关闭连接后数据会丢失       # 也可以指定一个文件路径来创建或连接一个持久化的 DuckDB 数据库文件, e.g., con = duckdb.connect('my_ashare_db.duckdb')       con = duckdb.connect(database=':memory:', read_only=False)          # 查询方式1: 将 Parquet 文件注册为一个表 (临时或永久，取决于连接)       # con.execute(f"CREATE OR REPLACE TABLE stock_data AS SELECT * FROM read_parquet('{single_parquet_file_path}');")       # result_df_method1 = con.execute("SELECT date, close, volume FROM stock_data WHERE close > 15 ORDER BY date DESC LIMIT 5;").fetchdf()       # print("\n查询结果 (方法1 - 注册为表):")       # print(result_df_method1)          # 查询方式2: 直接在 FROM 子句中使用 read_parquet 函数引用文件       # 这是更常见和直接的方式       query_select_recent = f"""       SELECT           date,           open,           close,           high,           low,           volume       FROM read_parquet('{single_parquet_file_path}')       WHERE close > 15.0  -- 假设股价单位是元，查询收盘价大于15的记录       ORDER BY date DESC   -- 按日期降序排序       LIMIT 10;            -- 返回最近的10条记录       """       print(f"\n执行查询: 获取股票 {stock_code_queried} 收盘价 > 15.0 的最近10条记录")       result_df_recent = con.execute(query_select_recent).fetchdf() # fetchdf() 将结果转换为 Pandas DataFrame       print("查询结果:")       print(result_df_recent)          # 示例：计算指定年份的平均收盘价和总成交量       target_year_analysis = "2023"       query_aggregation = f"""       SELECT           strftime(date, '%Y') AS year, -- 提取年份           AVG(close) AS avg_close_price,           SUM(volume) AS total_volume,           MAX(high) AS max_high_price_in_year,           MIN(low) AS min_low_price_in_year       FROM read_parquet('{single_parquet_file_path}')       WHERE strftime(date, '%Y') = '{target_year_analysis}' -- 筛选特定年份       GROUP BY year; -- 按年份分组（实际上这里只会有一年）       """       print(f"\n执行查询: 计算股票 {stock_code_queried} 在 {target_year_analysis} 年的统计数据")       agg_result_df = con.execute(query_aggregation).fetchdf()       print(f"{target_year_analysis}年统计结果:")       print(agg_result_df)          # 关闭 DuckDB 连接       con.close()       print("\n--- DuckDB 查询结束 ---")   `

**示例 2: 使用 DuckDB 查询分区 Parquet 数据**

如果数据按照 3.3 节描述的 Hive 风格进行了分区存储，DuckDB 可以高效地查询这些数据，并利用分区信息进行查询优化（分区裁剪）。

Python

`import duckdb   import os   import pandas as pd # 仅用于打印DataFrame      # --- 分区数据查询参数 ---   # 假设分区数据存储在 "ashare_data_partitioned" 目录下   # 并且遵循 stock_code=XXX/year=YYYY/data.parquet 的结构   partitioned_base_dir = "ashare_data_partitioned"      # 检查分区根目录是否存在且不为空   if not os.path.exists(partitioned_base_dir) or not os.listdir(partitioned_base_dir):       print(f"提示: 分区数据目录 '{partitioned_base_dir}' 不存在或为空。")       print("请先运行类似 3.3 节中的分区数据存储逻辑来生成数据，或确保路径正确。")       print("跳过分区数据查询示例。")   else:       print(f"\n--- 开始使用 DuckDB 查询分区 Parquet 数据 (根目录: {partitioned_base_dir}) ---")       con = duckdb.connect(database=':memory:', read_only=False)          # DuckDB 会自动从目录结构中发现分区列 (如 stock_code, year)       # 使用通配符 * 来扫描所有匹配的分区       # hive_partitioning=True (或 1) 告诉 DuckDB 这是一个 Hive 分区布局       # DuckDB 0.9.0+ 自动推断 Hive 分区，如果文件名是 data.parquet, part_*.parquet 等       # 路径中的 '**/' 可以匹配多级子目录，但这里我们明确两级分区       # 'data.parquet' 是我们在分区存储概念代码中使用的文件名       partitioned_files_path_pattern = os.path.join(partitioned_base_dir, 'stock_code=*', 'year=*', 'data.parquet')       # 或者更通用地扫描所有parquet文件: os.path.join(partitioned_base_dir, '**', '*.parquet')       # 但前者对于标准的Hive分区更精确          # 查询特定股票在特定年份的数据，利用分区裁剪       target_stock_partitioned = '000001'# 假设这个股票的数据已按分区方式存储       target_year_partitioned = 2023    # 假设这个年份的数据已按分区方式存储          # 检查目标分区是否存在，以使示例更健壮       # 实际查询中，如果分区不存在，DuckDB的查询会返回空结果或错误，具体取决于版本和查询       example_target_partition_path = os.path.join(partitioned_base_dir, f"stock_code={target_stock_partitioned}", f"year={target_year_partitioned}", "data.parquet")       if not os.path.exists(example_target_partition_path):            print(f"警告: 示例目标分区文件 '{example_target_partition_path}' 不存在。")            print("分区查询可能不会返回预期结果，或因找不到文件而报错。请确保已生成相应分区数据。")             query_specific_partition_data = f"""       SELECT           date,           close,           volume,           stock_code, -- 'stock_code' 列由 DuckDB 从分区路径中推断出来           year        -- 'year' 列也由 DuckDB 从分区路径中推断出来       FROM read_parquet('{partitioned_files_path_pattern}', hive_partitioning=True)       WHERE stock_code = '{target_stock_partitioned}' AND year = {target_year_partitioned}       ORDER BY date DESC       LIMIT 5;       """       print(f"\n执行查询: 获取股票 {target_stock_partitioned} 在 {target_year_partitioned} 年分区数据中的最近5条记录")       try:           result_df_partitioned = con.execute(query_specific_partition_data).fetchdf()           if not result_df_partitioned.empty:               print("查询结果:")               print(result_df_partitioned)           else:               print(f"未能查询到股票 {target_stock_partitioned} 在 {target_year_partitioned} 年的分区数据。")               print(f"请检查路径 '{partitioned_files_path_pattern}' 是否正确，以及对应数据是否存在。")       except Exception as e: # DuckDB 可能因找不到文件或路径模式问题抛出 IO或Catalog异常           print(f"查询分区数据时发生错误: {e}")           print(f"请确保路径 '{partitioned_files_path_pattern}' 和 hive_partitioning 设置正确，并且目录下存在有效的 Parquet 文件。")             # 查询所有数据中，2023年收盘价最高的5条记录（跨所有股票）       query_top_closes_all_stocks = f"""       SELECT           date,           stock_code,           year,           open,           high,           low,           close,           volume       FROM read_parquet('{partitioned_files_path_pattern}', hive_partitioning=True)       WHERE year = 2023 -- 筛选2023年的数据，DuckDB会利用year分区进行优化       ORDER BY close DESC       LIMIT 5;       """       print(f"\n执行查询: 获取所有分区股票在 2023 年收盘价最高的5条记录")       try:           top_closes_df = con.execute(query_top_closes_all_stocks).fetchdf()           if not top_closes_df.empty:               print("查询结果:")               print(top_closes_df)           else:               print("未能查询到2023年的任何数据，或查询结果为空。")       except Exception as e:           print(f"查询分区数据时发生错误: {e}")          con.close()       print("\n--- DuckDB 分区查询结束 ---")   `

**重要提示关于分区查询:**

-   当使用 `read_parquet` 并配合通配符（如 `*` 或 `**`) 和 `hive_partitioning=True` 时，DuckDB 可以智能地只读取满足 `WHERE` 子句中分区列条件的文件（分区裁剪），从而大幅提高查询效率。
    
-   目录结构必须严格遵循 `key=value` 的 Hive 分区格式，例如 `year=2023/month=01/data.parquet`。
    
-   文件名在每个最内层分区目录中最好保持一致 (例如都叫 `data.parquet`)。
    

**4\. 性能考量与进阶应用**

-   **数据更新:**
    

-   日度数据:
    
    可以每日增量获取最新数据。对于 Parquet，通常的做法是：
    
-   **分钟级数据:** 考虑每隔一段时间（如每日收盘后）将当天的分钟数据合并存储为一个或少数几个 Parquet 文件。
    

1.  按日期/月份创建新的 Parquet 文件（例如 `data_20250515.parquet`）。
    
2.  如果需要单个聚合文件，可以定期（如每月、每年）将小的 Parquet 文件合并成一个较大的文件。DuckDB 可以轻松查询多个文件或目录下的所有文件。
    

-   **数据压缩:** Parquet 支持多种压缩算法（如 Snappy, Gzip, ZSTD）。`pyarrow` 默认使用 Snappy，它在压缩率和解压速度之间取得了较好的平衡。可以在 `to_parquet` 时通过 `compression` 参数指定：
    
    Python
    
    `# stock_hist_df.to_parquet(parquet_file_path, engine='pyarrow', compression='gzip', index=False)   # stock_hist_df.to_parquet(parquet_file_path, engine='pyarrow', compression='zstd', index=False)   `
    
-   **与 Pandas 集成:** DuckDB 与 Pandas 的集成非常紧密：
    

-   查询结果转为 DataFrame: `con.execute("SQL").fetchdf()` 或 `.df()`。
    
-   从 Pandas DataFrame 创建/注册表: `con.register('my_pandas_table', pandas_df)` 或 `con.execute("CREATE TABLE my_new_table AS SELECT * FROM pandas_df")`。
    

-   **复杂分析:** DuckDB 支持窗口函数、CTE (Common Table Expressions)、JOINs、复杂的聚合函数等高级 SQL 功能。这使得可以直接在 Parquet 数据上进行复杂的金融分析，如计算移动平均线 (MA)、指数移动平均线 (EMA)、布林带 (Bollinger Bands)、各种技术指标和因子分析等，而无需将数据加载到 Pandas 中进行所有计算。
    
    Python
    
    `# 示例：使用窗口函数计算20日移动平均收盘价 (概念性SQL)   # query_moving_average = f"""   # SELECT   #     date,   #     close,   #     AVG(close) OVER (ORDER BY date ASC ROWS BETWEEN 19 PRECEDING AND CURRENT ROW) AS ma20_close   # FROM read_parquet('{single_parquet_file_path}')   # ORDER BY date DESC   # LIMIT 100;   # """   # ma_df = con.execute(query_moving_average).fetchdf()   # print(ma_df)   `
    
-   **性能测试：**测试数据为10年A股日频因子
    

操作类型

DuckDB+Parquet

SQLite

Pandas+HDF5

全量写入

38秒

2分12秒

1分45秒

时间范围查询

0.8ms

15ms

120ms

因子横截面分析

1.2秒

8.5秒

3.4秒

存储空间

1.8GB

6.7GB

1.5GB

**5\. 结论**

结合Parquet 的高效列式存储以及 DuckDB 的极速查询分析引擎，可以为A股数据构建一个强大、灵活且成本效益高的数据解决方案。该方案特别适用于个人量化研究者、小型投资团队以及需要在本地环境进行快速数据探索、原型验证和复杂分析的场景。通过合理地组织数据存储（尤其是利用分区）并充分发挥 DuckDB 的 SQL 分析能力，可以有效应对海量 A 股数据的挑战，为投资决策和策略回测提供坚实的数据基础和高效的分析工具。

  

代码及更多资源见星球，加入QuantML星球，与星主和850+专业人士一起交流学习：

![图片](assets/003.webp)