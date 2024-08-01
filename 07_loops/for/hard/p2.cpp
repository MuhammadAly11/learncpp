#include <iostream>
using namespace std;
int main() {
	int r;
	cout << "runs: ";
	cin >> r;

	for (int i = 0; i < r; i++) {
		cout << "Howmany numbers: ";
		int nrs;
		cin >> nrs;
		cout << "numbers one by one\n";

		int res = 0;
		for (int j = 1; j <= nrs; j++) {
			int num, sum = 1;
			cin >> num;

			for (int k = 0; k < j; k++) {
				sum *= num;
			}

			res += sum;
		}
		cout << "Special sum = " << res << endl;
	}
}
