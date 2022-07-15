#include "../helpers/iohelper.h"

void array2D()
{
  // Arrays with 5 rows and 10 columns
  // In this example, everything is on the stack
  int rows = 3;
  int cols = 4;
  int example[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  print2DIntArray(example, rows, cols);
}

void arrayOfPointers()
{
  // Another way to represent a 2DArray is with an array of pointers
  // In this case, there's an array of 3 pointers to other arrays
  // The array of pointers is inside the stack,
  // But the arrays those pointers are pointing to are on the heap.
  int rows = 3;
  int cols = 4;
  int *example[3];
  
  for (int i = 0; i < rows; i++) {
    example[i] = malloc(cols * sizeof(int));
  }
  print2dArray(example, rows, cols);

}

void pointerToArrayOfPointers()
{
  // The 3rd way to represent a 2D array, is with both the main array and sub arrays allocated on the heap.
  int rows = 3;
  int cols = 4;
  int **example = malloc(rows * sizeof(int));
  for (int i = 0; i < cols; i++) {
    example[i] = malloc(cols * sizeof(int));
  }
  
}

int main()
{
  return 0;
}