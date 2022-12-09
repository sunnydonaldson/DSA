#include "../helpers/iohelper.h"
#include "../helpers/arrayhelper.h"
#include <string.h>

void howToIncreaseSize() {
    printf("for the original size, ");
    int size = getUserInt();

    printf("for the larger size, ");
    int newSize = getUserInt();

    // We can't change the size of static arrays
    // But we can allocate a neww array of any size we want, and copy over the original
    int *original = malloc(size * sizeof(int));
    fillValues(original, size, 4);

    int *larger = malloc(newSize * sizeof(int));

    for (int i = 0; i < size; i++) {
        larger[i] = original[i];
        printf("larger[%d] is now %d.\n", i, larger[i]);
    }

    for (int i = size; i < newSize; i++) {
        printf("extra space: larger[%d] is %d\n", i, larger[i]);
    }

    // You can also use memcpy
    printf("Another array size for an example");
    int otherSize = getUserInt();
    printf("For a bigger array to copy to ");
    int otherBigSize = getUserInt();
    int *otherArr = malloc(otherSize * sizeof(int));
    fillValues(otherArr, otherSize, 8);
    int *otherBigArr = malloc(otherBigSize * sizeof(int));

    memcpy(otherBigArr, otherArr, otherBigSize * sizeof(int));

    printIntArray(otherBigArr, otherBigSize);

    free(original);
    free(larger);
    free(otherArr);
    free(otherBigArr);    
}

void dynamicArrays() {
    int originalSize = getUserInt();
    int *original = malloc(originalSize * sizeof(int));
    fillValues(original, originalSize, 4);

    printf("Before resize \n");
    printIntArray(original, originalSize);


    printf("For the next value in the array, ");
    int nextValue = getUserInt();

    // It's convention to double size of array when re-allocating
    int newSize = originalSize * 2;
    int *temp = malloc(newSize * sizeof(int));
    copyInts(original, temp, originalSize);

    free(original); // Discard the array that's too small
    original = temp;
    temp = NULL;
    // The size of the original array is now a valid index
    // We can insert the extra value that wouldn't fit before here.
    int nextEmpty = originalSize;

    original[nextEmpty] = nextValue;
    printf("after resize\n");
    printIntArray(original, newSize);
    free(original);
}

int main() {
    // Allocate an array on the heap
    int size = getUserInt();
    int *array = malloc(size * sizeof(int));
    free(array);
    dynamicArrays();
    // howToIncreaseSize();
    
    return 0;
}