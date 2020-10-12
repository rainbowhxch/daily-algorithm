#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int deadline = *std::max_element(candies.begin(), candies.end()) - extraCandies;

        for (auto i : candies) {
            if (i >= deadline)
                ans.emplace_back(true);
            else
                ans.emplace_back(false);
        }

        return ans;
    }
};
