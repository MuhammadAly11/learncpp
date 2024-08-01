#include <climits>
#include <iostream>
using namespace std;

int main() {
	cout << "Times: ";
	int t;
	cin >> t;

	int i = 1, n, res = INT_MAX, num;
	while (t > 0) {
		cout << "n of numbers: ";
		cin >> n;
		cout << "numbers one by one\n";
		while (n > 0) {
			cout << "number " << i << ": ";
			cin >> num;
			if (res > num)
				res = num;

			n--;
			i++;
		}
		cout << "Min: " << res << endl;
		res = INT_MAX;
		i = 1;

		t--;
	}

	cout << endl;
	return 0;
}
