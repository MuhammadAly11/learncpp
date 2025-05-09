/*  This project focuses on design and doesn't care
 *  about details like spaces in string
 *  I will try implementing it using MVC pattern*/
#include <iostream>
#include <string>
#include <vector>

enum class LoginStatus { LOGED_IN, LOGED_OUT };
enum class UserStatus { ADMIN, USER };

std::string UsedUsernameErr = "This username is already used.";
std::string CredntialsErr = "Incorrect username or password";

class BookData {
private:
  std::vector<std::string> pages;
  std::string name;
  std::string ISBN;
  std::string author;
  int pagesNum;

public:
  BookData() {}
  BookData(std::string name, std::string author, std::string ISBN, int pagesNum,
           std::vector<std::string> pages)
      : name(name), author(author), ISBN(ISBN), pagesNum(pagesNum),
        pages(pages) {}

  int getPageNums() { return pagesNum; }
  void getPage(std::string content, int page) { content = pages.at(page); }
};

class BookModel {
private:
  std::vector<BookData> books;

public:
};

class BookViewer {
public:
  void viewPage(BookData &book, int page = 1) {
    std::cout << "Current Page: " << page << "/" << book.getPageNums() << "\n";
    std::string content;
    int choice = bookMenu();

    book.getPage(content, page);
    std::cout << content;
  }

  int bookMenu() {
    std::cout << "Menu:\n"
              << "\t1: Next Page"
              << "\t2: Previous Page"
              << "\t3: Stop Reading\n"
              << "\nEnter number in range 1 - 3: ";

    int choice;
    std::cin >> choice;
    return choice;
  }
};

class BookController {
private:
  BookModel model;
  BookViewer viewer;

public:
  void readBook() {}
};

class UserData {
private:
  std::string name;
  std::string email;
  std::string username;
  std::string password;
  UserStatus status;

public:
  UserData() {}
  UserData(std::string name, std::string email, std::string username,
           std::string password, UserStatus status = UserStatus::USER)
      : name(name), email(email), username(username), password(password),
        status(status) {}

  std::string getName() const { return name; }
  std::string getEmail() const { return email; }
  std::string getUsername() const { return username; }
  std::string getPassword() const { return password; }
  UserStatus getStatus() const { return status; }

  void setName(const std::string &name) { this->name = name; }
  void setEmail(const std::string &email) { this->email = email; }
  void setUsername(const std::string &username) { this->username = username; }
  void setPassword(const std::string &password) { this->password = password; }
};

class UserView {
public:
  int userMenu(UserData &data) {
    int choice;
    showProfileLine(data);
    std::cout << "\nMenu:\n"
              << "\t 1: View Profile\n"
              << "\t 2: List & Select from my reading history\n"
              << "\t 3: List & Select from available books\n"
              << "\t 4: Logout\n"
              << "\nEnter number in range 1 - 4: ";
    std::cin >> choice;
    return choice;
  }
  void showProfileLine(UserData &data) {
    std::string view;
    if (data.getStatus() == UserStatus::USER)
      view = "User";
    else
      view = "Admin";
    std::cout << "\nHello " << data.getUsername() << " | " << view << " View\n";
  }
  void viewProfile(UserData &data) {
    std::cout << "\nName: " << data.getName() << "\nEmail: " << data.getEmail()
              << "\nUsername: " << data.getUsername();
  }
  void listHistory() {}
  void listBooks() {}

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

  void inputAddUser(UserData &user) {
    std::string tmp;

    std::cout << "Enter username (no spaces): ";
    std::cin >> tmp;
    user.setUsername(tmp);
    std::cout << "Enter password (no spaces): ";
    std::cin >> tmp;
    user.setPassword(tmp);
    std::cout << "Enter name (no spaces): ";
    std::cin >> tmp;
    user.setName(tmp);
    std::cout << "Enter email (no spaces): ";
    std::cin >> tmp;
    user.setEmail(tmp);
  }

  void inputLogin(UserData &user) {
    std::string tmp;

    std::cout << "Enter username (no spaces): ";
    std::cin >> tmp;
    user.setUsername(tmp);
    std::cout << "Enter password (no spaces): ";
    std::cin >> tmp;
    user.setPassword(tmp);
  }

  void printError(std::string &err) {
    std::cout << "\n" << "Error: " << err << "\n";
  }
};

class UserModel {
private:
  std::vector<UserData> users;

public:
  bool isAded(UserData &data) {
    if (findUser(data.getUsername()) != nullptr) {
      return true;
    }
    return false;
  }

  bool add(UserData &data) {
    if (isAded(data)) {
      return false;
    }
    users.push_back(data);
    return true;
  }

  bool isCorrect(UserData data) {
    UserData *dataPtr = findUser(data.getUsername());
    if (dataPtr == nullptr || data.getPassword() != dataPtr->getPassword()) {
      return false;
    }
    return true;
  }

  UserData *findUser(const std::string &username) {
    for (UserData &cur : users) {
      if (cur.getUsername() == username) {
        return &cur;
      }
    }
    return nullptr;
  }
};

class UserController {
private:
  UserModel userModel;
  UserView userView;

public:
  UserController() : userModel() {}

  UserController(UserModel &userModel, UserView &userView)
      : userModel(userModel), userView(userView) {}

  UserData *addUser() {
    UserData newUser;
    while (true) {
      userView.inputAddUser(newUser);
      if (userModel.add(newUser)) {
        return userModel.findUser(newUser.getUsername());
      } else {
        userView.printError(UsedUsernameErr);
      }
    }
  }

  UserData *addUser(UserData &data) {
    if (userModel.add(data)) {
      return userModel.findUser(data.getUsername());
    } else {
      userView.printError(UsedUsernameErr);
      return nullptr;
    }
  }

  UserData *login() {
    UserData data;
    while (true) {
      userView.inputLogin(data);
      if (userModel.isCorrect(data)) {
        return userModel.findUser(data.getUsername());
      }
      userView.printError(CredntialsErr);
    }
  }

  int startMenu() { return userView.startMenu(); }
  int menu(UserData &data) { return userView.userMenu(data); }
  void viewProfile(UserData &data) { userView.viewProfile(data); }
};

class systemManager {
private:
  UserData *currentUser = nullptr;
  UserController userController;
  LoginStatus loginStatus = LoginStatus::LOGED_OUT;

public:
  systemManager() {
    // hardcode the some users
    UserData admin("Admin", "admin@bookshop.com", "admin", "Password",
                   UserStatus::ADMIN);
    UserData user("user1", "user1@bookshop.com", "user1", "userpass",
                  UserStatus::USER);
    userController.addUser(admin);
    userController.addUser(user);
  }
  ~systemManager() { currentUser = nullptr; }

  void run() {
    while (true) {
      if (loginStatus == LoginStatus::LOGED_OUT) {
        int choice = userController.startMenu();
        switch (choice) {
        case 1:
          handelLogin();
          break;
        case 2:
          handelSingup();
          break;
        }
      }

      int choice = userController.menu(*currentUser);
      switch (choice) {
      case 1:
        userController.viewProfile(*currentUser);
        break;
      case 4:
        loginStatus = LoginStatus::LOGED_OUT;
        currentUser = nullptr;
        break;
      }
    }
  }

  void handelSingup() {
    currentUser = userController.addUser();
    loginStatus = LoginStatus::LOGED_IN;
  }

  void handelLogin() {
    currentUser = userController.login();
    loginStatus = LoginStatus::LOGED_IN;
  }
};

int main() {
  systemManager system;
  system.run();
}
