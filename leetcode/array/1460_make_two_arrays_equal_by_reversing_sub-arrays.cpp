#include <vector>
#include <array>

using std::vector;
using std::array;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        array<int, 1001> book = {0};

        for (auto i : target)
            book[i]++;
        for (auto i : arr)
            book[i]--;
        for (auto i : book)
            if (i != 0)
                return false;

        return true;
    }
};
