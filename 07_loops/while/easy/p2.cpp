#include <iostream>
using namespace std;

int main () {
    int num;
    char c;
    cout << "positive intger: ";
    cin >> num;
    cout << "char: ";
    cin >> c;

    while (num > 0) {
	cout << c;
	num--;
    }
    cout << "\n";

    return 0;
}
