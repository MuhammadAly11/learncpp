#include <iostream>
using namespace std;

bool is_palindrome(int arr[], int len, int pos = 0) {
  if (pos >= len - 1) {
    return true;
  }

  if (arr[pos] != arr[len - 1]) {
    return false;
  }

  return is_palindrome(arr, len - 1, pos + 1);
}

int main() {
  const int max = 100;
  int len;
  cout << "Array len: ";
  cin >> len;

  int arr[max];
  cout << "Values: ";
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  if (is_palindrome(arr, len))
    cout << "Yes, it's palindrome.\n";
  else
    cout << "No, it isn't palindrome.\n";

  return 0;
}
