from methods.linearizado import Linearizado
from methods.matricial import Matricial
from methods.retas import Retas
import numpy as np
import sympy as sy

x = [1, 1.5, 2, 3]
y = [1.1, 1.4, 2.3, 2.8]

# x = [0, 1, 2]
# y = [1, 3, 8]

print("*** Reta ***")
a0, a1, r2_score = Retas(x, y).solve()
print("a0 = {}\na1 = {}\nR2 = {}".format(a0, a1, r2_score))
print()
print("*** Matricial ***")
X, r2_score = Matricial(x, y, 1).solve()
print("X = {}\nR2 = {}".format(X, r2_score))
print()
# print("*** Linearizado ***")
# X, r2_score = Linearizado(x, y).solve()
# print("X = {}\nR2 = {}".format(X, r2_score))
