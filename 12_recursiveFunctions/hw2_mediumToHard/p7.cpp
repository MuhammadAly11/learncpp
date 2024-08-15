#include <iostream>
using namespace std;

bool is_prime(int num, int i = 2) {
  if (i == num)
    return true;

  if (num == 2)
    return true;

  if (num <= 1)
    return false;

  if (num % i == 0)
    return false;

  return is_prime(num, i + 1);
}

int count_primes(int st, int en) {
  if (st == en)
    return 0;

  return is_prime(st) + count_primes(st + 1, en);
}

int main() {
  int st, en;
  cout << "Start: ";
  cin >> st;
  cout << "End: ";
  cin >> en;

  cout << "Primes between " << st << " and " << en << " ==> "
       << count_primes(st, en) << endl;

  return 0;
}
