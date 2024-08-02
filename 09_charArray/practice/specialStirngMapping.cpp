#include <iostream>
using namespace std;

int main() {
	string input;
	cout << "Sting: ";
	cin >> input;

	string letters_map = "YZIMNESTODUAPWXHQFBRJKCGVL";
	string digits_map = "!@#$%^&*()";

	for (int i = 0; i < input.size(); i++) {
		if ('a' <= input[i] && input[i] <= 'z') {
			input[i] = letters_map[input[i] - 'a'];
		}
		else if ('0' <= input[i] && input[i] <= '9') {
			input[i] = digits_map[input[i] - '0'];
		}
		cout << input[i];
	}
	cout << endl;
}
