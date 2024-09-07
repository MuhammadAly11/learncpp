#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

const std::string USERS_FILE{"users.txt"};
const std::string QESTIONS_FILE{"questions.txt"};

std::fstream open_file(std::string outFile, bool write = false) {
  std::fstream usersio;
  if (write) {
    usersio.open(outFile, std::ios::out | std::ios::app);
  } else {
    usersio.open(outFile, std::ios::in);
  }
  if (usersio.fail()) {
    std::cerr << "Error opening file.\n";
    exit(1);
  }
  return usersio;
}

std::string getLastLine(std::string File) {
  std::fstream users = open_file(File);
  std::string last_line, cur_line;
  while (std::getline(users, cur_line)) {
    if (!cur_line.empty())
      last_line = cur_line;
  }
  users.close();
  return last_line;
}

struct User {
  std::string user_name, name, password, email;
  int id;
  bool aq;

  void print() {
    std::fstream users = open_file(USERS_FILE);
    std::string user, tmp;
    while (std::getline(users, user)) {
      std::stringstream ss(user);
      std::getline(ss, tmp, ',');
      std::cout << "ID: " << tmp;
      std::getline(ss, tmp, ',');
      std::getline(ss, tmp, ',');
      std::getline(ss, tmp, ',');
      std::cout << "\tName: " << tmp << "\n";
    }
  }

  bool signup() {
    std::cout << "Enter username (nospaces): ";
    std::cin >> user_name;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Allow anonymous questions? (0 or 1): ";
    std::cin >> aq;
    id = lastId() + 1;
    std::string user = findUser();
    if (!user.empty()) {
      std::cout << "This user name is already taken.\n";
      return false;
    }
    saveToFile();
    return true;
  }

  bool login() {
    std::cout << "Enter username & password: ";
    std::cin >> user_name >> password;
    std::string user = findUser();
    if (user.empty() || user == user_name) {
      std::cout << "Wrong username or password.\n";
      return false;
    }
    // Accept user and set user data
    userData(user);
    return true;
  }

  std::string findUser() {
    std::string line;
    std::fstream users = open_file(USERS_FILE);
    std::string tmp_user = ',' + user_name + ',',
                tmp_password = ',' + password + ',';
    while (getline(users, line)) {
      if (line.find(tmp_user) != std::string::npos &&
          line.find(tmp_password) != std::string::npos) {
        users.close();
        return line;
      } else if (line.find(tmp_user) != std::string::npos) {
        users.close();
        return user_name;
      }
    }
    users.close();
    return "";
  }

  void userData(std::string user) {
    std::stringstream ss(user);
    std::string tmp;

    std::getline(ss, tmp, ',');
    id = std::stoi(tmp);
    std::getline(ss, tmp, ',');
    user_name = tmp;
    std::getline(ss, tmp, ',');
    password = tmp;
    std::getline(ss, tmp, ',');
    name = tmp;
    std::getline(ss, tmp, ',');
    email = tmp;
    std::getline(ss, tmp, ',');
    aq = std::stoi(tmp);
  }

  void saveToFile() {
    std::fstream users = open_file(USERS_FILE, true);
    users << id << "," << user_name << "," << password << "," << name << ","
          << email << "," << aq << "\n";
    users.close();
  }

  int lastId() {
    std::string last_user = getLastLine(USERS_FILE);
    if (last_user.empty())
      return 0;
    std::stringstream ss(last_user);
    std::string last_id;
    std::getline(ss, last_id, ',');
    return std::stoi(last_id);
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
        logedin = user.signup();
      } else if (choice == 6) {
        user.print();
      }
    }
  }
};

int main() {
  askme_sys sys;
  sys.run();

  return 0;
}
