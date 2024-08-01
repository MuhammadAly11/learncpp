#include <iostream>
using namespace std;

int main() {
	// read array
	int n, max = 200;
	cout << "n (<= 200): ";
	cin >> n;
	int arr[max];
	cout << "numbers 1 by 1: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	const int digit_max = 10;
	int digits[digit_max] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < digit_max; j++) {
			int num = arr[i];
			// if (num == 0)
			// 	digits[0]++; // to handel the bug
			while (num) {
				if (num % 10 == j) {
					digits[j]++;
				}
				num = num / 10;
			}
		}
	}

	for (int i = 0; i < digit_max; i++) {
		cout << i << " appeared --> " << digits[i] << " times\n";
	}
	return 0;
}

// I have a bug in this code it doen't count 0
