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

void DisplayBSTNode(BSTNode *root) {
  assert(root != NULL);
  printf("%d, ", root->val);
}

void InorderBST(BSTNode *root, void (*process)(BSTNode *)) {
  if (root == NULL) {
    return;
  }

  InorderBST(root->left, process);
  (*process)(root);
  InorderBST(root->right, process);
}

void PreorderBST(BSTNode *root, void (*process)(BSTNode *)) {
  if (root == NULL) {
    return;
  }

  (*process)(root);
  PreorderBST(root->left, process);
  PreorderBST(root->right, process);
}

void PostorderBST(BSTNode *root, void (*process)(BSTNode *)) {
  if (root == NULL) {
    return;
  }

  PostorderBST(root->left, process);
  PostorderBST(root->right, process);
  (*process)(root);
}