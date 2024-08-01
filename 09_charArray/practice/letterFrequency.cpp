#include <iostream>
using namespace std;

int main() {
	cout << "String: ";
	string letters;
	cin >> letters;

	int fq['z' + 1] {0};
	for (int i = 0; i < letters.size(); i++) {
		if ('a' <= letters[i] && letters[i] <= 'z') {
			fq[letters[i]]++;
		}
	}

	for (int i = 0; i < ('z' + 1); i++) {
		if (fq[i]) {
			cout << (char)i << " ==> " << fq[i] << endl;
		}
	}
}
