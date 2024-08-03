#include <iostream>
using namespace std;

int main() {
	string input, suffix;
	cout << "Input: ";
	cin >> input;
	cout << "Suffix: ";
	cin >> suffix;

	// fix bug if the prefix is large than input
	if (suffix.size() > input.size()) {
		cout << "No\n";
		return 0;
	}

	for (int i = 1; i < suffix.size(); i++) { //fixbug: when i=0, it will access size which is out of array size
		if (suffix[suffix.size() - i] != input[input.size() - i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
