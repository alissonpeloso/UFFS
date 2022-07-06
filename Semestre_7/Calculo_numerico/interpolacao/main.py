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

# ----
# ----
# ----

# P = [[1, 3], [2, 5]]
# x = 2

# P = [[0, 0], [np.pi/6, 0.5], [np.pi/2, 1]]
# x = np.pi/2

# P = [[1, 0], [3, 6], [4, 24], [5, 60]]
# x = 2

P = [[-5, 0.0384], [-3, 0.1], [0, 1], [2, 0.2], [4, 0.0588]]
x = (3)

# P = [[86, 1552], [93.3, 1548], [98.9, 1544], [104.4, 1538], [110, 1532]]
# x = 110

print("### LAGRANGE ###")
lagrange = Lagrange(P, x)
print()

print("### DIFERENÇAS DIVIDIDAS ###")

dd = DD(P, x)
print()

# Precisa ter o h igual em todos os casos, ou seja, diferença entre os "x" precisam ser iguais.
print("### DIFERENÇAS FINITAS ###")

df = DF(P, x)
print()
