#include <iostream>
using namespace std;

bool is_prefix(const string &str, const string &pre, int pos = 0) {
  if (pre.length() > str.length()) {
    return false;
  }

  // Base
  if (pos == pre.length()) {
    return true;
  }

  if (str[pos] != pre[pos]) {
    return false;
  }

  return is_prefix(str, pre, pos + 1);
}

int main() {
  string str, pre;
  cout << "String: ";
  cin >> str;
  cout << "Prefix: ";
  cin >> pre;

  if (is_prefix(str, pre)) {
    cout << "Yes, it's a prefix\n";
    return 0;
  }
  cout << "NO, it isn't a prefix\n";
}
