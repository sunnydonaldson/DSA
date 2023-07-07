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
};

BSTNode *CreateNode(int val, BSTNode *left, BSTNode *right);
void DeleteNode(BSTNode **node);
void InsertNode(BSTNode *root, BSTNode *node);
void DisplayBSTNode(BSTNode *root);
void InorderBST(BSTNode *root, void (*process)(BSTNode *));
void PreorderBST(BSTNode *root, void (*process)(BSTNode *));
void PostorderBST(BSTNode *root, void (*process)(BSTNode *));

#endif
