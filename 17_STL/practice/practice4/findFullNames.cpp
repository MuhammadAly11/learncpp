// Solved after watching solution
// from todolist
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void printVec(vector<string> &vec) {
  for (auto x : vec) {
    cout << x << ", ";
  }
  cout << endl;
}

int main() {
  int num_names;
  cout << "Nummber of full names: ";
  cin >> num_names;
  map<string, vector<string>> mp;

  while (num_names--) {
    int num;
    cin >> num;
    vector<string> names;
    string cur_name, str;
    for (int i = 0; i < num; i++) {
      cin >> str;
      if (i)
        cur_name += " ";
      cur_name += str;
      names.push_back(cur_name);
    }

    for (auto key : names) {
      mp[key].push_back(cur_name);
    }
  }

  int queries;
  cin >> queries;

  cout << "Output: \n";
  while (queries--) {
    int num;
    cin >> num;
    string str, cur_name;

    for (int i = 0; i < num; i++) {
      cin >> str;
      if (i)
        cur_name += " ";
      cur_name += str;
    }

    printVec(mp[cur_name]);
  }

  return 0;
}
