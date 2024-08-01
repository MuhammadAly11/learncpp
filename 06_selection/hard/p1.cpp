#include <iostream>
using namespace std;

int main() {
    int x, s, e, ctn {0};
    cout << "Enter a number: ";
    cin >> x;

    cout << "Enter 3 intervals"
    << endl << "start [space] end\n";

    cin >> s >> e;
    if (x > s && x < e)
	ctn++;
    cin >> s >> e; 
    if (x > s && x < e)
	ctn++;
    cin >> s >> e; 
    if (x > s && x < e)
	ctn++;

    cout << "The number exists in " << ctn << " intervals\n";
    return 0;
}
