#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive intger: ";
    int num;
    cin >> num;

    int mod = num % 2;
    cout << "first method using %2 --> " << (mod == 0) << "\n";

    double division = num / 2.0;
    cout << "2nd method using / --> " << ( ( division - (int)division ) == 0.0) << "\n";

    double last = num % 10;
    cout << "3rd method using %10 --> " << ( last == 2 || last == 4 || last == 6 || last == 8) << "\n";
}
