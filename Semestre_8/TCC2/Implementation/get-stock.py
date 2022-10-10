# Raw Package
import numpy as np
import pandas as pd

# Data Source
import yfinance as yf

# Data viz
import plotly.graph_objs as go

import datetime

def getStockPrice(stock, period):
    df = pd.DataFrame()
    for i in range(0, period, 7):
        end = datetime.datetime.now() - datetime.timedelta(days=i)
        start = end - datetime.timedelta(days=7)
        aux_df = yf.download(stock, start.strftime(
            "%Y-%m-%d"), end.strftime("%Y-%m-%d"), interval="1m")
        df = pd.concat([aux_df, df])

    print(df)


getStockPrice("USDBRL=X", 60)
