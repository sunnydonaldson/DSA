#ifndef triangular_matrices_h
#define triangular_matrices_h
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
*****************************lower triangular matrix****************************
* For a matrix to be a lower triangular matrix, every element at [i][j]
* where i >= j must be non-zero.
* Conversely, every element at [i][j] where j > i must be 0;
*
*  j 1 2 3 4 5 
* i  ---------
* 1| 1 0 0 0 0
* 2| 2 3 0 0 0
* 3| 3 6 8 0 0 
* 4| 1 4 7 8 0
* 5| 2 5 7 9 1
* 
*  j 1 2 3 4 5 
* i  ---------
* 1|
* 2|
* 3|
* 4|
* 5|
* 
* There's no need to waste space by storing all the 0s, when we know that everything where j > i is 0.
* We can just use a 1d array to store all the non-zero values, and use a formula to look them up.
*
* The lower triangular matrix above can be represented like:
* [1, 2, 3, 3, 6, 8, 1, 4, 7, 8, 2, 5, 7, 9, 1]
*
* The size of this array can be found by calculating the n + (n-1), + (n-2), ..., 0
* There's a cool trick to do this: size = n * (n + 1)  / 2
* 
* We can look up a value in this 1d array by using the formula:
*   (i * (i -1) / 2) + ( j - 1)
* The first term finds the correct row, and the second term finds the correct column.
*
**/

typedef struct LowerTriangularMatrix {
  int *arr;
  size_t size;
} LowerTriangularMatrix;

LowerTriangularMatrix *InstantiateLowerTriangularMatrix(size_t size);
void FreeLowerTriangularMatrix(LowerTriangularMatrix **m);
void PrintLowerTriangularMatrix(LowerTriangularMatrix *m);
int GetLowerTriangularMatrixValue(LowerTriangularMatrix *m, size_t i, size_t j);
void SetLowerTriangularMatrixValue(LowerTriangularMatrix *m, size_t i, size_t j, int value);

#endif
