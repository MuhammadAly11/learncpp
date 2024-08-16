#include <iostream>
using namespace std;

const int SPECIALIZATIONS = 15;
const int QUEUE = 15;
string patients[SPECIALIZATIONS][QUEUE]{};
int statuses[SPECIALIZATIONS][QUEUE];

int choose() {
  int choice = -1;
  while (choice == -1) {
    cout << "1) Add new patient\n"
         << "2) Print all patients\n"
         << "3) Get next patient\n"
         << "4) Exit\n"
         << "Enter your choice:";
    cin >> choice;
    if (1 > choice || choice > 4) {
      cout << "Invalid input, Try agian.\n\n";
      choice = -1;
    }
  }
  return choice;
}

bool valid_patient(int &specialization, string &name, int &status) {
  cout << "Enter specialization, name, status: ";
  cin >> specialization >> name >> status;
  if (1 > specialization || specialization > 15 || 1 < status || status < 0) {
    return false;
  }
  return true;
}

int count_patients(const int specialization) {
  int cnt{specialization};
  for (int i = 0; i < QUEUE; i++) {
    if (statuses[specialization][i] == -1)
      cnt--;
  }
  return cnt;
}

void prepend(int specialization, const string &name) {
  for (int i = QUEUE; i > 1; i--) {
    patients[specialization][i-1] = patients[specialization][i-2]; 
    statuses[specialization][i-1] = statuses[specialization][i-2]; 
  }
  patients[specialization][0] = name; 
  statuses[specialization][0] = 1;
}

void append(int specialization, const string &name) {
  int next = count_patients(specialization);
  patients[specialization][next] = name; 
  statuses[specialization][next] = 0;
}

bool add_patient() {
  int specialization, urgent;
  string name;
  if (!valid_patient(specialization, name, urgent)) {
    cout << "Invalid input. try agian.\n\n";
    return 0;
  }
  if (count_patients(specialization) == QUEUE) {
    cout << "Sorry we can't add more patients for this specialization\n\n";
    return 0;
  }
  if (urgent) {
    prepend(specialization, name);
  } else {
    append(specialization, name);
  }
  return 1;
}

void hospital() {
  int cnt{};
  while (true) {
    int choice = choose();
    if (choice == 1) {
      cnt += add_patient();
    } else if (choice == 2) {
      // cnt += print_all();
    } else if (choice == 3) {

    } else {
      break;
    }
  }
  cout << "You have done " << cnt << " successful operations.\n";
}

void set_arrays() {
  for (int i = 0; i < SPECIALIZATIONS; i++)
    for (int j = 0; j < QUEUE; j++)
      statuses[i][j] = -1;
}

int main() {
  set_arrays();
  hospital();

  return 0;
}
