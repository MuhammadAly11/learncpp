#include <iostream>
using namespace std;

int main() {
	int N, M;
	cout << "N: ";
	cin >> N;
	cout << "M: ";
	cin >> M;

	int i {1};
	while (i <= N) {
		int j = 1;
		while (j <= M) {
			cout << i << "  *  " << j << "  =  " << i * j << endl;
			j++;
		}
		i++;
	}
}
