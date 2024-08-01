#include <iostream>
using namespace std;

int main() {
    int num, power, res {1};
    cout << "number: ";
    cin >> num;
    cout << "power: ";
    cin >> power;

    while (power > 0) {
	res *= num;
	power--;
    }

    cout << "Asnwer: " << res;
    cout << "\nbye bye\n";
    return 0;
}
