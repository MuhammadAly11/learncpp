#include <iostream>
using namespace std;

int main() {
    int nb, ng, nt;
    cout<< "Enter number of boys, girls and teachers: ";
    cin>> nb>> ng>> nt;

    cout<< "nb > 25 --> "<< (nb > 25) << endl;
    cout<< "ng <= 30 --> "<< (ng <= 30) << endl;
    cout<< "nb > 20 and nt > 2 OR ng > 30 and nt > 4 --> "
	<< (nb > 20 && nt > 2 || ng > 30 && nt > 4)<< endl;
    cout<< "nb < 60 OR ng < 70 --> "
	<< (nb < 60 || ng < 70)<< endl;
    cout<< "nb !>= 60 OR ng !>= 70 --> " // neither nor 
	//worng << (nb < 60 || ng < 70)<< endl; // worng
	<< ( ( !(nb >= 60) && !(ng >= 70) ) );
    cout<< "nb is 10 more than ng --> "
	<< (nb == ng + 10)<< endl;
    cout<< "Difference between nb and ng is more than 10 or nt > 5 --> "
	<< ((nb - ng > 10) || (ng - nb) > 10 || nt > 5)<< endl;
    cout<< "Either nb is 10 more students than ng or ng is 15 more students than nb --> "
	<< (nb == ng + 10 || ng == nb + 15)<< endl;
}
