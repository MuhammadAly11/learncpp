#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

struct askme_sys {
  bool is_logedin{false};
  std::ofstream users;

  askme_sys() {
    users.open("users.txt");
    if (users.fail()) {
      std::cerr << "Error opennig file.\n";
      exit(1);
    }
  }

  void add_user() {
    std::string user_name, name, password, email;
    int id;
    bool aq;
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

    users << id << "," << user_name << "," << password << "," << name << ","
          << email << "," << aq;
  }

  int menu(bool is_first) {
    int choice{};
    if (is_first) {
      std::cout << "Menu:\n"
                << "\t1: Login\n"
                << "\t2: Sing up\n";
      std::cout << "Enter number in range 1 - 2: ";
    } else {
      std::cout << "Menu:\n"
                << "\t1: Print Questions To Me\n"
                << "\t2: Print Questions From Me\n"
                << "\t3: Answer Question\n"
                << "\t4: Delete Question\n"
                << "\t5: Ask Question\n"
                << "\t6: List System Users\n"
                << "\t7: Feed\n"
                << "\t8: Logout\n";
      std::cout << "Enter number in range 1 - 8: ";
    }
    std::cin >> choice;
    return choice;
  }

  void run() {
    while (int choice = menu(is_logedin) && choice != 8) {
      if (choice == 1 && !is_logedin) {
        add_user();
        is_logedin = true;
      }
    }
  }

};

int main() {
  askme_sys sys;
  sys.run();

  return 0;
}
