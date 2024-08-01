#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	cout << "n: ";
	cin >> n;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = i, sum = 0;
		while (tmp) {
			int last_digit = tmp % 10;
			tmp /= 10;
			sum += last_digit;
		}
		if (a <= sum && sum <= b) {
			res += i;
		}
	}
	cout << "result: " << res << endl;
}
