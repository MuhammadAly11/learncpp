#include <iostream>
using namespace std;

int main() {
	string str, substr;
	cout << "str: ";
	cin >> str;
	cout << "substr: ";
	cin >> substr;

	// fix bug if the prefix is large than input
	if (substr.size() > str.size()) {
		cout << "No\n";
		return 0;
	}

	int cnt {};
	for (int i = 0; i < str.size() - substr.size() + 1; i++) { // fixbug: if str=substr the loop will never run
		if (substr[0] == str[i]) {
			cnt = 1;
			for (int j = 1; j < substr.size(); j++) {
				if (substr[j] == str[i + j]) {
					cnt++;
				}
			}
		}
		// fixbug: don't start over if letter is repeated
		if (cnt == substr.size()) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}
