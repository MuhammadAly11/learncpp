#include <iostream>
using namespace std;

int main() {
    const int max = 100;
    int matrix[max][max];

    int size;
    cout << "Matrix size: ";
    cin >> size;

    cout << "Values:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    int r {}, c {}, diagonal_sum {}, upper_sum {}, lower_sum {};
    while (r < size && c < size) {
        diagonal_sum += matrix[r][c];
        for (int i = r + 1; i < size; i++) {
            lower_sum += matrix[i][c];
        }
        for (int i = r - 1; i >= 0; i--) {
            upper_sum += matrix[i][c];
        }
        r++, c++;
    }

    cout << "Lower triangle sum = " << diagonal_sum + lower_sum << "\n";
    cout << "Upper triangle sum = " << diagonal_sum + upper_sum << "\n";
}
