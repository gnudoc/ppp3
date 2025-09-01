#include <iostream>
int main() {

  std::cout << "Enter your name: " << std::endl;
  std::string first_name;
  std::cin >> first_name;
  std::cout << "Hello, " << first_name << "!" << std::endl;
  return 0;
}
