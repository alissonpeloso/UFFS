quntpal=int(input('Quantas palavras você deseja imprimir? '))
vel=float(input('Qual a velocidade da impressora? (words/s)'))
wsec=quntpal/vel
wmin=wsec/60
wmin=int(wmin)
sobsec=(wsec/60-wmin)*60
sobsec=int(sobsec)
print('Serão necessários ', wmin,' minutos e', sobsec ,' segundos para a impressão do texto ')
