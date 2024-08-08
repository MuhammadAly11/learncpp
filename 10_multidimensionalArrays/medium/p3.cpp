// find mountains
#include <iostream>
using namespace std;

int main() {
  const int size = 100;
  int rows, colomns;
  cout << "rows and colomns: ";
  cin >> rows >> colomns;

  int commands;
  cout << "Number of commands: ";
  cin >> commands;
  int i{}, j{};
  while (commands--) {
    int direction, steps;
    cout << "Direction and steps: ";
    cin >> direction >> steps;
    if (direction == 1) {
      int ni = i - steps;
      ni = ni % rows;
      if (ni < 0) {
        ni = rows - (-ni);
      }
      cout << "(" << ni << ", " << j << ")\n";
      i = ni;
    } else if (direction == 2) {
      int nj = j + steps;
      nj = nj % colomns;
      cout << "(" << i << ", " << nj << ")\n";
      j = nj;
    } else if (direction == 3) {
      int ni = i + steps;
      ni = ni % rows;
      cout << "(" << ni << ", " << j << ")\n";
      i = ni;
    } else if (direction == 4) {
      int nj = j - steps;
      nj = nj % colomns;
      if (nj < 0) {
        nj = colomns - (-nj);
      }
      cout << "(" << i << ", " << nj << ")\n";
      j = nj;
    }
  }

  return 0;
}
