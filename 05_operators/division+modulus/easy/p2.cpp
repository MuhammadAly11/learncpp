#include "iostream"
using namespace std;

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    double mod = a % b;
    cout << mod / (double)b << "\n"; 

    return 0;
}
