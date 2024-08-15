#include <climits>
#include <iostream>
using namespace std;

const int MAX = 100;

void get_dimensions(int &rows, int &cols) {
  cout << "rows: ";
  cin >> rows;
  cout << "colomns: ";
  cin >> cols;
}

void readGrid(int grid[][MAX], int rows, int cols) {
  cout << "Values: ";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
    }
  }
}

int sumBot(int grid[][MAX], int ROWS, int COLS, int row = 0, int col = 0) {
  if (row == ROWS - 1 && col == COLS - 1)
    return grid[row][col];

  int nrow, ncol, max;
  //	      d, r, d
  int dr[] = {1, 0, 1};
  int dc[] = {0, 1, 1};
  bool is_firs = true;

  for (int d = 0; d < 3; d++) {
    int nr = row + dr[d];
    int nc = col + dc[d];
    if (nr < ROWS && nc < COLS) {
      if (is_firs || max < grid[nr][nc]) {
        max = grid[nr][nc];
        nrow = nr;
        ncol = nc;
        is_firs = false;
      }
    }
  }

  return grid[row][col] + sumBot(grid, ROWS, COLS, nrow, ncol);
}

int main() {
  int cols, rows;
  get_dimensions(rows, cols);

  int grid[MAX][MAX];
  readGrid(grid, rows, cols);

  cout << "The sum: " << sumBot(grid, rows, cols) << endl;

  return 0;
}
