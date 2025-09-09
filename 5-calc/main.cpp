#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <stdexcept>
int main() {
  std::cout << "Please enter an expression in the form: int op int op int and "
               "end with an x (where operator can be + - * or /):\n> ";
  
  int lval{0};
  //char op{0};
  int rval{0};
  if (!(std::cin >> lval)) {
    std::cerr << "Oops. Invalid first value.\n";
    return 1;
  }

  for (char op; std::cin >> op;) {
    if (op == 'x')
      break;

    if (!(std::cin >> rval)) {
      std::cerr << "Oops. Invalid number value.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    switch (op) {
    case '+':
      lval += rval;
      break;
    case '-':
      lval -= rval;
      break;
    case '*':
      lval *= rval;
      break;
    case '/':
      try {
        if (rval == 0) {
	  throw std::runtime_error("Division by zero not allowed!");
        }
	lval /= rval;
      } catch (const std::runtime_error &e) {
	std::cerr << "Exception! " << e.what() << std::endl;
      }
      break;
    default:
      std::cerr << "Invalid operator " << op << ".\n";
      break;
    }
  }
  std::cout << "Result is: " << lval << std::endl;
  return 0;
}
