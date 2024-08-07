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

    int queries;
    cout << "Queries number: ";
    cin >> queries;

    while (queries--) {
        bool is_smaller = true;
        int row1, row2;
        cout << "Query: ";
        cin >> row1 >> row2;

        for (int i = 0; i < colomns; i++) {
            if (matrix[row1 - 1][i] >= matrix[row2 - 1][i]) {
                is_smaller = false;
                break;
            }
        }
        if (is_smaller)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
