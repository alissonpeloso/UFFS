from re import X
import matplotlib.pyplot as plt
import numpy as np


class Matricial():
    def __init__(self, A, y) -> None:
        self.A = np.array(A)
        self.y = np.array(y)
        self.verify()

    def verify(self):
        pass

    def solve(self):
        A = self.A
        y = self.y

        X = np.linalg.inv(A) @ y
        print(X)
