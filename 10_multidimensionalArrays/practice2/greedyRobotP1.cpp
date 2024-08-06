#include <climits>
#include <iostream>
using namespace std;

int main() {
    const int size = 100;
    int rows, colomns;
    cout << "rows and colomns (<=100): ";
    cin >> rows >> colomns;

    int matrix[size][size];
    cout << "Values: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colomns; j++) {
            cin >> matrix[i][j];
        }
    }

    //    r, d, diagonal
    int dr[3] = {0, 1, 1};
    int dc[3] = {1, 0, 1};

    int r{}, c{}, cc, rr, max{INT_MIN}, sum {matrix[0][0]};
    while (true) {
        for (int i = 0; i < 3; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (matrix[nr][nc] > max && nr < rows && nc < colomns) {
                max = matrix[nr][nc];
                rr = nr;
                cc = nc;
            }
        }
        sum += max;
        r = rr;
        c = cc;
        cout << "the new max " << max << " at " << r << ", " << c << " with sum: " << sum << endl;
        if (r == rows - 1 && c == colomns - 1) {
            break;
        }
        max = INT_MIN;
    }
    cout << "Special Sum: " << sum << endl;
}
