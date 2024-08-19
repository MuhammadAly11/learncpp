#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct book {
  int id{};
  string name;
  int quantity;
  int borrowed{};
  string borrowers[MAX_SIZE];
};

struct user {
  string name;
  int id{};
};

bool is_prefix(const string &str, const string &pre) {
  for (int i = 0; i < pre.length(); i++) {
    if (pre[i] != str[i]) {
      return false;
    }
  }
  return true;
}

struct library_books {
  book books[MAX_SIZE];
  int len{};

  void add(string name, int id, int quantity) {
    books[len].name = name;
    books[len].id = id;
    books[len].quantity = quantity;
    len++;
  }

  void search(string prefix) {
  }

  void print(string sort) {
    // by id or name
  }
};

struct library_users {
  user users[MAX_SIZE];

  void add(string name, int id) {
  }

  void print() {
  }
};

void print_menu() {
  cout << "\nLibrary Menu: \n"
       << "1) Add book\n"
       << "2) Search book by prefix\n"
       << "3) Print who borrowed book by name\n"
       << "4) Print library by id\n"
       << "5) Print library by name\n"
       << "6) Add user\n"
       << "7) Borrow book\n"
       << "8) Retrun book\n"
       << "9) Print all users\n"
       << "10) Print this menu\n"
       << "11) Exit\n";
}

int menu() {
  int choice{-1};
  while (choice == -1) {
    cout << "\nEnter your choice [1 - 10]: ";
    cin >> choice;
    if (1 > choice || choice > 10) {
      cout << "Invalid input. Input must be between 1 and 11\n"
           << "Enter 10 to print the menu. Please try again\n";
      choice = -1;
    }
  }
  return choice;
}

void libSystem() {
  int chioce = menu();
  return;
}

int main() {
  libSystem();
  return 0;
}
