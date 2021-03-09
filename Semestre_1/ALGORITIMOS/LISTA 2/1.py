a = int(input('Escreva o número: '))
if a % 11 == 0 and a % 5 == 0:
    print('O número é divisível por 5 e por 11')
elif a % 11 == 0:
    print('O número é divisível por 11')
elif a % 5 == 0:
    print('O número é divisível por 5')
elif a == 0:
    print('Impossível dividir')
else:
    print('O número não é divisível por 5, nem por 11')
