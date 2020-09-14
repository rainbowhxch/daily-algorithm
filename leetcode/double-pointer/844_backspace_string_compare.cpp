#include <string>

using std::string;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        int skips_cnt = 0, skipt_cnt = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skips_cnt++; i--;
                } else if (skips_cnt > 0) {
                    skips_cnt--; i--;
                } else {
                    break;
                }
            }

            while (j >= 0) {
                if (T[j] == '#') {
                    skipt_cnt++; j--;
                } else if (skipt_cnt > 0) {
                    skipt_cnt--; j--;
                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0 && S[i] != T[j])
                return false;
            if ((i >= 0) ^ (j >= 0))
                return false;

            i--; j--;
        }

        return true;
    }
};
