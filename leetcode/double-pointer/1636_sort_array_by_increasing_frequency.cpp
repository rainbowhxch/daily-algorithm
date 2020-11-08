#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::sort;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const auto &i : nums)
            m[i]++;
        sort(nums.begin(), nums.end(), [&m](int a, int b) {
                if (m[a] == m[b])
                    return a > b;
                return m[a] < m[b];
                });

        return nums;
    }
};
