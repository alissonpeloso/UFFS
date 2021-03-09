typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}tree_node;

int lookup(tree_node* node, int target) {
  // 1. Caso base == empty tree
  // nesse caso, o target não é encontrado e retorna falso
  if (node == NULL) {
    return 0;
  }
  else {
    // 2. Caso encontrado retorna true
    if (target == node->data) {
      return 1;
    }
    else {
      // 3. Caso contrário, verifica (recursivamente) a subárvore correta
      if (target < node->data) {
        return(lookup(node->left, target));
      }
      else {
        return(lookup(node->right, target));
      }
    }
  }
}

tree_node *NewNode(int data) {
  tree_node *node = (tree_node *)malloc(sizeof(tree_node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

tree_node* insert(tree_node* node, int data) {
	  // 1. Se a árvore estiver vazia, retorne um novo nó único
  if (node == NULL) {
    return NewNode(data);
  }
  else {
    // 2. Caso contrário, recorra a árvore
    if (data <= node->data) {
      node->left = insert(node->left, data);
    }
    else {
      node->right = insert(node->right, data);
    }
    return node;
  }
}

int size(tree_node* node) {
  if (node==NULL) {
    return 0;
  } else {
    return size(node->left) + 1 + size(node->right);
  }
}

int maxDepth(tree_node* node) {
  if (node==NULL) {
    return 0;
  }
  else {
    // calcular a profundidade de cada subárvore
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    // usa a maiorz
    if (lDepth > rDepth) {
      return lDepth+1;
    }
    else {
      return rDepth+1;
    }
  }
}

int minValue(tree_node* node) {
  tree_node* current = node;
  // loop para encontrar a folha mais a esquerda
  while (current->left != NULL) {
    current = current->left;
  }
  return current->data;
}

int maxValue(tree_node* node) {
  tree_node* current = node;
  // loop para encontrar a folha mais a esquerda
  while (current->right != NULL) {
    current = current->right;
  }
  return current->data;
}

void printTreeInOrder(tree_node* node) {
  //implementar
  // Dada uma árvore de pesquisa binária, imprima seus elementos
  // de dados em ordem correta.

  // 1. Caso base == empty tree
  if (node == NULL){
    return ;
  }

  // 2. imprime (recursivamente) o lado esquerdo
  printTreeInOrder(node->left);

  // 3. imprime o nodo atual
  printf("%d ", node->data);

  // 4. imprime (recursivamente) o lado direito
  printTreeInOrder(node->right);
}

void printPostorder(tree_node* node) {
  //implementar
  // Dada uma árvore binária, imprima seus nós de acordo com o
  // percurso de pós-ordem "de baixo para cima".

  // 1. Caso base == empty tree
  if (node == NULL)
  {
    return;
  }

  // 2. imprime (recursivamente) o lado esquerdo
  printTreeInOrder(node->left);

  // 3. imprime (recursivamente) o lado direito
  printTreeInOrder(node->right);

  // 4. imprime o nodo atual
  printf("%d ", node->data);
}

void printPreorder(tree_node* node) {
  //implementar
  // Dada uma árvore binária, imprima seus nós de acordo com o
  // percurso de pré-ordem "de cima para baixo ".

  // 1. Caso base == empty tree
  if (node == NULL)
  {
    return;
  }

  // 1. imprime o nodo atual
  printf("%d ", node->data);

  // 3. imprime (recursivamente) o lado esquerdo
  printTreeInOrder(node->left);

  // 4. imprime (recursivamente) o lado direito
  printTreeInOrder(node->right);
}

int isBST(tree_node* node) {
  if (node==NULL) {
    return 1;
  }
  // falso se o min da esquerda é maior que o valor atual
  if (node->left!=NULL && minValue(node->left) > node->data){
    return 0;
  }
  // falso se o max da direita é menor ou igual que o valor atual
  if (node->right!=NULL && maxValue(node->right) <= node->data){
    return 0;
  }
  // false se os galhos abaixo (verificados recursivamente) não são uma BST
  if (!isBST(node->left) || !isBST(node->right)){
    return 0;
  }
  // se chegou até aqui, é uma BST
  return 1;
}
