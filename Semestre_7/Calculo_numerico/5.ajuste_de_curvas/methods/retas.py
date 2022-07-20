import numpy as np
from sklearn.metrics import r2_score as r2


class Retas():
    def __init__(self, x: list, y: list) -> None:
        self.x = x
        self.y = y

    def solve(self):
        x = self.x
        y = self.y
        n = len(x)

        sumXiYi = 0
        sumXi = 0
        sumYi = 0
        sumXi2 = 0

        for i in range(len(x)):
            sumXiYi += (x[i] * y[i])
            sumXi += x[i]
            sumYi += y[i]
            sumXi2 += (x[i]**2)

        a1 = (n*sumXiYi - sumXi*sumYi)/(n*sumXi2 - (sumXi**2))
        a0 = (sumYi - a1 * sumXi)/n

        y_hat = [a0 + a1*x[i] for i in range(len(x))]

        r2_score = r2(y, y_hat)

        return a0, a1, r2_score
