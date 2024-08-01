#include <iostream>
using namespace std;

int main() {
    int num, res {0};
    cout << "number: ";
    cin >> num;

    if (num == 0)
	res = 1;
    while (num != 0) {
	num /= 10;
	res ++;
    }

    cout << "digits: " << res;
    cout << "\nbye bye\n";
    return 0;
}


// bug: treat the case where the input is zero
