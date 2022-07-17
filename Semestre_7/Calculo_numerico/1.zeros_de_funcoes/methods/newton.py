import math
import matplotlib.pyplot as plt
from methods.method import Method
import sympy as sy
from numpy import *


class Newton(Method):
    def __init__(self, f: str, epsilon: float, a: float, b: float):
        super().__init__(f, epsilon, a, b)
        x = sy.Symbol('x')
        self.df1 = str(
            sy.diff(eval(self.f.replace("np", "sy")), x))
        self.df2 = str(
            sy.diff(eval(self.f.replace("np", "sy")), x, 2))

    def diff1(self, x):
        return eval(self.df1)

    def diff2(self, x):
        return eval(self.df2)

    def solve(self):
        a = self.a
        b = self.b
        epsilon = self.episolon
        func = self.func
        diff1 = self.diff1
        diff2 = self.diff2

        midpointAB = (a + b) / 2
        if diff1(midpointAB) * diff2(midpointAB) > 0:
            x = b
        else:
            x = a

        fdx = func(x)

        iterations = 1
        while abs(fdx) >= epsilon:

            x = x - (fdx / diff1(x))

            fdx = func(x)
            iterations += 1

        print("Result:", x)
        print("Iterations:", iterations)
        print()

        self.plotGraph(x, fdx)
