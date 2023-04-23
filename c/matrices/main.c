#include "diagonal_matrix.h"
#include "triangular_matrices.h"

int main() {
  DiagonalMatrix *matrix = InstantiateDiagonalMatrix(10);
  SetDiagonal(12, matrix, 0);
  printf("get diagonal at 0: %d\n", GetDiagonal(matrix, 0));
  DisplayDiagonalMatrix(matrix);

  LowerTriangularMatrix *lower = InstantiateLowerTriangularMatrix(10);
  for (int i = 0; i < 10*(10 -1) / 2; i++) {
    lower->arr[i] = i + 1;
  }
  printf("\n");

  PrintLowerTriangularMatrix(lower);

  printf("\n");
  SetLowerTriangularMatrixValue(lower, 1, 1, 20);
  PrintLowerTriangularMatrix(lower);

  FreeLowerTriangularMatrix(&lower);
  return 0;
}
