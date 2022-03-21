from func import *

print('Insira uma lista de valores separada por espaço e direi a média dos valores:')
a = list(map(float, input().split()))

print('Média:',lmed(a))
