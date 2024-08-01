#include <iostream>
using namespace std;

int main() {
	// read array
	int n, max = 200;
	cout << "n (<= 200): ";
	cin >> n;
	int arr[max];
	cout << "numbers 1 by 1 (between -500 and 270): ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// find the most frequent number
	const int range = 271+501+300; 
	int f[range] = {0};
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0)
			f[arr[i]]++;
		else
			f[ (-arr[i]) + 300 ]++;
	}

	int max_pos = -1;
	for (int i = 0; i < range; i++) {
		if (max_pos == -1 || max_pos < f[i]) {
			max_pos = i;
		}
	}

	int max_real;
	if (max_pos > 300) {
		max_real = -(max_pos - 300);
	}
	cout << max_real << " repeated " << f[max_pos] << " times\n";
}
