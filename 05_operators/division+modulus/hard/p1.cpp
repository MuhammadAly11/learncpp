#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of days: ";
    int days;
    cin >> days;

    int years = days / 360;
    days -= years * 360;

    int months = days / 30;
    days -= months * 30;

    cout << "years: " << years << endl
	<< "months: " << months << endl
	<< "days: " << days << endl;
}
