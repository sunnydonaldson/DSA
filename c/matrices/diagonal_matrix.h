#ifndef diagonal_matrix_h
#define diagonal_matrix_h

typedef struct DiagonalMatrix {
  int size;
  int arr[];
} DiagonalMatrix;

void SetDiagonal(int value, DiagonalMatrix *m, int index);
int GetDiagonal(DiagonalMatrix *m, int index);

#endif
