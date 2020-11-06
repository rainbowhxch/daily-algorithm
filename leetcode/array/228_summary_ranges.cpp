#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::to_string;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int j = 0;
        if (nums.size() == 0)
            return ans;

        for (int i = 0;i < nums.size()-1;++i) {
            if (nums[i] != nums[i+1]-1) {
                if (i == j)
                   ans.push_back(to_string(nums[i]));
                else
                    ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
                j = i+1;
            }
        }

        if (j == nums.size()-1)
            ans.push_back(to_string(nums[j]));
        else
            ans.push_back(to_string(nums[j]) + "->" + to_string(nums[nums.size()-1]));

        return ans;
    }
};
