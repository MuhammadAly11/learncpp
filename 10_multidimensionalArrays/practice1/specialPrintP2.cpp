#include <iostream>
using namespace std;

int main() {
  const int max = 100;
  int rows, colomns;
  cout << "rows and colomns (<=100): ";
  cin >> rows >> colomns;

  // read array
  int matrix[max][max];
  cout << "Values 1 by 1: ";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      cin >> matrix[i][j];
    }
  }

  // get special sums
  int final_row {}, final_colomn {}, ldiagonal {}, rdiagonal {};
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      if (i == j)
        ldiagonal += matrix[i][j];
      if (i + j == rows)
        rdiagonal += matrix[i][j];
      if (i == rows - 1)
        final_row += matrix[i][j];
      if (j == colomns - 1)
        final_colomn += matrix[i][j];
    }
  }

  cout << "Sum of left diagonal = " << ldiagonal << endl;
  cout << "Sum of right diagonal = " << rdiagonal << endl;
  cout << "Sum of final row = " << final_row << endl;
  cout << "Sum of final colomn = " << final_colomn << endl;
}
