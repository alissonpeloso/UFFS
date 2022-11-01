import yfinance as yf
import pandas as pd

class Stock:
    def __init__(self, timeframe, period = None):
        self.period = period
        self.timeframe = int(timeframe)
    
    def getDF(self):
        period = self.period
        timeframe = self.timeframe

        df = pd.read_csv('data/'+str(timeframe)+'min.csv')
        df = df.iloc[::-1]

        if period == None:
            return df
            
        df = df[-period:-1]
        return df

