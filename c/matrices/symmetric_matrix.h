#ifndef symmetric_matrix_h
#define symmetric_matrix_h

#include <stdlib.h>
#include "triangular_matrices.h"

void SetSymmetricValue(LowerTriangularMatrix *m, size_t i, size_t j, int value);
int GetSymmetricValue(LowerTriangularMatrix *m, size_t i, size_t j);
void PrintSymmetricMatrix(LowerTriangularMatrix *m);

#endif

/*******************************************************************************
An example of a symmetric matrix.

1 2 3 4
2 9 7 6
3 7 4 8
4 6 8 5

A matrix is symmetrical if it's equal to it's transpose.


A key characteristic is: matrix[i][j] == matrix[j][i]
This means we can use either a lower, or upper triangular matrix.
But instead of returning 0 for cases where j > i, we return m[j][i]
(for lower triangular matrix).

*******************************************************************************/
