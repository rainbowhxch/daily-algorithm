#include <vector>

using std::vector;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        int mmax = arr[n-1];

        for (int i = n-1;i > 0;--i) {
            if (arr[i] > mmax) {
                mmax = arr[i];
            }

            ans[i-1] = mmax;
        }

        return ans;
    }
};
