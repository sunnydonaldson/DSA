/************************************************************************************************
* Given a set of n elements, how many different combinations of a subset of size r can be found?
* 0 <= r <= n
* This formula defines the number of combinations: n!/r!((n -r)!)
* 
* Pascal's triangle can be used to find combinations just using addition
************************************************************************************************/

#include "../helpers/iohelper.h"
#include "../helpers/arrayhelper.h"

// O(n)
int factorial(int n)
{
  int result = 1;
  for(;n > 0; n--)
    result *= n;
  return result;
}

// This version isn't recursive
int combinations(int n, int r)
{
  int nFact = factorial(n);
  int rFact = factorial(r);
  int nSubRFact = factorial(n - r);
  return nFact / (rFact * nSubRFact);
}

int combinationsRecursive(int n, int r)
{
  if (n == r || r == 0)
    return 1;
  return combinationsRecursive(n-1, r-1) + combinationsRecursive(n-1, r);
}


int main()
{
  int n = getUserInt();
  int r = getUserInt();
  printf("combinations of subset %d of set %d: %d\n", r, n, combinations(n, r));
  return 0;
}