#include <iostream>
using namespace std;

int main() {
	const int size = 200;
	int idx;
	cout << "index (1, 200): ";
	cin >> idx;

	int recaman[size] {};
	bool marked[size] {};
	for (int i = 1; i <= idx; i++) {
		int last_value = recaman[i-1];
		int last_idx = i - 1;
		int value = last_value - last_idx - 1;
		if (!(value > 0) || marked[value]) {
			value = last_value + last_idx + 1;
		}
		marked[value] = 1;
		recaman[i] = value;
	}
	
	cout << idx << " --> " << recaman[idx] << endl;
}
