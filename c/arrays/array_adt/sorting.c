#include "arrayADT.h"

Array *mergeArrays(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  int i = 0, j = 0, x = 0;
  while (i < a->length && j < b->length)
  {
    if (a->arr[i] < b->arr[j]) {
      result->arr[x++] = a->arr[i++];
    } else {
      result->arr[x++] = b->arr[j++];
    }
  }
  for (; i < a->length; i++)
    result->arr[x++] = a->arr[i];
  for (; j < b->length; j++)
    result->arr[x++] = a->arr[j];
  result->length = result->size;
  return result;
}

int isSorted(Array *a)
{
  for (int i = 1; i < a->length; i++)
    if (a->arr[i] < a->arr[i - 1])
      return FALSE;
  return TRUE;
}
