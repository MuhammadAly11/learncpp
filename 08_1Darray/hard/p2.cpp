#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

int main() {
	const int size = 200;
	int n, k;
	cout << "k(<n): ";
	cin >> k;
	cout << "n(<200): ";
	cin >> n;

	assert(k < n);
	assert(n < size);

	cout << "n numbers 1 by 1: ";
	int arr[size];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = INT_MIN;
	int start_idx, end_idx;
	int sum = 0;
	int range = k;
	for (int i = 0, j = 0; i < n+1; i++) {
		if (i == k) {
			if (sum > max) {
				max = sum;
				end_idx = i - 1;
				start_idx = i - range;
			}
			j++;
			i = j - 1;
			k++;
			sum = 0;
			continue;
		}
		sum += arr[i];
	}
	cout << "range: " << start_idx << " --> " << end_idx
		<< " with max: " << max << endl;
}
