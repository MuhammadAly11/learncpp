#include <iostream>
using namespace std;

double arr_avg(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }
  // Got ths equation form ChatGPT by accident, but I got it
  return (arr[len - 1] + (len - 1) * arr_avg(arr, len - 1)) / len;
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

  cout << "Avrege of array: " << arr_avg(arr, len) << endl;

  return 0;
}
