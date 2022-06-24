/*************************************************************
* Three recursion is where a recursive functions calls itself more than once.
* Whereas linear recursion, is where a recursive function only calls itself once.
************************************************************/

#include<stdio.h>
#include<stdlib.h>

void treeRecursion(int n) {
  if (n > 0) {
    printf("%d\n", n);
    treeRecursion(n - 1);
    treeRecursion(n -1);
  }
}

int main() {
  treeRecursion(5);
  return 0;
}