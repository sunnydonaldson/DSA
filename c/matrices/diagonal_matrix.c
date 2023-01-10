#include "diagonal_matrix.h"
#include <assert.h>

//  A diagonal matrix is a matrix where all elements that aren't at position [i][j] (where i == j) are 0.
//  The elements on the diagonal, can be non-zero, but they could also be zero.
// 1 0 0 0
// 0 3 0 0
// 0 0 5 0
// 0 0 0 9

DiagonalMatrix *InstantiateDiagonalMatrix(size_t size)
{
  DiagonalMatrix *m = malloc(sizeof(DiagonalMatrix));
  m->arr = malloc(sizeof(int) * size);
  m->size = size;
  return m;
}

void SetDiagonal(int value, DiagonalMatrix *m, int index)
{
  assert(index >= 0 && index < m->size);
  m->arr[index] = value;
}

int GetDiagonal(DiagonalMatrix *m, int index)
{
  assert(index >= 0 && index < m->size);
  return m->arr[index];
}
