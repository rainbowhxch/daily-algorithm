#include <string>
#include <algorithm>

using std::string;
using std::reverse;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0;
        int p1 = num1.length()-1;
        int p2 = num2.length()-1;
        while (p1 >= 0 || p2 >= 0) {
            int x1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int x2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int cur_value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            res.push_back(cur_value+'0');
            p1--; p2--;
        }

        if (carry != 0)
            res.push_back(carry+'0');

        reverse(res.begin(), res.end());
        return res;
    }
};
