#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
} Node;

typedef struct {
    int weigth;
    Node *origin;
    Node *destiny;
} Edge;

struct list_edges{
    Edge *edge;
    struct list_edges *previous;
    struct list_edges *next;
};
typedef struct list_edges Edges;

struct control_edges{
    Edges * head;
    Edges * tail;
};
typedef struct control_edges Control;

void insertion(Node * origin, Node * destiny, int weigth, Control * control){
    Edge * newEdge = malloc(sizeof(Edge));
    newEdge->origin = origin;
    newEdge->destiny = destiny;
    newEdge->weigth = weigth; 

    Edges * addEdge = malloc(sizeof(Edges));
    addEdge->edge = newEdge;
    addEdge->next = NULL;
    addEdge->previous = NULL;

    if(control->head == NULL && control->tail == NULL){
        addEdge->next = NULL;
        addEdge->previous = NULL;
        control->head = addEdge;
        control->tail = addEdge;
    }
    else{
        Edges * aux = control->tail;
        
        // Caso: Inserir no final da fila
        if(newEdge->weigth >= aux->edge->weigth){
            aux->next = addEdge;
            addEdge->previous = aux;
            addEdge->next = NULL;
            control->tail = addEdge;
        }
        else{
            do{
                //Caso: Inserir no início da fila 
                if(aux == control->head && newEdge->weigth < aux->edge->weigth){
                    addEdge->previous = NULL;
                    addEdge->next = aux;
                    aux->previous = addEdge;
                    control->head = addEdge;
                    break;
                }
                if(aux->previous == NULL){
                    break;
                }
                aux = aux->previous;
                if(newEdge->weigth >= aux->edge->weigth){
                    addEdge->next = aux->next;
                    addEdge->previous = aux;
                    addEdge->next->previous = addEdge;
                    aux->next = addEdge;
                    break;
                }
            }while (aux);
        }
    }
    return;
}

void createList(int ** matAdj, int n, Control * control){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(matAdj[i][j] > 0){
                Node * origin = malloc(sizeof(Node));
                Node * destiny = malloc(sizeof(Node));
                origin->value = i;
                destiny->value = j;
                insertion(origin, destiny, matAdj[i][j], control);
            }
        }
    }
}

void printList(Control * control, int visiting){
    Edges * aux = control->head;
    int count = 0;
    printf("\n\n========================================= Etapa %d =========================================\n", visiting+1);

    printf("\n|\tpe\t|\tvi\t|\tvj\t|\n");
    printf("|---------------+---------------+---------------|\n");
    do {
        printf("|\t%d\t|\t%d\t|\t%d\t|", aux->edge->weigth, aux->edge->origin->value, aux->edge->destiny->value);
        if(count == visiting){
            printf(" ← visiting");
        }
        printf("\n");
        if(aux->next != NULL){
            aux = aux->next;
        }
        else{
            break;
        }
        count++;
    }while (aux);
    printf("\n");
}

void printVControl(int * vControl, int n, int vi, int vj){
    char pointers[100] = "";
    char hr[100] = "";
    char head[100] = "";
    char line[100] = "";
    strcat(head, "Ver\t|");
    strcat(line, "P\t|");
    strcat(hr, "--------");
    strcat(pointers, " \t");

    for(int i = 0; i < n; i++){
        if(i == vi || i == vj){
            strcat(pointers, " ↓\t");
        }
        else{
            strcat(pointers, "\t");
        }

        char ver[5] = "";
        sprintf(ver, "%d", i);
        strcat(head, ver);
        strcat(head, "\t|");

        char p[5] = "";
        sprintf(p, "%d", vControl[i]);
        strcat(line, p);
        strcat(line, "\t|");

        strcat(hr, "+-------");
    }
    strcat(hr, "|");
    printf("%s\n", pointers);
    printf("%s\n", head);
    printf("%s\n", hr);
    printf("%s\n", line);    
}

int findRoot(int * vControl, int pos){
    int node = vControl[pos];
    int root = pos;
    while(node >= 0){
        root = node;
        node = vControl[node];
    }
    return root;
}

void kruskal(Control * control, int n, int *vControl){
    Edges * aux = control->head;
    char path[100] = "\nArestas da árvore geradora mínima:\n\t";
    int visiting = 0;
    while (aux) {
        int vi = aux->edge->origin->value;
        int vj = aux->edge->destiny->value;

        int rooti = findRoot(vControl, vi);
        int rootj = findRoot(vControl, vj);

        if(rooti == rootj){

        }
        else if(vControl[rootj] == vControl[rooti] || vControl[rootj] < vControl[rooti]){
            vControl[rootj]+= vControl[rooti];
            vControl[rooti] = rootj;

            char temp[5] = "";
            strcat(path, "(");

            sprintf(temp, "%d", vi);
            strcat(path, temp);
            strcat(path, ",");

            sprintf(temp, "%d", vj);
            strcat(path, temp);
            strcat(path, ") ");
        }
        else if(vControl[rootj] > vControl[rooti]){
            vControl[rooti] += vControl[rootj];
            vControl[rootj] = rooti;

            char temp[5] = "";
            strcat(path, "(");

            sprintf(temp, "%d", vi);
            strcat(path, temp);
            strcat(path, ",");

            sprintf(temp, "%d", vj);
            strcat(path, temp);
            strcat(path, ") ");
        }
        printList(control, visiting);
        printVControl(vControl, n, vi, vj);
        printf("%s\n", path);

        if(vControl[rootj] == n*(-1) || vControl[rooti] == n*(-1)){
            printf("\n\t→ Já encontramos a Árvore de Spanning Mínima :D\n");
            return;
        }

        if(aux->next != NULL){
            aux = aux->next;
        }
        else{
            return;
        }
        visiting++;
    }
}

int main(){
    int ** matAdj;
    int n;
    int * vControl;

    printf("Insira o número de vértices: ");
    scanf("%d", &n);

    //Criando a Matriz de adjacencia
    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    //Preenchendo Matriz de adjacencia
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Inira o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    // Alocando vetor de controle
    vControl = malloc(sizeof(int)*n);

    // Printando Matriz de adjacencia
    printf("\n****************************** Matriz ******************************\n");

    for(int i = 0; i < n; i++){
        vControl[i] = -1;   //Aproveitando para preencher vetor de controle
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    Control * control = malloc(sizeof (Control));
    control->head = NULL;
    control->tail = NULL;

    createList(matAdj, n, control);  

    kruskal(control, n, vControl);
}
