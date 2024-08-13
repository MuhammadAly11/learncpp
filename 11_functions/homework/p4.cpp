#include <iostream>
using namespace std;

bool is_palindrome(int arr[], int size) {
  for (int i = 0; i < size / 2; i++) {
    if (arr[i] != arr[size - i - 1])
      return 0;
  }
  return 1;
}

int main() {
  int size;
  const int max = 100;
  cout << "Array size: ";
  cin >> size;

  int arr[max];
  cout << "Numbers 1 by 1: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  if (is_palindrome(arr, size))
    cout << "Yes, it's palindromic\n";
  else
    cout << "No, it isn't palindromic\n";
  return 0;
}
