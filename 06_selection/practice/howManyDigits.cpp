#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive integer: ";
    int num;
    cin >> num;

    int digits {0};
    if (num / 10 == 0) {
	cout << "Output: " << "1" << "digits\n";
    }
    else if (num / 100 == 0) {
	cout << "Output: 2 digits\n";
    }
    else if (num / 1000 == 0) {
	cout << "Output: 3 digits\n";
    }
    else if (num / 10000 == 0) {
	cout << "Output: 4 digits\n";
    }
    else {
	cout << "Output: 5+ digits\n";
    }
}
