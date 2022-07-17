import math
import matplotlib.pyplot as plt
import numpy as np
from methods.method import Method


class Cordas(Method):
    def solve(self):
        a = self.a
        b = self.b
        epsilon = self.episolon
        func = self.func

        fda = func(a)
        fdb = func(b)
        x = (a * fdb - b * fda) / (fdb - fda)
        fdx = func(x)
        iterations = 1

        whichFunc = -1
        if fdx * fda > 0:
            whichFunc = 0
        else:
            whichFunc = 1

        while abs(fdx) >= epsilon:

            if whichFunc == 0:
                x = (x * fdb - b * fdx) / (fdb - fdx)
            elif whichFunc == 1:
                x = (a * fdx - x * fda) / (fdx - fda)

            fdx = func(x)
            iterations += 1

        print("Result:", x)
        print("Iterations:", iterations)
        print()

        self.plotGraph(x, fdx)
