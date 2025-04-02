/*  This project focuses on design and doesn't care
 *  about details like spaces in string
 *  I will try implementing it using MVC pattern*/
#include <iostream>
#include <string>

enum class LoginStatus { LOGED_IN, LOGED_OUT };
enum class UserStatus { ADMIN, USER };

class UserView {
public:
  void printMenu() {}
  void showProfile() {}
  void listHistory() {}
  void listBooks() {}
};

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

class UserController {
private:
  UserModel &userModel;
  UserView &userView;

public:
  UserController(UserModel &userModel, UserView &userView)
      : userModel(userModel), userView(userView) {}
};

class systemManager {
private:
  UserView userView;
  UserModel userModel;
  UserController userController(UserModel, UserView);
  LoginStatus loginStatus = LoginStatus::LOGED_OUT;
  UserStatus userStatus;

public:
  void run() {
    while (loginStatus == LoginStatus::LOGED_OUT) {
      int choice = startMenu();
    }
  }

  int startMenu() {
    std::cout << "Menu:\n"
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
