/*  This project focuses on design and doesn't care
 *  about details like spaces in string
 *  I will try implementing it using MVC pattern*/
#include <stdio.h>
#include <string>

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

void setName(const std::string& name) { this->name = name; }
void setEmail(const std::string& email) { this->email = email; }
void setUsername(const std::string& username) { this->username = username; }
void setPassword(const std::string& password) { this->password = password; }
};

class UserController {
    public:
    UserController(UserModel& userModel, UserView& userView) {}
    
};



int main() {
}
