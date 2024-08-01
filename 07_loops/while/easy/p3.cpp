#include <iostream>
using namespace std;

int main () {
    int rows;
    cout << "number of rows: ";
    cin >> rows;
    int tmp_rows = rows;

    while (rows > 0) {

	int cnt = tmp_rows + 1 - rows;

	while (cnt > 0) {
	    cout << "*";
	    cnt--;
	}

	cout << "\n";
	rows--;
    }

    return 0;
}
