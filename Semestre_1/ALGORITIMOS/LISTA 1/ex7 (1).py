sal=float(input('Qual o valor do salário/hora? '))
hor=float(input('Quantas horas trabalhadas? (ex:25,5) '))
salbruto=sal*hor
salliq=salbruto*0.8
adiant=input('Possui algum adiantamento? (y/n) ')
if adiant =='y':
	valad=float(input('Qual o valor do adiantamento? ')) 
	print('O salário será R${:.2f} '.format(salliq-valad))
elif adiant =='n':
	print('O salário será R$%5.2f'%(salliq))
