#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "n: ";
	cin >> n;

	cout << "numbers one by one: ";
	int numbers[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int max = numbers[0];
	for (int i = 0; i < n; i++) {
		if (max < numbers[i]) {
			max = numbers[i];
		}
	}

	int max2 = numbers[0];
	for (int i = 0; i < n; i++) {
		if (max2 < numbers[i] && numbers[i] != max) {
			max2 = numbers[i];
		}
	}

	cout << "max1: " << max << endl;
	cout << "max2: " << max2 << endl;
}
