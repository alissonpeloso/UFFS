from func import *

a = int(input('Insira um número inteiro e direi se ele é perfeito: '))
if perf(a) == 1:
    print(a,'é um número perfeito!')
else:
    print(a,'não é um número perfeito!')
