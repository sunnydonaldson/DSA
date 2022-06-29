#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "../helpers/iohelper.h"

/************************************************************************************************
The taylor series
There are O(n^2) multiplications
e^x = 1 + x/1 + (x^2)/2! + (x^3)/3! + ...

The taylor series with horners rule
Only O(n) multiplications.
We can take common factors out of the terms, to reduce the number of multiplications.
So e^x = 1 + x/1 + (x^2)/2! + (x^3)/3! + (x^4)/4! ... becomes,
e^x = 1 + x/1(1 + x/2(1 + x/3(1 + x/4 ... )))
*************************************************************************************************/


double e(int x, int n) {
  static double power = 1;
  static double factorial = 1;
  double result = 0.0;
  if (n == 0) {
    return 1;
  } else {
    result = e(x, n-1);
  }
  power *= x;
  factorial *= n;
  return result + (double) power/factorial;
}

double eWithHornersRuleRecursive(double x, double n) {
  static double s = 1; // Come on Sunny, you can find a better variable name than that
  if (n == 0) {
    return s;
  }
  s = 1 + x / n * s;
  return eWithHornersRuleRecursive(x, n-1);
}

double eWithHornersRuleIterative(double x, double n) {
  double s = 1;
  for (;n > 0; n--) {
    s = 1 + x / n * s;
  }
  return s;
}

int main() {
  // The larger the value of n, the more precise it will be
  int x = getUserInt();
  int n = getUserInt();
  printf("%f\n", e(x, n));
  printf("Taylor series with Horner's rule: %f\n", eWithHornersRuleRecursive(x, n));
  printf("Taylor series with Horner's rule, but iterative: %f\n", eWithHornersRuleIterative(x, n));
  return 0;
}