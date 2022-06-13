from methods.jacobi import Jacobi
from methods.gs import GS

# Tem que colocar . alguma coisa em algum valor, se não for floar ele faz divisão troll

A = [[3, 1, -1], [1, 2, -3.0], [0.5, 1, -5]]
b = [2, 4, 1.0]

episolon = 10**-10

# jacob = Jacobi(A, b, episolon)
# jacob.solve()
gs = GS(A, b, episolon)
gs.solve()
