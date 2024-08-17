#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct history {
  string date;
  int cost {};
  string description;
};

struct car {
  string model;
  bool is_used;
  history hist;
};

struct inventory {
  car cars[MAX_SIZE];
};

struct location {
  string name;
  string address;
  inventory store;
};

location locations[MAX_SIZE];

int main() {
    
    return 0;
}
