#include "BST.h"

static size_t Max(size_t a, size_t b);
static void DeleteLeaf(BSTNode *leaf);

BSTNode *CreateNode(int val, BSTNode *left, BSTNode *right) {
  BSTNode *node = malloc(sizeof(BSTNode));
  node->val = val;
  node->left = left;
  node->right = right;
  return node;
}

void DeleteTree(BSTNode **node) {
  PostorderBST(*node, &DeleteLeaf);
  *node = NULL;
}

BSTNode *DeleteNode(BSTNode *node, int key) {
  if (!node || (!node->left && !node->right)) {
    printf("node is null, or has no children.\n");
    free(node);
    return NULL;
  }

  if (key < node->val) {
    node->left = DeleteNode(node->left, key);
  } else if (key > node->val) {
    node->right = DeleteNode(node->right, key);
  } else {
    BSTNode *replace;
    if (Height(node->left) > Height(node->right)) {
      replace = InorderPredecessor(node);
      node->val = replace->val;
      node->left = DeleteNode(replace, node->val);
    } else {
      replace = InorderSuccessor(node);
      node->val = replace->val;
      node->right = DeleteNode(replace, node->val);
    }
    printf("replace not null? %d\n", replace != NULL);

  }
  return node;
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

void PostorderBST(BSTNode *root, void *(*process)(BSTNode *)) {
  if (root == NULL) {
    return;
  }

  PostorderBST(root->left, process);
  PostorderBST(root->right, process);
  (*process)(root);
}

size_t Height(BSTNode *root) {
  if (!root) {
    return 0;
  }

  return 1 + Max(Height(root->left), Height(root->right));
}

static size_t Max(size_t a, size_t b) {
  return a > b ? a : b;
}

BSTNode *InorderPredecessor(BSTNode *root) {
  assert(root->left);

  root = root->left;
  while (root->right) {
    root = root->right;
  }
  return root;
}

BSTNode *InorderSuccessor(BSTNode *root) {
  assert(root->right);

  root = root->right;
  while (root->left) {
    root = root->left;
  }
  return root;
}

static void DeleteLeaf(BSTNode *leaf) {
  assert(!leaf->left && !leaf->right);
  free(leaf);
}