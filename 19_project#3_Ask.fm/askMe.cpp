#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

struct user {
  std::string user_name, name, password, email;
  int id;
  bool aq;

  void add(std::ofstream &users) {
    std::cout << "Enter username (nospaces): ";
    std::cin >> user_name;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Allow anonymous questions? (0 or 1): ";
    std::cin >> aq;

    saveToFile(users);
  }

  void saveToFile(std::ofstream &users) {
    users << id << "," << user_name << "," << password << "," << name << ","
          << email << "," << aq << "\n";
  }
};

struct askme_sys {
  bool logedin{false};
  std::ofstream users;

  askme_sys() {
    users.open("users.txt", std::ios::app);
    if (users.fail()) {
      std::cerr << "Error opennig file.\n";
      exit(1);
    }
  }

  int menu(bool logedin) {
    int choice{};
    if (!logedin) {
      std::cout << "\nMenu:\n"
                << "\t1: Login\n"
                << "\t2: Sing up\n";
      std::cout << "\nEnter number in range 1 - 2: ";
    } else {
      std::cout << "\nMenu:\n"
                << "\t1: Print Questions To Me\n"
                << "\t2: Print Questions From Me\n"
                << "\t3: Answer Question\n"
                << "\t4: Delete Question\n"
                << "\t5: Ask Question\n"
                << "\t6: List System Users\n"
                << "\t7: Feed\n"
                << "\t8: Logout\n";
      std::cout << "\nEnter number in range 1 - 8: ";
    }
    std::cin >> choice;
    return choice;
  }

  void run() {
    int choice;
    while ((choice = menu(logedin)) && choice != 8) {
      if (choice == 1 && !logedin) {
        // user.login();
      } else if (choice == 2 && !logedin) {
        user new_user;
        new_user.add(users);
        logedin = true;
      }
    }
  }
};

int main() {
  askme_sys sys;
  sys.run();

  return 0;
}
