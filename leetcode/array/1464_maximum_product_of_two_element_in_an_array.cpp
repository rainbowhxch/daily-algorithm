#include <vector>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_1 = 0, max_2 = 0;

        for (auto i : nums) {
            if (i > max_1) {
                max_2 = max_1;
                max_1 = i;
            } else if (i > max_2) {
                max_2 = i;
            }
        }

        return (max_1-1) * (max_2-1);
    }
};
