#include "symmetric_matrix.h"//

void SetSymmetricValue(LowerTriangularMatrix *m, size_t i, size_t j, int value) {
  if (i < j) {
    size_t tmp = i;
    i = j;
    j = tmp;
  }
  SetLowerTriangularMatrixValue(m, i, j, value);
}

int GetSymmetricValue(LowerTriangularMatrix *m, size_t i, size_t j) {
  if (i < j) {
    size_t tmp = i;
    i = j;
    j = tmp;
  }
  return GetLowerTriangularMatrixValue(m, i, j);
}

void PrintSymmetricMatrix(LowerTriangularMatrix *m) {
  for (int i = 1; i < m->size; i++) {
    for (int j = 1; j < m->size; j++) {
      int value = GetSymmetricValue(m, i, j);
      printf("%d ", value);

      if (value / 10 == 0) {
        printf(" ");
      }
    }
    printf("\n");
  }
}
