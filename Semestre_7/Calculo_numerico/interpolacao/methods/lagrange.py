from re import X
import matplotlib.pyplot as plt
import numpy as np


class Lagrange():
    def __init__(self, P, x) -> None:
        self.P = np.array(P)
        self.x = np.array(x)

    def solve(self):
        P = self.P
        x = self.x
        size = len(P)

        result = 0
        for i in range(size):
            L = P[i][1]
            for j in range(size):
                if j != i:
                    L = L * (x - P[j][0])/(P[i][0] - P[j][0])

            result += L

        print("P({}) = {}".format(x, result))
