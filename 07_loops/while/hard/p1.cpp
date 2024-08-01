#include <iostream>
using namespace std;

int main() {
	int words;
	cout << "number of words: ";
	cin >> words;

	string word;
	int i = 1;
	while (i <= words) {
		cout << "word" << i << ": ";
		cin >> word;
		if (word == "no" || word == "No" || word == "nN" || word == "NO" || 
			word == "on" || word == "On" || word == "oN" || word == "ON") {
			cout << "output: " << word << endl;
		}

		i++;
	}
}
