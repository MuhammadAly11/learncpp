/*  This project focuses on design and doesn't care
 *  about details like spaces in string
 *  I will try implementing it using MVC pattern*/
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
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

  int getPageNums() const { return pagesNum; }
  std::string getName() const { return name; }
  void getPage(std::string &content, int page) const {
    content = pages.at(--page);
  }
};

class BookModel {
private:
  std::vector<BookData> books;

public:
  void addBook(BookData &book) { books.push_back(book); }

  std::vector<std::string> listBooks() {
    std::vector<std::string> list;
    for (auto &x : books) {
      list.push_back(x.getName());
    }
    return list;
  }

  BookData &getBookByIndex(int idx) { return books.at(idx); }
};

class SessionData {
private:
  const BookData *const book;
  int curPage;
  std::time_t lastTime;

public:
  SessionData(int curPage, std::time_t lastTime, const BookData *book)
      : curPage(curPage), lastTime(lastTime), book(book) {}

  std::string getLastTime() {
    auto time = localtime(&lastTime);
    std::ostringstream oss;
    oss << std::put_time(time, "%Y-%m-%d %H:%M:%S");
    return oss.str();
  }
  int getCurPage() const { return curPage; }
  int getPagesNum() const { return book->getPageNums(); }
  const std::string getBookNmae() const { return book->getName(); }
  const BookData *getBook() const { return book; }
};

class BookViewer {
public:
  void viewPage(const BookData &book, int pageNum = 1) {
    std::cout << "\nCurrent Page: " << pageNum << "/" << book.getPageNums()
              << "\n";
    std::string content;

    book.getPage(content, pageNum);
    std::cout << content << "\n";
  }

  int bookMenu() {
    std::cout << "\nMenu:\n"
              << "\t1: Next Page\n"
              << "\t2: Previous Page\n"
              << "\t3: Stop Reading\n"
              << "\nEnter number in range 1 - 3: ";

    int choice;
    std::cin >> choice;
    return choice;
  }

  int listBooks(std::vector<std::string> list) {
    int choice, i = 0;
    std::cout << "Our current book collection: \n";
    for (auto x : list) {
      std::cout << "\t" << ++i << " " << x << "\n";
    }
    std::cout << "\nWhich book to read\n"
              << "Enter number in range 1 - " << i << ": ";
    std::cin >> choice;

    return choice;
  }
};

class BookController {
private:
  BookModel model;
  BookViewer viewer;

public:
  void addBook(BookData &book) { model.addBook(book); }

  SessionData *readBook(const SessionData *session) {
    const BookData *curBook = nullptr;
    int curPage = 1;

    if (session == nullptr) {
      auto list = model.listBooks();
      int bookNum = viewer.listBooks(list);
      curBook = &model.getBookByIndex(bookNum);
    } else {
      curBook = session->getBook();
      curPage = session->getCurPage();
    }

    int choice = -1;
    SessionData *newSession = nullptr;
    while (true) {
      viewer.viewPage(*curBook, curPage);
      choice = viewer.bookMenu();

      if (choice == 1)
        curPage++;
      else if (choice == 2)
        curPage--;
      else if (choice == 3) {
        std::time_t lastRead = time(nullptr);
        newSession = new SessionData(curPage, lastRead, curBook);
        return newSession;
      }
    }
  }
};

class UserData {
private:
  std::string name;
  std::string email;
  std::string username;
  std::string password;
  std::vector<SessionData> sessions;
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
  const std::vector<SessionData> &getSessions() { return sessions; }
  const SessionData &getSeesionByIdx(int n) { return sessions.at(n); }

  void setName(const std::string &name) { this->name = name; }
  void setEmail(const std::string &email) { this->email = email; }
  void setUsername(const std::string &username) { this->username = username; }
  void setPassword(const std::string &password) { this->password = password; }
  void addSession(const SessionData &session) { sessions.push_back(session); }
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

  int listSessions(UserData &data) {
    std::cout << "\n";
    auto sessions = data.getSessions();

    if (sessions.empty()) {
      std::cout << "You have no reading history yet.\n";
      return -1;
    }

    int i = 0, choice;
    for (auto session : sessions) {
      std::cout << ++i << ": " << session.getBookNmae() << ": "
                << session.getCurPage() << "/" << session.getPagesNum() << " - "
                << session.getLastTime() << "\n";
    }
    std::cout << "\nWhich sessiont to open?\n"
              << "Enter number in range 1 - " << i << ": ";
    std::cin >> choice;
    return choice - 1; // to be index
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

  const SessionData *chooseSessions(UserData &data) {
    int choice = userView.listSessions(data);
    if (choice == -1) {
      return nullptr;
    }
    auto *session = &data.getSeesionByIdx(choice);
    return session;
  }

  void saveSession(UserData &data, const SessionData *session) {
    data.addSession(*session);
  }
  int startMenu() { return userView.startMenu(); }
  int menu(UserData &data) { return userView.userMenu(data); }
  void viewProfile(UserData &data) { userView.viewProfile(data); }
};

class systemManager {
private:
  UserData *currentUser = nullptr;
  UserController userController;
  BookController bookCtrl;
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
    std::vector<std::string> pages = {"The first page", "The second page",
                                      "The third page"};
    BookData a("first book", "the autor", "ISBN_892374", 3, pages);
    BookData b("2nd book", "2nd autor", "ISBN_89asdf2374", 3, pages);
    bookCtrl.addBook(a);
    bookCtrl.addBook(b);
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
      case 2: {
        auto session = userController.chooseSessions(*currentUser);
        if (session == nullptr) {
          break;
        }
        session = bookCtrl.readBook(session);
        userController.saveSession(*currentUser, session);
        if (session != nullptr) {
          delete session;
          session = nullptr;
        }
      } break;
      case 3: {
        auto session = bookCtrl.readBook(nullptr);
        userController.saveSession(*currentUser, session);
        if (session != nullptr) {
          delete session;
          session = nullptr;
        }
      } break;
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
