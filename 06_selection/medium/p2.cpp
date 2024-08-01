#include <iostream>
using namespace std;

int main() {
    int n, tmp;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter " << n << " nummbers one by one\n";

    cin >> tmp;
    n--;
    int res = tmp;

    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;
    if (n > 0)	cin >> tmp; n--; if(res < tmp)	res = tmp;

    cout << "Maximum ==> " << res << endl;
}

// inspired by p1 solution
//
// after seeing the solution: my solution works but it will run even if n !> 0
// I should put all the code under first if condition
