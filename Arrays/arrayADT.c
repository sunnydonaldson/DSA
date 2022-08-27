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

#define TRUE 1
#define FALSE 0

typedef struct Array {
  int *arr;
  size_t size;
  size_t length;
} Array;
// Side note
// typedef struct Array Array does the same as above
// it might make it clearer how typedef works.

// Maybe refactor into header file...
void fillValues(Array *arr, int value);
Array *instantiate(size_t size);
void printArray(Array *arr);
void append(Array *arr, int value);
void freeArray(Array **arr);
int get(Array *arr, size_t idx);
void set(Array *arr, size_t idx, int value);
int *search(Array *arr, int value);

// Initializes an instance of Array on the heap
Array *instantiate(size_t size)
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

int get(Array *arr, size_t idx)
{
  assert(idx < arr->length);
  return arr->arr[idx];
}

void set(Array *arr, size_t idx, int value)
{
  assert(idx < arr->length);
  arr->arr[idx] = value;
}

// Returns the address of the element if found, else NULL.
int *search(Array *arr, int value)
{
  for (size_t i = 0; i < arr->length; i++)
    if (arr->arr[i] == value)
      return &(arr->arr[i]);
  return NULL;
}

int main() {
  Array *array = instantiate(32);
  printArray(array);
  append(array, 12);
  append(array, 14);
  printArray(array);

  int *maybe12 = search(array, 12);
  printf("Array contains 12? %d\n", maybe12 != NULL);
  printf("address: %p, value: %d\n", maybe12, *maybe12);
  int *maybe99 = search(array, 99);
  printf("Array contains 99? %d\n", maybe99 != NULL);

  freeArray(&array);
  return 0;
}