#include <vector>

using std::vector;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int cur_distribution = 1;

        while (candies > cur_distribution) {
            ans[(cur_distribution-1) % num_people] += cur_distribution;
            candies -= cur_distribution;
            cur_distribution++;
        }
        ans[(cur_distribution-1) % num_people] += candies;

        return ans;
    }
};
