#include "arrayADT.h"

void insert(Array *arr, size_t idx, int value)
{
  if (arr->length + 1 >= arr->size) // enough room for +1 element?
    resize(arr);
  assert(idx <= arr->length); // index is within the currently used space
  for (size_t i = arr->length++; i > idx; i--)
    arr->arr[i] = arr->arr[i -1];
  arr->arr[idx] = value;
}

void sortedInsert(Array *arr, int value)
{
  if (arr->length + 1 >= arr->size)
    resize(arr);
  int i = arr->length -1;
  while(arr->arr[i] > value) {
    arr->arr[i+1] = arr->arr[i];
    i--;
  }
  arr->arr[i+1] = value;
  arr->length++;
}
