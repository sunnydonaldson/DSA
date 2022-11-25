#ifndef iohelper_h
#define iohelper_h

#include "stdio.h"
#include "stdlib.h"

int *getUserInts(int numInts);
int getUserInt();
void printIntArray(int *arr, int size);
void print2DIntArray(int **arr, int rows, int cols);

#endif


