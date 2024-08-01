#include <iostream>
using namespace std;

int main() {
	const int max = 200;

	int n;
	cout << "n: ";
	cin >> n;
	
	int numbers[max];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	cout << "before: ";
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n / 2; i++) {
		int tmp = numbers[i];
		numbers[i] = numbers[n-i-1];
		numbers[n-i-1] = tmp;
	}

	cout << "after: ";
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}
