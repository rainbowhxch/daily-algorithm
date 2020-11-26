#include <cmath>
#include <vector>

using std::vector;
using std::sqrt;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid = sqrt(area);

        while (area % mid != 0) mid--;

        return {area/mid, mid};
    }
};
