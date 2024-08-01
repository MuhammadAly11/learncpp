// josephus problem
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	const int size = 200;
	int n, k;

	cout << "N(<200): ";
	cin >> n;
	assert(n < 200 && n >= 1);

	cout << "K(<=1000000): ";
	cin >> k;
	assert(k <= 1000000 && k >= 1);

	int players[size] {0};
	for (int i = 1; i <= n; i++) {
		players[i] = i;
	}
	
	cout << "Output: ";
	bool killed[size + 1] {0};
	int cnt {0}, kills {0};
	for (int i = 1; kills < n; i++) {
		cnt += (!killed[players[i]]);
		if (cnt == k) {
			killed[players[i]] = true;
			cout << players[i] << " ";
			cnt = 0;
			kills++;
		}
		if (i == n)
			i = 0;
	}
	
	cout << endl;
}
