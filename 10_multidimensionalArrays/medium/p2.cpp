// find mountains
#include <iostream>
using namespace std;

int main() {
  const int size = 100;
  int rows, colomns;
  cout << "rows and colomns: ";
  cin >> rows >> colomns;

  int matrix[size][size];
  cout << "Values:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      cin >> matrix[i][j];
    }
  }

  //       u,  d,  r,  l, ur, ul, dr, dl
  int di[]{-1, 1, 0, 0, -1, -1, 1, 1};
  int dj[]{0, 0, -1, 1, -1, 1, -1, 1};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      bool is_mountain = 1;
      for (int d = 0; d < 8; d++) {
        int ni = i + di[d], nj = j + dj[d];
        if ( ni < 0 || ni >= rows || nj < 0 || nj >= colomns ) {
          continue;
        }
        if (matrix[i][j] <= matrix[ni][nj]) {
          is_mountain = 0;
          break;
        }
      }
      if (is_mountain)
        cout << "Mountain Position: (" << i << ", " << j << ")"
             << " with value: " << matrix[i][j] << endl;
    }
  }

  return 0;
}
