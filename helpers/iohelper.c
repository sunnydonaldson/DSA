#include "iohelper.h"
int getUserInt() {
  int result;
  printf("Please enter an integer:\n>");
  scanf("%d", &result);
  return result;
}

int *getUserInts(int numInts) {
  // remember to free this later
  int *result = (int *) malloc(sizeof(int) * numInts);
  for (int i = 0; i < numInts; i++) {
    result[i] = getUserInt();
  }
  return result;
}

void printIntArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}