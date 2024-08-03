#include <iostream>
using namespace std;

int main() {
	string str, subsequence;
	cout << "str: ";
	cin >> str;
	cout << "subsequence: ";
	cin >> subsequence;

	int cnt = 0, pos = -1;
	for (int i = 0; i < subsequence.size(); i++) {
		for (int j = pos + 1; j < str.size(); j++) {
			if (subsequence[i] == str[j]) {
				pos = j;
				cnt++;
			}
		}
	}
	if (cnt == subsequence.size())
		cout << "Yes\n";
	else
		cout << "NO\n";
}
