#include <iostream>
using namespace std;

int main() {
	const int arr_max = 200;
	int n;
	cout << "n: ";
	cin >> n;

	int arr[arr_max];
	// numbers between 0, 2000
	cout << "numbers one by one: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == max) {
			arr[i] = min;
		}
		else if (arr[i] == min) {
			arr[i] = max;
		}
	}

	cout << "result: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
}
