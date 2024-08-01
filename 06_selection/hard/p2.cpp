#include <iostream>
using namespace std;

int main() {
    int s1, e1, s2, e2, ctn {0};

    cout << "Enter 2 intervals"
    << endl << "start [space] end\n";

    cin >> s1 >> e1;
    cin >> s2 >> e2;

    cout << "Interval: ";
    if (s1 <= s2 && s2 <= e1) {
	cout << s2;
	if (s1 <= e2 && e2 <= e1) 
	    cout << "-->" << e2 << endl;
	else
	    cout << "-->" << e1 << endl;
    }
    else {
	if (s1 <= e2 && e2 <= e1) {
	    cout << s1;
	    cout << "-->" << e2 << endl;
	}
	else
	    cout << -1 << endl;
    }

    return 0;
}
