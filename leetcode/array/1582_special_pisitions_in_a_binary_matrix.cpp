#include <vector>

using std::vector;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int m = mat.size(), n = mat[0].size();

        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                if (mat[i][j] != 1) continue;
                else {
                    for (int k = 0;k < m;++k)
                        if ((mat[k][j] % 2) == 1 && k != i) {
                            goto not_special;
                        }
                    for (int k = 0;k < n;++k)
                        if ((mat[i][k] % 2) == 1 && k != j) {
                            goto not_special;
                        }

                    cnt++;

                    not_special:
                        for (int k = 0;k < m;++k)
                            mat[k][j] += 2;
                        for (int k = 0;k < n;++k)
                            mat[i][k] += 2;
                }
            }
        }

        return cnt;
    }
};
