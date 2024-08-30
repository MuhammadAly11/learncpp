#include <iostream>
#include <vector>
using namespace std;

int main() {
  int win_sz;
  cout << "Enter window size: \n";
  cin >> win_sz;

  vector<int> nums;
  cout << "Enter -99 to stop program\n" << "Enter numbers: \n";
  int num{};
  while (true) {
    cin >> num;
    if (num == -99)
      break;
    nums.push_back(num);
  }

  vector<int> max_values;
  while ((int)nums.size() >= 3) {
    int max_value = nums[0];
    for (int i = 1; i < win_sz; i++) {
      if (max_value < nums[i]) {
        max_value = nums[i];
      }
    }
    nums.erase(nums.begin());
    max_values.push_back(max_value);
  }

  cout << "Output: ";
  bool is_first = true;
  for (auto x : max_values) {
    if (!is_first)
      cout << " ";
    cout << x;
    is_first = false;
  }
  cout << "\n";
  return 0;
}
