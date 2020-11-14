#include <string>

using std::string;

class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int cnt = 1;

        for (int i = 0;i < s.size()-1;++i) {
            if (s[i] != s[i+1]) {
                if (cnt > ans)
                    ans = cnt;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt > ans)
            ans = cnt;

        return ans;
    }
};
