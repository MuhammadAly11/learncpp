#include <iostream>
using namespace std;

void arr_accumulate(int arr[], int len) {
  if (len == 1) {
    return;
  }

  arr_accumulate(arr, len - 1);

  arr[len - 1] += arr[len - 2];
}

int main() {
  const int max = 100;
  int len;
  cout << "array len: ";
  cin >> len;

  int arr[max];
  cout << "Numbers 1 by 1: ";
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  arr_accumulate(arr, len);

  cout << "Incremented array: \n";
  for (int i = 0; i < len; i++) {
    if (i)
      cout << " ";
    cout << arr[i];
  }
  cout << endl;

  return 0;
}
