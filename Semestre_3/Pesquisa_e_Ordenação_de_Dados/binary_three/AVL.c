#include <stdio.h>
#include <stdlib.h>
#define EXIT 10

struct Node{
    int value;
    struct Node *right;
    struct Node *left;
} typedef node;

node *addNode(node *root, node *new);

node *removeNode(node *root, int value);

int menu()
{
    int op = 0;
    char opInStr[50];

    printf("----------------------------------------------------------------------------\n");
    printf("1 - Criar novo nodo   | 2 - Deletar um nodo   | 3 - Buscar um nodo \n4 - Print árvore 2D   | 5 - Print em PreOrder | 6 - Print InOrder\n7 - Print em PosOrder | 10 - Encerrar         |\n");
    printf("----------------------------------------------------------------------------\n");

    printf("\nOpção desejada: ");
    scanf("%s", opInStr);

    op = atoi(opInStr);
    return op;
}

node *insertNode(node *root){
    node *newNode = malloc(sizeof(node));
    printf("Insira o valor que deseja adicionar: ");
    scanf("%d", &newNode->value);
    root = addNode(root,newNode);
    printf("**Adicionado com sucesso**\n");
    return root;
}

node *delNode(node *root){
    int removeValue;
    printf("Insira o valor que deseja remover: ");
    scanf("%d", &removeValue);
    root = removeNode(root, removeValue);
    printf("**%d Removido com sucesso**\n", removeValue);
    return root;
}

node *searchNode(node *root, int v){
    if(root == NULL){
        return NULL;
    }
    if(root->value == v){
        return root;
    }
    if(root->value >= v){
        searchNode(root->left, v);
    }
    else{
        searchNode(root->right,v);
    }
}

void queryNode(root){
    int value;
    printf("Insira o valor que deseja buscar: ");
    scanf("%d", &value);
    node *temp = searchNode(root, value);
    printf("**Nodo encontrado:**\n\nValor: %d\n", temp->value);
    return;
}

void printPreOrder(node *root){
    if (root == NULL){
        return;
    }
    else{
        printf("%d, ", root->value);

        if(root->left != NULL){
            printPreOrder(root->left);
        }
        if(root->right != NULL){
            printPreOrder(root->right);
        }
    }
}

void printInOrder(node *root){
    if (root == NULL){
        return;
    }
    else{
        if(root->left != NULL){
            printInOrder(root->left);
        }
        printf("%d, ", root->value);
        if(root->right != NULL){
            printInOrder(root->right);
        }
    }
}

void printPosOrder(node *root){
    if (root == NULL){
        return;
    }
    else{
        if(root->left != NULL){
            printPosOrder(root->left);
        }
        if(root->right != NULL){
            printPosOrder(root->right);
        }
        printf("%d, ", root->value);
    }
}

int biggestInt(int a, int b){
    return (a > b) ? a : b; 
}

int heightThree(node *root){
    int right=0, left=0;
    if (root == NULL){
        return 0;
    }
    else{
        if (root->left == NULL && root->right == NULL){
            return 1;
        }
        else{
            if (root->right != NULL){
                right = (1 + heightThree(root->right));
            }
            if (root->left != NULL){
                left = (1 + heightThree(root->left));
            }
            return biggestInt(right, left);
        }
    }
}

node *RR(node *root){
    node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

node *LL(node *root){
    node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

node *LR(node *root){
    root->left = RR(root->left);
    node *newRoot = LL(root);
    return newRoot;
}

node *RL(node *root){
    root->right = LL(root->right);
    node *newRoot = RR(root);
    return newRoot;
}

int fBalance(node *root){
    int heightLeft = heightThree(root->left), heightRight = heightThree(root->right);
    return (heightLeft-heightRight);
}

node *balanceTree(node *root){
    int diff = fBalance(root);
    if(diff > 1){
        if(fBalance(root->left) < 0){
            root = LR(root);
        } else{
            root = LL(root);
        }
    }else if(diff < -1){
        if(fBalance(root->right) < 0){
            root = RR(root);
        } else{
            root = RL(root);
        }
    }
    return root;
}

node *addNode(node *root, node *new){
    new->left = NULL;
    new->right = NULL;
    if (root == NULL){
        return new;
    } 
    else{
        if(root->value >= new->value){
            root->left = addNode(root->left, new);
        }
        else{
            root->right = addNode(root->right, new);
        }
    }
    root = balanceTree(root);
    return root;
}

void print2DUtil(node *root, int space){ 
    if (root == NULL) 
        return; 
  
    space += 10; 
  
    print2DUtil(root->right, space); 
  
    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->value); 
   
    print2DUtil(root->left, space); 
}

node *biggestNode(node *root){
    node *father = root;

    if (root == NULL){
        printf("Não pode entrar aqui, se entra tem erro de lógica.\n\n");
    }

    root = root->right;
    while(root->right != NULL){
        father = root;
        root = root->right;
    }
    //aqui o root ja é o maior, não tem filhos a direita.
    father->right = root->left; //tirei o root da árvore
    return root;
}

node *removeNode(node *root, int value){
    if (root == NULL){
        return NULL;
    } 
    else{
        if(root->value == value){
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                node *aux = root->left;
                free(root);
                return aux;
            }
            else if(root->left == NULL && root->right != NULL){
                node *aux = root->right;
                free(root);
                return aux;
            }
            else{
                node *newRoot;
                if(root->left->right == NULL){
                    newRoot = root->left;
                    newRoot->right = root->right;
                }
                else{
                    newRoot = biggestNode(root->left);
                    newRoot->left = root->left;
                    newRoot->right = root->right;
                }
                free(root);
                return newRoot;
            }
        }
        else if(root->value > value){
            root->left = removeNode(root->left, value);
        }
        else{
            root->right = removeNode(root->right, value);
        }
    }
    root = balanceTree(root);
    return root;
}

void cleanAVL(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->left != NULL)
        {
            cleanAVL(root->left);
        }
        if (root->right != NULL)
        {
            cleanAVL(root->right);
        }
        free(root);
    }
}

int main(void) {
    int op = 0;
    node *root = NULL;
    printf("\n###########################################################################\n");
    printf("#                    [ AVL Tree - by Alisson Peloso ]                     #\n");
    printf("###########################################################################\n");

    while (op != EXIT)
    {
        op = menu();
        switch (op)
        {
        case 1:
            root = insertNode(root);
            break;
        case 2:
            root = delNode(root);  
            break;
        case 3:
            queryNode(root);
            break;
        case 4:
            printf("\n***Lista em formato de árvore 2D***\n\n");
            print2DUtil(root, 0);
            if(root == NULL){
                printf("- Nenhum nodo encontrado\n\n");
            }
            break;
        case 5:
            printf("\n***Lista em PreOrder***\n\n");
            printPreOrder(root);
            if(root == NULL){
                printf("- Nenhum nodo encontrado");
            }
            printf("\n\n");
            break;
        case 6:
            printf("\n***Lista InOrder***\n\n");
            printInOrder(root);
            if(root == NULL){
                printf("- Nenhum nodo encontrado");
            }
            printf("\n\n");
            break;
        case 7:
            printf("\n***Lista em PosOrder***\n\n");
            printPosOrder(root);
            if(root == NULL){
                printf("- Nenhum nodo encontrado");
            }
            printf("\n\n");
            break;
        case 10:
            cleanAVL(root);
            system("exit");
            break;
        default:
            printf("\nOpção não existente\n");
        }
    }
    return 0;
}
