#include <climits>
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "n: ";
	cin >> n;

	int arr[n];
	cout << "numbers 1 by 1: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min1) {
			min3 = min2;
			min2 = min1;
			min1 = arr[i];
		}
		if (arr[i] < min2 && min1 != arr[i]) {
			min3 = min2;
			min2 = arr[i];
		}
		if (arr[i] < min3 && min1 != arr[i] && min2 != arr[i])
			min3 = arr[i];
	}

	cout << "minimum 3: " << min1 << " < " << min2 << " < " << min3 << endl; 
}
