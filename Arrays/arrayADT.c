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
#include <limits.h>

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
void fillArray(Array *arr, int value);
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
void sortedInsert(Array *arr, int value);
Array *mergeArrays(Array *a, Array *b);
int isSorted(Array *a);
int delete(Array *arr, size_t idx);
int max(Array *arr);
int min(Array *arr);
int sum(Array *arr);
double avg(Array *arr);
void reverse(Array *arr);
void leftShift(Array *arr, int numToShift);
void leftRotate(Array *arr, int numToRotate);
Array *intersection(Array *a, Array *b);


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
      return arr->arr;
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

int binarySearch(Array *arr, int key)
{
  assert(arr->length >= 1);
  size_t low = 0;
  size_t high = arr->length -1;
  size_t mid;
  
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr->arr[mid] == key)
      return mid;
    else if (key < arr->arr[mid])
      high = mid -1;
    else
      low = mid + 1;
  }
  return -1;
}

void insert(Array *arr, size_t idx, int value)
{
  assert(arr->length + 1 <= arr->size); // enough room for +1 element?
  assert(idx <= arr->length); // index is within the currently used space
  for (size_t i = arr->length++; i > idx; i--)
    arr->arr[i] = arr->arr[i -1];
  arr->arr[idx] = value;
}

void sortedInsert(Array *arr, int value)
{
  assert(arr->length + 1 <= arr->size);
  int i = arr->length -1;
  while(arr->arr[i] > value) {
    arr->arr[i+1] = arr->arr[i];
    i--;
  }
  arr->arr[i+1] = value;
  arr->length++;
}

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
  freeArray(&a);
  freeArray(&b);
  return result;
}

int isSorted(Array *a)
{
  for (int i = 1; i < a->length; i++)
    if (a->arr[i] < a->arr[i - 1])
      return FALSE;
  return TRUE;
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

int max(Array *arr)
{
  int max = arr->arr[0];
  for (int i = 1; i < arr->length; i++ )
    if (arr->arr[i] > max)
      max = arr->arr[i];
  return max;
}

int min(Array *arr)
{
  int min = arr->arr[0];
  for (int i = 1; i < arr->length; i++)
    if (arr->arr[i] < min)
      min = arr->arr[i];
  return min;
}

int sum(Array *arr)
{
  int sum = 0;
  for (int i = 0; i < arr->length; i++)
    sum += arr->arr[i];
  return sum;
}

double avg(Array *arr)
{
  return (double) sum(arr) / arr->length;
}

void reverse(Array *arr)
{
  assert(arr->length > 0);
  int tmp;
  for (int i = 0, j = arr->length -1; i < j; i++, j--) {
    swap(&arr->arr[i], &arr->arr[j]);
  }
}

void leftShift(Array *arr, int numToShift)
{
  if (numToShift > arr->length)
    numToShift = arr->length;
  for (size_t i = numToShift; i < arr->length; i++)
    arr->arr[i - numToShift] = arr->arr[i];
  for (size_t j = arr->length - numToShift; j < arr->length; j++)
    arr->arr[j] = 0;
}

void leftRotate(Array *arr, int numToRotate)
{
  // An optimisation
  numToRotate = numToRotate % arr->length;
  int *tmp = malloc(arr->length * sizeof(int));
  for (size_t i = numToRotate, j = 0; i < arr->length; i++, j++)
    tmp[j] = arr->arr[i];
  for (size_t i = 0, j=numToRotate; i < numToRotate; i++, j++)
    tmp[j] = arr->arr[i];
  for (size_t i = 0; i < arr->length; i++)
    arr->arr[i] = tmp[i];
  free(tmp);
}

Array *intersection(Array *a, Array *b)
{
  Array *result = instantiate(a->length + b->length);
  printf("result length %d\n", result->length);
  for (int i = 0; i < a->length; i++)
    result->arr[length++] = a->arr[i];

  for (int i = 0; i < b->length; i++)
    if (search(result, b->arr[i]) == NULL)
      result->arr[result->length++] = b->arr[i];
  return result;
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

  Array *orderedArray = instantiate(63);
  // -2 to leave space to exercise sortedInsert + insert
  int i;
  for (i = 0; i < orderedArray->size -1; i++)
    orderedArray->arr[i] = i * 2;
  orderedArray->length = i;
  printf("ordered array\n");
  printArray(orderedArray);
  int numToInsert = 19;
  printf("Insert %d into ordered array.\n", numToInsert);
  sortedInsert(orderedArray, numToInsert);
  printArray(orderedArray);

  printf("\nbinary search: %d\n", binarySearch(orderedArray, 10));
  printf("min of array: %d\n", min(orderedArray));
  printf("max of array: %d\n", max(orderedArray));
  printf("sum of array: %d\n", sum(orderedArray));
  printf("average of array: %f\n", avg(orderedArray));

  printf("\n Other sorted array: \n");
  Array *otherOrderedArray = instantiate(5);
  for (i = 0; i < 5; i++)
    otherOrderedArray->arr[i] = i * 3 + 1;
  otherOrderedArray->length = 5;
  printArray(otherOrderedArray);
  printf("\nMerge sorted arrays:\n");
  Array *result = mergeArrays(orderedArray, otherOrderedArray);
  printArray(result);
  printf("merged array isSorted? %d\n", isSorted(result));



  reverse(result);
  printf("reversed array:\n");
  printArray(result);


  Array *smallArray = instantiate(5);
  for (int i = 0; i < smallArray->size -2; i++)
    smallArray->arr[i] = 1 + i * 2;
  smallArray->length = smallArray->size;
  printf("small array \n");
  printArray(smallArray);
  leftShift(smallArray, 2);
  printf("after shifting left by 2: \n");
  printArray(smallArray);
  leftShift(smallArray, 5);
  printf("after shifting left by 5\n");
  printArray(smallArray);

  for (int i = 0; i < smallArray->size; i++)
    smallArray->arr[i] = 1 + i * 2;
  printf("reset to original state:\n");
  printArray(smallArray);
  leftRotate(smallArray, 3);
  printf("after left rotate 3\n");
  printArray(smallArray);
  leftRotate(smallArray, 1);
  printf("after left rotate 1\n");
  printArray(smallArray);
  
  freeArray(&result);
  freeArray(&array);
  freeArray(&smallArray);

  return 0;
}
