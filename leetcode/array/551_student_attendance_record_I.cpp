#include <string>

using std::string;

class Solution {
public:
    bool checkRecord(string s) {
        int absent_cnt = 0, late_cnt = 0;
        for (const auto &c : s) {
            if (c == 'A') {
                absent_cnt++;
                late_cnt = 0;
            } else if (c == 'L') {
                late_cnt++;
            } else {
                late_cnt = 0;
            }

            if (absent_cnt > 1)
                return false;
            if (late_cnt > 2)
                return false;
        }

        return true;
    }
};
