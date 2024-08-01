#include <iostream>
using namespace std;

int main() {
	int cnt = 0;
	for (int y = 70; y <= 400; y++) {
		for (int x = 50;x <= 300 && x < y; x++)
			cnt+= ( (x + y) % 7 == 0 );
	}
	cout << "output: " << cnt << endl;
	cout << "Bye Bye\n";
}

// optimized solution 
// x don't loop if it's not less the y
