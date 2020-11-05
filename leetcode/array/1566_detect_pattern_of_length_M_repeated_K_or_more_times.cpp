#include <vector>

using std::vector;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = m, cnt = 0;i < arr.size();++i) {
            cnt = arr[i] == arr[i-m] ? cnt+1 : 0;
            if (cnt == (k-1)*m)
                return true;
        }

        return false;
    }
};
