#include <iostream>
using namespace std;

int arr_sum(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }
  return arr[len - 1] + arr_sum(arr, len - 1);
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

  cout << "Sum of array: " << arr_sum(arr, len) << endl;

  return 0;
}
