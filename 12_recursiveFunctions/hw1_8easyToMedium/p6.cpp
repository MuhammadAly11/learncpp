#include <iostream>
using namespace std;

void arr_inc(int arr[], int len) {
  if (len == 0) {
    return;
  }

  arr[len - 1] += len - 1;

  arr_inc(arr, len - 1);
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

  arr_inc(arr, len);

  cout << "Incremented array: \n";
  for (int i = 0; i < len; i++) {
    if (i)
      cout << " ";
    cout << arr[i];
  }
  cout << endl;

  return 0;
}
