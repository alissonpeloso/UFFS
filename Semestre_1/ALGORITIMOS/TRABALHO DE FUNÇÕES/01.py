from func import *

for i in range(5):
    name=input('Escreva o nome do estudante: ')
    n1 = float(input('Insira a primeira nota: '))
    n2 = float(input('Insira a segunda nota: '))
    print('aluno:',name,'- média:',med(n1,n2))
