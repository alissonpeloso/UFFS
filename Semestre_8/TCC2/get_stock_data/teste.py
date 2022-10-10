# Raw Package
import numpy as np
import pandas as pd

#Data Source
import yfinance as yf

#Data viz
import plotly.graph_objs as go

data = yf.download(tickers="GC=F", period="7d", interval="1m")
print(data)