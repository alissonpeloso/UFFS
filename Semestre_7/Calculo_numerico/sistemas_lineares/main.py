from methods.jacobi import Jacobi
from methods.gs import GS

A = [[3, 0.5], [1, -1]]
b = [3, 1]

episolon = 0.0000001

jacob = Jacobi(A, b, episolon)
jacob.solve()
gs = GS(A, b, episolon)
gs.solve()
