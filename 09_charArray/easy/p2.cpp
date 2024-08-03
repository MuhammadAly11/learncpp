#include <iostream>
using namespace std;

int main() {
	string input, suffix;
	cout << "Input: ";
	cin >> input;
	cout << "Suffix: ";
	cin >> suffix;

	for (int i = 0; i < suffix.size(); i++) {
		if (suffix[suffix.size() - i] != input[input.size() - i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
