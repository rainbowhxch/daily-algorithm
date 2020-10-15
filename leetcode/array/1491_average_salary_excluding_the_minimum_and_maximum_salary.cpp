#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    double average(vector<int>& salary) {
        double avg = 0;
        int mmax = std::numeric_limits<int>::min();
        int mmin = std::numeric_limits<int>::max();
        for (auto i : salary) {
            mmax = std::max(mmax, i);
            mmin = std::min(mmin, i);
            avg += i;
        }

        return (avg - mmax - mmin) / (salary.size() - 2);
    }
};
