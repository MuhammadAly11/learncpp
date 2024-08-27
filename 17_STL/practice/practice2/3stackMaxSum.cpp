#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int sum_of_stack(stack<int> stack) {
  int sum{};
  while (!stack.empty()) {
    sum += stack.top();
    stack.pop();
  }
  return sum;
}

template <typename T> T Min(T a, T b, T c) { return min(min(a, b), c); }

int main() {
  stack<int> a;
  stack<int> b;
  stack<int> c;
  for (int i = 1; i <= 4; i++) {
    a.push(i);
  }
  b.push(2);
  b.push(2);
  b.push(2);
  b.push(4);
  b.push(0);
  c.push(0);
  c.push(3);
  c.push(3);
  c.push(5);

  int suma{sum_of_stack(a)};
  int sumb{sum_of_stack(b)};
  int sumc{sum_of_stack(c)};
  while (suma != sumb || sumb != sumc || suma != sumc) {
    int minSum = Min(suma, sumb, sumc);
    if (suma > minSum) {
      suma -= a.top();
      a.pop();
    }
    if (sumb > minSum) {
      sumb -= b.top();
      b.pop();
    }
    if (sumc > minSum) {
      sumc -= c.top();
      c.pop();
    }
  }
  cout << "Max value: " << suma << endl;
  return 0;
}
