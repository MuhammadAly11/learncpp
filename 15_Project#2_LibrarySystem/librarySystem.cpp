#include <algorithm>
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

bool cmp_name(book &a, book &b) { return a.name < b.name; }
bool cmp_id(book &a, book &b) { return a.id < b.id; }

struct library_books {
  book books[MAX_SIZE];
  int len{};

  void add() {
    string name;
    int id, quantity;
    cout << "Enter book info: id & name & total quantity: ";
    cin >> id >> name >> quantity;
    books[len].name = name;
    books[len].id = id;
    books[len].quantity = quantity;
    len++;
  }

  void search() {
    string pre;
    cout << "Enter book name prefix: ";
    cin >> pre;
    for (int i = 0; i < len; i++) {
      if (is_prefix(books[i].name, pre)) {
        cout << books[i].name << endl;
      }
    }
  }

  void print(string type = "id") {
    if (type == "name")
      sort(books, books + len, cmp_name);
    else
      sort(books, books + len, cmp_id);
    for (int i = 0; i < len; i++) {
      cout << "id = " << books[i].id << ", name = " << books[i].name
           << ", quantitiy " << books[i].quantity << ", borrowed "
           << books[i].borrowed << endl;
    }
  }
};

struct library_users {
  user users[MAX_SIZE];

  void add(string name, int id) {}

  void print() {}
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
    cout << "\nEnter your choice [1 - 11]: ";
    cin >> choice;
    if (1 > choice || choice > 11) {
      cout << "Invalid input. Input must be between 1 and 11\n"
           << "Enter 10 to print the menu. Please try again\n";
      choice = -1;
    }
  }
  return choice;
}

void libSystem() {
  library_books library;
  library_users users;
  print_menu();
  while (true) {
    int choice = menu();
    if (choice == 11)
      break;
    else if (choice == 1)
      library.add();
    else if (choice == 2)
      library.search();
    else if (choice == 4)
      library.print();
    else if (choice == 5)
      library.print("name");
    else if (choice == 10)
      print_menu();
  }
  cout << "Bye Bye\n";
}

int main() {
  libSystem();
  return 0;
}
