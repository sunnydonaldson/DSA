#include <stdio.h>
#include "./BST.h"

int main() {
  BSTNode *root = CreateNode(12, NULL, NULL);
  printf("root->val: %d\n", root->val);
  InsertNode(root, CreateNode(4, NULL, NULL));
  InsertNode(root, CreateNode(19, NULL, NULL));
  DeleteNode(&root);
  printf("root is null pointer? %d\n", root == NULL);
  return 0;
}