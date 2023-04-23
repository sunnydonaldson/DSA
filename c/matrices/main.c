#include "diagonal_matrix.h"
#include "symmetric_matrix.h"
#include "triangular_matrices.h"

void DiagonalMatrices() {
  DiagonalMatrix *matrix = InstantiateDiagonalMatrix(10);
  SetDiagonal(12, matrix, 0);
  printf("get diagonal at 0: %d\n", GetDiagonal(matrix, 0));
  DisplayDiagonalMatrix(matrix);
}

void TriangularMatrices() {
  LowerTriangularMatrix *m = InstantiateLowerTriangularMatrix(10);
  for (int i = 0; i < 10*(10 -1) / 2; i++) {
    m->arr[i] = i + 1;
  }
  printf("\n");
  PrintLowerTriangularMatrix(m);

  printf("\n");
  SetLowerTriangularMatrixValue(m, 1, 1, 20);
  PrintLowerTriangularMatrix(m);

  FreeLowerTriangularMatrix(&m);
}

void SymmetricMatrices() {
  LowerTriangularMatrix *m = InstantiateLowerTriangularMatrix(10);
  for (int i = 0; i < 10*(10 -1) / 2; i++) {
    m->arr[i] = i + 1;
  }
  printf("\n");
  PrintSymmetricMatrix(m);

  printf("\n");
  SetSymmetricValue(m, 4, 5, 22);
  PrintSymmetricMatrix(m);

  FreeLowerTriangularMatrix(&m);
}

int main() {
  DiagonalMatrices();
  TriangularMatrices();
  SymmetricMatrices();
  return 0;
}
