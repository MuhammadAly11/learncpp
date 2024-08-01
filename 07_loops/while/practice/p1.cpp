#include <iostream>
using namespace std;

int main() {
    cout << "enter an integer: ";
    int num, cnt {3};
    cin >> num;

    while (cnt <= num) {
	cout << cnt << ", ";
	cnt += 3;
    }
    cout << "\n end\n";
    return 0;
}
