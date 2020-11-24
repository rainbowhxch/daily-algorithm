#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using std::vector;
using std::string;
using std::unordered_map;
using std::sort;
using std::to_string;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
     unordered_map<int, int> m;
     const int SIZE_OF_NUMS = nums.size();
     vector<string> ans(SIZE_OF_NUMS);
     for (int i = 0; i < SIZE_OF_NUMS;++i) {
       m[nums[i]] = i;
     }
     sort(nums.begin(), nums.end(), [](const int a, const int b){return a > b;});
     if (SIZE_OF_NUMS > 0)  ans[m[nums[0]]] = "Gold Medal";
     if (SIZE_OF_NUMS > 1)  ans[m[nums[1]]] = "Silver Medal";
     if (SIZE_OF_NUMS > 2)  ans[m[nums[2]]] = "Bronze Medal";
     for (int i = 3; i < SIZE_OF_NUMS; ++i) {
       ans[m[nums[i]]] = to_string(i+1);
     }

     return ans;
  }
};
