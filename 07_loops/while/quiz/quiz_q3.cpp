#include<iostream>
using namespace std;
 
int main() {
    int x = 0;
 
    while(x++ < 50) {

	cout << x << endl;

	cout<<x++<<" ";

	cout << x << endl;

	++x += 10;

	cout << x << endl;
    }
    return 0;
}
