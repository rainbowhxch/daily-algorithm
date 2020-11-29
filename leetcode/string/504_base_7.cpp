#include <string>
#include <algorithm>

using std::string;
using std::reverse;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res;
        bool is_minus = false;
        if (num < 0) {
            is_minus = true;
            num = -num;
        }
        while (num != 0) {
            res.push_back((num % 7)+'0');
            num /= 7;
        }
        if (is_minus)
            res.push_back('-');

        reverse(res.begin(), res.end());
        return res;
    }
};
