#include <cassert>
#include <iostream>
using namespace std;

int main() {
  const int size = 100;
  int depth, rows, colomns;
  cout << "depth, rows and colomns: ";
  cin >> depth >> rows >> colomns;

  int matrix[size][size][size];
  cout << "Values:\n";
  int idx{};
  for (int d = 0; d < depth; d++) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < colomns; j++) {
        cout << idx++ << " = " << d << ", " << i << ", " << j << endl;
      }
    }
  }

  int choice;
  cout << "Choose: ";
  cin >> choice;
  assert(choice == 1 || choice == 2);

  if (choice == 1) {
    int d, r, c;
    cout << "depth, rows and colomns: ";
    cin >> d >> r >> c;
    int ans = (d * rows * colomns) + (r * colomns) + c;
    cout << "1D idx ==> " << ans << endl;
  } else {
    int idx;
    cout << "1D idx: ";
    cin >> idx;
    int RC = rows * colomns;
    cout << "3D idx: (" << idx / RC << ", " << (idx % RC) / colomns << ", "
         << (idx % RC) % colomns << ")" << endl;
  }

  return 0;
}
