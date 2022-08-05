/**************************************************************************************
 * In memory, 2d arrays are flattened out to just 1 dimension.
 * So how do we map from the arr[i][j] notation that's convenient for programmers, to
 * this flattened representation?
 * We can either use the row-major or column-major formula.
 * The row-major formula is what's used by the c-compiler,
 * and it's probably the most common in other languages too.
 * 
 * With the row-major mapping, the 2d array is put into memory row by row.
 * The row-major formula for a 2d array: arr[m][n] (m rows x n columns)
 * Given the address of the first element in the array, L0;
 * 
 * The element at arr[i][j] = L0 + (i * n) + j
 * 
 * So for example, if we have a the matrix of size 3 x 2, and L0 = 100
 * [[4, 6],
 * [8, 3],
 * [6, 3]]
 * We can find the address of arr[2][1] with 100 + (3 * 1) + 2
 * 
 * 
 * The other option is column-major mapping.
 * With this option, the 2d array is put into memory column by column
 * 
 * The column major formula for a matrix of a 2d array, arr[m][n], given L0, is:
 * arr[i][j] = L0 + (j * m) + i
 * 
 * Traditionally it's been said that there's no particular advantage to either mapping.
 * Technically they do have the same number of operations, and the user of the array
 * will interact with them in the same way regardless.
 * 
 * However, because of how caching works (By loading data near what's currently being accessed into memory)
 * if you know you're going to be iterating over the data in order, the row-major mapping would be
 * better because the CPU will have already cached the next few elements by the time you come to read them.
 * 
 * These formulas can be generalised to work with N-dimensional arrays.
 * I don't have motivation to do that now.
 *************************************************************************************/
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
  // Doesn't actually do anything the user can see.
  pointerToArrayOfPointers();
  arrayOfPointers();
  array2D();
  return 0;
}