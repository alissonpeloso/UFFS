from re import X
import numpy as np

# Diferenças Finitas
# Precisa ter o h igual em todos os casos, ou seja, diferença entre os "x" precisam ser iguais.


class DF():
    def __init__(self, P, x) -> None:
        self.P = np.array(P)
        self.x = np.array(x)

    def solve(self):
        P = self.P
        x = self.x
        size = len(P)

        h = P[1][0] - P[0][0]  # x1 - x0
        z = (x - P[0][0])/h  # (x - x0)/h

        y = 0
        for i in range(size):
            partial = self.getDelta(0, i) / np.math.factorial(i)
            for j in range(i):
                partial *= (z - j)
            y += partial

        print("P({}) = {}".format(x, y))

    def getDelta(self, i, n):
        P = self.P
        getDelta = self.getDelta

        if n == 0:
            return P[i][1]  # yi
        return (getDelta(i+1, n-1) - getDelta(i, n-1))
