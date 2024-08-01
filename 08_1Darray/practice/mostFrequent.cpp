#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "n: ";
	cin >> n;

	const int max = 200;
	int arr[max];

	cout << "numbers onr bby one: \n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int big = 0, idx;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = i+1; j < n; j++) {
			cnt += (arr[i] == arr[j]);
		}
		if (cnt > big) {
			big = cnt;
			idx = i;
		}
	}
	cout << "Most frequent: " << arr[idx] << endl;
}
