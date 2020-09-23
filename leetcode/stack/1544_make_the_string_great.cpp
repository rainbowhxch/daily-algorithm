#include <string>

using std::string;

class Solution {
public:
    string makeGood(string s) {
        string res;
        const int dis = 32;

        for (auto c : s) {
            if (res.size() != 0 && abs(res.back()-c) == dis) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};
