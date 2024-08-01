#include <iostream>
using namespace std;

int main() {
	cout << "positive intger (end): ";
	int end;
	cin >> end;

	int n = 0;
	while (n < end) {
		if (n % 8 == 0) {
			cout << n << ", ";
		}
		else if (n % 3 == 0 && n % 4 == 0) {
			cout << n << ", ";
		}

		n++;
	}

	cout << endl;
	return 0;
}
