#include <iostream>
using namespace std;

void get_input(string &str, string &pattern, string &replacement) {
  cout << "string: ";
  cin >> str;
  cout << "pattern: ";
  cin >> pattern;
  cout << "replacment: ";
  cin >> replacement;
}

bool start_with(const string &input, const string &pattern, int pos) {
  for (int i = 0; i < pattern.length(); i++) {
    if (input[pos + i] != pattern[i]) {
      return 0;
    }
  }
  return 1;
}

string replace_str(const string &input, const string &pattern,
                   const string &to) {
  string replaced;
  for (int i = 0; i < input.length(); i++) {
    if (start_with(input, pattern, i)) {
      replaced += to;
      i += pattern.length() - 1;
    } else {
      replaced += input[i];
    }
  }
  return replaced;
}

int main() {
  string str, pattern, replacement;
  get_input(str, pattern, replacement);
  string replaced = replace_str(str, pattern, replacement);

  cout << "replaced: " << replaced << endl;

  return 0;
}
