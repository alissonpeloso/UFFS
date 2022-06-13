from re import X
import matplotlib.pyplot as plt
import numpy as np


class Newton():
    def __init__(self, P, x) -> None:
        self.P = np.array(P)
        self.x = np.array(x)

    def solve(self):
        P = self.P
        x = self.x
        size = len(P)

        y = 0
        for i in range(size):
            partial = self.getDelta(0, i)
            for j in range(i):
                partial *= (x - P[j][0])  # (x - xj)
            y += partial

        print("P({}) = {}".format(x, y))

    def getDelta(self, i, n):
        P = self.P
        getDelta = self.getDelta

        if n == 0:
            return P[i][1]  # yi
        return (getDelta(i+1, n-1) - getDelta(i, n-1))/(P[i+n][0] - P[i][0])
