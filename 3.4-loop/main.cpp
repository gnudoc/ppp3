#include <iostream>
int square(int n) { return n * n; }

int squ(int n) {
  int s{0};
  for (int i = 0; i < n; ++i)
    s += n;
  return s;
}

int main() {
  int num1{0};
  while (num1 < 100) {
    std::cout << num1 << '\t' << square(num1) << '\n';
    ++num1;
  }

  for (int num2{0}; num2 < 100; ++num2)
    std::cout << num2 << "\t\t" << square(num2) << '\n';

  for (int num3{0}; num3 < 100; num3 += 2)
    std::cout << num3 << "\t\t\t" << square(num3) << '\n';

  for (int num4{0}; num4 < 1000; ++num4)
    std::cout << num4 << '\t' << squ(num4) << '\n';
    
  return 0;
}
