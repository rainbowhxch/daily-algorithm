#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::sort;
using std::unordered_map;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> clone(arr.begin(), arr.end());
        unordered_map<int, int> m;
        int rank = 1;
        sort(clone.begin(), clone.end());

        for (const auto &i : clone) {
            if (m[i] == 0) {
                m[i] = rank;
                rank++;
            }
        }

        for (const auto &i : arr)
            ans.push_back(m[i]);

        return ans;
    }
};
