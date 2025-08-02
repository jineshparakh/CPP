#include <iostream>

int main() {
  int x = 100;
  // pointers are datatypes that store address
  // of other variables.
  // In this case, px will store address of x
  int* px = &x;

  std::cout << "x is: " << x << std::endl;
  std::cout << "&x is: " << &x << std::endl;
  std::cout << "px is: " << px << std::endl;

  // Retrive the value of type pointer variable points to
  std::cout << "px deferenced is: " << *px << std::endl;

  return 0;
}