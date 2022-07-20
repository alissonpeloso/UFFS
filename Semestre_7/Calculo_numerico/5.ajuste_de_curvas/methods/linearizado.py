import numpy as np
from methods.matricial import Matricial
from sklearn.metrics import r2_score as r2


class Linearizado():  # Caso particular: y = A*e^(b*x)
    def __init__(self, x: list, y: list) -> None:
        self.x = x
        self.y = y

    def solve(self):
        x = self.x
        y = self.y
        n = len(x)

        Y = np.log(y)
        X, r2_score = Matricial(x, Y, 1).solve()

        X[0] = np.exp(X[0])

        return X, r2_score
