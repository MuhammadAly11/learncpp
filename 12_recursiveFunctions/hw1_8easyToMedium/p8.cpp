#include <iostream>
using namespace std;

int max2(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

void arr_leftmax(int arr[], int len) {
  if (len == 1) {
    return;
  }

  arr_leftmax(arr, len - 1);

  arr[len - 1] = max2(arr[len - 1], arr[len - 2]);
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

  arr_leftmax(arr, len);

  cout << "Incremented array: \n";
  for (int i = 0; i < len; i++) {
    if (i)
      cout << " ";
    cout << arr[i];
  }
  cout << endl;

  return 0;
}
