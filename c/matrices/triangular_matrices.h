#ifndef triangular_matrices_h
#define triangular_matrices_h
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LowerTriangularMatrix {
  int *arr;
  size_t size;
} LowerTriangularMatrix;

LowerTriangularMatrix *InstantiateLowerTriangularMatrix(size_t size);
void FreeLowerTriangularMatrix(LowerTriangularMatrix **m);

#endif
