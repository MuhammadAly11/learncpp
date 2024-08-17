#include <iostream>
using namespace std;

const int MAX_LEN = 10;

struct queue {
  int arr[MAX_LEN];
  int added = {};

  void add_end(int value) {
    if (error())
      return;
    arr[added] = value;
    added++;
  }

  void add_front(int value) {
    if (error())
      return;
    for (int i = added; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = value;
    added++;
  }

  void remove_front() {
    cout << arr[0] << endl;
    for (int i = 1; i < added; i++) {
      arr[i - 1] = arr[i];
    }
    added--;
  }

  void print() {
    for (int i = 0; i < added; i++) {
      if (i)
        cout << " ";
      cout << arr[i];
    }
    cout << endl << endl;
  }

  bool error() {
    if (added >= MAX_LEN) {
      cout << "Queue is full.\n";
      return true;
    }
    return false;
  }
};

int main() {
  queue list;
  for (int i = 0; i < 5; i++) {
    list.add_end(i);
  }

  list.print();
  list.add_end(8);
  list.print();
  list.add_end(8);
  list.print();
  list.add_end(8);
  list.print();
  list.add_end(8);
  list.print();
  list.add_end(8);
  list.print();
  list.remove_front();
  list.print();
  list.remove_front();
  list.print();
  list.add_front(7);
  list.print();
  list.remove_front();
  list.print();
  list.remove_front();
  list.print();

  return 0;
}
