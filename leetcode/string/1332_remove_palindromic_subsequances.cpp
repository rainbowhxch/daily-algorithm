#include <string>

using std::string;

class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - s.empty() - equal(s.begin(), s.end(), s.rbegin());
    }
};
