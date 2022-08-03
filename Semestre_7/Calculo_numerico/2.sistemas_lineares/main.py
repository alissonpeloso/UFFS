from methods.jacobi import Jacobi
from methods.gs import GS

# Tem que colocar . alguma coisa em algum valor, se não for floar ele faz divisão troll

# A = [[4, 2, 0, -1, 1], [-1, 5, 0, -1, 1],
#      [1, -1, 4.0, -1, 1], [1, -2, 1, -6, 1], [0, -1, 1, -1, 7]]
# b = [15, 13, 32.0, 10, 30]

A = [[1045, 22.57, 61], [22.57, 1.6114,
                         2.38], [61, 2.38, 7.0]]
b = [481.4, 24.911, 59.4]

episolon = 10**-10

# jacob = Jacobi(A, b, episolon)
# jacob.solve()
gs = GS(A, b, episolon)
gs.solve()
