#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter 2 integers: ";
    cin >> a >> b;

    bool a_even = (a % 2 == 0);
    bool b_even = (b % 2 == 0);

    if ( !a_even && !b_even )
	cout << "a * b = " << a * b << endl;
    else if ( a_even && b_even )
	cout << "a / b = " << a / b << endl;
    else if ( !a_even && b_even )
	cout << "a + b = " << a + b << endl;
    else
	cout << "a - b = " << a - b << endl;

    return 0;
}
