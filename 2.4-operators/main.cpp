#include <cmath>
#include <iostream>
int main() {
  std::cout << "Enter a double: " << std::endl;
  double d{0};
  std::cin >> d;

  std::cout << "d == " << d << "\nd+1 == " << d + 1 << "\n3*d == " << 3 * d
            << "\nhalf of d == " << d / 2
            << "\nand square root of d == " << sqrt(d) << std::endl;

  std::cout << "Now enter an int: " << std::endl;
  int i{0};
  std::cin >> i;

  std::cout << "i == " << i << "\ni+1 == " << i + 1 << "\n3*i == " << 3 * i
       << "\ni squared == " << i * i << "\ni mod 2 == " << i % 2
       << "\nand square root of i == " << sqrt(i) << std::endl;

  std::cout << "Now please enter your first and last names: " << std::endl;
  std::string first;
  std::string last;
  std::cin >> first >> last;
  std::string name = first + ' ' + last;

  std::cout << "Hello, " << name << '\n';

  if (first == last)
      std::cout << "Your first and last names are the same!" << std::endl;
  if (first < last)
      std::cout << first << " is alphabetically before " << last << std::endl;
  if (first > last)
      std::cout << first << " is alphabetically after " << last << std::endl;

  return 0;
      
}
