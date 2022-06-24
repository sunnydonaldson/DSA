#include "stdio.h"
void b(int n);
/******************************************************************
  Indirect recursion is where one function calls others, and at some point in the chain,
  The original function is called again, creating a cycle.
******************************************************************/

void a(int n) {
  if (n > 0) {
    printf("a: %d\n", n);
    b(n -1);
  }
}

void b(int n) {
  if(n > 1) {
    printf("b: %d\n", n);
    a(n / 2);
  }
}

int main() {
  a(20);
  return 0;
}