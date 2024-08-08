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

    int queries;
    cout << "Queries number: ";
    cin >> queries;

    while (queries--) {
        int start_i, start_j, r, c, primes {};
        cout << "Start indices & rows and colomns to consider(1-based): ";
        cin >> start_i >> start_j >> r >> c;
        for (int i = start_i; i < r + start_i - 1; i++) {
            for (int j = start_j; j < c + start_j - 1; j++) {
                int cnt = 2;
                bool is_prime = true;
                while (cnt < matrix[i][j]) {
                    if (matrix[i][j] % cnt == 0)
                        is_prime = false;
                    cnt++;
                }
                if (is_prime) {
                    cout << matrix[i][j] << " ";
                    primes++;
                }
            }
        }
        cout << "\nNumber of primes: " << primes << endl;
    }

    return 0;
}
