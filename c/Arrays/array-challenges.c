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

    return 0;
}
