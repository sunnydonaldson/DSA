#include "../helpers/iohelper.h"
/*****************************************************************************************
* m^n = m*m*m...
        \/\/
          n
So, m * m, n times.
* Similar to factorial, the exponent of a number can be proven by induction,
* And one of the steps is m^n = m^(n-1) * m;
* Which can be translated directrly to recursion.
*****************************************************************************************/

// Space complexity of O(n) because a stackframe is required for each recursive call
// O(n) time complexity
int recursiveExponent(int m, int n) {
  if (n == 0) {
    return 1;
  }
  return recursiveExponent(m, n-1) * m;
}

// O(1) space complexity
// O(n) time complexity
// No risk of stackoverflow
int iterativeExponent(int m, int n) {
  int product = 1;
  for (int i = 1; i <= n; i++) {
    product *= m;
  }
  return product;
}

int main() {
  printf("An exponent is where we raise a number m to the power n\n");
  int m = getUserInt();
  int n = getUserInt();
  printf("exponent (using recursion) of %d^%d: %d\n", m, n, recursiveExponent(m, n));
  printf("exponent (using iteration) of %d^%d: %d\n", m, n, iterativeExponent(m, n));
}