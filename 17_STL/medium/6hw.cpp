#include <iostream>
#include <string>

int main() {
  std::cout << "Enter your string: ";
  std::string str;
  std::cin >> str;

  for (int i = 1; i < str.length();) {
    if (str[i] == str[i - 1]) {
      str.erase(i - 1, 2);
      if (i > 1)
        i--;
    } else {
      i++;
    }
  }

  std::cout << "Output: " << str << "\n";
  return 0;
}
