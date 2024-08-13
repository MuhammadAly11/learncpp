#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    int maxValue = a;
    if (maxValue < b)
        maxValue = b;
    if (maxValue < c)
        maxValue = c;
    return maxValue;
}

int max(int a, int b, int c, int d) {
    int maxValue = max(a, b, c);
    if (maxValue < d)
        maxValue = d;
    return maxValue;
}

int max(int a, int b, int c, int d, int e) {
    int maxValue = max(a, b, c, d);
    if (maxValue < e)
        maxValue = e;
    return maxValue;
}

int max(int a, int b, int c, int d, int e, int f) {
    int maxValue = max(a, b, c, d, e);
    if (maxValue < f)
        maxValue = f;
    return maxValue;
}

int main() {
    cout << "6 numbers: ";
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int maxValue = max(a, b, c, d, e, f);
    cout << "Max value ===> " << maxValue << endl;
    return 0;
}
