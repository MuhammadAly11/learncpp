#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cout << "Odd number: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (n - 1 - j == i || j == i) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}
