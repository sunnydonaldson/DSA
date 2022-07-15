/************************************************************************
 * In memory, a 2D array is represented like a 1D array.
 * In other words, it's flattened into one dimension.
 ***********************************************************************/
#include "iohelper.h"
int getUserInt()
{
  int result;
  printf("Please enter an integer:\n>");
  scanf("%d", &result);
  return result;
}

int *getUserInts(int numInts)
{
  // remember to free this later
  int *result = (int *) malloc(sizeof(int) * numInts);
  for (int i = 0; i < numInts; i++) {
    result[i] = getUserInt();
  }
  return result;
}

void printIntArray(int *arr, int size)
{
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

void printStack2DIntArray(int *arr, int rows, int cols)
{
  for (int rowIdx = 0; rowIdx < rows; rowIdx++) {
    for (int colIdx = 0; colIdx < cols; colIdx++) {
      printf("[%d][%d] = %d\n", rowIdx, colIdx, (arr[rowIdx])[colIdx]);
    }
  }
}

void printHeap2DIntArray(int **arr, int rows, int cols) {
  for (int rowIdx = 0; rowIdx < rows; rowIdx++) {
    for (int colIdx = 0; colIdx < cols; colIdx++) {
      printf("[%d][%d] = %d\n", rowIdx, colIdx, arr[rowIdx][colIdx]);
    }
  }

}