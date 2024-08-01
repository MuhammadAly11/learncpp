#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive integer: ";
    int n;
    cin >> n;

    if (n % 2 == 0) {
	cout << n % 10 << endl;
    }
    else {
	if (n < 1000)
	    cout << n % 100 << endl; 
	else if (n < 1000000)
	    cout << n % 10000 << endl;
	else
	    cout << -n << endl;
    }
}
