from methods.linearizado import Linearizado
from methods.matricial import Matricial
from methods.retas import Retas
import numpy as np
import sympy as sy

# x = [00.05, 0.5, 1.0, 1.5, 1.8, 2]
# y = [1, 0.68, 0.59, 0.47, 0.43, 0.38]

x = [25.03, 27.03, 28.33, 29.51, 31.57]
y = [1.227, 1.251, 1.262, 1.259, 1.234]

# x = [0, 1, 2]
# y = [1, 3, 8]

print("*** Reta ***")
a0, a1, r2_score = Retas(x, y).solve()
print("a0 = {}\na1 = {}\nR2 = {}".format(a0, a1, r2_score))
print()
print("*** Matricial ***")
X, r2_score = Matricial(x, y, 3).solve()
print("X = {}\nR2 = {}".format(X, r2_score))
print()
print("*** Linearizado ***")
X, r2_score = Linearizado(x, y).solve()
print("X = {}\nR2 = {}".format(X, r2_score))
