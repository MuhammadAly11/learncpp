#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive integer: ";
    int n;
    cin >> n;
    int sum {0};
    int digits;

    if (n < 10000)
	cout << "This number is small\n";
    else {
	digits = n % 1000;
	sum += n % 10;
	n /= 10;
	sum += n % 10;
	n /= 10;
	sum += n % 10;
	n /= 10;
	if (sum % 2 != 0)
	    cout << "this is a great number\n";
	else {
	    if (digits % 2 != 0)
		cout << "this is a good number\n";
	    else if ( (digits / 10) % 2 != 0)
		cout << "this is a good number\n";
	    else if ( (digits / 100) % 2 != 0)
		cout << "this is a good number\n";
	    else
		cout << "this is a bad number\n";
	}
    }
}
