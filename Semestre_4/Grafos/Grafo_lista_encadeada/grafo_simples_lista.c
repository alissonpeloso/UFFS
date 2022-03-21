#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct {
	int val;
} Vertice;

typedef struct {
	Vertice *origem;
	Vertice *destino;
} Aresta;

struct tp_list_vet {
	Vertice *v;
	struct tp_list_vet *ant;
	struct tp_list_vet *prox;
};
typedef struct tp_list_vet Vertices;

struct tp_list_edges {
	Aresta *e;
	struct tp_list_edges *prox;
	struct tp_list_edges *ant;
};
typedef struct tp_list_edges Arestas;

typedef struct {
	Vertices *primeiroV;
	Vertices *ultimoV;

	Arestas *primeiroA;
	Arestas *ultimoA;

	bool eh_orientado;
} Grafo;

Grafo *inicializaGrafo(){
	Grafo *G = malloc(sizeof(Grafo));
	G->primeiroV = NULL;
	G->ultimoV = NULL;
	G->primeiroA = NULL;
	G->ultimoA = NULL;

	return G;
}

Vertice * getVertice(Grafo *g, int val){
	Vertices *aux = g->primeiroV;

	while (aux != NULL) {
		if(aux->v->val == val){
			return aux->v;
		}
		aux = aux->prox;
	}
		printf("ERRO: Vertice não encontrado!\n");
	return NULL;
}

void liberaMemoria(Grafo *G){
	Vertices *auxV = G->primeiroV;
	Arestas *auxA = G->primeiroA;
	
	while(auxV != NULL){
		auxV = G->primeiroV->prox;
		free(G->primeiroV);
		G->primeiroV = auxV;
	}

	while(auxA != NULL){
		auxA=G->primeiroA->prox;
		free(G->primeiroA);
		G->primeiroA = auxA;
	}


	free(G);

	printf("\nMemoria liberada\n");
}

void imprimeVertices(Grafo *g){
	Vertices *aux = g->primeiroV;

	printf("****** Lista de Vértices ********\n\t{");
	while(aux != NULL){
		printf("%d", aux->v->val);
		if (aux != g->ultimoV){
			printf(", ");
		}
		aux=aux->prox;
	}
	printf("}\n");
}

void imprimeAresta(Grafo *g){
	Arestas *aux = g->primeiroA;

	printf("****** Lista de Arestas ********\n\t{");
	while(aux != NULL){
		printf("(%d,%d)", aux->e->origem->val, aux->e->destino->val);
		if (aux != g->ultimoA){
			printf(", ");
		}
		aux = aux->prox;
	}
	printf("}\n");
}

void insereVertice(Grafo *G, int val){
	Vertice *newV;
	Vertices *auxV;

	newV = malloc(sizeof(Vertice)); //nosso vértice
	newV->val = val;

	auxV = malloc(sizeof(Vertices));
	auxV->ant = NULL;
	auxV->prox = NULL;
	auxV->v = newV;

	if (G->primeiroV == NULL){ //lista Vazia
		G->primeiroV = auxV;
		G->ultimoV = auxV; 
	} else { //faz o encadeamento
		G->ultimoV->prox = auxV; //O proximo do ultimo ser o novo elemento
		auxV->ant = G->ultimoV; //anterior do novo elemento ser o ultimo
		G->ultimoV = auxV;  //o novo elemento vira o ultimo
	}
}

void insereAresta(Grafo *G, int origem, int destino){
	Aresta *newA;
	Arestas *auxA;
	newA = malloc(sizeof(Aresta)); //nosso vértice
	newA->destino = getVertice(G,destino);
	newA->origem = getVertice(G,origem);

	if(newA->origem == NULL || newA->destino == NULL){
		printf("ERRO: Não foi possível gerar a aresta a partir dos valores (origem/destino) informados!\n");
		exit(0);
	}

	auxA = malloc(sizeof(Arestas));
	auxA->ant = NULL;
	auxA->prox = NULL;
	auxA->e = newA;

	if (G->primeiroA == NULL){ //lista Vazia
		G->primeiroA = auxA;
		G->ultimoA = auxA; 
	} else { //faz o encadeamento
		//printf("Não é o primeiro\n");
		G->ultimoA->prox = auxA; //O proximo do ultimo ser o novo elemento
		auxA->ant = G->ultimoA; //anterior do novo elemento ser o ultimo
		G->ultimoA = auxA;  //o novo elemento vira o ultimo
		//printf("Feito\n");
	}
}

