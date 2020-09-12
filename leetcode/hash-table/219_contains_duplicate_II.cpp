#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (int i = 0;i < nums.size();++i) {
            int tmp = nums[i];

            if (m[tmp] != 0 && i - m[tmp] + 1 <= k) {
                return true;
            } else {
                m[tmp] = i + 1;
            }
        }

        return false;
    }
};
