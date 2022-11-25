#include "../helpers/iohelper.h"
#include "../helpers/stack.h"


void TOH(int n, int a, int b, int c)
{
  if (n > 0) {
    TOH(n -1, a, c, b);
    printf("from %d to %d.\n", a, c);
    TOH(n -1, b, a, c);
    
  }
}

int main()
{
  int a = 1;
  int b = 2;
  int c = 3;
  int n = getUserInt();
  TOH(n, a, b, c);
  return 0;
}