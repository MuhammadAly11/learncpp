// concatenating strings
#include <iostream>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int size;
	if (s1.size() > s2.size())
		size = s1.size();
	else
		size = s2.size();

	for (int i = 0; i < size; i++) {
		if (i < s1.size())
			cout << s1[i];
		if (i < s2.size())
			cout << s2[i];
	}
	cout << endl;
}
