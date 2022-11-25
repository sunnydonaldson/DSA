#include "arrayADT.h"

// Initializes an instance of Array on the heap
Array *instantiate(size_t size)
{
  Array *array = malloc(sizeof(Array));
  array->arr = malloc(size * sizeof(int));
  array->size = size;
  array->length = 0;
  return array;
}

void fillArray(Array *arr, int value)
{
  for (size_t i = 0; i < arr->size; i++) {
    arr->arr[i] = value;
  }
}

void printArray(Array *arr)
{
  for (size_t i = 0; i < arr->length; i++) {
    printf("[%zu]= %d\n", i, arr->arr[i]);// %zu for size_t
  }
}

// Because the struct has members on the heap we need to explicitly free them
// Accept a pointer to pointer so we can guarantee setting it to null.
void freeArray(Array **arr)
{
  free((*arr)->arr);
  free(*arr);
  *arr = NULL;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
