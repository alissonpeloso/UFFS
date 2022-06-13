from methods.bissecao import Bissecao
from methods.cordas import Cordas
from methods.method import Method
from methods.newton import Newton
from sympy import *

f = "x*(np.cosh(200/x)-1)-100"
epsilon = 10**(-10)
r = ""

while r.upper() != "Y":
    a = float(input("insira um valor para 'a': "))
    b = float(input("insira um valor para 'b': "))

    method = Method(f, epsilon, a, b)
    try:
        method.plotGraph()
        while True:
            r = str(input("Há apenas uma raiz entre a e b (y/n)? "))
            if r.upper() == "Y" or r.upper() == "N":
                break
            else:
                print("{} não reconhecido".format(r))

    except:
        print("Um erro ocorreu")
        exit(1)

opt = -1

while opt == -1:
    print("1 - Método da Bisseção\n2 - Método das Cordas\n3 - Método de Newton\n0 - Sair")
    opt = int(input("Selecione a opção desejada: "))
    print()
    if opt == 1:
        bisec = Bissecao(f, epsilon, a, b)
        bisec.solve()
        opt = -1
    elif opt == 2:
        cord = Cordas(f, epsilon, a, b)
        cord.solve()
        opt = -1
    elif opt == 3:
        newton = Newton(f, epsilon, a, b)
        newton.solve()
        opt = -1
    elif opt == 0:
        exit(1)
    else:
        print("Selecione uma opção válida")
        opt = -1
