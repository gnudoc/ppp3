#include <iostream>

int main() {
  std::cout << "Enter 1st name, 2nd name, and age:" << std::endl;
  std::string first_name = "??";
  std::string second_name = "??";
  float age_years = -1.0;
  float age_months = -1.0;
  std::cin >> first_name >> second_name >> age_years;
  age_months = age_years * 12;
  std::cout << "Hello, " << first_name << " " << second_name << " (aged "
            << age_months << " months)" << std::endl;
  return 0;
}
