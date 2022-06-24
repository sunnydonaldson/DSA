#include<stdio.h>
#include<stdlib.h>
/********************************************************************************
*  Tail recursion is where the recursive call is the last statement in a function.
********************************************************************************/

int tailRecursion(int n) {
  static int counter = 0;
  if (n > 0) {
    printf("Call number: %d\n", ++counter);
    // do some other stuff before recursive call

    return tailRecursion(n-1);
    // return tailRecursion(n - 1) + n; // This isn't tail recursion,
    // because the + n has to be calculated after the call to tailRecursion, so it's not the last operation.
  } else {
    printf("Total number of recursive calls = %d\n", counter);
    return 0; // base case
  }
}

int main() {
  int n = 5;
  printf("tailRecursion(%d) = %d\n", n, tailRecursion(n));
  return 0;
}