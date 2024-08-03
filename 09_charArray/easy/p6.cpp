#include <iostream>
using namespace std;

int main() {
	string str;
	cout << "str: ";
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
		if (str[i] != str[i+1])
			cout << " ";
	}
	cout << endl;
}
