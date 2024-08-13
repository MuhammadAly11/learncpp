#include <iostream>
using namespace std;

bool is_prime(int num) {
  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int nth_prime(int nth) {
  int cnt{}, i{2};
  while (i) {
    cnt += (is_prime(i));
    if (cnt == nth) {
      return i;
    }
    i++;
  }
  return 0;
}

int main() {
  int nth;
  cout << "number of prime: ";
  cin >> nth;

  cout << nth << "th prime ===> " << nth_prime(nth) << endl;
  return 0;
}
