#include <cassert>
#include <iostream>
using namespace std;

int main() {
	const int size = 200;
	int n;
	cout << "N(<200): ";
	cin >> n;
	assert(n < 200 && n >= 1);

	int arr[size];
	cout << "numbers 1 by 1: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

}
