#ifndef bst_h
#define bst_h
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct BSTNode BSTNode;
struct BSTNode {
  int val;
  BSTNode *left;
  BSTNode *right;
  size_t height;
};

BSTNode *CreateNode(int val, BSTNode *left, BSTNode *right);
void DeleteTree(BSTNode **root);
BSTNode *DeleteNode(BSTNode *node, int key);
void InsertNode(BSTNode *root, BSTNode *node, void (PostProcess)(BSTNode *));
void DisplayBSTNode(BSTNode *root);
void InorderBST(BSTNode *root, void (*process)(BSTNode *));
void PreorderBST(BSTNode *root, void (*process)(BSTNode *));
void PostorderBST(BSTNode *root, void (*process)(BSTNode *));
size_t Height(BSTNode *root);
BSTNode *InorderPredecessor(BSTNode *root);
BSTNode *InorderSuccessor(BSTNode *root);

#endif
