atv=input('Qual atividade física você irá fazer? ')
calat=float(input('Quantas calorias você gasta por hora ao '+atv+'? '))
qntcal=float(input('Quantas caloria você quer perder? '))
hour=int(qntcal/calat)
mint=((qntcal/calat)-hour)*60
minto=int(mint)
print('Você vai precisar',atv,'durante',hour,'horas e',minto,'minutos para perder',calat,'calorias :D ')
