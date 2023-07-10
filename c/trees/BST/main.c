#include <stdio.h>
#include "./BST.h"


int main() {
  BSTNode *root = CreateNode(12, NULL, NULL);
  printf("root->val: %d\n", root->val);
  InsertNode(root, CreateNode(4, NULL, NULL), NULL);
  InsertNode(root, CreateNode(19, NULL, NULL), NULL);
  InsertNode(root, CreateNode(22, NULL, NULL), NULL);
  InsertNode(root, CreateNode(2, NULL, NULL), NULL);

  printf("inorder traversal: ");
  InorderBST(root, &DisplayBSTNode);

  printf("\npreorder traversal: ");
  PreorderBST(root, &DisplayBSTNode);

  printf("\npostorder traversal: ");
  PostorderBST(root, &DisplayBSTNode);

  printf("\nHeight of tree, from: %zu", Height(root));

  printf("\nInorder predecessor of root: %d", InorderPredecessor(root)->val);
  printf("\nInorder successor of root: %d", InorderSuccessor(root)->val);
  printf("\n");

  DeleteTree(&root);
  printf("display after delete:\n");
  InorderBST(root, &DisplayBSTNode);
  return 0;
}