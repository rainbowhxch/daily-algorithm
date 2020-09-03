#include <vector>

using std::vector;

class NumArray {
	public:
		NumArray(vector<int> &nums) {
			this->sums = new int[nums.size()+1];
			for (int i = 0;i < nums.size();++i) {
				sums[i+1] = sums[i] + nums[i];
			}
		}

		int sumRange(int i, int j) {
			return sums[j+1] - sums[i];
		}

	private:
		int *sums;
}
