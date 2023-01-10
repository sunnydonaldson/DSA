#ifndef diagonal_matrix_h
#define diagonal_matrix_h
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct DiagonalMatrix {
  int size;
  int *arr;
} DiagonalMatrix;

DiagonalMatrix *InstantiateDiagonalMatrix(size_t size);
void SetDiagonal(int value, DiagonalMatrix *m, int index);
int GetDiagonal(DiagonalMatrix *m, int index);
void DisplayDiagonalMatrix(DiagonalMatrix *m);

#endif
