#include <iostream>
using namespace std;

int main() {
    cout << "Enter 2 numbers: ";
    double n1, n2;
    cin >> n1 >> n2;

    if (n1 < n2)
	cout << "the minimum is: " << n1 << endl;
    else if (n2 < n1)
	cout << "the minimum is: " << n2 << endl;
    else
	cout << "the 2 numbers are equal\n";
}
