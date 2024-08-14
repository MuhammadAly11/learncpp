#include <iostream>
using namespace std;

int suffix_sum(int arr[], int len, int &suffix) {
  if (suffix > len)
    return -1;
  if (suffix == 0)
    return 0;

  suffix--;
  return arr[len - 1] + suffix_sum(arr, len - 1, suffix);
}

int main() {
  const int max = 100;
  int len, suffix{};
  cout << "Array len: ";
  cin >> len;
  cout << "Suffix len: ";
  cin >> suffix;

  int arr[max];
  cout << "Values: ";
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  cout << "Sum of last " << suffix << " elemnts ==> "
       << suffix_sum(arr, len, suffix) << endl;

  return 0;
}
