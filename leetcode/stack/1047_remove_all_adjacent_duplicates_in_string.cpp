#include <string>

using std::string;

class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";

        for (auto c : S) {
            if (res.size() != 0 && res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};
