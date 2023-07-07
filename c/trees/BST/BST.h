#ifndef bst_h
#define bst_h
#include <stdlib.h>
#include <stdio.h>

typedef struct BSTNode BSTNode;
struct BSTNode {
  int val;
  BSTNode *left;
  BSTNode *right;
};

BSTNode *CreateNode(int val, BSTNode *left, BSTNode *right);
void DeleteNode(BSTNode **node);

#endif
