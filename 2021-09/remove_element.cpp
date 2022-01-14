#include <vector>

using std::vector;

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 10};
  int lowIdx = 0;
  int removedTarget = 1;

  for (int fastIdx = 0; fastIdx < nums.size(); ++fastIdx) {
    if (nums[fastIdx] != removedTarget) {
      nums[lowIdx++] = nums[fastIdx];
    }
  }

  return 0;
}
