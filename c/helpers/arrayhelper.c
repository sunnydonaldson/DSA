#include "arrayhelper.h"


int *makeIntArray(int size) {
  int *arr = malloc(size * sizeof(int));
  fillValues(arr, size, 0);
  return arr;
}

int  *fillValues(int *arr, int size, int value) {
  for (int i = 0; i < size; i++) {
    arr[i] = value;
  }
  return arr;
}

void copyInts(int *source, int *dest, int sourceSize) {
  for (int i = 0; i < sourceSize; i++)
    dest[i] = source[i];
}