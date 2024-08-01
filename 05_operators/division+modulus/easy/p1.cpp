#include <iostream>
using namespace std;

int main () {
    double a, b, c, d, e;
    cout << "Enter 5 numbers: ";
    cin >> a >> b >> c >> d >> e;

    cout << "A) "
	 << (a + b + c + d + e) / 5 << "\n";
    cout << "B) "
	 << (a + b + c) / (d + e) << "\n";
    cout << "c) "
	 << ( (a + b + c) / 3 ) / ( (d + e) / 2 ) << "\n";
} 
