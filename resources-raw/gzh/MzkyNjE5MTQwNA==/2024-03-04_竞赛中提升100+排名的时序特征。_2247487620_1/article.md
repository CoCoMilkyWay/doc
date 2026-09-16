# 竞赛中提升100+排名的时序特征。

JK 量化前沿速递 2024-03-04 12:00 江苏

> 原文地址: [https://mp.weixin.qq.com/s?\_\_biz=MzkyNjE5MTQwNA==&mid=2247487620&idx=1&sn=79864df47b9c71ae5ebc71adb4bcf338&chksm=c34c84a46fc2bc0dbe13a501d522a8e42c6ef2bf34ec1a5450220cb6e3764b38750ce6516608#rd](https://mp.weixin.qq.com/s?__biz=MzkyNjE5MTQwNA==&mid=2247487620&idx=1&sn=79864df47b9c71ae5ebc71adb4bcf338&chksm=c34c84a46fc2bc0dbe13a501d522a8e42c6ef2bf34ec1a5450220cb6e3764b38750ce6516608#rd)

# 

  

**竞赛中的时序文本特征。**

  

简介

![](assets/001.png)

本文介绍一种非常强的特征，该特征经常被用在一些竞赛或者实践问题中；例如：

1.  一些题目的app中，某些题目的难度评估；
    
2.  推荐问题中商品的受喜好的情况；
    
3.  ...
    

那么这个特征是怎么做到的呢？

# 

框架

![](assets/001.png)

`df['items_prev'] = df.groupby(['user_id'])['items'].shift()   # 对相邻两个文本进行处理   df['feature']    = df[['items_prev','items']].apply(lambda x: function(x['items_prev'], x['items']))   # 对处理后的共性文本进行特征提取   featues = function2(df['feature'])   `

其中上述的function可以是计算两个context的交集，例如某个用户在浏览商品时，滑动窗口中的商品的交集，品类的交集等；然后再对这些交集内部的商品进行Count等操作，就可以知道所有被连续两次浏览的商品的次数，以此来衡量该商品的受喜好程度。

# 

案例

![](assets/001.png)

-   https://www.kaggle.com/code/rsakata/psp-3-fe-and-train-lgb
    

`class FeatureMaker():       def __init__(self):           self.map_key = None           self.valid_keys = None           self.list_text_seq = None           self.map_text_seq = None           self.feature_names = []                          def prepare(self, df, threshold):           # concatenation of variables           keys = df[["level", "name", "event_name", "room_fqid", "fqid", "text"]].values.tolist()           keys = [str(values[0]).zfill(2) + "_" + "_".join(["None" if type(v) != str else v for v in values[1:]]) for values in keys]           count_keys = Counter(keys)           valid_keys = [key for key, value in count_keys.items() if value >= threshold]           self.map_key = {key: i for i, key in enumerate(valid_keys)}           self.valid_keys = set(valid_keys)                      # text sequence of important events (notification_click)           df_tmp = df.query("event_name == 'notification_click'")[["session_id", "text"]].fillna("")           df_tmp["text_prev"] = df_tmp.groupby("session_id")["text"].shift()           df_tmp = df_tmp.dropna()           df_agg = df_tmp.groupby(["text_prev", "text"], as_index=False).size().sort_values("size", ascending=False)           self.list_text_seq = [(text1, text2) for text1, text2 in zip(df_agg["text_prev"], df_agg["text"])]           self.map_text_seq = {value: i for i, value in enumerate(self.list_text_seq)}                      self.feature_names += [f"count_{key}" for key in self.map_key.keys()]           self.feature_names += [f"bdiff_{key}" for key in self.map_key.keys()]           self.feature_names += [f"fdiff_{key}" for key in self.map_key.keys()]           self.feature_names += [f"time_between_{text1}_and_{text2}" for text1, text2 in self.list_text_seq]           self.feature_names += ["last_time", "diff_level_group_0to1", "diff_level_group_1to2"]              def make_feature(self, features, df_session, session_id, level_group):           keys = df_session[["level", "name", "event_name", "room_fqid", "fqid", "text"]].values.tolist()           keys = [str(values[0]).zfill(2) + "_" + "_".join(["None" if type(v) != str else v for v in values[1:]]) for values in keys]                      values_time = df_session["elapsed_time"].tolist()           values_event = df_session["event_name"].tolist()           values_text = df_session["text"].tolist()                      # time diff between level_group           if level_group == 1:               features[-2] = values_time[0] - features[-3]           elif level_group == 2:               features[-1] = values_time[0] - features[-3]                      # last time           features[-3] = values_time[-1]              text_prev = ""           time_prev = 0           for i in range(len(df_session)):               if keys[i] in self.valid_keys:                   # count                   feature_idx = self.map_key[keys[i]]                   if level_group <= 1:                       features[feature_idx] += 1                   # bdiff                   feature_idx += len(self.map_key)                   if level_group <= 1 and i > 0:                       features[feature_idx] += values_time[i] - values_time[i-1]                   # fdiff                   feature_idx += len(self.map_key)                   if i < len(df_session) - 1:                       features[feature_idx] += values_time[i+1] - values_time[i]               # text_seq               if values_event[i] == "notification_click":                   if (text_prev, values_text[i]) in self.map_text_seq:                       feature_idx = len(self.map_key)*3 + self.map_text_seq[(text_prev, values_text[i])]                       features[feature_idx] += values_time[i] - time_prev                   text_prev = values_text[i]                   time_prev = values_time[i]              return features`

# 

适用问题

![](assets/001.png)

所有相邻文本序列问题中。