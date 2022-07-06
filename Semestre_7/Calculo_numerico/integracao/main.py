from methods.trapezio import Trapezio
from methods.simpson1 import Simpson1
from methods.simpson2 import Simpson2
import numpy as np
import sympy as sy

f = "np.exp(x)"
n = 7
a = 0
b = 1

print("*** Exata ***")
x = sy.Symbol("x")
print("A =", sy.integrate(f.replace("np.", ""), (x, a, b)))
print()
print("*** Trapézio ***")
Trapezio(f, a, b, n)
print()
print("*** Simpson 1 ***")
Simpson1(f, a, b, n)  # n = 3,5,7,9,...
print()
print("*** Simpson 2 ***")
Simpson2(f, a, b, n).plotGraph()  # n = 4,7,10,13,...
