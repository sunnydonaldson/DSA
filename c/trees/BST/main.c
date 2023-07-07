#include <stdio.h>
#include "./BST.h"

void display(BSTNode *root) {
  printf("%d, ", root->val);
}

int main() {
  BSTNode *root = CreateNode(12, NULL, NULL);
  printf("root->val: %d\n", root->val);
  InsertNode(root, CreateNode(4, NULL, NULL));
  InsertNode(root, CreateNode(19, NULL, NULL));

  printf("inorder traversal: ");
  InorderBST(root, &DisplayBSTNode);

  printf("\npreorder traversal: ");
  PreorderBST(root, &DisplayBSTNode);

  printf("\npostorder traversal: ");
  PostorderBST(root, &DisplayBSTNode);

  DeleteNode(&root);
  printf("root is null pointer? %d\n", root == NULL);
  return 0;
}