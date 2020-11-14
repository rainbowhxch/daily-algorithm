#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        unordered_map<char, int> m;

        for (int i = s.size()-1;i >= 0;--i) {
            if (m[s[i]] == 0)
                m[s[i]] = i;
        }

        for (int i = 0;i < s.size();++i) {
            int tmp = m[s[i]] - i - 1;
            if (tmp > res)
                res = tmp;
        }

        return res;
    }
};
