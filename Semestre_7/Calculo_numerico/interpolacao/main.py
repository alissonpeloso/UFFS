from methods.lagrange import Lagrange
from methods.matricial import Matricial
from methods.DF import DF
from methods.DD import DD
import numpy as np

# A = [[1, 1991, 1991**2], [1, 2000, 2000**2], [1, 2010, 2010**2]]
# y = [0.525, 0.682, 0.79]

# A = [[1, 0, 0], [1, 0.6, -0.36], [1, 1, -1]]
# y = [4, 2.23, -0.91]

# A = [[4, 2, 0, -1, 1], [1, -1, 4.0, -1, 1],
#      [-1, 5, 0, -1, 1], [0, -1, 1, -1, 7], [1, -2, 1, -6, 1]]
# y = [15, 32, 13.0, 30, 10]

# matricial = Matricial(A, y)
# matricial.solve()

# ----
# ----
# ----

# P = [[1, 3], [2, 5]]
# x = 1.7

# P = [[0, 0], [np.pi/6, 0.5], [np.pi/2, 1]]
# x = 0.2

# P = [[1, 0], [3, 6], [4, 24], [5, 60]]
# x = 2

P = [[0, 1], [1, 4], [2, 8]]
x = 1.3

print("### LAGRANGE ###")
lagrange = Lagrange(P, x)
lagrange.solve()
print()

print("### DIFERENÇAS DIVIDIDAS ###")

dd = DD(P, x)
dd.solve()
print()

print("### DIFERENÇAS FINITAS ###")

df = DF(P, x)
df.solve()
print()
