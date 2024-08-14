#include <iostream>
using namespace std;

int recursive_pow(int value, int p = 2) {
  if (p == 0)
    return 1;

  return value * recursive_pow(value, p - 1);
}

int main() {
  int value, power;
  cout << "value: ";
  cin >> value;
  cout << "power: ";
  cin >> power;

  cout << value << " to power of " << power << " ==> "
       << recursive_pow(value, power) << endl;
  return 0;
}
