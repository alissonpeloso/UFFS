from methods.lagrange import Lagrange
from methods.matricial import Matricial
from methods.DF import DF
from methods.DD import DD
import numpy as np
import matplotlib.pyplot as plt


P = [[-4, 0.0588], [-3, 0.1], [-2, 0.2],
     [-1, 0.5], [0, 1], [1, 0.5], [2, 0.2], [3, 0.1], [4, 0.0588]]
x = 100

X = np.linspace(-4, 4)
Y = 1 / (1 + (X)**2)


Y2 = []

for i in X:
    df = DF(P, i)
    Y2.append(df.solve())

plt.plot(X, Y)
plt.plot(X, Y2)

plt.show()
