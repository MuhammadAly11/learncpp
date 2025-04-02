/*  This project focuses on design and doesn't care
 *  about details like spaces in string
 *  I will try implementing it using MVC pattern*/
#include <iostream>
#include <string>
#include <vector>

enum class LoginStatus { LOGED_IN, LOGED_OUT };
enum class UserStatus { ADMIN, USER };

class UserModel {
private:
  std::string name;
  std::string email;
  std::string username;
  std::string password;

public:
  std::string getName() const { return name; }
  std::string getEmail() const { return email; }
  std::string getUsername() const { return username; }
  std::string getPassword() const { return password; }

  void setName(const std::string &name) { this->name = name; }
  void setEmail(const std::string &email) { this->email = email; }
  void setUsername(const std::string &username) { this->username = username; }
  void setPassword(const std::string &password) { this->password = password; }
};

class UserView {
public:
  void printMenu() {}
  void showProfile() {}
  void listHistory() {}
  void listBooks() {}

  UserModel inputAddUser() {
    std::string tmp;
    UserModel userData;

    std::cout << "Enter username (no spaces): ";
    std::cin >> tmp;
    userData.setUsername(tmp);
    std::cout << "\nEnter password (no spaces): ";
    std::cin >> tmp;
    userData.setPassword(tmp);
    std::cout << "\nEnter name (no spaces): ";
    std::cin >> tmp;
    userData.setName(tmp);
    std::cout << "\nEnter email (no spaces): ";
    std::cin >> tmp;
    userData.setEmail(tmp);

    return userData;
  }
};

class UserController {
private:
  UserModel &userModel;
  UserView &userView;

public:
  UserController(UserModel &userModel, UserView &userView)
      : userModel(userModel), userView(userView) {}

  void addUser() { userModel = userView.inputAddUser(); }
};

class UserRepo {
private:
  std::vector<UserModel> users;

public:
  bool add(UserModel &curUser) { users.push_back(curUser); }
  UserModel *findUser(const std::string &username) {
    for (UserModel cur : users) {
      if (cur.getUsername() == username) {
        return &cur;
      }
    }
  }
};

class systemManager {
private:
  UserRepo userRepo;
  UserModel currentUser;
  UserView userView;
  UserController userController;
  LoginStatus loginStatus = LoginStatus::LOGED_OUT;
  UserStatus userStatus;

public:
  systemManager() : userController(currentUser, userView) {}

  void run() {
    while (loginStatus == LoginStatus::LOGED_OUT) {
      int choice = startMenu();
      switch (choice) {
      case 1:
      case 2:
      }
    }
  }

  void handelSingup() {
    userController.addUser();
    userRepo.add(currentUser);
  }

  int startMenu() {
    std::cout << "\nMenu:\n"
              << "\t 1: Login\n"
              << "\t 2: Signup\n"
              << "\n"
              << "Enter number in range 1 - 2: ";

    int choice;
    std::cin >> choice;
    return choice;
  }
};

int main() {
  systemManager system;
  system.run();
}
