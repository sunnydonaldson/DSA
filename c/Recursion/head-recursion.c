#include<stdio.h>
#include<stdlib.h>

/********************************************************************
* Head recursion is where the recursive call is the first thing in the method.
* It means nothing gets computed during the calling stage.
* Everything happens during the returning stage.
*
* Head recursion can't easily be converted into a loop
*********************************************************************/

void headRecursion(int n) {
  static int counter = 0;
  if (n > 0) {
    headRecursion(n -1);
    //---- an arbitrary amount of stuff after the recursive call-----------
    printf("number of calls: %d\n", ++counter);
  }
}

int main() {
  int n = 5;
  headRecursion(n);
  return 0;
}