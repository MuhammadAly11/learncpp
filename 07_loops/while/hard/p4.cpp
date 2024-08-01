#include <iostream>
using namespace std;

int main() {
	cout << "runs: ";
	int r;
	cin >> r;
	
	while (r) {
		int N;
		cout << "howmany: ";
		cin >> N;
		int i {1}, res {0};
		while (i <= N) {
			cout << "number " << i << " : ";
			int num;
			cin >> num;
			int j = 0, powered = 1;
			while (j < i) {
				powered *= num;
				j++;
			}
			res += powered;
			i++;
		}
		cout << "result: " << res << endl;
	
		r--;
	}
}
