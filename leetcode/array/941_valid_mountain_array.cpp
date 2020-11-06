#include <vector>

using std::vector;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i;

        for (i = 0;i < arr.size()-1;++i)
            if (arr[i] >= arr[i+1])  break;
        if (i == 0 || i == arr.size()-1 || arr[i] == arr[i+1])
            return false;
        for (;i < arr.size()-1;++i)
            if (arr[i] <= arr[i+1]) return false;

        return true;
    }
};
