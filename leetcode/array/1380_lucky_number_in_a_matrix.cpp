#include <iterator>
#include <limits>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        for (auto i{matrix.begin()};i < matrix.end();++i) {
            auto it{std::min_element(i->begin(), i->end())};
            int idx_col{static_cast<int>(std::distance(i->begin(), it))};

            int tmp_min{*it};
            int tmp_max{find_max_element_in_col(matrix, idx_col)};
            if (tmp_max == tmp_min)
                res.push_back(tmp_min);
        }

        return res;
    }

private:
    int find_max_element_in_col(const vector<vector<int> > &matrix, int idx_col) {
        int mmax = std::numeric_limits<int>::min();
        for (auto &i : matrix) {
            mmax = std::max(mmax, i[idx_col]);
        }

        return mmax;
    }
};
