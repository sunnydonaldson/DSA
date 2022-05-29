#include<iostream>

// defining a struct
struct Rectangle {
  int length;
  int width;
};

int main() {
  // Initialized on the stack
  struct Rectangle my_rectangle;
  my_rectangle.length = 4;
  my_rectangle.width = 5;
  return 0;
}