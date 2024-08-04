#include <iostream>
using namespace std;

int main() {
  const int size{20};
  int salarys[size] {};
  int ages[size] {};
  string names[size] {};
  char genders[size] {};
  int next = {};
  while (true) {
    cout << "\nEnter your choice:\n"
         << "1) Add new employee\n"
         << "2) Print all employees\n"
         << "3) Delete by age\n"
         << "4) Upadte salary by name\n";

    int choice;
    cin >> choice;
    if (choice == 1) {
      cout << "Enter name: ";
      cin >> names[next];
      cout << "Enter age: ";
      cin >> ages[next];
      cout << "Enter salary: ";
      cin >> salarys[next];
      cout << "Enter gender (M/F): ";
      cin >> genders[next];
    } else if (choice == 2) {
      cout << "*****************\n";
      for (int i = 0; i < size; i++) {
        if (salarys[i]) {
          cout << names[i] << "\t" << ages[i] << "\t" << salarys[i] << "\t"
               << genders[i] << endl;
        }
      }
    } else if (choice == 3) {
      cout << "Enter start and end age: ";
      int start, end;
      cin >> start >> end;
      for (int i = 0; i < size; i++) {
        if (start < ages[i] && ages[i] < end) {
          ages[i] = 0;
          salarys[i] = 0;
          names[i] = "";
          genders[i] = ' ';
        }
      }
    } else if (choice == 4) {
      cout << "Enter name and salary: ";
      string name;
      cin >> name;
      int salary;
      cin >> salary;
      for (int i = 0; i < size; i++) {
        if (name == names[i]) {
          salarys[i] = salary;
        }
      }
    }
    next++;
  }
}
