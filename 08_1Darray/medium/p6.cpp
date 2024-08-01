#include <iostream>
using namespace std;

int main() {
	// read array
	const int max = 900;
	int n;
	cout << "n (<= 900): ";
	cin >> n;
	int arr[max];
	cout << "numbers 1 by 1 (<= 500): ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
}
