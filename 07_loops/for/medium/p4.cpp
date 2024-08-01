#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "+ve int < 500: ";
	cin >> n;
	cout << "2";

	for (int i = 3; i < n; i++) {
		bool is_prime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			cout << ", " << i;
		}
	}
	cout << "\n";
}
