#include <iostream>
using namespace std;

class MyVector {
private:
  int *arr;
  int len = 100;

public:
  MyVector(int len, int default_value = 0) {
    this->len = len;
    this->arr = new int[len];

    for (int i = 0; i < len; ++i) {
      this->arr[i] = default_value;
    }
  }
  MyVector(const MyVector &other) {
    len = other.len;

    this->arr = new int[len];
    for (int i = 0; i < other.len; i++) {
      arr[i] = other.arr[i];
    }
  }
  ~MyVector() { delete[] this->arr; }
  void set(int pos, int value) {
    if (get(pos) != -1)
      arr[pos] = value;
  }
  int get(int pos) {
    if (pos > len) {
      return -1;
    }
    return this->arr[pos];
  }
  int GetLength() { return len; }
};

int main() {
  MyVector v(10, 12345);
  MyVector v2(v);

  v2.set(3, 12000);

  cout << v.get(5); // 12345

  return 0;
}
