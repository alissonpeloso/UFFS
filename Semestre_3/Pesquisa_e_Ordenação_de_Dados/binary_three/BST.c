#include <stdio.h>

struct Node{
    int value;
    struct Node *right;
    struct Node *left;
} typedef node;

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

int main() {
    int a[] = {30,14,51,9,21,43,82,3,27,99};
    node *root = NULL;

    for(int i = 0; i < sizeof(a)/sizeof(int) ; i++){
        node *aux = malloc(sizeof(node));
        aux->value = a[i];
        root = addNode(root, aux);
    }

    printPosOrder(root);
    printf("\n");

    return 0;
}