#include <iostream>
#include <stack>

int reverse_num(int num) {
  int rev{};
  std::stack<int> s;
  while (num) {
    s.push(num % 10);
    num /= 10;
  }

  int f{1};
  while (!s.empty()) {
    rev += s.top() * f;
    s.pop();
    f *= 10;
  }
  return rev;
}

int main() {
  std::cout << "Enter number: \n";
  int num;
  std::cin >> num;

  std::cout << "Reversed: " << reverse_num(num) << std::endl;
  return 0;
}
