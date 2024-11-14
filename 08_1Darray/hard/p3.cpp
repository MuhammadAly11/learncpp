// ToDo >> solved after watching solution
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  const int size = 200;
  int n;
  cout << "N(<200): ";
  cin >> n;
  assert(n < 200 && n >= 1);

  int arr[size];
  cout << "numbers 1 by 1: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res++;
    for (int j = i; j < n - 1; j++) {
      if (arr[j] <= arr[j + 1])
        res++;
      else
        break;
    }
  }

  cout << "\nOutput: " << res << "\n";
}
