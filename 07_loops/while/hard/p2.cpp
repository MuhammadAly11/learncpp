#include <iostream>
using namespace std;

int main() {
	int num;
	cout << "psitive intger: ";
	cin >> num;
	int digits = num;

	int zeros {0};
	while (digits) {
		zeros++;
		digits /= 10;
	}

	int rev {0};
	while (zeros) {
		zeros--;
		int i = 0, powered = 1;
		while (i < zeros) {
			powered *= 10;
			i++;
		}
		rev += (num % 10) * powered;
		num /= 10;
	}
	cout << "Reverse: " << rev << endl;
	cout << "Reverse * 3: " << rev * 3 << endl;
}
