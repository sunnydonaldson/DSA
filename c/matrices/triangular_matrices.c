#include "triangular_matrices.h"

LowerTriangularMatrix *InstantiateLowerTriangularMatrix(size_t size) {
  LowerTriangularMatrix *m = malloc(sizeof(LowerTriangularMatrix));
  if (!m) {
    fprintf(stderr, "Memory allocation for LowerTriangularMatrix of size %zu failed!\n", size);
  }

  m->size = size;
  m->arr = malloc((size * (size -1)) / 2 * sizeof(int));
  if (!m->arr) {
    fprintf(stderr, "Memory allocation of array failed!\n");
  }

  return m;
}

void FreeLowerTriangularMatrix(LowerTriangularMatrix **m) {
  free((*m)->arr);
  free(*m);
}

void PrintLowerTriangularMatrix(LowerTriangularMatrix *m) {
  for (size_t i = 1; i < m->size; i++) {
    for (size_t j = 1; j < m->size; j++) {
      int value = GetLowerTriangularMatrixValue(m, i, j);
      printf("%d ", value);
      if (value / 10 == 0) {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int GetLowerTriangularMatrixValue(LowerTriangularMatrix *m, size_t i, size_t j) {
  assert(i < m->size && j < m->size);

  if (i < j) {
    return 0;
  }

  return m->arr[(i*(i-1) / 2) + (j - 1)];
  
}
