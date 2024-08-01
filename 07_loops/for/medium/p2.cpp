#include <iostream>
using namespace std;

int main() {
	int cnt = 0, end = 200;
	for (int a = 1; a <= end; a++) {
		for (int b = 1; b <= end; b++) {
			for (int c = 1; c <= end; c++) {
				int d = (a+b) - c;
				cnt += ( 1 <= d && d <= end);
			}
		}
	}

	cout << "output: " << cnt << endl;
	return 0;
}
