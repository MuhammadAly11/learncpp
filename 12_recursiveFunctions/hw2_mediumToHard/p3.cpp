#include <iostream>
using namespace std;

int prefix_sum(int arr[], int len, int &prefix, int st_pos = 0) {
  if (prefix > len)
    return -1;
  if (prefix == 0)
    return 0;

  return arr[st_pos] + prefix_sum(arr, len, --prefix, st_pos + 1);
}

int main() {
  const int max = 100;
  int len, prefix{};
  cout << "Array len: ";
  cin >> len;
  cout << "prefix len: ";
  cin >> prefix;

  int arr[max];
  cout << "Values: ";
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  cout << "Sum of first " << prefix << " elemnts ==> "
       << prefix_sum(arr, len, prefix) << endl;

  return 0;
}
