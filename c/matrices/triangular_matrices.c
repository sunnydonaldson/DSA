#include "triangular_matrices.h"

LowerTriangularMatrix *InstantiateLowerTriangularMatrix(size_t size)
{
  LowerTriangularMatrix *m = malloc(sizeof(LowerTriangularMatrix));
  if (!m) {
    fprintf(stderr, "Memory allocation for LowerTriangularMatrix of size %zu failed!\n", size);
  }

  m->size = size;
  m->arr = malloc(size * sizeof(int));
  if (!m->arr) {
    fprintf(stderr, "Memory allocation of array failed!\n");
  }

  return m;
}

void FreeLowerTriangularMatrix(LowerTriangularMatrix **m)
{
  free((*m)->arr);
  free(*m);
}
