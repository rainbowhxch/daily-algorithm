#include <vector>

using std::vector;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for (const auto &i : A)
            if (i % 2 == 0)
                sum += i;

        for (const auto &i : queries) {
            int pre_val = A[i[1]];
            int modified_val = pre_val + i[0];

            if (pre_val % 2 == 0)
                sum -= pre_val;
            if (modified_val % 2 == 0)
                sum += modified_val;

            A[i[1]] = modified_val;
            ans.push_back(sum);
        }

        return ans;
    }
};
