#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

struct Node{
    int value;
    struct Node *right;
    struct Node *left;
} typedef node;

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

int main(void) {
    node *root = NULL;
    int a[] = {5,9,7};
    
    for(int i = 0; i < sizeof(a)/sizeof(int); i++){
        node *aux = malloc(sizeof(node));
        aux->value = a[i];
        root = addNode(root, aux);
        printf("%d, ", aux->value);
    }
    printf("\n");
    print2DUtil(root, 0);
    printf("-----------------------------------------------------------------------------------\n");
    root = removeNode(root, 7);
    print2DUtil(root, 0);
    node *aux2 = malloc(sizeof(node));
    aux2->value = 10;
    root = addNode(root,aux2);
    printf("\n");

    return 0;
}
