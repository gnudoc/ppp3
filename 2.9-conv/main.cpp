#include <iostream>
int main() {

  char c{'x'};
  int i1{c}; // promoting (widening) a char to int
  int i2{i1 + 10000};
  double d{i2 + 7.3}; // promoting (widening) an int to a double
  std::cout << "c = " << c << '\n'
            << "i1 = " << i1 << '\n'
            << "i2 = " << i2 << '\n'
            << "d = " << d << std::endl;
  return 0;
}
