#include<iostream>

// defining a struct
struct Rectangle {
  int length;
  int width;
};

struct Octagon {
  int lengths[8];
};

// By default, structs are passed by value.
int calcArea(struct Rectangle r) {
  std::cout << "original length (as passed to area function): " << r.length << std::endl;

  // Since structs are passed by value, we can modify the one we get passed
  // Without worrying about altering the original
  r.length = 1000;
  std::cout << "new length (altered inside area function): " << r.length << std::endl;
  return r.length * r.width;
}

int calcAreaPassByReference(struct Rectangle &r) {
  return r.length * r.width;
}

int passStructByValueWithArrayMember(struct Octagon shape) {
  // Arrays can normally only be passed by address
  // But because the struct is being passed by value, a special exception has to be made
  // So array members of structs get passed by value, if the struct gets passed by value.
  shape.lengths[0] = 1000;
  std::cout << "changing the lengths inside the pass by value function: " << shape.lengths[0] << std::endl;
}

int passStructByReferenceWithArrayMember(struct Octagon &shape) {
  // In this case, since the struct was passed by reference, the array won't be copied.
  // It'll be passed as a pointer to the first element of the array (like normal)
  std::cout << "inside a method where the struct was passed by reference" << std::endl;
  shape.lengths[0] = 5000;
  std::cout << "modifying the shape's array inside the method" << shape.lengths[0] << std::endl;
}


int main() {
  // Initialized on the stack
  struct Rectangle my_rectangle;
  my_rectangle.length = 4;
  my_rectangle.width = 5;
  int area = calcArea(my_rectangle);
  std::cout << "the length in main after calling area function: " << my_rectangle.length << std::endl;
  std::cout << "and the area " << area << std::endl;
  calcAreaPassByReference(my_rectangle);
  struct Octagon shape = {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << "My Shape struct has an array member: " << std::endl;
  std::cout << shape.lengths[0] << std::endl;
  passStructByValueWithArrayMember(shape);
  std::cout << "the original shape, after running the function: " << shape.lengths[0] << std::endl;
  passStructByReferenceWithArrayMember(shape);
  std::cout << "lengths outside the function again: " << shape.lengths[0] << std::endl;
  
  return 0;
}