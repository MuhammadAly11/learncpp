#include<iostream>
using namespace std;

void do_something1(int n) {	// print number digit by digit reversed
	if (n) {
		cout << n % 10;
		do_something1(n / 10);
	}
}

void do_something2(int n) {
	if (n) {
		do_something2(n / 10);
		cout << n % 10;
	}
}

int main() {
	do_something1(123456);
	cout << "\n";
	do_something2(123456);

	return 0;
}


// trace without running code
// 1 ==> print the number reversed
// 2 ==> print the number is it's

