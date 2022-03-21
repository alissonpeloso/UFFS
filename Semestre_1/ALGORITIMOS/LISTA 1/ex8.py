n1=float(input('Qual foi a nota da primeira prova? '))
n2=float(input('Qual a nota da segunda? '))
n3=float(input('Qual a nota da terceira avaliação? '))
med=(n1*3+n2*2+n3*5)/10
print('A sua média na disciplina Tópicos em Blim Blom é {:.1f}'.format(med))
if med>=6:
	print('Boaa c#%&$, você passou! ')
else:
	print('Poxa, tem que estudar mais... ')
