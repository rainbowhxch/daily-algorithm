#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() == 1) return true;
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for (int i = 2;i < arr.size();++i) {
            if (diff != arr[i] - arr[i-1])
                return false;
        }

        return true;
    }
};
