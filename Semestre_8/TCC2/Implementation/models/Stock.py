import datetime
import yfinance as yf
import pandas as pd

class Stock:
    def __init__(self, stock, period):
        self.stock = str(stock)
        self.period = int(period)
    
    def getDF(self):
        period = self.period
        stock = self.stock
        
        df = pd.DataFrame()
        for i in range(0, int(period), 7):
            end = datetime.datetime.now() - datetime.timedelta(days=i)
            start = end - datetime.timedelta(days=7)
            aux_df = yf.download(stock, start.strftime(
                "%Y-%m-%d"), end.strftime("%Y-%m-%d"), interval="1m")
            df = pd.concat([aux_df, df])
        return df
