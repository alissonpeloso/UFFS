from func import *

n1 = int(input('Digite o primeiro número: '))
n2 = int(input('Digite o segundo número: '))
if prime(n1) and prime(n2):
    if gem(n1,n2):
        print(n1,'e',n2,'são primos gêmeos')
    else:
        print(n1,'e',n2,'não são primos gêmeos')
else:
    print(n1,'e',n2,'não são primos gêmeos')
