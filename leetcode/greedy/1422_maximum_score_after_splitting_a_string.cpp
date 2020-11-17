#include <string>

using std::string;

class Solution {
public:
    int maxScore(string s) {
        int cur_score = 0;

        for (int i = 1;i < s.length();++i)
            if (s[i] == '1')
                cur_score++;
        if (s[0] == '0')
            cur_score++;
        int max_score = cur_score;

        for (int i = 1;i < s.length()-1;++i) {
            if (s[i] == '1') {
                cur_score--;
            } else {
                cur_score++;
            }
            if (cur_score > max_score)
                max_score = cur_score;
        }

        return max_score;
    }
};
