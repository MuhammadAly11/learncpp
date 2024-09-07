#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

const std::string USERS_FILE{"users.txt"};

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
  std::string last_line;
  while (std::getline(users, last_line)) {
    std::cout << "test: " << last_line << "\n";
  }
  std::cout << "after loop: " << last_line;
  users.close();
  return last_line;
}
int main() {
  std::string str = getLastLine(USERS_FILE);
  std::cout << "last line: " << str;

  return 0;
}

