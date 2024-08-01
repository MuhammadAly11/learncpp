#include <iostream>
using namespace std; 

int main() {
    cout << "Enter 2 numbers (start and end): ";
    int start, end;
    cin >> start >> end;

    int sum = end * (end+1) / 2;
    cout << "Sum ot numbers from 1 to " << end << " = " << sum << "\n";

    int sum_to_start = (start-1) * (start) / 2;
    int sum_from_start = sum - sum_to_start;
    cout<< "Sum ot numbers from" << start <<  " to " << end << " = "
	<< sum_from_start << "\n";

    return 0; 
}
