#include <iostream>
using namespace std;

int main() {
    cout << "This program will tell you how many numbers <= x and how many > x\n";
    cout << "Enter x: ";
    int x;
    cin >> x;
    cout << "Enter 5 integers: ";
    int n1, n2, n3, n4, n5;
    cin >> n1>> n2>> n3>> n4>> n5; 
    int less {0}, more {0};
    if (n1 > x)
	more++;
    else
	less++;
    if (n2 > x)
	more++;
    else
	less++;
    if (n3 > x)
	more++;
    else
	less++;
    if (n4 > x)
	more++;
    else
	less++;
    if (n5 > x)
	more++;
    else
	less++;

    cout << "nums <= x: " << less << endl;
    cout << "nums > x: " << more << endl;
    
    return 0;
}


// I knew this is a poor solution
