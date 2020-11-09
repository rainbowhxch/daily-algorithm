#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, size_t> m;

        for (size_t i = 0;i < pieces.size();++i)
            m[pieces[i][0]] = i;
        for (size_t i = 0;i < arr.size();) {
            if (m.find(arr[i]) != m.end()) {
                int tmp = m[arr[i]];

                for (size_t j = i+1;j < i+pieces[tmp].size();++j) {
                    if (arr[j] != pieces[tmp][j-i])
                        return false;
                }
                i += pieces[tmp].size();
            } else {
                return false;
            }
        }

        return true;
    }
};
