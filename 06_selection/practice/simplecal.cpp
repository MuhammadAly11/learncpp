#include <iostream>
using namespace std;

int main() {
    cout << "Enter simple math problem: ";
    double n1, n2;
    string sign;
    cin >> n1 >> sign >> n2;

    if (sign == "+")
	cout << n1 + n2 << endl; 
    else if (sign == "-")
	cout << n1 - n2 << endl;
    else if (sign == "*")
	cout << n1 * n2 << endl;
    else if (sign == "/")
	cout << n1 / n2 << endl;
}
