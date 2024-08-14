#include <iostream>
using namespace std;

int length_3n_plus_1(int num){
    int length {};

    if (num == 1)
        return 1;

    if (num % 2 == 0)
        num /= 2;
    else
        num = 3 * num + 1;

    return 1 + length_3n_plus_1(num);
}

int main() {
    int num;
    cout << "3n+1 Input: ";
    cin >> num;

    cout << "length ==> " << length_3n_plus_1(num) << endl;
    
    return 0;
}
