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


	for (int i = 0; i < n/2; i++) {
		if (arr[i] != arr[n-i-1]) {
			cout << "Not palindrome\n";
			return 0;
		}
	}
	cout << "Yes palindrome\n";
}
