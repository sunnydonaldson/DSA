#include "arrayADT.h"

Array *arrayUnion(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  printf("result length %zu\n", result->length);
  for (size_t i = 0; i < a->length; i++)
    result->arr[result->length++] = a->arr[i];

  for (size_t i = 0; i < b->length; i++)
    if (search(result, b->arr[i]) == NULL)
      result->arr[result->length++] = b->arr[i];
  return result;
}

Array *arrayIntersection(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  for (size_t i = 0; i < a->length; i++)
    if (search(b, a->arr[i]) != NULL)
      result->arr[result->length++] = a->arr[i];
  return result;
}

