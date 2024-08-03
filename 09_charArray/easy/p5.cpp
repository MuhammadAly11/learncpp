#include <iostream>
using namespace std;

int main() {
	string str;
	cout << "str: ";
	cin >> str;

	int num {};
	for (int i = 0; i < str.size(); i++) {
		num *= 10;
		num += str[i] - '0';
	}
	cout << "to number: " << num << endl;
	cout << "to number x 3: " << num * 3 << endl;
}
