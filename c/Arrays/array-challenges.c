#include "./Array-ADT/arrayADT.h"

void findMissingElementsFromSequence(Array *sequence)
{
    assert(sequence->length >= 2);
    int expectedDifference = 1;
    for (size_t i = 0; i < sequence->length -1; i++) {
        while (sequence->arr[i] + expectedDifference != sequence->arr[i +1])
            printf("Missing %d\n", sequence->arr[i] + expectedDifference++);
        expectedDifference = 1;
    }
}
int main()
{
    Array *sequence = instantiate(10);
    for (int i = 0; i < sequence->size -2; i++) {
        sequence->arr[i] = i + 1;
    }
    sequence->arr[sequence->size -2] = 20;
    sequence->arr[sequence->size -1] = 21;
    sequence->length = sequence->size;
    findSingleMissingElementFromSequence(sequence);
    freeArray(&sequence);

    return 0;
}