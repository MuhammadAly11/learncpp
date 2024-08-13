#include <iostream>
using namespace std;

void arrayPrint(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    if (i)
      cout << " ";
    cout << arr[i];
  }
  cout << endl;
}

int power(int num, int pw) {
  if (pw == 0)
    return 1;
  int tmp = num;
  while (--pw) {
    num *= tmp;
  }
  return num;
}

void set_powers(int arr[], int len = 5, int m = 2) {
  for (int i = 0; i < len; i++) {
    arr[i] = power(m, i);
  }
}

int main() {
  const int max = 100;
  int len, base;
  cout << "len: ";
  cin >> len;
  cout << "base: ";
  cin >> base;

  int arr[max];

  set_powers(arr, len, base);
  arrayPrint(arr, len);

  return 0;
}
