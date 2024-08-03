#include <iostream>
using namespace std;

int main() {
	string input, prefix;
	cout << "Input: ";
	cin >> input;
	cout << "Prefix: ";
	cin >> prefix;

	// fix bug if the prefix is large than input
	if (prefix.size() > input.size()) {
		cout << "No\n";
		return 0;
	}

	for (int i = 0; i < prefix.size(); i++) {
		if (prefix[i] != input[i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
