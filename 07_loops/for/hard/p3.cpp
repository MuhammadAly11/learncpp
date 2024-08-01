// couldn't solve it .. course solution: 

#include <iostream>
using namespace std;

int main() {
	int n, m, w;
	cout << "n: "; cin >> n;
	cout << "m: "; cin >> m;
	cout << "w: "; cin >> w;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			int c = j + i;
			if (1 <= c && c <= w) {
				cnt += w - c + 1;
			}
		}
	}
	cout << "result: " << cnt << endl;
}


