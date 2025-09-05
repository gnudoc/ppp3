#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

//********EX 2********//
void print_char_and_int(char c) {
  int c_int{c};
  std::cout << c << ' ' << c_int << std::endl;
}

void print_chars_and_ints(std::string str) {
  std::cout << "The chars and their ascii codes: \n";
  for (char c : str) {
    print_char_and_int(c);
  }
  std::cout << std::endl;
}
////////////////////////

//********EX 3********//
double median(std::vector<double> nums) {
  std::ranges::sort(nums);
  size_t size = nums.size();
  if (size % 2 == 0)
    return (nums[size / 2] + nums[size / 2 - 1]) / 2.0;
  else
    return nums[nums.size() / 2];
  
}
////////////////////////

//********EX 4********//
double total(const std::vector<double>& nums) {
  double sum{0};
  for (double num : nums) {
    sum += num;
  }
  return sum;
}
double smallest(const std::vector<double>& nums) {
  double smallest = nums[0];
  for (double num : nums) {
    if (num < smallest)
      smallest = num;
  }
  return smallest;
}
double largest(const std::vector<double>& nums) {
  double largest = nums[0];
  for (double num : nums) {
    if (num > largest)
      largest = num;
  }
  return largest;
}
double mean(const std::vector<double>& nums) {
  return total(nums) / (double)nums.size();
}
////////////////////////

//********EX 5********//
void guess(int bottom, int top) {
  int new_guess{bottom + (top - bottom) / 2};
  std::cout << "Is your number " << new_guess << "?" << std::endl;
  char response;
  std::cin >> response;

  switch (response) {
  case 'h':
    guess(new_guess + 1, top);
    break;
  case 'c':
    std::cout << "woohoo! Thanks for playing!";
    break;
  case 'l':
    guess(bottom, new_guess - 1);
    break;
  default:
    std::cout << "Please enter h, l or c." << std::endl;
    guess(bottom, top);
    break;
  }
}
////////////////////////


int main() {
  // ex2
  // accept a string and print it one char to a line with its representation as an int
  std::cout << "Enter a string: ";
  std::string str_in;
  std::cin >> str_in;
  print_chars_and_ints(str_in);

  // ex3
  // accept a list of temperatures and give its median
  std::vector<double> temps;
  std::cout << "Enter a list of space-separated doubles then a non-number: ";
  for (double temp; std::cin >> temp;)
    temps.push_back(temp);
  std::cout << "The median is: " << median(temps) << std::endl;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

  // ex4
  // accept a list of distances and give its total, smallest, largest, and mean
  std::vector<double> distances;
  std::cout << "Enter a list of space-separated doubles then a non-number: ";

  for (double dist; std::cin >> dist;)
    distances.push_back(dist);

  std::cout << total(distances) << std::endl;;
  std::cout << smallest(distances) << std::endl;
  std::cout << largest(distances) << std::endl;
  std::cout << mean(distances) << std::endl;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

  // ex5
  int bottom{1};
  int top{100};
  std::cout << "Pick a number between " << bottom << "  and " << top << "." << std::endl;
  std::cout << "When I guess, please respond h for higher, l for lower, c for "
               "correct.";
  guess(bottom, top);

  // ex6
  std::string op_w;
  char op;
  double first{0};
  double second{0};
  double ans{0};
  std::cout << "Please enter a number, RET, a number, RET, a +, -, * or / "
               "character then RET:"
            << std::endl;
  std::cin >> first;
  std::cin >> second;
  std::cin >> op;
  switch (op) {
  case '+':
    op_w = "sum";
    ans = first + second;
    break;
  case '-':
    op_w = "difference";
    ans = first - second;
    break;
  case '*':
    op_w = "product";
    ans = first * second;
    break;
  case '/':
    op_w = "quotient";
    ans = first / second;
    break;
  }
  std::cout << "The " << op_w << " of " << first << " and " << second << " is "
            << ans << "." << std::endl;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

  // ex7
  std::vector<std::string> num_names;
  num_names = {"zero", "one", "two",   "three", "four",
               "five", "six", "seven", "eight", "nine"};

  std::cout << "Enter a number between 0 and 9 and I'll return it as a word."
            << "\n-OR-" << std::endl;
  std::cout << "Enter a number-word between zero and nine and I'll return it "
               "as a number."
            << std::endl;
  
  std::string line;
  int num;

  
  std::getline(std::cin, line);
  std::stringstream ss(line);

  if (ss >> num && ss.eof()) {
    if (num > 0 && num <= 9)
      std::cout << num_names[(size_t)num] << std::endl;
    else
      std::cout << "Number out of range.";
  } else {
    auto it = std::find(num_names.begin(), num_names.end(), line);
    if (it != num_names.end()) {
      auto index = std::distance(num_names.begin(), it);
      std::cout << index << std::endl;
    } else {
      std::cout << "Unexpected input!" << std::endl;
    }
  }
}
