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
  }
  return node;
}

void InsertNode(BSTNode *root, BSTNode *node, void (PostProcess)(BSTNode *)) {
  assert(root && node);
  node->height = 1;

  if (node->val < root->val) {
    if (!root->left) {
      root->left = node;
    } else {
        InsertNode(root->left, node, PostProcess);
    }
  } else {
    if (!root->right) {
      root->right = node;
    } else {
      InsertNode(root->right, node, PostProcess);
    }
  }

  if (PostProcess) {
    PostProcess(root);
  }

  root->height = Max(root->left ? root->left->height : 0, root->right ? root->right->height : 0) + 1;
}

void DisplayBSTNode(BSTNode *root) {
  assert(root);
  printf("%d, ", root->val);
}

void InorderBST(BSTNode *root, void (*process)(BSTNode *)) {
  if (!root) {
    return;
  }

  InorderBST(root->left, process);
  (*process)(root);
  InorderBST(root->right, process);
}

void PreorderBST(BSTNode *root, void (*process)(BSTNode *)) {
  if (!root) {
    return;
  }

  (*process)(root);
  PreorderBST(root->left, process);
  PreorderBST(root->right, process);
}

void PostorderBST(BSTNode *root, void (*process)(BSTNode *)) {
  if (!root) {
    return;
  }

  PostorderBST(root->left, process);
  PostorderBST(root->right, process);
  (*process)(root);
}

size_t Height(BSTNode *root) {
  return root ? root->height : 0;
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

/** Only use if you can guarantee that the node is a leaf **/
static void DeleteLeaf(BSTNode *leaf) {
  free(leaf);
}