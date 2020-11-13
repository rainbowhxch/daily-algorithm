#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        string sentence = "";

        for (const auto &i : words)
            sentence += "-" + i;

        for (const auto &i : words) {
            int idx1 = sentence.find(i);
            int idx2 = sentence.find(i, idx1+1);
            if (idx2 != i.npos)
                ans.push_back(i);
        }

        return ans;
    }
};
