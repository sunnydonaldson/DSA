#include "arrayADT.h"

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
