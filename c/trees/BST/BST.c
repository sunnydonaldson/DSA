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

void InsertNode(BSTNode *root, BSTNode *node) {
  assert(root != NULL && node != NULL);

  if (node->val < root->val) {
    if (root->left == NULL) {
      root->left = node;
    } else {
      InsertNode(root->left, node);
    }
  } else {
    if (root->right == NULL) {
      root->right = node;
    } else {
      InsertNode(root->right, node);
    }
  }
}
