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

<<<<<<< HEAD
<<<<<<< HEAD
// If you trace the recursion tree, we see that it takes O(n) recursive calls
int memoizedRecursiveFib(int n, int *seenCalls) {
=======
=======
>>>>>>> origin/main
int memoizedRecursiveFib(int n, int *seenCalls) {
  // There's conflicting advice on wether you should free dynamically allocated memory
  // being pointed to by a static pointer.  Carnegie Mellon says you don't, so I won't.
  // https://wiki.sei.cmu.edu/confluence/display/c/MEM31-C.+Free+dynamically+allocated+memory+when+no+longer+needed
<<<<<<< HEAD
>>>>>>> origin/main
=======
>>>>>>> origin/main
  if (n <= 1) {
    seenCalls[n] = n;
    return n;
  }
  
<<<<<<< HEAD
<<<<<<< HEAD
  if (seenCalls[n -1] == -1)
    seenCalls[n-1] = memoizedRecursiveFib(n -1, seenCalls);
  if (seenCalls[n -2] == -1)
    seenCalls[n-2] = memoizedRecursiveFib(n -2, seenCalls);
  
  return seenCalls[n-2] + seenCalls[n-1];
=======
=======
>>>>>>> origin/main
  if (seenCalls[n -1] == -1) {
    seenCalls[n -1] = memoizedRecursiveFib(n -1, seenCalls);
  }
  if (seenCalls[n -2] == -1) {
    seenCalls[n -2] = memoizedRecursiveFib(n -2, seenCalls);
  }
  return seenCalls[n -2] + seenCalls[n -1];
<<<<<<< HEAD
>>>>>>> origin/main
=======
>>>>>>> origin/main
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
<<<<<<< HEAD
<<<<<<< HEAD
  int *fibValues = fillValues(makeIntArray(n), n, -1);
  printf("memoized recursive fibonacci: %d\n", memoizedRecursiveFib(n, fibValues));
  printf("recursive fibonacci: %d\n", recursiveFib(n));
=======
=======
>>>>>>> origin/main
  // It would be better to have seenCalls as a static variable
  // in the memoizedFib function, but it seems that some compilers
  // don't let you functions to initialize static variables.
  int *seenCalls = fillValues(makeIntArray(n), n, -1);
<<<<<<< HEAD
>>>>>>> origin/main
=======
>>>>>>> origin/main
  printf("iterative fibonacci: %d\n", iterativeFib(n));
  printf("Memoized recursive fibonacci: %d\n", memoizedRecursiveFib(n, seenCalls));
  printf("recursive fibonacci: %d\n", recursiveFib(n));
  return 0;
}