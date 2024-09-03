#include <iostream>
#include <map>
#include <string>

bool is_prefix(std::string pre, std::string str) {
  for (int i = 0; i < (int) pre.size(); i++) {
    if (pre[i] != str[i])
      return false;
  }
  return true;
}

int main() {
  std::cout << "Number of strings: \n";
  int num_strs;
  std::cin >> num_strs;

  std::map<int, std::string> mp;
  for (int i = 0; i < num_strs; i++) {
    std::cin >> mp[i];
  }

  std::cout << "Number of queries: \n";
  int num_quaries;
  std::cin >> num_quaries;
  std::string quary;
  for (int i = 0; i < num_quaries; i++) {
    std::cin >> quary;
    bool is_first = true;
    for (auto pair : mp) {
      if (is_prefix(quary, pair.second)) {
        if (!is_first)
          std::cout << ", ";
        std::cout << pair.second;
        is_first = false;
      }
    }
    std::cout << "\n";
  }

  return 0;
}
