from flask_restful import Resource
from flask import jsonify
import numpy as np
import pandas as pd
import yfinance as yf
import plotly.graph_objs as go
import datetime

class Stock(Resource):
  def get(self, stock, period):
    period = int(period)
    stock = str(stock)

    df = pd.DataFrame()
    for i in range(0, int(period), 7):
      end = datetime.datetime.now() - datetime.timedelta(days=i)
      start = end - datetime.timedelta(days=7)
      aux_df = yf.download(stock, start.strftime(
          "%Y-%m-%d"), end.strftime("%Y-%m-%d"), interval="1m")
      df = pd.concat([aux_df, df])
    return df.to_json()