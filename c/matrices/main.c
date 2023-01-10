#include "diagonal_matrix.h"
#include "triangular_matrices.h"

int main()
{
  DiagonalMatrix *matrix = InstantiateDiagonalMatrix(10);
  SetDiagonal(12, matrix, 0);
  printf("get diagonal at 0: %d\n", GetDiagonal(matrix, 0));
  DisplayDiagonalMatrix(matrix);

  LowerTriangularMatrix *lower = InstantiateLowerTriangularMatrix(10);
  FreeLowerTriangularMatrix(&lower);
  return 0;
}
