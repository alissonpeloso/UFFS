alg=float(input('Qual a quantidade de algodão que temos dísponivel? (g) '))
camis=alg/95
camis=int(camis)
sobr=((alg/95)-camis)*95
print('Com ',alg,'g de algodão, podemos fazer ',camis,' camisas e sobrarão aproximadamente {:.2f}g de algodão.'.format(sobr))
