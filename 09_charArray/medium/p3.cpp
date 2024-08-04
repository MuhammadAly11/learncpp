#include <iostream>
using namespace std;

int main() {
	string num;
	cout << "num: ";
	cin >> num;

	int carry {0};
	for (int i = 0; i < num.size(); i++) {
		int digit = num[num.size() - i - 1] - '0';
		if (i < 4)
			digit += 5;
		digit += carry;
		if (digit >= 10) {
			carry = digit / 10;
			if (carry == 0)
				carry = 1;
			digit = digit % 10;
		} else {
			carry = 0;
		}
		num[num.size() - i - 1] = digit + '0'; 
	}

	if (carry)
		cerr << carry;
	cerr << num << endl;
}
