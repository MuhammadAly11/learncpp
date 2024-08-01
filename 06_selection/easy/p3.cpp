#include <iostream>
using namespace std;

int main() {
    int a, b, c; 
    cout << "Enter 3 integers: ";
    cin >> a >> b >> c;

    int big = -1;
    if (big <= b && b < 100)
	big = b;
    if (big <= c && c < 100)
	big = c;
    if (big <= a && a < 100)
	big = a;
    cout << "largest < 100: " << big << endl;

    return 0;
}

// I knew that I have to make the variable the minimum of integers
