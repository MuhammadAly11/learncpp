#include <iostream>
#include <queue>
#include <stack>

void reverse_queue(std::queue<int> &q) {
  std::stack<int> st;
  int tmp;
  while (!q.empty()) {
    tmp = q.front();
    st.push(tmp);
    q.pop();
  }
  while (!st.empty()) {
    tmp = st.top();
    q.push(tmp);
    st.pop();
  }
}

void print_queue(std::queue<int> q) {
  while (!q.empty()) {
    std::cout << q.front();
    q.pop();
  }
  std::cout << "\n";
}

int main() {
  std::queue<int> q;
  for (int i = 1; i < 10; i++) {
    q.push(i);
  }

  std::cout << "queue before: ";
  print_queue(q);

  reverse_queue(q);

  std::cout << "queue after: ";
  print_queue(q);

  return 0;
}
