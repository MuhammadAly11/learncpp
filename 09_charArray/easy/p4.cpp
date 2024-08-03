#include <iostream>
using namespace std;

int main() {
	string str, subsequence;
	cout << "str: ";
	cin >> str;
	cout << "subsequence: ";
	cin >> subsequence;

	// fix bug if the prefix is large than input
	if (subsequence.size() > str.size()) {
		cout << "No\n";
		return 0;
	}

	int cnt = 0, pos = -1;
	for (int i = 0; i < subsequence.size(); i++) {
		for (int j = pos + 1; j < str.size(); j++) {
			if (subsequence[i] == str[j]) {
				pos = j;
				cnt++;
				continue; // fixbug: only take the first position
			}
		}
	}
	if (cnt == subsequence.size())
		cout << "Yes\n";
	else
		cout << "NO\n";
}
