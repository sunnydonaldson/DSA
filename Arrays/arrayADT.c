/*********************************************************************************
 * As well as the primitive arrays, there's an array abstract datatype.
 * The array ADT combines a dynamically allocated array, with some common methods
 * such as: display, append, insert, delete, search, get, set, max/min, reverse
 * and shift/rotate.
 *  
*********************************************************************************/
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
  int *arr;
  int size;
  int length;
} Array;
// Side note
// typedef struct Array Array does the same as above
// it might make it clearer how typedef works.

// Maybe refactor into header file...
void fillValues(Array *arr, int value);
Array *instantiate(int size);
void printArray(Array *arr);
void append(Array *arr, int value);

// Initializes an instance of Array on the heap
Array *instantiate(int size)
{
  Array *array = malloc(sizeof(Array));
  array->arr = malloc(size * sizeof(int));
  array->size = size;
  array->length = 0;
  fillValues(array, 0);
  return array;
}

void fillValues(Array *arr, int value)
{
  for (int i = 0; i < arr->size; i++) {
    arr->arr[i] = value;
  }
}

void printArray(Array *arr)
{
  for (int i = 0; i < arr->length; i++) {
    printf("[%d]= %d\n", i, arr->arr[i]);
  }
}

void append(Array *arr, int value)
{
  assert(arr->length + 1 <= arr->size);
  arr->arr[arr->length++] = value;
}

// Because the struct has members on the heap we need to explicitly free them
// Accept a pointer to pointer so we can guarantee setting it to null.
void freeArray(Array **arr)
{
  free((*arr)->arr);
  free(*arr);
  *arr = NULL;
}

int main() {
  Array *array = instantiate(32);
  printArray(array);
  append(array, 12);
  append(array, 14);
  printArray(array);
  freeArray(&array);
  return 0;
}