import matplotlib.pyplot as plt
import numpy as np
from methods.method import Method


class GS(Method):

    def getLUdecomposition(self, A):
        L = np.zeros((A.shape[0], A.shape[0]))
        D = np.zeros((A.shape[0], A.shape[0]))
        U = np.zeros((A.shape[0], A.shape[0]))

        for i in range(A.shape[0]):
            for j in range(A.shape[0]):
                if i < j:
                    U[i][j] = A[i][j]
                elif i == j:
                    D[i][j] = A[i][j]
                elif i > j:
                    L[i][j] = A[i][j]

        return L, D, U

    def solve(self):
        A = self.A
        b = self.b
        epsilon = self.episolon
        x = np.zeros((A.shape[0]))

        AA, bb = self.getDiagonal1()

        L, D, U = self.getLUdecomposition(AA)

        iterations = 0
        invLD = np.linalg.inv(L + D)
        p1 = invLD.dot(bb)
        p2 = invLD.dot(U)
        while(np.linalg.norm(AA.dot(x)-bb) >= epsilon):
            x = p1 - (p2.dot(x))
            iterations += 1

        print(x)
        print("iterações: {}".format(iterations))
