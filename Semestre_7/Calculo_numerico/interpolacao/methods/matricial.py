import matplotlib.pyplot as plt
import numpy as np
from methods.method import Method


class Matricial(Method):
	def __init__(self, A, b, epsilon) -> None:
		self.A = np.array(A)
		self.b = np.array(b)
		self.episolon = epsilon
		self.verify()
    def solve(self):
        A = self.A
        b = self.b
        epsilon = self.episolon
        x = np.zeros((A.shape[0]))

        AA, bb = self.getDiagonal1()

        iterations = 0
        I = np.eye(AA.shape[0])
        c = (AA - I)
        while(np.linalg.norm(AA.dot(x)-bb) >= epsilon):
            x = bb - np.dot(c, x)
            iterations += 1

        print(x)
        print("iterações: {}".format(iterations))
