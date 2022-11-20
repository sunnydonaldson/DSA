/*********************************************************************************
 * As well as the primitive arrays, there's an array abstract datatype.
 * The array ADT combines a dynamically allocated array, with some common methods
 * such as: display, append, insert, delete, search, get, set, max/min, reverse
 * and shift/rotate.
 *  
*********************************************************************************/
#include "arrayADT.h"

void append(Array *arr, int value)
{
  assert(arr->length + 1 <= arr->size);
  arr->arr[arr->length++] = value;
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

