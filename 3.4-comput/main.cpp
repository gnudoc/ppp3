#include <iostream>
int main() {
  
  constexpr double yen_to_dol {0.0069};
  constexpr double kro_to_dol {0.095};
  constexpr double pou_to_dol {1.3};
  constexpr double fra_to_dol{1.17};

  double amount{0};
  char curr{'a'};

  std::cout << "Please enter an amount followed by [y/k/p/f] for the currency "
               "you want to convert from: ";
  std::cin >> amount >> curr;

  switch (curr) {
  case 'y':
    std::cout << amount << "YEN = " << amount * yen_to_dol << "USD.\n";
    break;
  case 'k':
    std::cout << amount << "KRO = " << amount * kro_to_dol << "USD.\n";
    break;
  case 'p':
    std::cout << amount << "GBP = " << amount * pou_to_dol << "USD.\n";
    break;
  case 'f':
    std::cout << amount << "FRA = " << amount * fra_to_dol << "USD.\n";
    break;
  default:
    std::cout << "Not sure what you said there. Sorry.\n";
    break;
  }

  return 0;
}
