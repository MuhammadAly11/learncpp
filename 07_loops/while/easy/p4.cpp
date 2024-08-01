#include <iostream>
using namespace std;

int main () {
    int rows;
    cout << "number of rows: ";
    cin >> rows;

    while (rows > 0) {

	int cnt = rows;

	while (cnt > 0) {
	    cout << "*";
	    cnt--;
	}

	cout << "\n";
	rows--;
    }

    return 0;
}
