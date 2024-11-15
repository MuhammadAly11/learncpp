#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

int main() {
  map<char, char> parentheses;
  parentheses['('] = ')';
  parentheses['['] = ']';
  parentheses['{'] = '}';

  string str = "";
  cout << "Enter string: \n";
  while (str != "stop") {
    stack<char> s;
    cin >> str;
    cout << str << endl;

    for (int i = 0; i < str.length(); i++) {
      if (!s.empty() && str[i] == parentheses[s.top()]) {
        s.pop();
      } else
        s.push(str[i]);
    }

    if (s.empty())
      cout << "Valid\n";
    else
      cout << "Invalid\n";
  }
}
