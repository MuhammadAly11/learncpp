#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    cout << "Enter 10 integers ";
    cin >> n1>> n2>> n3>> n4>> n5>> n6>> n7>> n8>> n9>> n10;

    int tmp = n1;

    if (tmp < n1)
	tmp = n1;
    if (tmp < n2)
	tmp = n2;
    if (tmp < n3)
	tmp = n3;
    if (tmp < n4)
	tmp = n4;
    if (tmp < n5)
	tmp = n5;
    if (tmp < n6)
	tmp = n6;
    if (tmp < n7)
	tmp = n7;
    if (tmp < n8)
	tmp = n8;
    if (tmp < n9)
	tmp = n9;
    if (tmp < n10)
	tmp = n10;

    cout << "Maximum ==> " << tmp << endl;
}

// the only other way I could think of with using only 2 integers will require input numbers one by one
// and compare each input to the current largest one
// which will lead to repeated code also
