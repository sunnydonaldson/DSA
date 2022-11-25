#include "stdio.h"
#include "../helpers/iohelper.h"

/***********************************************************
* The factorial of a number n (n!) is 1*2*3...*n,
* Which can be expressed as 1*2*3...*(n-1)*n
* Which can be simplified to factorial(n-1)*n
* This is essentially the same the steps taken for proving by induction
* So, anything that can be proved by induction can directly be converted to a recursive solution
*
* NOTE: 0! = 1
* 1! = 1
***********************************************************/

// Space complexity of O(n) because an activation record needs to be created for each call
// Time complexity of O(n)
// If n is large, there's a risk of a stack-overflow
// In this particular case, I think the result would become too big to fit in an int before a stackoverflow happens
int recursiveFactorial(int n) {
  // base case
  if (n == 0) {
    return 1;
  }
  return recursiveFactorial(n-1) * n;
}

// space complexity of O(1)
// time complexity of O(n)
// No risk of stackoverflow
int iterativeFactorial(int n) {
  int product = 1;
  for (int i = 1; i <= n; i++) {
    product *= i;
  }
  return product;
}

int main() {
  int n = getUserInt();
  printf("factorial of %d: %d\n", n, recursiveFactorial(n));
  printf("factorial of %d using iteration %d\n", n, iterativeFactorial(n));
  int *int_array = makeIntArray(4);
  free(int_array);
  
  return 0;
}