import math
import matplotlib.pyplot as plt
import numpy as np
from methods.method import Method


class Bissecao(Method):
    def solve(self):
        a = self.a
        b = self.b
        epsilon = self.episolon
        func = self.func

        fdx = epsilon+1
        fda = func(a)

        iterations = 0
        while abs(fdx) >= epsilon:
            x = (a + b)/2
            fdx = func(x)

            if fdx * fda > 0:
                a = x
            else:
                b = x
            iterations += 1

        print("Result:", x)
        print("Iterations:", iterations)
        print()

        self.plotGraph(x, fdx)
