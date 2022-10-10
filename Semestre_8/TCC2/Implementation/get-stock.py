# # Raw Package
# import numpy as np
# import pandas as pd

# # Data Source
# import yfinance as yf

# # Data viz
# import plotly.graph_objs as go

# import datetime


# def getStockPrice(stock, period):
#     df = pd.DataFrame()
#     for i in range(0, period, 7):
#         end = datetime.datetime.now() - datetime.timedelta(days=i)
#         start = end - datetime.timedelta(days=7)
#         aux_df = yf.download(stock, start.strftime(
#             "%Y-%m-%d"), end.strftime("%Y-%m-%d"), interval="1m")
#         df = pd.concat([aux_df, df])

#     print(df)


# getStockPrice("USDBRL=X", 60)

from alpha_vantage.timeseries import TimeSeries
import pandas as pd
import matplotlib.pyplot as plt

alpha_vantage_api_key = "P300MRQT6N5ZSUHJ"


def pull_intraday_time_series_alpha_vantage(alpha_vantage_api_key, ticker_name, data_interval='15min'):
    ts = TimeSeries(key=alpha_vantage_api_key, output_format='pandas')
    data, meta_data = ts.get_intraday(
        ticker_name, outputsize='full', interval=data_interval)
    data['date_time'] = data.index
    return data, meta_data


#### EXECUTE IN MAIN FUNCTION ####
ts_data, ts_metadata = pull_intraday_time_series_alpha_vantage(
    alpha_vantage_api_key, ticker_name="WDOFUT", data_interval='1min')

print(ts_data)
# Plot the high prices
