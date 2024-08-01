#include <iostream>
using namespace std;

int main() {
	const int arr_max = 1000;
	int n;
	cout << "n: ";
	cin >> n;

	int arr[arr_max];
	cout << "numbers one y one: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int min = arr[0] + arr[1] + 1 - 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (min > arr[i] + arr[j] + j - i) {
				min = arr[i] + arr[j] + j - i; 
			}
		}
	}

	cout << "Min: " << min << endl;
}
