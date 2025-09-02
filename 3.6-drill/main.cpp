#include <algorithm> //for sort
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

// this really needs re-factored as functions, but I'm just trying to get used
// to the environment and tooling


// compute mean and median temps, to demonstrate vectors
int main() {
  std::vector<double> temps;
  std::vector<double> vnum;
  double val;
  double smallest;
  double largest;
  std::string unit;
  char term;
  double conv;
  double sum_{0};

  std::cout << "Enter some temps and then a non-num character then RET.";
  for (double temp; std::cin >> temp;) {
    temps.push_back(temp);
  }

  if (temps.size() == 0) {
    std::cout << "No temps entered; no meaningful averages possible.";
  } else {
    double sum{0};
    for (double x : temps)
      sum += x;
    std::cout << "Ave (mean) temp: " << sum / (double)temps.size() << std::endl;

    std::ranges::sort(temps);
    std::cout << "Median temp: " << temps[temps.size()/2] << std::endl;
  }

  while (true) {
    std::cout << "Enter a double then cm/m/in/ft. Or a | to exit: ";

    if (!(std::cin >> val)) { // read the input, see if it fits in a val
      std::cin.clear(); // remove the err chars then see if the rest is a |
      std::cin >> term;
      if (term == '|') { // if input done, analyse and report
        std::ranges::sort(vnum);
        largest = vnum[0];
        smallest = vnum[0];
        std::cout << "OK. The values in metres: \n";
        for (double d : vnum) {
          std::cout << d << std::endl;
          if (d > largest)
            largest = d;
          if (d < smallest)
            smallest = d;
	  sum_ += d;
        }
        std::cout << "The sum is: " << sum_ << std::endl;
        std::cout << "The largest was: " << largest << std::endl;
        std::cout << "The smallest was: " << smallest << std::endl;
	break;
      } else {
        std::cout
            << "Invalid entry. Enter a double in m/cm/in/ft, or | to exit.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	continue;
      }
    }
    // If not invalid: read, convert, and add to vector
    std::cin >> unit;

    // should really be enums, but the book hasn't covered those yet...
    if (unit == "m")
      conv = 1;
    else if (unit == "cm")
      conv = 0.01;
    else if (unit == "in")
      conv = 0.0254;
    else if (unit == "ft")
      conv = 0.3048;
    if (unit == "m" || unit == "cm" || unit == "in" || unit == "ft") {
      std::cout << "You entered: " << val << ' ' << unit << '\n';
      val *= conv;
      std::cout << "Equiv to " << val << "m\n";
      vnum.push_back(val);
    } else
      std::cout
          << "Invalid unit. Enter a double in m/cm/in/ft, or | to exit.\n";
  }
  return 0;  
}
