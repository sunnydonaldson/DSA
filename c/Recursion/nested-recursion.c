#include "stdio.h"
/***********************************************************************************************************
  Nested recursion is where you call a function recursively, and pass a recursive call to the same function.
***********************************************************************************************************/

int nestedRecursion(int n) {
  printf("%d\n", n);
  if (n > 0) {
   return nestedRecursion(nestedRecursion(n -1));
  } else {
    return n;
  }
  
}

int main() {
  nestedRecursion(4);
  return 0;
}