#include <iostream>
using namespace std;

int main () {
    int start, end;
    cout << "enter start: ";
    cin >> start;
    cout << "enter end: ";
    cin >> end;

    while (start <= end) {
	cout << start << endl;
	start++;
    }

    return 0;
}
