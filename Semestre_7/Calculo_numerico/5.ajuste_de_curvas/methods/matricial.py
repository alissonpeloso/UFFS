import numpy as np
from sklearn.metrics import r2_score as r2


class Matricial():
    def __init__(self, x: list, y: list, grau: int) -> None:
        self.x = x
        self.y = y
        self.grau = grau

    def sumXn(self, x, n):
        return sum(map(lambda x: x**n, x))

    def sumXnY(self, x, n, y):
        s = 0
        for i in range(len(x)):
            s += x[i]**n*y[i]

        return s

    def solve(self):
        x = self.x
        y = self.y
        n = len(x)
        grau = self.grau

        A = []
        Y = []
        for i in range(grau+1):
            aux = []
            for j in range(grau+1):
                aux.append(self.sumXn(x, i+j))
            A.append(aux)
            Y.append(self.sumXnY(x, i, y))

        print(A)
        print(Y)

        X = np.linalg.inv(np.transpose(A)@A) @ np.transpose(A) @ Y

        y_hat = []
        for i in range(n):
            s = 0
            for j in range(len(X)):
                s += X[j]*(x[i]**j)
            y_hat.append(s)

        r2_score = r2(y, y_hat)

        return X, r2_score
