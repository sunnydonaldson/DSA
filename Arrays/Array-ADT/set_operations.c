#include "arrayADT.h"

// O(n * m) essentially O(n^2)
Array *arrayUnion(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  for (size_t i = 0; i < a->length; i++)
    append(result, a->arr[i]);

  for (size_t i = 0; i < b->length; i++)
    if (search(result, b->arr[i]) == NULL)
      append(result, b->arr[i]);
  return result;
}

// Effectively just merge, but without duplicates
Array *sortedUnion(Array *a, Array *b)
{
  size_t i = 0, j = 0;
  Array *result = instantiate(a->size + b->size);
  while (i < a->length && j < b->length) {
    if (a->arr[i] < b->arr[j]) {
      append(result, a->arr[i++]);
    } else if (a->arr[i] > b->arr[j]) {
      append(result, b->arr[j++]);
    } else {
      append(result, a->arr[i]);
      i++, j++;
    }
  }

  for (; i < a->length; i++)
    append(result, a->arr[i]);
  for(; j < b->length; j++)
    append(result, b->arr[j]);
  return result;
}

// O(n * m) essentially O(n^2)
Array *arrayIntersection(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  for (size_t i = 0; i < a->length; i++)
    if (search(b, a->arr[i]) != NULL)
      append(result, a->arr[i]);
  return result;
}

Array *sortedIntersection(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  size_t i = 0, j = 0;
  while (i < a->length && j < b->length) {
    if (a->arr[i] < b->arr[j]) {
      i++;
    } else if (a->arr[i] > b->arr[j]) {
      j++;
    } else {
      append(result, a->arr[i]);
      i++, j++;
    }
  }
  return result;
}

// Effectively a - b
// O(n * m) essentially O(n^2)
Array *difference(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  for (int i = 0; i < a->length; i++)
    if (search(b, a->arr[i] == NULL))
       append(result, a->arr[i]);
  return result;
}
