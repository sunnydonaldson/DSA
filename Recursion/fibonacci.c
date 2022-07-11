#include "../helpers/iohelper.h"
#include "../helpers/arrayhelper.h"
#include <stdio.h>

// Approximately O(2^n)
// The function ends up calling itself multiple times with the same value
// This is called excessive recursion.
int recursiveFib(int n) {
  if (n <= 1) {
    return n;
  }
  return recursiveFib(n - 1) + recursiveFib(n - 2);
}

// If you trace the recursion tree, we see that it takes O(n) recursive calls
int memoizedRecursiveFib(int n, int *seenCalls) {
  if (n <= 1) {
    seenCalls[n] = n;
    return n;
  }

  if (seenCalls[n -1] == -1)
    seenCalls[n-1] = memoizedRecursiveFib(n -1, seenCalls);
  if (seenCalls[n -2] == -1)
    seenCalls[n-2] = memoizedRecursiveFib(n -2, seenCalls);
  
  return seenCalls[n-2] + seenCalls[n-1];
}

// O(n)
int iterativeFib(int n) {
  if (n <= 1) {
    return n;
  }

  int previous = 0;
  int current = 1;
  int tmp = 0;
  for (int i = 2; i <= n; i++) {
    tmp = current;
    current = previous + current;
    previous = tmp;
  }
  return current;
}


int main() {
  int n = getUserInt();
  // It would be better to have seenCalls as a static variable
  // in the memoizedFib function, but it seems that some compilers
  // don't let you functions to initialize static variables.
  int *seenCalls = fillValues(makeIntArray(n), n, -1);
  
  printf("iterative fibonacci: %d\n", iterativeFib(n));
  printf("Memoized recursive fibonacci: %d\n", memoizedRecursiveFib(n, seenCalls));
  printf("recursive fibonacci: %d\n", recursiveFib(n));
  return 0;
}