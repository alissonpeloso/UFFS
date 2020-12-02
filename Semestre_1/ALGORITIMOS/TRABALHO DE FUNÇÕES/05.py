from func import *

a = list(map(int, input('Insira a primeira lista separando os números por espaços: ').split()))
b = list(map(int, input('Insira a segunda lista separando os números por espaços: ').split()))

print(solve(a,b))
