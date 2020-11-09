#include <string>

using std::string;

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0, tmp_depth = 0;
        for (const auto &c : s) {
            if (c == '(')
                tmp_depth++;
            if (tmp_depth > max_depth)
                max_depth = tmp_depth;
            if (c == ')')
                tmp_depth--;
        }

        return max_depth;
    }
};
