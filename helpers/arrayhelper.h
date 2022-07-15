#ifndef arrayhelper_h
#define arrayhelper_h

#include "stdlib.h"

int *makeIntArray(int);
int *fillValues(int *arr, int size, int value);
void copyInts(int *source, int *destination, int sourceSize);

#endif