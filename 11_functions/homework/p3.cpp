#include <iostream>
using namespace std;

double add(double x, double y) { return x + y; }
double subtract(double x, double y) { return x - y; }
double multiply(double x, double y) { return x * y; }
double divide(double x, double y) { return x / y; }

void readNums(double &x, double &y) {
  cout << "Enter 2 numbers: ";
  cin >> x >> y;
}

int menu() {
  int choice;
  while (true) {
    cout << "1) Add 2 numbers" << endl
         << "2) Subtract 2 numbers" << endl
         << "3) Multiply 2 numbers" << endl
         << "4) Divide 2 numbers" << endl
         << "5) End the program" << endl;
    cin >> choice;

    if (1 <= choice && choice <= 5) {
      break;
    }
    cout << "Invalid option. Try again.\n";
  }
  return choice;
}

void calculate() {
  int operations{};
  while (true) {
    int choice = menu();
    if (choice == 5) {
      cout << "You have done " << operations << " operations" << endl;
      break;
    }
    operations++;

    double x, y;
    readNums(x, y);

    if (choice == 1)
      cout << add(x, y) << endl;
    else if (choice == 2)
      cout << subtract(x, y) << endl;
    else if (choice == 3)
      cout << multiply(x, y) << endl;
    else {
      if (y == 0) {
        cout << "division by zero isn't allowed\n";
        continue;
      }
      cout << divide(x, y) << endl;
    }
  }
}

int main() {
  calculate();
  return 0;
}
