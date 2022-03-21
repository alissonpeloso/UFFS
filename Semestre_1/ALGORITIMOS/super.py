# tipo de estrutura para armazenar os dados dos produtos
class tprod:
	cod=0
	nome=''
	preco=0.0

# função que retorna o preço do produto
# recebe como parâmetro um código (c) e uma lista de produtos (lprod)
def retpreco(c, lprod):
	for i in range(len(lprod)):
		if lprod[i].cod==c:
			return lprod[i].preco
	return -1 ## se não encontrar o código na lista retorna 0
#
# função que retorna o nome do produto
# recebe como parâmetro um código (cod) e uma lista de produtos (lprod)
def retnome(cod,lprod):
	for i in range(len(lprod)):
		if lprod[i].cod==cod:
			return lprod[i].nome
	return 'Produto não cadastrado' ## retorno caso o produto não for encontrado

# função que insere uma estrutura do tipo produto (p) na lista
# perceba que lista é um ponteiro, assim alterando ela altera
# automaticamente a lista que será passada na chamada da função
def cadproduto(p,lista):
		lista.append(p)
#
#
# função para inserção dos produtos via input
def insereproduto(lista):
	while True:
		p=tprod()
		p.cod=int(input('Código: '))
		if p.cod==0:
			break
		if retpreco(p.cod,lista)!=-1: ## verifica se o código já foi cadastro
			print('Código já cadastrado!') ## se preço == 0 o produto não existe
			continue ## caso sim, volta para o início do laço
		p.nome=input('Nome: ')
		p.preco=float(input('Preço: '))
		cadproduto(p,lista) ## chama a função de cadastro
#
def loadProducts(lista):
	f =open('Produtos.txt','a+')
	f.seek(0)
	llin=f.readlines()
	for l in llin:
		prod=l.split(',')
		p=tprod()
		p.cod=int(prod[0])
		p.nome=prod[1]
		p.preco=float(prod[2][:-1])
		lista.append(p)
	f.close()
#
def storeProducts(lista):
	f=open('Produtos.txt','w')
	for i in range(len(lista)):
		f.write(str(lista[i].cod)+','+lista[i].nome+','+str(lista[i].preco)+'\n')
	f.close()
### os produtos estão sendo inseridos manualmente na lista
### para utilizar a função que pede os produtos via teclado:
### início do programa principal ###
produtos=[]
loadProducts(produtos)
insereproduto(produtos)
storeProducts(produtos)
c='S'
while c=='S':
	print('*** Caixa pronto para próxima compra ***')
	total=0
	cod=int(input('Código: '))
	while cod!=0:
		psr = 0
		qt=int(input('Quantidade: '))
		print(retnome(cod,produtos),' ',end='')
		pr=retpreco(cod,produtos)
		if pr == -1:
			print('Produto Não Cadastrado!')
		else:
			psr+=pr*qt
			total+=pr*qt
			print('R$ {:.2f} | Valor Parcial: R$ {:.2f} '.format(psr,total))
		cod=int(input('Código: '))
	print('Valor final: %.2f'%total)
	c=input('Continua (S/N): ').upper()
print('Obrigado por utilizar o nosso programa!')
