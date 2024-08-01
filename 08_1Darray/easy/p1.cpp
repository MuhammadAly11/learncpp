#include <iostream>
using namespace std;

int main() {
	const int max = 200;
	int n;
	cout << "n: ";
	cin >> n;

	int arr[max];
	cout << "numbers one by one: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i-1]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
