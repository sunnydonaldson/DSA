#include "../../helpers/iohelper.h"
#include "../../helpers/arrayhelper.h"
/****************************************************************************
 * The array ADT (Abstract Datatype) is the combination of a primitive array
 * with a bunch of useful operations for it.
 * 
 * The properties of the array ADT are:
 * 1. Array Space
 * 2. size
 * 3. length
 * 
 * Size holds the size of the array that's been allocated, length holds
 * the number of elements in the array.
 * 
 ***************************************************************************/

struct Array
{
  int *A;
  int size;
  int length;
};

int main()
{
  struct Array arr;
  printf("enter a size to allocate for the array: \n");
  arr.size = getUserInt();
  arr.A = fillValues(malloc(arr.size * sizeof(int)), arr.size, 0);
  arr.length = arr.size;
  printIntArray(arr.A, arr.length);
  return 0;
}