#include <iostream>
using namespace std; 

int main() {
    int n1, n2, swap;
    cin >> n1 >> n2;

    // todo
    swap = n1;
    n1 = n2;
    n2 = swap;
    
    cout<< n1 << " " << n2 << endl;

    return 0; 
}
