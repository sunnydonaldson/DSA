#include <iostream>

int main() {
  std::cout << "arrays :)" << std::endl;
  int size = 3;
  
  // initialized on stack.
  int arr[3] = {1, 2, 3};

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }

  //for each loop also works
  for (int i: arr) {
    std::cout << i << std::endl;
  }
  return 0;
}