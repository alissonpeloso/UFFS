#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main()
{
	tree_node *root=NULL;

	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 4);
  root = insert(root, 6);

	printf("Lookup: %d\n", lookup(root, 8));

  printf("Size: %d\n", size(root));

  printf("maxDepth: %d\n", maxDepth(root));

  printf("minValue: %d\n", minValue(root));

  printf("InOrdem\n");
	printTreeInOrder(root);

  printf("\nPosOrdem\n");
	printPostorder(root);

  printf("\nPreOrdem\n");
	printPreorder(root);

  return 0;
}
