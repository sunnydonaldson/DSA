#include <stdio.h>
#include <stdlib.h>

int recursiveStuff(int n) {
  //  This is an example of tail recursion,
  // Because the recursive call happens after the logic in the method is carried out
  static int x = 0; // In this case the static variable stays the same once the calling stage has finished
  if (n > 0) {
    x++;
    return recursiveStuff(n-1) + x;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("please pass a single integer\n");
    return 1;
  }
  
  int n = atoi(argv[1]);
  printf("recursiveStuff(%d) = %d\n", n, recursiveStuff(n));
  return 0;
}