#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;

        haystack = needle + "$" + haystack;
        int n = haystack.size();
        vector<int> v(n);
        for (int i = 1;i < n;++i) {
            int j = v[i-1];
            while (j > 0 && haystack[i] != haystack[j])
                j = v[j-1];
            if (haystack[i] == haystack[j])
                j++;
            if (j == needle.size())
                return i - 2 * needle.size();
            v[i] = j;
        }

        return -1;
    }
};
