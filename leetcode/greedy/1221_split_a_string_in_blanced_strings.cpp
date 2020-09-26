#include <string>

using std::string;

class Solution {
public:
    int balancedStringSplit(string s) {
        int balanced = 0;
        int ans = 0;

        for (auto c : s) {
            if (c == 'R')
                balanced++;
            else
                balanced--;

            if (balanced == 0)
                ans++;
        }

        return ans;
    }
};
