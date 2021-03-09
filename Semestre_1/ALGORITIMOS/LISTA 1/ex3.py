maq1=1
maq2=3
maq3=2.5
day=int(input('Quantos dias as máquinas funcionaram? '))
qlq=input('Quais máquinas funcionaram? (ex:1,2,3) ')
if qlq == '1,2,3':
	print('Foram feitos {} postes'.format((maq1+maq2+maq3)*day))
elif qlq == '1,2':
	print('Foram feitos {} postes'.format((maq1+maq2)*day))
elif qlq == '1':
	print('Foram feitos {} postes'.format(maq1*day))
elif qlq == '1,3':
	print('Foram feitos {} postes'.format((maq1+maq3)*day))
elif qlq == '2':
	print('Foram feitos {} postes'.format(maq2*day))
elif qlq == '2,3':
	print('Foram feitos {} postes'.format((maq2+maq3)*day))
elif qlq == '3':
	print('Foram feitos {} postes'.format(maq3*day))
else:
	raise ValueError('Insira os valores em ordem crescente! ')
