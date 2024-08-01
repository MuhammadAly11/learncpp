#include <iostream>
using namespace std;

int main() {
	const int arr_max = 1000;
	int n;
	cout << "n: ";
	cin >> n;

	int arr[arr_max] = {0};
	// numbers between 0, 500
	cout << "numbers one by one: ";
	int num, j = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (j == 0) {
			arr[j] = num;
			j++;
			continue;
		}
		if (num > arr[j-1]) {
			arr[j] = num;
			j++;
		}
	}

	cout << "result: \n";
	for (int i = 0; i < j; i++)
		cout << arr[i] << " ";
	cout << endl;
}
