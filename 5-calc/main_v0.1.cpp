#include <iostream>
#include <ostream>
#include <stdexcept>
int main() {
  std::cout << "Please enter an expression in the form: int op int op int a (where operator can be + - * or /):\n> ";
  int lval{0};
  char op{0};
  int rval{0};
  std::cin >> lval >> op >> rval;

  int res{0};

  switch (op) {
  case '+':
    res = lval + rval;
    break;
  case '-':
    res = lval - rval;
    break;
  case '*':
    res = lval * rval;
    break;
  case '/':
    try {
      if (rval == 0) {
	throw std::runtime_error("Division by zero not allowed!");
      }
      res = lval / rval;
    } catch (const std::runtime_error &e) {
      std::cerr << "Exception! " << e.what() << std::endl;
    }
    break;
  default:
    std::cout << "The operator needs to be +, -, *, /" << std::endl;
  }
  if (res) 
    std::cout << "Answer: " << res << std::endl;
  
}
