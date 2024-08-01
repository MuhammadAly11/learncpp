#include <iostream>
using namespace std;

int main() {
	cout << "rows: ";
	int rows;
	cin >> rows;

	int i {1};
	while (i <= rows) {
		int k = 1;
		while (k <= rows - i) {
			cout << " ";
			k++;
		}
		k = 1;
		while (k < i) {
			cout << "*";
			k++;
		}

		cout << "*";

		k = 1;
		while (k < i) {
			cout << "*";
			k++;
		}
		k = 1;
		while (k <= rows - i) {
			cout << " ";
			k++;
		}

		cout << endl;
		i++;
	}

	i = 1;
	while (i <= rows) {
		int k = 1;
		while (k < i) {
			cout << " ";
			k++;
		}
		k = 1;
		while (k <= rows - i) {
			cout << "*";
			k++;
		}

		cout << "*";

		k = 1;
		while (k <= rows - i) {
			cout << "*";
			k++;
		}
		k = 1;
		while (k < i) {
			cout << " ";
			k++;
		}
		
		cout << endl;
		i++;
	}
}
