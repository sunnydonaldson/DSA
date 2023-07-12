#include <stdio.h>
#include "./avl_tree.h"

void LlExample() {
  BSTNode *root = CreateNode(2, NULL, NULL);
  PreorderBST(root, &DisplayBSTNode);
  printf("cheese\n");
  AvlInsert(root, CreateNode(1, NULL, NULL));
  printf("bacon\n");
  AvlInsert(root, CreateNode(0, NULL, NULL));
  printf("sausages\n");
  PreorderBST(root, &DisplayBSTNode);
}
int main() {
  LlExample();
  return 0;
}