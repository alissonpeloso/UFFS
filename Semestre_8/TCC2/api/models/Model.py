import pandas as pd
from keras.models import Sequential, load_model
from keras.layers import Dense, Dropout, LSTM, Reshape
from keras.callbacks import EarlyStopping, ReduceLROnPlateau, ModelCheckpoint
from sklearn.preprocessing import MinMaxScaler
import numpy as np
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
import tensorflow as tf
from Stock import Stock
import json

weightsFolder = 'weights/';

# config object example
# config = 
# {
# 	X_columns : ['Fechamento', 'Volume Quantidade'],
# 	y_columns : ['Fechamento'],
# 	n_steps: 144,
# 	m_predictions: 21,
# 	test_size = 0.0,
# 	layers : [
# 		{
# 			units: 100,
# 			dropout: 0.3,
# 		},
# 		{
# 			units: 50,
# 			dropout: 0.3,
# 		},
# 		{
# 			units: 50,
# 			dropout: 0.3,
# 		},
# 		{
# 			units: 50,
# 			dropout: 0.3,
# 		}
# 	],
# 	epochs : 100,
# 	stock : {
#         timeframe : 2,
#         periods : 7200,
#   }
# }

class Model:
    def __init__(self, config = {}, timeframe = 2, periods = 7200):
        self.config = config
        if (config.get('stock') != None):
            stock = Stock(timeframe, periods)
        else:
            stock = Stock(2, 7200)
        dataset = stock.getDF()

        self.dataset = dataset.replace({',': '.'}, regex=True)
        self.X_columns = config['X_columns'] if config.get('X_columns') != None else ['Fechamento', 'Volume Quantidade']
        self.y_columns = config['y_columns'] if config.get('y_columns') != None else ['Fechamento']
        self.n_steps = config['n_steps'] if config.get('n_steps') != None else 144
        self.m_predictions = config['m_predictions'] if config.get('m_predictions') != None else 13
        self.test_size = config['test_size'] if config.get('test_size') != None else 0.0
        self.X = None 
        self.y = None
        self.scaler_X = None
        self.scaler_y = None
        print(self.dataset[-10:-1])
        self.prepare_dataset()

    def prepare_dataset(self):
        ### Scaling X and y parameters
        X_unscaled = self.dataset[self.X_columns].iloc[:, :].values
        y_unscaled = self.dataset[self.y_columns].iloc[:, :].values

        self.scaler_X = MinMaxScaler(feature_range=(0, 1))
        X_scaled = self.scaler_X.fit_transform(X_unscaled)

        self.scaler_y = MinMaxScaler(feature_range=(0, 1))
        y_scaled = self.scaler_y.fit_transform(y_unscaled)

        X, y = list(), list()
        for i in range(len(X_scaled)):
            # find the end of this pattern
            end_ix = i + self.n_steps
            end_iy = end_ix + self.m_predictions
            # check if we are beyond the sequence
            if end_ix > len(X_scaled)-1 or end_iy > len(X_scaled)-1 :
                break
            # gather input and output parts of the pattern
            seq_x, seq_y = X_scaled[i:end_ix], y_scaled[end_ix:end_ix+self.m_predictions] 

            X.append(seq_x)
            y.append(seq_y)

        self.X = np.array(X)
        self.y = np.array(y)
        
        size = len(self.X)
        self.X_train = np.array(X[:int(size - (size*self.test_size))])
        self.X_test = np.array(X[int(size - (size*self.test_size)) : -1])
        self.y_train = np.array(y[:int(size - (size*self.test_size))])
        self.y_test = np.array(y[int(size - (size*self.test_size)) : -1])     

    def fit(self, model_name = 'default.h5'):
        X_train, y_train = self.X_train, self.y_train

        layers = (self.config['layers'] if self.config.get('layers') != None else [])

        if (len(layers) == 0):
            layers = [
                {
                    'units': 100,
                    'dropout': 0.3,
                },
                {
                    'units': 50,
                    'dropout': 0.3,
                },
                {
                    'units': 50,
                    'dropout': 0.3,
                },
                {
                    'units': 50,
                    'dropout': 0.3,
                }
            ]

        # LSTM structure
        regressor = Sequential()

        for index, layer in enumerate(layers):
            if (index == 0):
                regressor.add(LSTM(units=layer['units'], return_sequences=True, input_shape=(X_train.shape[1], len(self.X_columns))))
            elif (index == len(layers) - 1):
                regressor.add(LSTM(units=layer['units']))
            else:
                regressor.add(LSTM(units=layer['units'], return_sequences=True))
            regressor.add(Dropout(layer['dropout']))

        # Output layer
        regressor.add(Dense(units=self.m_predictions, activation='sigmoid')) ## 8 ou 13

        regressor.add(Reshape((self.m_predictions, 1)))

        # Building the network
        regressor.compile(optimizer='rmsprop', loss='mean_squared_error',
                            metrics=['mean_absolute_error'])

        # Funções de Callback
        es = EarlyStopping(monitor='loss', min_delta=1e-10, patience=10, verbose=1)
        rlr = ReduceLROnPlateau(monitor='loss', factor=0.2, patience=5, verbose=1)
        mcp = ModelCheckpoint(filepath='pesos.h5', monitor='loss',
                                save_best_only=True, verbose=1)
        regressor.fit(X_train, y_train, epochs=100, batch_size=32 ,callbacks=[es, rlr, mcp])

        regressor.save(weightsFolder+model_name)
    
    def test(self, model_name = 'default.h5'):
        regressor = load_model(weightsFolder+model_name)
        y_hat = regressor.predict(self.X_test)
        y_hat = np.reshape(y_hat, (y_hat.shape[0], y_hat.shape[1]))
        y_test = np.reshape(self.y_test, (self.y_test.shape[0], self.y_test.shape[1]))
        y_hat = self.scaler_y.inverse_transform(y_hat)
        y_test = self.scaler_y.inverse_transform(y_test)

        mse = mean_squared_error(y_test, y_hat)
        print('MSE: %.3f' % mse)

        rmse = np.sqrt(mse)
        print('RMSE: %.3f' % rmse)

        mae = mean_absolute_error(y_test, y_hat)
        print('MAE: %.3f' % mae)

        r2 = r2_score(y_test, y_hat)
        print('R2: %.3f' % r2)

    
    def predict(self, model_name = 'default.h5'):
        regressor = load_model(weightsFolder+model_name)
        test = self.X[-1].reshape(1, self.X[-1].shape[0], self.X[-1].shape[1])
        y_hat = regressor.predict(test)
        y_hat = np.reshape(y_hat, (y_hat.shape[0], y_hat.shape[1]))
        return self.scaler_y.inverse_transform(y_hat)

with open('config/1.json') as json_file:
    config = json.load(json_file)
    lstm = Model(config, 2, 7200)
    lstm.test("2min_default.h5")
