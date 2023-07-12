#include "avl_tree.h"
/**

There are effectively 4 different imbalances for a tree of size 3, and one balanced representation:
    2   0          2    0
   /     \        /      \
  1       1      0        2
 /         \      \      /
0           2      1    1

They're named LL, RR LR, RL imbalances respectively.
The letters correspond to the directions from the root.
For example, the first one goes Left, then Left, so LL.

The balanced version of this tree is:
   1
  / \
 0  2

The total number of BST representations with n keys can be found with the Catalan number Cn:
Cn = (2n)!/((n + 1) * n!)

So, for 3 nodes:
C3 = (2*3)!/((3 + 1)! * 3!) = 6!/(4! * 3!) = (6 * 5 * 4!)/(4! * 3!) = (6 * 5)/3! = 30/6 = 5

This is the idea behind AVL trees. Since you can represent the same 3 node tree in 5 different ways,
where one of them is balanced, and the rest imbalanced. If you make an insertion into the BST such that a node becomes imbalanced,
switch it over to the balanced representation.

Given this intuition, the 4-step algorithm for inserting into an AVL tree is:

Do the standard BST insert

For each node along the path you followed to get to where the new node was inserted
  (can be done after making the recursive call):
  
    Calculate the balance factor for the node:
      balance_factor = Height(left_sub_tree) - Height(right_sub_tree)
      A node is balanced if it's balance factor is: -1, 0, or 1.
      Otherwise, it's imbalanced.

    Figure out which imbalance it is (LL, LR, RR, RL), if any:
      If the balance factor is > 1:
        Check the heights of the left child and it's children
      If it's < -1:
        Check the heights of the right child and it's children

    Perform the correpsonding rotations:
      If LL imbalance: Right Rotation (Also known as LL, or clockwise)
      If RR imbalance: Left Rotation (Also known as RR, or anti-clockwise)
      If LR imbalance: Left rotate from the child, it's now a LL imbalance, just do the LL rotation above.
      If RL imbalance: Right rotate from the child, it's now a RR imbalance, just do the RR rotation above.
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

