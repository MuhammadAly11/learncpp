#include <deque>
#include <iostream>
using namespace std;

struct last_k_numbers_sum_stream {
  int k;
  deque<int> stream;

  last_k_numbers_sum_stream(int _k = 3) { k = _k; }

  int next(int new_num) {
    int tmp = k;
    int sum{};
    stream.push_back(new_num);
    deque<int> copy = stream;
    while (tmp-- && !copy.empty()) {
      sum += copy.back();
      copy.pop_back();
    }
    if (stream.size() > k)
      stream.pop_front();
    return sum;
  }
};

int main() {
  int k;
  cout << "LastNumbers (K): ";
  cin >> k;
  last_k_numbers_sum_stream processor(k);

  cout << "Enter numbers: ";
  int num;
  while (cin >> num) {
    cout << "Sum ==> " << processor.next(num) << "\n";
  }

  return 0;
}
