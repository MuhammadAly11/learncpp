#include <iostream>
using namespace std;

int main() {
  const int size = 100;
  int matrix[size][size];

  int rows, colomns;
  cout << "rows and colomns(<100): ";
  cin >> rows >> colomns;

  cout << "Values:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      cin >> matrix[i][j];
    }
  }

  int tranopsed[size][size];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colomns; j++) {
      tranopsed[j][i] = matrix[i][j];
    }
  }

  cout << endl;
  for (int i = 0; i < colomns; i++) {
    for (int j = 0; j < rows; j++) {
      cerr << tranopsed[i][j] << "\t";
    }
    cerr << endl;
  }
}
