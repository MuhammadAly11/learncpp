#include <iostream>
#include <set>
#include <string>

bool is_prefix(std::string pre, std::string str) {
  for (int i = 0; i < (int)pre.size(); i++) {
    if (pre[i] != str[i])
      return false;
  }
  return true;
}

int main() {
  std::cout << "Number of strings: \n";
  int num_strs;
  std::cin >> num_strs;

  std::set<std::string> names;
  for (int i = 0; i < num_strs; i++) {
    std::string name;
    std::cin >> name;
    names.insert(name);
  }

  std::cout << "Number of queries: \n";
  int num_quaries;
  std::cin >> num_quaries;
  std::string quary;
  for (int i = 0; i < num_quaries; i++) {
    std::cin >> quary;
    bool is_first = true;
    for (auto name : names) {
      if (is_prefix(quary, name)) {
        if (!is_first)
          std::cout << ", ";
        std::cout << name;
        is_first = false;
      }
    }
    std::cout << "\n";
  }

  return 0;
}
