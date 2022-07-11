#include <stdlib.h>
#include <assert.h>

typedef struct stack_t {
  int size;
  int index;
  int *arr;
}Stack;

Stack initStack(int size);
void push(Stack *stack, int value);
int pop(Stack *stack);