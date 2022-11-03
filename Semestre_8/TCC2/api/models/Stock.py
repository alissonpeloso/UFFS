import pandas as pd


class Stock:
    def __init__(self, timeframe, period=None):
        self.period = period
        self.timeframe = int(timeframe)
        self.df = None

    def getDF(self):
        period = self.period
        timeframe = self.timeframe

        df = pd.read_csv('data/'+str(timeframe)+'min.csv')
        df = df.iloc[::-1]

        if period == None:
            return df

        df = df[-period:-1]
        self.df = df.replace({',': '.'}, regex=True)
        self.df.astype({
            'Abertura': 'float64',
            'Máxima': 'float64',
            'Mínima': 'float64',
            'Fechamento': 'float64',
            'Volume Quantidade': 'int32'
        }, copy=False)

    def MA(self, windowSize, columnName):
        numberSeries = self.df[columnName].squeeze()
        movingAverages = numberSeries.rolling(windowSize).mean()
        self.df["MA"+str(windowSize)] = movingAverages
