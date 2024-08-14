#include <iostream>
using namespace std;

void right_max(int arr[], int len, int st_pos = 0) {
  if (st_pos == len - 1)
    return;

  right_max(arr, len, st_pos + 1);

  arr[st_pos] = max(arr[st_pos], arr[st_pos + 1]);
}

int main() {
  const int max = 100;
  int len, pos {};
  cout << "Array len: ";
  cin >> len;
  cout << "Start position: ";
  cin >> pos;

  int arr[max];
  cout << "Values: ";
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }

  right_max(arr, len, pos);

  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
