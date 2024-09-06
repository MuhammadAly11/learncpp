#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

const std::string USERS_FILE{"users.txt"};
const std::string QESTIONS_FILE{"questions.txt"};

std::fstream open_file(bool write) {
  std::fstream usersio;
  if (write) {
    usersio.open(USERS_FILE, std::ios::app);
  } else {
    usersio.open(USERS_FILE, std::ios::in);
  }
  if (usersio.fail()) {
    std::cerr << "Error opennig file.\n";
    exit(1);
  }
  return usersio;
}

struct User {
  std::string user_name, name, password, email;
  int id;
  int cur_id;
  bool aq;

  void add() {
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

    saveToFile();
    cur_id++;
  }

  bool login() {
    std::cout << "Enter username & password: ";
    std::cin >> user_name >> password;
    if (find_user() == -1) {
      std::cout << "This user isn't in our database.\n";
      return false;
    }
    return true;
  }

  int find_user() {
    std::fstream users = open_file(false);
    std::string line;
    while (getline(users, line)) {
      if (line.find(user_name) != std::string::npos &&
          line.find(password) != std::string::npos) {
        std::stringstream ss(line);
        while (std::getline(ss, line, ',')) {
          users >> id;
          users >> user_name;
          users >> password;
          users >> name;
          users >> email;
          users >> aq;
          users.close();
          return id;
        }
      }
    }
    users.close();
    return -1;
  }

  void saveToFile() {
    std::fstream users = open_file(true);
    users << id << "," << user_name << "," << password << "," << name << ","
          << email << "," << aq << "\n";
    users.close();
  }
};

struct askme_sys {
  bool logedin{false};

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
    User user;
    while ((choice = menu(logedin)) && choice != 8) {
      if (choice == 1 && !logedin) {
        logedin = user.login();
      } else if (choice == 2 && !logedin) {
        user.add();
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
