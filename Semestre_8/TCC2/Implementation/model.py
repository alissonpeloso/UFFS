import pandas as pd
from keras.models import Sequential, load_model
from keras.layers import Dense, Dropout, LSTM, Reshape
from keras.callbacks import EarlyStopping, ReduceLROnPlateau, ModelCheckpoint
from routes.Stock import Stock
from sklearn.preprocessing import MinMaxScaler
import numpy as np
from sklearn.metrics import mean_squared_error
import tensorflow as tf

class Model:
    def __init__(self, dataset, X_columns = ['Close', 'Volume'], y_columns = ['Close'], n_steps = 144, m_predictions = 21, test_size = 0):
        self.dataset = dataset
        self.X_columns = X_columns
        self.y_columns = y_columns
        self.n_steps = n_steps
        self.m_predictions = m_predictions
        self.test_size = test_size
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

        # LSTM structure
        # Camada de entrada
        regressor = Sequential()
        regressor.add(LSTM(units=100, return_sequences=True, input_shape=(X_train.shape[1], len(self.X_columns))))
        regressor.add(Dropout(0.3))

        # Cada Oculta 1
        # regressor.add(LSTM(units=50, return_sequences=True))
        # regressor.add(Dropout(0.3))

        # Cada Oculta 2
        # regressor.add(LSTM(units=50, return_sequences=True))
        # regressor.add(Dropout(0.3))

        # Cada Oculta 3
        regressor.add(LSTM(units=50))
        regressor.add(Dropout(0.3))

        # Camada de Saída
        regressor.add(Dense(units=self.m_predictions, activation='sigmoid'))

        regressor.add(Reshape((21, 1)))

        # Building the network
        regressor.compile(optimizer='rmsprop', loss='mean_squared_error',
                            metrics=['mean_absolute_error'])

        # Funções de Callback
        es = EarlyStopping(monitor='loss', min_delta=1e-10, patience=10, verbose=1)
        rlr = ReduceLROnPlateau(monitor='loss', factor=0.2, patience=5, verbose=1)
        mcp = ModelCheckpoint(filepath='pesos.h5', monitor='loss',
                                save_best_only=True, verbose=1)
        regressor.fit(X_train, y_train, epochs=100, batch_size=32 ,callbacks=[es, rlr, mcp])

        regressor.save(model_name)
    
    def test(self, model_name = 'default.h5'):
        regressor = load_model(model_name)
        y_hat = regressor.predict(self.X_test)
        y_hat = np.reshape(y_hat, (y_hat.shape[0], y_hat.shape[1]))
        y_test = np.reshape(self.y_test, (self.y_test.shape[0], self.y_test.shape[1]))
        y_hat = self.scaler_y.inverse_transform(y_hat)
        y_test = self.scaler_y.inverse_transform(y_test)

        rmse = np.sqrt(mean_squared_error(y_test, y_hat))
        print('Test RMSE: %.3f' % rmse)

        mse = mean_squared_error(y_test, y_hat)
        print('Test MSE: %.3f' % mse)
    
    def predict(self, model_name = 'default.h5'):
        regressor = load_model(model_name)
        return regressor.predict(self.X[-1])

stock = Stock()
df = stock.getDF('GC=F', 30)
lstm = Model(df, test_size=0.3)
lstm.fit()
lstm.test()