#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct book {
  int id{};
  string name;
  int quantity;
  int borrowed{};
};

struct user {
  string name;
  int id{};
};

struct borrowing {
  int book_id[MAX_SIZE];
  int user_id[MAX_SIZE];
  int len{};
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

  int find(const string &name) {
    for (int i = 0; i < len; i++) {
      if (books[i].name == name) {
        return books[i].id;
      }
    }
    return -1;
  }
  int find(int id) {
    for (int i = 0; i < len; i++) {
      if (books[i].id == id) {
        return i;
      }
    }
    return -1;
  }
};

struct library_users {
  user users[MAX_SIZE];
  int len{};

  void add() {
    int id;
    string name;
    cout << "Enter your name & national id: ";
    cin >> name >> id;
    users[len].id = id;
    users[len].name = name;
    len++;
  }

  void print() {}

  int find(const string &username) {
    for (int i = 0; i < len; i++) {
      if (users[i].name == username) {
        return users[i].id;
      }
    }
    return -1;
  }

  int find(int id) {
    for (int i = 0; i < len; i++) {
      if (users[i].id == id) {
        return i;
      }
    }
    return -1;
  }
};

void borrow(library_users &users, library_books &library, borrowing &borrows) {
  string username, bookname;
  cout << "Enter user name & book name: ";
  cin >> username >> bookname;
  int user_id = users.find(username);
  if (user_id == -1) {
    cout << "This user isn't in our database.\n";
    return;
  }
  int book_id = library.find(bookname);
  if (book_id == -1) {
    cout << "This book isn't in our database.\n";
    return;
  }
  if (library.books[library.find(book_id)].quantity <=
      library.books[library.find(book_id)].borrowed) {
    cout << "Sorry, Book total quantity is zero\n";
    return;
  }
  borrows.user_id[borrows.len] = user_id;
  borrows.book_id[borrows.len] = book_id;
  borrows.len++;
  library.books[library.find(book_id)].borrowed++;
}

void return_book(library_users &users, library_books &library,
                 borrowing &borrows) {
  cout << "Enter user name & book name: ";
  string username, bookname;
  cin >> username >> bookname;
  int user_id = users.find(username);
  if (user_id == -1) {
    cout << "This user isn't in our database.\n";
    return;
  }
  int book_id = library.find(bookname);
  if (book_id == -1) {
    cout << "This book isn't in our database.\n";
    return;
  }
  for (int i = 0; i < borrows.len; i++) {
    if (borrows.book_id[i] == book_id && borrows.user_id[i] == user_id) {
      borrows.book_id[i] = -1;
      borrows.user_id[i] = -1;
    }
  }
  library.books[library.find(book_id)].borrowed--;
}

void print_borrowers(library_users &users, library_books &library,
                     borrowing &borrows) {
  cout << "Enter book name: ";
  string name;
  cin >> name;
  int book_id = library.find(name);
  if (book_id == -1) {
    cout << "This book isn't in our database.\n";
    return;
  }
  for (int i = 0; i < borrows.len; i++) {
    if (borrows.book_id[i] == book_id) {
      int id = borrows.user_id[i];
      cout << users.users[users.find(id)].name << "\n";
    }
  }
}

void print_users(library_users &users, library_books &library,
                 borrowing &borrows) {
  for (int i = 0; i < users.len; i++) {
    cout << "user " << users.users[i].name << ", id " << users.users[i].id
         << ", borrowed books ids: ";
    for (int j = 0; j < borrows.len; j++) {
      if (users.users[i].id == borrows.user_id[j]) {
        cout << borrows.book_id[j] << " ";
      }
    }
    cout << "\n";
  }
}

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
  freopen("c.in", "r", stdin);
  library_books library;
  library_users users;
  borrowing borrows;
  for (int i = 0; i < MAX_SIZE; i++) {
    borrows.book_id[i] = -1;
    borrows.user_id[i] = -1;
  }
  print_menu();
  while (true) {
    int choice = menu();
    if (choice == 11)
      break;
    else if (choice == 1)
      library.add();
    else if (choice == 2)
      library.search();
    else if (choice == 3)
      print_borrowers(users, library, borrows);
    else if (choice == 4)
      library.print();
    else if (choice == 5)
      library.print("name");
    else if (choice == 6)
      users.add();
    else if (choice == 7)
      borrow(users, library, borrows);
    else if (choice == 8)
      return_book(users, library, borrows);
    else if (choice == 9)
      print_users(users, library, borrows);
    else if (choice == 10)
      print_menu();
  }
  cout << "Bye Bye\n";
}

int main() {
  libSystem();
  return 0;
}
