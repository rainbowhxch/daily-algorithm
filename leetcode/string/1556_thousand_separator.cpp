#include <string>

using std::string;

class Solution {
public:
    string thousandSeparator(int n) {
        string tmp = std::to_string(n);
        int n_length = tmp.length()+tmp.length()/3-(tmp.length()%3 ? 0 : 1);
        string res(n_length, ' ');

        for (int i = tmp.length()-1, j = 0;i >= 0;--i, ++j) {
            if (j % 3 == 0)
                res[n_length--] = '.';
            res[n_length--] = tmp[i];
        }

        return res;
    }
};
