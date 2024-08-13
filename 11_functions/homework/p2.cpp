#include <iostream>
using namespace std;

void reverseStr(string &str) {
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int main() {
    string str;
    cout << "Stirng: ";
    cin >> str;

    reverseStr(str);
    cout << "Reversed: " << str << endl;
    return 0;
}
