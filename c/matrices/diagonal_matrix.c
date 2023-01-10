#include "diagonal_matrix.h"
#include <assert.h>

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
