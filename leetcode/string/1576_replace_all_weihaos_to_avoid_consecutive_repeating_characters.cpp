#include <string>

using std::string;

class Solution {
public:
    string modifyString(string s) {
        int N = s.length();
        if (N == 1) return s == "?" ? "a" : s;
        if (s[0] == '?') s[0] = s[1] == 'a' ? 'b' : 'a';
        if (s[N-1] == '?') s[N-1] = s[N-2] == 'a' ? 'b' : 'a';

        for (int i = 1; i < N-1; ++i) {
            if (s[i] == '?') {
                if (s[i-1] != 'a' && s[i+1] != 'a') s[i] = 'a';
                else if (s[i-1] != 'b' && s[i+1] != 'b') s[i] = 'b';
                else s[i] = 'c';
            }
        }

        return s;
    }
};
