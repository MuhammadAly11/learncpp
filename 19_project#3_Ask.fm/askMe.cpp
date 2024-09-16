#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string USERS_FILE{"users.txt"};
const std::string QUESTIONS_FILE{"questions.txt"};
const int q_id = 1, q_form_user = 2, q_to_user = 3, q_type = 4, q_text = 5,
          q_answer = 6; // number of colomns in question vector and file

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
  std::vector<std::string> question; // id, from, to, n|t, qt, answers
  std::string user_name, name, password, email;
  int id;
  bool aq;

  void printUsers() {
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
    id = lastId(USERS_FILE) + 1;
    std::string user = findUser();
    if (!user.empty()) {
      std::cout << "This user name is already taken.\n";
      return false;
    }
    saveToUsers();
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

  void saveToUsers() {
    std::fstream users = open_file(USERS_FILE, true);
    users << id << "," << user_name << "," << password << "," << name << ","
          << email << "," << aq << "\n";
    users.close();
  }

  int lastId(std::string file) {
    std::string last_user = getLastLine(file);
    if (last_user.empty())
      return 100;
    std::stringstream ss(last_user);
    std::string last_id;
    std::getline(ss, last_id, ',');
    return std::stoi(last_id);
  }

  void inputQuestion() {
    question.clear();
    int last_question_id = lastId(QUESTIONS_FILE);
    question.push_back(std::to_string(++last_question_id)); // Q id
    std::string tmp;
    question.push_back(std::to_string(id)); // form
    std::cout << "Enter user id or -1 to cancel: ";
    std::cin >> tmp;
    question.push_back(tmp); // to
    // TODO: implemnt this
    if (false)
      std::cout << "Note: Anonymous question are not allowed for this user\n ";
    std::cout
        << "For thread question: Enter question id or -1 for new question: ";
    std::cin >> tmp;
    question.push_back(tmp); // new or thread
    std::cout << "Enter question text: ";
    std::cin.ignore();
    std::getline(std::cin, tmp); // text of question
    question.push_back(tmp);
  }

  void saveToQusetions() {
    std::fstream qfile = open_file(QUESTIONS_FILE, true);
    for (auto value : question) {
      qfile << value << ",";
    }
    qfile << "\n";
    qfile.close();
  }

  std::vector<std::string> getQuestions(int user_id, int pos) {
    std::vector<std::string> v;
    std::fstream qfile = open_file(QUESTIONS_FILE);
    std::string line;
    std::string str_id = std::to_string(user_id);

    while (std::getline(qfile, line) &&
           line.find(str_id) != std::string::npos) {
      int times = pos;
      std::stringstream ss(line);
      std::string tmp;
      while (times--) {
        std::getline(ss, tmp, ',');
      }
      if (tmp == str_id)
        v.push_back(line);
    }

    qfile.close();
    return v;
  }

  void getQuestionDataFromLine(std::string line) {
    question.clear();
    std::string tmp;
    std::stringstream ss(line);
    while (std::getline(ss, tmp, ',')) {
      question.push_back(tmp);
    }
  }

  void printQuestion() {
    std::cout << "Question Id (" << question.at(q_id - 1) << ") form user id("
              << question.at(q_form_user - 1)
              << ") \t Question: " << question.at(q_text - 1) << "\n";
    if (q_answer - 1 < question.size()) {
      std::cout << "\t Answer: " << question.at(q_answer - 1) << "\n";
    }
  }

  // takes position of colomn and substring and return the line
  std::string get(std::string sub_str, int pos) {
    std::string ret{}, tmp{"-1"};
    auto qfile = open_file(QUESTIONS_FILE);
    std::string line;

    while (std::getline(qfile, line)) {
      if (line.find(sub_str) == std::string::npos)
        continue;

      int times = pos;
      std::stringstream ss(line);
      while (times--) {
        std::getline(ss, tmp, ',');
      }

      if (sub_str == tmp) {
        ret = line;
        break;
      }
    }

    qfile.close();
    return ret;
  }

  void answer() {
    std::string id_str, ans;
    std::cout << "Enter question id or -1 to cancel: ";
    std::cin >> id_str;
    std::string line = get(id_str, q_id);
    if (line == "") {
      std::cout << "Invalid question id.\n";
      return;
    }
    getQuestionDataFromLine(line);
    printQuestion();
    std::cout << "\n";
    if ((q_answer - 1) < question.size()) {
      std::cout << "Warning: Already answered. Answer will be updated.\n";
    }

    std::cout << "Enter answer: ";
    std::cin.ignore();
    std::getline(std::cin, ans);
    question.push_back(ans);
    saveToQusetions();
  }

  void ask() {
    inputQuestion();
    saveToQusetions();
  }

  void printQuestions(int pos) {
    auto questions = getQuestions(id, pos);
    for (auto line : questions) {
      getQuestionDataFromLine(line);
      printQuestion();
    }
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
      } else if (choice == 1) {
        user.printQuestions(q_to_user); // position of the user to whom the
                                        // question was asked in question vector
      } else if (choice == 2) {
        user.printQuestions(
            q_form_user); // position of the user form whom the
                          // question was asked in question vector
      } else if (choice == 3) {
        user.answer();
      } else if (choice == 5) {
        user.ask();
      } else if (choice == 6) {
        user.printUsers();
      }
    }
  }
};

int main() {
  askme_sys sys;
  sys.run();

  return 0;
}
