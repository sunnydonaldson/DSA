#include "BST.h"

BSTNode *CreateNode(int val, BSTNode *left, BSTNode *right) {
  BSTNode *node = malloc(sizeof(BSTNode));
  node->val = val;
  node->left = left;
  node->right = right;
  return node;
}

void DeleteNode(BSTNode **node) {
  if (*node == NULL) {
    return;
  }

  DeleteNode(&(*node)->left);
  DeleteNode(&(*node)->right);
  free(*node);
  *node = NULL;

}
