from methods.lagrange import Lagrange
from methods.matricial import Matricial
from methods.newton import Newton
import numpy as np

# A = [[1, 1991, 1991**2], [1, 2000, 2000**2], [1, 2010, 2010**2]]
# y = [0.525, 0.682, 0.79]

# A = [[1, 0, 0], [1, 0.6, -0.36], [1, 1, -1]]
# y = [4, 2.23, -0.91]

# matricial = Matricial(A, y)
# matricial.solve()

# ----

# P = [[1, 3], [2, 5]]
# x = 1.7

# lagrange = Lagrange(P, x)
# lagrange.solve()

P = [[0, 0], [np.pi/6, 0.5], [np.pi/2, 1]]
x = 0.2

newton = Newton(P, x)
newton.solve()
