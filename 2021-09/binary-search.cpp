#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 10};
  int target = 10;
  int l = 0, r = nums.size() - 1;

  while (l < r) {
    int m = (l + r) / 2;
    if (nums[m] < target) {
      l = m;
    } else if (nums[m] > target) {
      r = m;
    } else {
      cout << m;
    }
  }

  return 0;
}
