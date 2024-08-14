#include <iostream>
using namespace std;

void sequence(int num) {
    cout << num << " ";

    if (num == 1)
        return;

    if (num % 2 == 0) {
        num /= 2;
    } else {
        num = 3 * num + 1;
    }

    sequence(num);
}

int main() {
    int num;
    cout << "Number: ";
    cin >> num;

    sequence(num);
    cout << endl;
    return 0;
}
