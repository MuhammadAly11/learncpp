#include <iostream>
#include <string>
using namespace std;

int main() {
    string name1, id1;
    double grade1;

    cout << "what is student 1 name: ";
    cin >> name1; 
    cout << "His id: ";
    cin >> id1; 
    cout << "His math exam grade: ";
    cin >> grade1; 

    string name2, id2;
    double grade2;

    cout << "what is student 2 name: ";
    cin >> name2; 
    cout << "His id: ";
    cin >> id2; 
    cout << "His math exam grade: ";
    cin >> grade2; 

    cout<< "Students grades in math\n";
    cout<< name1 << " (with id " << id1 << ") got grade: " << grade1 << endl;
    cout<< name2 << " (with id " << id2 << ") got grade: " << grade2 << endl;
    cout<< "Average grade is " << (grade1+grade2) / 2 << endl;

    return 0;
}
