import pandas as pd
from keras.models import Sequential, load_model
from keras.layers import Dense, Dropout, LSTM
from keras.callbacks import EarlyStopping, ReduceLROnPlateau, ModelCheckpoint
from routes.Stock import Stock
from sklearn.preprocessing import MinMaxScaler
import numpy as np

stock = Stock()
DataSet = stock.getDF("USDBRL=X", 30)

train = False


def split_sequence(sequence, n_steps):
    X, y = list(), list()
    for i in range(len(sequence)):
        # find the end of this pattern
        end_ix = i + n_steps
        # check if we are beyond the sequence
        if end_ix > len(sequence)-1:
            break
        # gather input and output parts of the pattern
        seq_x, seq_y = sequence[i:end_ix], sequence[end_ix]
        X.append(seq_x)
        y.append(seq_y)
    return np.array(X), np.array(y)


base_treinamento = DataSet[['Close', 'Volume']].iloc[:, :].values

scaler_X = MinMaxScaler(feature_range=(0, 1))
base_scaled = scaler_X.fit_transform(base_treinamento)

scaler_y = MinMaxScaler(feature_range=(0, 1))
scaler_y.fit_transform(base_treinamento[:, 0:1])

# create the previsors
previsores = []
preco_real = []
NRecursao = 21
NPrevisores = 2
MPrevisoes = 1

X_train, y_train = split_sequence(base_scaled, NRecursao)
y_train = y_train[:, 0:1]  # Seleciona o fechamento como label

X_test = base_scaled

# LSTM structure
if train:
    # Camada de entrada
    regressor = Sequential()
    regressor.add(LSTM(units=100, return_sequences=True,
                       input_shape=(X_train.shape[1], NPrevisores)))
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
else:
    regressor = load_model('pesos.h5')

# Test data
# y_hat = regressor.predict(np.array([X_test]))
# y_hat = scaler_y.inverse_transform(y_hat)

y_hat = []
for i in range(np.array([X_test])):
    

print(y_hat)
