from methods.retas import Retas
import numpy as np
import sympy as sy

x = [1, 1.5, 2, 3]
y = [1.1, 1.4, 2.3, 2.8]
xPoint = None

print("*** Reta ***")
if xPoint:
    result = Retas(x, y, xPoint).solve()
    print("Result:", result)
else:
    a0, a1 = Retas(x, y).solve()
    print("a0 = {}\na1 = {}".format(a0, a1))
