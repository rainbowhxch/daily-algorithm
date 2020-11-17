#include <string>

using std::string;

class Solution {
public:
    string reformat(string s) {
        string l, d;
        string res(s);

        for (const auto &i : s) {
            if (isdigit(i))
                d.push_back(i);
            else
                l.push_back(i);
        }
        if (l.length() < d.length()) swap(l, d);
        if (l.length() - d.length() > 1)
            return "";

        int idx = 0;
        for (int i = 0;i < d.length();++i) {
            res[idx++] = l[i];
            res[idx++] = d[i];
        }
        if (l.length() != d.length())
            res[idx] = l[d.length()];

        return res;
    }
};
