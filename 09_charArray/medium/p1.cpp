#include <iostream>
using namespace std;

int main() {
	string str;
	cout << "str: ";
	cin >> str;

	int cnt {};
	for (int i = 0; i < str.size(); i++) {
		cnt++;
		if (str[i] != str[i+1]) {
			cout << str[i] << cnt;
			if (i != str.size() - 1)
				cout << "_";
			cnt = 0;
		}
	}
	cout << endl;
}
