val=float(input('Qual o valor em Reais (R$)? '))
coteur=float(input('Qual a cotação do Euro? '))
cotdol=float(input('Qual a cotação do Dólar? '))
eur=val/coteur
dol=val/cotdol
resp=input('Você quer o valor em Dólar ou Euro? (d/e) ')
if resp=='d':
	print(' valor em dolar é US$ {:.2f}'.format(dol))
elif resp=='e':
	print('O valor em euro é € {:.2f}'.format(eur))

