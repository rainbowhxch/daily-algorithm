#include <vector>

using std::vector;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int MORE_THAN_25 = arr.size() / 4;

        for (int i = 0;i < arr.size();++i) {
            int more_idx = i + MORE_THAN_25;
            if (arr[more_idx] == arr[i])
                return arr[i];

            int tmp = arr[more_idx], j;
            for (j = more_idx-1;j > i;--j) {
                if (arr[j] != tmp)
                    break;
            }
            i = j + 1;
        }

        return -1;
    }
};
