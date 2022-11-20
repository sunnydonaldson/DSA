
#include "arrayADT.h"

int main() {
  Array *array = instantiate(32);
  printArray(array);
  append(array, 12);
  append(array, 14);
  printArray(array);

  int *maybe12 = search(array, 12);
  printf("Array contains 12? %d\n", maybe12 != NULL);
  printf("address: %p, value: %d\n", maybe12, *maybe12);
  int *maybe99 = search(array, 99);
  printf("Array contains 99? %d\n", maybe99 != NULL);

  printArray(array);
  printf("insert 44 at index 2\n");
  insert(array, 2, 44);
  printArray(array);
  printf("insert 22 at index 1\n");
  insert(array, 1, 22);
  printArray(array);
  printf("insert 434 at index 0\n");
  insert(array, 0, 434);
  printArray(array);
  // printf("insert at 100 (should fail)");
  // insert(array, 100, 99);

  printf("delete at index 0\n");
  delete(array, 0);
  printArray(array);

  printf("delete at index 2\n");
  delete(array, 2);
  printArray(array);
  // printf("delete at 99 (should fail)\n");
  printf("\n search with transposition\n");
  transposeSearch(array, 44);
  printArray(array);

  printf("\n search with move to head\n");
  moveToHeadSearch(array, 22);
  printArray(array);

  Array *orderedArray = instantiate(63);
  // -2 to leave space to exercise sortedInsert + insert
  int i;
  for (i = 0; i < orderedArray->size -1; i++)
    orderedArray->arr[i] = i * 2;
  orderedArray->length = i;
  printf("ordered array\n");
  printArray(orderedArray);
  int numToInsert = 19;
  printf("Insert %d into ordered array.\n", numToInsert);
  sortedInsert(orderedArray, numToInsert);
  printArray(orderedArray);

  printf("\nbinary search: %d\n", binarySearch(orderedArray, 10));
  printf("min of array: %d\n", min(orderedArray));
  printf("max of array: %d\n", max(orderedArray));
  printf("sum of array: %d\n", sum(orderedArray));
  printf("average of array: %f\n", avg(orderedArray));

  printf("\n Other sorted array: \n");
  Array *otherOrderedArray = instantiate(5);
  for (i = 0; i < 5; i++)
    otherOrderedArray->arr[i] = i * 3 + 1;
  otherOrderedArray->length = 5;
  printArray(otherOrderedArray);
  printf("\nMerge sorted arrays:\n");
  Array *result = mergeArrays(orderedArray, otherOrderedArray);
  printArray(result);
  printf("merged array isSorted? %d\n", isSorted(result));



  reverse(result);
  printf("reversed array:\n");
  printArray(result);


  Array *smallArray = instantiate(5);
  for (int i = 0; i < smallArray->size -2; i++)
    smallArray->arr[i] = 1 + i * 2;
  smallArray->length = smallArray->size;
  printf("small array \n");
  printArray(smallArray);
  leftShift(smallArray, 2);
  printf("after shifting left by 2: \n");
  printArray(smallArray);
  leftShift(smallArray, 5);
  printf("after shifting left by 5\n");
  printArray(smallArray);

  for (int i = 0; i < smallArray->size; i++)
    smallArray->arr[i] = 1 + i * 2;
  printf("reset to original state:\n");
  printArray(smallArray);
  leftRotate(smallArray, 3);
  printf("after left rotate 3\n");
  printArray(smallArray);
  leftRotate(smallArray, 1);
  printf("after left rotate 1\n");
  printArray(smallArray);

  Array *intersectionResult = arrayIntersection(array, result);
  printf("Intersection of 'result' and 'array': \n");
  printArray(intersectionResult);

  Array *unionResult = arrayUnion(array, result);
  printf("Union of 'array' and 'result': \n");
  printArray(unionResult);
  
  freeArray(&result);
  freeArray(&array);
  freeArray(&smallArray);
  freeArray(&intersectionResult);
  freeArray(&unionResult);

  return 0;
}
