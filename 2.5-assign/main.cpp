#include <iostream>
#include <string>
int main() {

  int i{0};
  std::string prev = "";
  std::string current = "";
  while (std::cin >> current) {
    ++i;
    if (prev == current)
      std::cout << "Word #" << i << " (" << current << ") was repeated"
                << std::endl;
    prev = current;
  }
  return 0;
}
