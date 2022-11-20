#ifndef arrayADT_h
#define arrayADT_h

#ifndef TRUE
  #define TRUE 1
#endif
#ifndef FAlSE
  #define FALSE 0
#endif

#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Side note
// typedef struct Array Array does the same as above
// it might make it clearer how typedef works.
typedef struct Array {
  int *arr;
  size_t size;
  size_t length;
} Array;

void fillArray(Array *arr, int value);
Array *instantiate(size_t size);
void printArray(Array *arr);
void append(Array *arr, int value);
void freeArray(Array **arr);
int get(Array *arr, size_t idx);
void set(Array *arr, size_t idx, int value);
int *search(Array *arr, int key);
int binarySearch(Array *arr, int key);
int *transposeSearch(Array *arr, int key);
int *moveToHeadSearch(Array *arr, int key);
void insert(Array *arr, size_t idx, int value);
void sortedInsert(Array *arr, int value);
Array *mergeArrays(Array *a, Array *b);
int isSorted(Array *a);
int delete(Array *arr, size_t idx);
int max(Array *arr);
int min(Array *arr);
int sum(Array *arr);
double avg(Array *arr);
void reverse(Array *arr);
void leftShift(Array *arr, int numToShift);
void leftRotate(Array *arr, int numToRotate);
Array *arrayIntersection(Array *a, Array *b);
Array *arrayUnion(Array *a, Array *b);

#endif
