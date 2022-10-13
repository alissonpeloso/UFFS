import pandas as pd
from keras.models import Sequential, load_model
from keras.layers import Dense, Dropout, LSTM
from keras.callbacks import EarlyStopping, ReduceLROnPlateau, ModelCheckpoint
from routes.Stock import Stock
from sklearn.preprocessing import MinMaxScaler
import numpy as np

class LSTM:
    def __init__(self, dataset, x_columns = ['Close', 'Volume'], y_columns = ['Close']):
        self.dataset = dataset
        self.x_columns = x_columns
        self.y_columns = y_columns
        self.X = None
        self.y = None
        self.scaler_X = None
        self.scaler_y = None
    
    def split_sequence(self, n_steps):
        X, y = list(), list()
        for i in range(len(self.X)):
            # find the end of this pattern
            end_ix = i + n_steps
            # check if we are beyond the sequence
            if end_ix > len(self.X)-1:
                break
            # gather input and output parts of the pattern
            seq_x, seq_y = self.X[i:end_ix], self.y[end_ix]
            X.append(seq_x)
            y.append(seq_y)
        return np.array(X), np.array(y)
    
    def prepare_dataset(self):
        X_unscaled = self.dataset[self.x_columns].iloc[:, :].values
        y_unscaled = self.dataset[self.y_columns].iloc[:, :].values

        self.scaler_X = MinMaxScaler(feature_range=(0, 1))
        self.X = self.scaler_X.fit_transform(X_unscaled)

        self.scaler_y = MinMaxScaler(feature_range=(0, 1))
        self.y = self.scaler_y.fit_transform(y_unscaled)

    def create_model(self, nRecursion, nForecasters, mPredictions, model_name):
        X_train, y_train = self.split_sequence(nRecursion)

        # LSTM structure
        # Camada de entrada
        regressor = Sequential()
        regressor.add(LSTM(units=100, return_sequences=True,
                            input_shape=(X_train.shape[1], nForecasters)))
        regressor.add(Dropout(0.3))

        # Cada Oculta 1
        regressor.add(LSTM(units=50, return_sequences=True))
        regressor.add(Dropout(0.3))

        # Cada Oculta 2
        regressor.add(LSTM(units=50, return_sequences=True))
        regressor.add(Dropout(0.3))

        # Cada Oculta 3
        regressor.add(LSTM(units=50))
        regressor.add(Dropout(0.3))

        # Camada de Saída
        regressor.add(Dense(units=1, activation='sigmoid'))

        # Building the network
        regressor.compile(optimizer='rmsprop', loss='mean_squared_error',
                            metrics=['mean_absolute_error'])

        # Funções de Callback
        es = EarlyStopping(monitor='loss', min_delta=1e-10, patience=10, verbose=1)
        rlr = ReduceLROnPlateau(monitor='loss', factor=0.2, patience=5, verbose=1)
        mcp = ModelCheckpoint(filepath='pesos.h5', monitor='loss',
                                save_best_only=True, verbose=1)
        regressor.fit(X_train, y_train, epochs=100, batch_size=32,
                        callbacks=[es, rlr, mcp])

        regressor.save(model_name)