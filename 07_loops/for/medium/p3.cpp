#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "+ve intger < 500: ";
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			cout << "Not prime\n";
			return 0;
		}
	}
	cout << "Yes, It's prime\n";

	return 0;
}
