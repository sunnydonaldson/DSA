#include "avl_tree.h"
/**
Steps for AVL:

Calcualte the balance factor for all nodes:
  balance_factor = Height(left_sub_tree) - Height(right_sub_tree)
  A node is balanced if it's balance factor is: -1, 0, or 1.
  Otherwise, it's imbalanced.
**/

static int BalanceFactor(BSTNode *root);

void AvlInsert(BSTNode *root, BSTNode *node) {
  assert(root && node);
  InsertNode(root, node);

}

static int BalanceFactor(BSTNode *root) {
  return (int)Height(root->left) - (int)Height(root->right);
}
