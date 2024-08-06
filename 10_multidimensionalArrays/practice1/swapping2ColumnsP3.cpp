#include <iostream>
using namespace std;

int main() {
  const int max = 100;
  int rows, colomns;
  cout << "rows and colomns (<=100): ";
  cin >> rows >> colomns;

  int matrix[max][max];
  cout << "Values 1 by 1: \n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      cin >> matrix[i][j];
    }
  }

  int idx1, idx2, tmp;
  cout << "Two indices to swap: ";
  cin >> idx1 >> idx2;
  for (int i = 0; i < rows; i++) {
    tmp = matrix[i][idx1];
    matrix[i][idx1] = matrix[i][idx2];
    matrix[i][idx2] = tmp;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}
