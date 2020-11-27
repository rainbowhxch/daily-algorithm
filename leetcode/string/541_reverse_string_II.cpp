#include <string>
#include <algorithm>

using std::string;
using std::min;

class Solution {
public:
    string reverseStr(string s, int k) {
        int N = s.length();
        for (int i = 0; i < N; i += 2*k) {
            int rev_start = i, rev_end = min(i+k-1, N-1);
            while (rev_start < rev_end) {
                char c = s[rev_start];
                s[rev_start++] = s[rev_end];
                s[rev_end--] = c;
            }
        }

        return s;
    }
};
