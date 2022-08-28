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
int *search(Array *arr, int key);
int *transposeSearch(Array *arr, int key);
int *moveToHeadSearch(Array *arr, int key);
static void swap(int *a, int *b);
void insert(Array *arr, size_t idx, int value);
int delete(Array *arr, size_t idx);

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
// There are a couple of ways that this function can be improved.
// Similarly to CPU caching, we can apply the rule of temporal locality,
// Which states that something that has been accessed recently, will likely
// need to be accessed again.  So we can improve the linear search by,
// moving the found key closer to the start of the array, so it gets found
// faster in future, instead of having to traverse the whole thing.
int *search(Array *arr, int key)
{
  for (size_t i = 0; i < arr->length; i++)
    if (arr->arr[i] == key)
      return &(arr->arr[i]);
  return NULL;
}
// The first way of improving the linear search is called transposition.
// When we find the key we want, we swap it with the element to its left.
// So, every time we search for the same key, it gets moved one position
// closer to the head of the array; eventually it'll get there.
int *transposeSearch(Array *arr, int key)
{
  for (size_t i = 0; i < arr->length; i++) {
    if(arr->arr[i] == key) {
      if (i > 0)
        swap((&arr->arr[i]), &(arr->arr[i-1]));
        return &(arr->arr[i-1]);
    }
  }
  return NULL;
}

// The second way of improving the linear search is where you
// swap the desired key with the element at the start of the array.
// This has a much more rapid improvement,
// but I can imagine a shortcoming being, when you swap 2
// commonly searched for elements, so 1 always ends up being
// near the end of the array.
int *moveToHeadSearch(Array *arr, int key)
{
  for (size_t i = 0; i < arr->length; i++) {
    if(arr->arr[i] == key) {
      swap(&(arr->arr[i]), &(arr->arr[0]));
      return arr;
    }
  }
  return NULL;
}

static void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void insert(Array *arr, size_t idx, int value)
{
  assert(arr->length + 1 <= arr->size); // enough room for +1 element?
  assert(idx <= arr->length); // index is within the currently used space
  for (size_t i = arr->length++; i > idx; i--)
    arr->arr[i] = arr->arr[i -1];
  arr->arr[idx] = value;
}

int delete(Array *arr, size_t idx)
{
  assert(idx < arr->length);
  int returnValue = arr->arr[idx];
  for (size_t i = idx; i < arr->length -1; i++)
    arr->arr[i] = arr->arr[i+1];
  arr->length--;
  return returnValue;
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

  printArray(array);
  printf("insert 44 at index 2\n");
  insert(array, 2, 44);
  printArray(array);
  printf("insert 22 at index 1\n");
  insert(array, 1, 22);
  printArray(array);
  printf("insert 434 at index 0\n");
  insert(array, 0, 434);
  printArray(array);
  // printf("insert at 100 (should fail)");
  // insert(array, 100, 99);

  printf("delete at index 0\n");
  delete(array, 0);
  printArray(array);

  printf("delete at index 2\n");
  delete(array, 2);
  printArray(array);
  // printf("delete at 99 (should fail)\n");
  printf("\n search with transposition\n");
  transposeSearch(array, 44);
  printArray(array);

  printf("\n search with move to head\n");
  moveToHeadSearch(array, 22);
  printArray(array);

  freeArray(&array);
  return 0;
}