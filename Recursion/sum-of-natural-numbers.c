#include "stdio.h"

int sumOfNaturalNumsTo(int n) {
  if (n == 0) {
    return n;
  }
  return sumOfNaturalNumsTo(n -1) + n;
}

//The same thing can be done iteratively
int iterativeSumOfNaturalNumsTo(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n;
    n--;
  }
  return sum;
}

int main() {
  printf("recursively: %d\n", sumOfNaturalNumsTo(10));
  printf("iteratively: %d\n", iterativeSumOfNaturalNumsTo(10));
}