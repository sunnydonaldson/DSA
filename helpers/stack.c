#include "./stack.h"

Stack initStack(int size)
{
  Stack stack;
  stack.size = size;
  stack.index = 0;
  stack.arr = malloc(size * sizeof(int));
  return stack;
}

void push(Stack *stack, int value) {
  assert(stack->index +1 < stack->size);
  stack->index += 1;
  stack->arr[stack->index] = value;
}

int pop(Stack *stack) {
  int result = stack->arr[stack->index];
  assert(stack->index -1 >= 0);
  stack->index--;
  return result;
}