//val é o nome do nodo
int grauVertice(Grafo *g, int val){ 
	Arestas *aux = g->primeiroA;
	int grau = 0;

	while(aux != NULL){
		if(aux->e->destino->val == val){
			grau++;
		}
		if(aux->e->origem->val == val){
			grau++;
		}
		aux = aux->prox;
	}
	
	return grau;
}

int grauEntradaVertice(Grafo *g, int val){ //todas as vezes que ele é destino
	if(!g->eh_orientado){
		printf("Grafo não orientado não possuí grau de entrada!");
		return -1;
	}
	Arestas *aux = g->primeiroA;
	int grau = 0;

	while(aux != NULL){
		if(aux->e->destino->val == val){
			grau++;
		}
		aux = aux->prox;
	}
	
	return grau;
}

int grauSaidaVertice(Grafo *g, int val){ //todas as vezes que ele é origem
	if(!g->eh_orientado){
		return -1;
	}
	Arestas *aux = g->primeiroA;
	int grau = 0;

	while(aux != NULL){
		if(aux->e->origem->val == val){
			grau++;
		}
		aux = aux->prox;
	}
	
	return grau;
}

bool verificaFonte(Grafo *G, int val){
	if(grauEntradaVertice(G, val) == 0 && grauSaidaVertice(G, val) > 0){
		return true;
	}
	return false;
}

bool verificaSumidouro(Grafo *G, int val){
	if(grauEntradaVertice(G, val) > 0 && grauSaidaVertice(G, val) == 0){
		return true;
	}
	return false;
}

int menu(){
	int op;
	printf("\n------------------------------------\nWhat do you desire?\n------------------------------------\n1 - Inserir vértices;\n2 - Inserir arestas;\n3 - Imprimir vértices;\n4 - Imprimir arestas;\n5 - Grau de um vértice;\n0 - Sair;\n\n");
	scanf("%d", &op);

	return op;
}

int main(){
	Grafo *G; //armazena o conjunto de vertices e arestas
	
	Vertices *auxV;
	Vertice *newV = NULL;

	Arestas *auxA;
	Aresta *newA = NULL;
	//inserção
	int i,n, val, origem, destino, isOriented, op = 1, gVer;

	//incializa o grafo
	G = inicializaGrafo();

	//verifica se o grafo é orientado
	printf("O grafo é orientado? (1 = yes/0 = no): ");
	scanf("%d", &isOriented);
	if(isOriented == 1){
		G->eh_orientado=true;
	}
	else{
		G->eh_orientado=false;
	}

	while (op != 0) {
		op = menu();
		switch (op) {
			case 1:
				printf("Digite o número de vértices: ");
				scanf("%d", &n); //numero de vertices.

				for(i=0;i<n;i++){
					scanf("%d", &val);
					insereVertice(G,val);
				}
			break;
			case 2:
				printf("\nDigite o número de Arestas: ");
				scanf("%d", &n); //numero de arestas.

				printf("\nDigite as arestas no formato Origem,Destino:\n");
				for(i=0;i<n;i++){
					scanf("%d,%d", &origem, &destino);
					insereAresta(G, origem,destino);
				}
			break;
			case 3:
				imprimeVertices(G);
			break;
			case 4:
				imprimeAresta(G);
			break;
			case 5:
				printf("Digite a vértice que deseja saber o grau: ");
				scanf("%d", &gVer);
				printf("O grau é: %d\n", grauVertice(G,gVer));
				if(isOriented){
					printf("O grau de saída do vértice %d é: %d\n", gVer, grauSaidaVertice(G, gVer));
					printf("O grau de entrada do vértice %d é: %d\n", gVer, grauEntradaVertice(G, gVer));

					if(verificaFonte(G, gVer)){
						printf("O vértice %d é fonte!\n", gVer);
					}
					if(verificaSumidouro(G, gVer)){
						printf("O vértice %d é sumidouro!\n", gVer);
					}
				}
			break;
			case 0:
				break;
			break;
			default:
				printf("Valor de seleção inválido\n");
			break;
		}
	}

	liberaMemoria(G);

	return 0;
}