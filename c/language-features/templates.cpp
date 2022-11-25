#include <iostream>


template<class T> // Defines a template class
// runs from the opening brace, to the closing brace.
class Numeracy {
private://Private by default, doesn't hurt to be explicit though
  T a;
  T b;

public:
  Numeracy(T, T);
  T add() {
    return a + b;
  }

  // Since the body of this method is defined inside the class,
  // We don't need to mark it explicitly as a template method.
  T sub() {
    return a - b;
  }
};

// Because we're writing this function outside of the template class (event though it's still a member)
// We need to define it as a template method
// Whenever we use the classname, we should pass a template parameter, which is why need <T> here.
template<class T>
Numeracy<T>::Numeracy(T a, T b) {
  this->a = a;
  this->b = b;
}

int main() {
  Numeracy<int> n(12, 20);
  std::cout << "Adding with integers: " << n.add() << std::endl;
  Numeracy<float> f(12.6, 30.3);
  std::cout << "Adding with floats: " << f.add() << std::endl;
  return 0;
}