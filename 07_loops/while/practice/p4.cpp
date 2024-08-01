#include <iostream>
using namespace std;

int main() {
    int num, t;
    cout << "Times: ";
    cin >> t;

    while (t > 0) {
	cout << "number: ";
	cin >> num;

	int sum = num * (num +1) / 2;
	cout << "Sum = " << sum << endl;

	t--;
    }

    cout << "bye bye\n";
    return 0;
}


// bug: treat the case where the input is zero
