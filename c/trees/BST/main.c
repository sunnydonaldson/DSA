#include <stdio.h>
#include "./BST.h"

int main() {
  BSTNode *root = CreateNode(12, NULL, NULL);
  printf("root->val: %d\n", root->val);
  DeleteNode(&root);
  printf("root is null pointer? %d\n", root == NULL);
  return 0;
}