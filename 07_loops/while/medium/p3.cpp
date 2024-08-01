#include <iostream>
using namespace std;

int main() {
	cout << "positive intger (0 < N < 30): ";
	int N;
	cin >> N;
	while (N < 1 || N > 30) {
	cout << "positive intger (0 < N < 30): ";
		cin >> N;
	}

	int i = 0;
	while (N > 0) {
		if (i % 3 == 0 && i % 4 != 0) {
			cout << i << ", ";
			N--;
		}

		i++;
	}

	cout << endl;
	return 0;
}
