import math
import matplotlib.pyplot as plt
import numpy as np


class Method:
    def __init__(self, f: str, epsilon: float, a: float, b: float):
        self.f = f
        self.episolon = epsilon
        self.a = a
        self.b = b

    def plotGraph(self, x=None, fdx=None):
        plt.axvline(x=0, c="gray")
        plt.axhline(y=0, c="gray")

        x1 = np.linspace(self.a, self.b, 100)
        y1 = self.func(x1)

        plt.plot(x1, y1, 'b', label="f(x)")
        if x != None and fdx != None:
            plt.plot(x, fdx, 'ro', label="root")
        plt.legend()
        plt.show()

    def func(self, x):
        return eval(self.f)
