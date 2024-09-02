#include <iostream>
#include <queue>

struct ourStack {
  std::queue<int> q;

  void push(int val) {
    q.push(val);
    int len = q.size();
    while (--len){
      int tmp = q.front();
      q.pop();
      q.push(tmp);
    }
  }
  void pop() {
    if (!q.empty())
      q.pop();
  }
  int top() { return q.front(); }
  bool empty() { return q.empty(); }
};

int main() {
  ourStack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);

  while (!s.empty()) {
    std::cout << s.top() << " ", s.pop();
  }
  std::cout << "\n";
  return 0;
}
