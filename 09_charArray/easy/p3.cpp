#include <iostream>
using namespace std;

int main() {
	string str, substr;
	cout << "str: ";
	cin >> str;
	cout << "substr: ";
	cin >> substr;

	int cnt {};
	for (int i = 0; i < str.size() - substr.size(); i++) {
		if (substr[0] == str[i]) {
			cnt = 1;
			for (int j = 1; j < substr.size(); j++) {
				if (substr[j] == str[i + j]) {
					cnt++;
				}
			}
		}
	}
	if (cnt == substr.size()) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}
