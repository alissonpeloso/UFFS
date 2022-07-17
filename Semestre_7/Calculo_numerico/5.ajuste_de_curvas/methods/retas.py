import numpy as np


class Retas():
    def __init__(self, x: list, y: list, xPoint=None) -> None:
        self.x = x
        self.y = y
        self.xPoint = xPoint

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

        if self.xPoint:
            return a0 + a1 * self.xPoint

        return a0, a1
