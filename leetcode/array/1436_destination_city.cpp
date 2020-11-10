#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (const auto &i : paths)
            s.insert(i[0]);

        for (const auto &i : paths) {
            if (s.find(i[1]) == s.end())
                return i[1];
        }

        return "";
    }
};
