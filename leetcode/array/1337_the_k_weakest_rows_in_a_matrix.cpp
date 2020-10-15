#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        struct {
            int idx;
            int cnt;
        } item[m];

        for (int i = 0;i < m;++i) {
            int l = 0, r = n-1;
            while (l < r) {
                int mid = (l+r) / 2;
                if (mat[i][mid] == 1) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            item[i].idx = i;
            item[i].cnt = l;
        }

        std::sort(item, item+m, [](auto &a, auto &b){
                    if (a.cnt == b.cnt)
                        return a.idx < b.idx;
                    return a.cnt < b.cnt;
                });

        for (auto i : item) {
            ans.push_back(i.idx);
            if (--k == 0) break;
        }

        return ans;
    }
};
