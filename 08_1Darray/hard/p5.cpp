// solved after watching solution
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  const int size = 1000;
  int n;
  cout << "N(<1000): ";
  cin >> n;
  assert(n < 1000 && n >= 1);

  int arr[size];
  cout << "numbers: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int res = 0;
  for (int i = 0; i < n; i++) {
    int zeros {}, ones {};
    for (int j = i; j < n; j++) {
      if (arr[j] == 0)
        zeros++;
      else
       ones++;

      if (zeros == ones) {
        int subarr = j - i + 1;
        if (subarr > res)
          res = subarr;
      }
    }
  }

  cout << "\nOutput: " << res << "\n";
}
