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
**/

typedef struct LowerTriangularMatrix {
  int *arr;
  size_t size;
} LowerTriangularMatrix;

LowerTriangularMatrix *InstantiateLowerTriangularMatrix(size_t size);
void FreeLowerTriangularMatrix(LowerTriangularMatrix **m);
void PrintLowerTriangularMatrix(LowerTriangularMatrix *m);
int GetLowerTriangularMatrixValue(LowerTriangularMatrix *m, size_t i, size_t j);

#endif
