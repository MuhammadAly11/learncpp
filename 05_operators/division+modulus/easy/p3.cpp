#include "iostream"
using namespace std;

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    double result = (double)a / b;
    double fraction = result - (int)result;
    cout << fraction * b << "\n";

    return 0;
}
