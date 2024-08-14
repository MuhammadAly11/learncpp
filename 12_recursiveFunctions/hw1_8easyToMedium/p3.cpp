#include <iostream>
using namespace std;

int max2(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int arr_max(int arr[], int len) {
  // fix bug: don't count arr[0] 2 times
  if (len == 1) {
    return arr[0];
  }
  return max2(arr[len - 1], arr_max(arr, len - 1));
}

int main() {
  const int max = 100;
  int len;
  cout << "array len: ";
  cin >> len;

  int arr[max];
  cout << "numbers 1 by 1: ";
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  cout << "Maximum value is : " << arr_max(arr, len) << endl;

  return 0;
}
