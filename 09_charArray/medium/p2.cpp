#include <iostream>
using namespace std;

int main() {
	string first, second;
	cout << "first: ";
	cin >> first;
	cout << "second: ";
	cin >> second;

	int size = first.size();
	if (size > second.size())
		size = second.size();

	int cnt {};
	for (int i = 0; i < size; i++) {
		if (first[i] < second[i]) {
			cout << "Is first <= second? Yes\n";
			return 0;
		} else if (first[i] == second[i]) {
			++cnt;
		} else {
			cout << "Is first <= second? No\n";
			return 0;
		}
		if (cnt == first.size()) {
			cout << "Is first <= second? Yes\n";
			return 0;
		}
	}
	cout << "Is first <= second? No\n";
}
