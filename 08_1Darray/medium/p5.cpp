#include <iostream>
using namespace std;

int main() {
	// read array
	const int max = 900, max_value = 500;
	int n;
	cout << "n (<= 900): ";
	cin >> n;
	int arr[max];
	cout << "numbers 1 by 1 (<= 500): ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int f[max_value + 1] = {0};
	for (int i = 0; i < n; i++) {
		if (!f[arr[i]])
			f[arr[i]] += i + 1;
	}

	int sorted[max] = {0};
	for (int i = 0; i < max_value+1; i++) {
		if (f[i]) {
			sorted[f[i]] = i;
		}
	}

	bool first = true;
	cout << "Output: \n";
	for (int i = 0; i < n; i++) {
		if (sorted[i]) {
			if (!first)
				cout << " ";
			cout << sorted[i];
			first = false;
		}
	}
	cout << endl;
}
