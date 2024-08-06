#include <iostream>
using namespace std;

int main() {
  const int max = 100;
  int rows, colomns;
  cout << "rows and colomns (<=100): ";
  cin >> rows >> colomns;

  int matrix[max][max];
  cout << "Values 1 by 1: ";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      cin >> matrix[i][j];
    }
  }

  int max_value = matrix[0][0];
  int row, colomn;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      if (max_value <= matrix[i][j]) {
        max_value = matrix[i][j];
        row = i;
        colomn = j;
      }
    }
  }

  cout << "The maximum value is at position " << row << ":" << colomn
       << "of value " << max_value << endl;
}
