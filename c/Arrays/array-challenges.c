#include "./Array-ADT/arrayADT.h"

void findMissingElementsFromSequence(Array *sequence)
{
    assert(sequence->length >= 2);
    printf("find missing elements from ordered sequence:\n");
    int expectedDifference = 1;
    for (size_t i = 0; i < sequence->length -1; i++) {
        while (sequence->arr[i] + expectedDifference != sequence->arr[i +1])
            printf("Missing %d\n", sequence->arr[i] + expectedDifference++);
        expectedDifference = 1;
    }
}

void findMissingElementsUnorderedSequence(Array *sequence)
{
  printf("find missing element from unordered sequence\n");
  // This technique is essentially hashing.
  // We need an index in our "hash table" for every number, so find the boundaries.
  int largest = max(sequence);
  Array *bitset = instantiate(largest);
  // FALSE (0) for numbers that we haven't found in the sequence
  fillArray(bitset, FALSE);
  
  for (size_t i = 0; i < sequence->length; i++)
    bitset->arr[sequence->arr[i]] = TRUE;

  int smallest = min(sequence);
  for (size_t i = smallest; i < bitset->length; i++)
    if (bitset->arr[i] == FALSE)
        printf("%zu not in sequence\n", i);
  freeArray(&bitset);
}

void findDuplicatesInSortedArray(Array *array)
{
    printf("\nfind duplicates in sorted array\n");
    assert(array->length >= 1);
    size_t j = 0;
    for (size_t i = 0; i < array->length -1; i++) {
        if (array->arr[i] == array->arr[i + 1]) {
            j = i + 1;
            while (array->arr[i] == array->arr[j]) j++;
            printf("%d repeated %zu times\n", array->arr[i], j - i);
            i = j - 1;
        }
    }
}

void findDuplicatesInUnsortedArray(Array *input)
{
    assert(input->length >= 1);
    printf("\nfind duplicates in un-sorted array.\n");
    Array *table = instantiate(max(input) +1);
    fillArray(table, 0);

    for (size_t i = 0; i < input->length; i++)
        table->arr[input->arr[i]]++;
    for (int i = min(input); i < table->length; i++)
        if (table->arr[i] > 1)
            printf("%d appeared %d times\n", i, table->arr[i]);
    freeArray(&table);
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
    findMissingElementsFromSequence(sequence);
    findMissingElementsUnorderedSequence(sequence);
    freeArray(&sequence);

    Array *sortedWithDuplicates = instantiate(10);
    fillArray(sortedWithDuplicates, 3);
    for (int i = 5; i < sortedWithDuplicates->size; i++) {
        sortedWithDuplicates->arr[i] = i;
    }
    sortedWithDuplicates->arr[9] = 8;
    printArray(sortedWithDuplicates);
    findDuplicatesInSortedArray(sortedWithDuplicates);
    freeArray(&sortedWithDuplicates);

    Array *unsortedWithDuplicates = instantiate(10);
    fillArray(unsortedWithDuplicates, 4);
    unsortedWithDuplicates->arr[0] = 8;
    unsortedWithDuplicates->arr[1] = 9;
    unsortedWithDuplicates->arr[5] = 9;
    unsortedWithDuplicates->arr[6] = 8;
    unsortedWithDuplicates->arr[7] = 7;

    findDuplicatesInUnsortedArray(unsortedWithDuplicates);
    freeArray(&unsortedWithDuplicates);
    return 0;
}
