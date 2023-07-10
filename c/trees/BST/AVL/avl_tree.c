#include "avl_tree.h"
/**
Steps for AVL:

Calcualte the balance factor for all nodes:
  balance_factor = Height(left_sub_tree) - Height(right_sub_tree)
  A node is balanced if it's balance factor is: -1, 0, or 1.
  Otherwise, it's imbalanced.
**/

static int BalanceFactor(BSTNode *root);
static void RestoreAvl(BSTNode *);

void AvlInsert(BSTNode *root, BSTNode *node) {
  assert(root && node);
  InsertNode(root, node, &RestoreAvl);

}

static void RestoreAvl(BSTNode * node) {
  int balance_factor = BalanceFactor(node);
  if (balance_factor <= 1 && balance_factor >= -1) {
    return;
  }

  if (balance_factor < -1) {
    // rotate_left
  } else {
    // rotate_right
  }
}

/** Returns negative if right subtree taller, positive if right shorter, else 0. **/
static int BalanceFactor(BSTNode *root) {
  return (int)Height(root->left) - (int)Height(root->right);
}

