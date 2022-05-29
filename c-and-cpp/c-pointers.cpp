#include<stdlib.h>

struct Rectangle {
  int width;
  int length;
};

void cppPointers() {
  // Just use the new keyword
  int *pointer = new int[5];
  delete[] pointer;
}
void cPointers() {
  int *p;
  
  // Use malloc to allocate memory on the heap in c
  // Pass the amount of memory we want to allocate
  // Sizeof gets the amount of memory an int takes for example
  //so we've allocated enough space for an array of 5 ints
  // Malloc returns a null pointer, so we have to cast it
  p = (int *) malloc(5* sizeof(int));
  free(p);
}

void references() {
  // References are just aliases for variables
  // They only exist in C++, not c
  int a = 5;
  // Use & when declaring a reference
  int &myRef = a;
  
}

void pointerToStruct() {
  // c-style memory allocation
  struct Rectangle *cPointer;
  cPointer = (struct Rectangle *) malloc(sizeof(struct Rectangle));
  cPointer->length = 10;
  cPointer->width = 20;

  // cpp-style
  struct Rectangle *cppPointer = new struct Rectangle();
  cppPointer->length = 20;
  cppPointer->width = 199;
  // Cleaning up
  free(cPointer);
  delete cppPointer;
}

int main() {
  cPointers();
  cppPointers();
  references();
  pointerToStruct();
  return 0;
}