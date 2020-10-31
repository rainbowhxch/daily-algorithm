#include <vector>

using std::vector;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int N = A.size();
        vector<bool> ans(N, false);
        ans[0] = A[0] == 0;

        for (int i = 1;i < N;++i) {
            A[i] = (A[i] + A[i-1] * 2) % 5;
            if (A[i] == 0)
                ans[i] = true;
            else
                ans[i] = false;
        }

        return ans;
    }
};
