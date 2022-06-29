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

int memoizedRecursiveFib(int n) {
  // There's conflicting advice on wether you should free dynamically allocated memory
  // being pointed to by a static pointer.  Carnegie Mellon says you don't, so I won't.
  // https://wiki.sei.cmu.edu/confluence/display/c/MEM31-C.+Free+dynamically+allocated+memory+when+no+longer+needed
  static int *seenCalls = fillValues(makeIntArray(n), n, -1);

  int x, int y;
  if (n <= 1) {
    return n;
  }
  
  if (seenCalls[n -1] != -1) {
    x = seenCalls[n -1];
  } else {
    x = memoizedRecursiveFib(n -1);
  }
  if (seenCalls[n -2] != -1) {
    y = seenCalls[n -2];
  } else {
    y = memoizedRecursiveFib(n -2);
  }
  return x + y;
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
  printf("recursive fibonacci: %d\n", recursiveFib(n));
  printf("iterative fibonacci: %d\n", iterativeFib(n));
}