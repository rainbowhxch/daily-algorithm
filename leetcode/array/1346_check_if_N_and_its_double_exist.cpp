#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (const auto &i : arr) {
            if (s.find(i*2) != s.end() || (i%2 == 0 && s.find(i/2) != s.end()))
                return true;
            s.insert(i);
        }

        return false;
    }
};
