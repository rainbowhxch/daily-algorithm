#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        unordered_set<int> s;
        set<pair<int, int> > p;
        for (auto i : nums) {
            if (s.find(i-k) != s.end()) p.insert({min(i-k, i), max(i-k, i)});
            if (s.find(i+k) != s.end()) p.insert({min(i+k, i), max(i+k, i)});

            s.insert(i);
        }

        return p.size();
    }
};
