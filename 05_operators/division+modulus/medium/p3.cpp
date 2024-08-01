#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive intger: ";
    double num;
    cin >> num;

    num /= 10;
    num = int(num);
    num /= 10;
    num = int(num);
    num /= 10;
    num = int(num);

    int digit = (int)num % 10;
    cout << "The 4th digit is: " << digit << endl;
}
