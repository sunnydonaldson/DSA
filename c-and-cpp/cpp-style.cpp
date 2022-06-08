#include <iostream>

// The same as the rectangle struct,
// But we're able to group both the state and behaviour together
class Rectangle {
// Members are private by default, No need to be explicit
// private:
  int length;
  int width;

// We want our methods to be public
public:
  // Constructor.
  Rectangle(int length, int width) {
    this->length = length;
    this->width = width;
  }

  int area() {
    return length * width;
  }

  void changeLength(int length) {
    this->length = length;
  }
};

int main() {
  Rectangle r(12, 3);
  std::cout << r.area() << std::endl;
  return 0;
}