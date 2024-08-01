#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive intger: ";
    double num;
    cin >> num;

    double sum {0};
    num = num / 10;
    sum += num - (int)num;
    num = (int)num;
    num = num / 10;
    sum += num - (int)num;
    num = (int)num;
    num = num / 10;
    sum += num - (int)num;

    cout << sum * 10 << "\n";
}
