#include <cmath>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (int i = 0;i < arr.size() - 2;++i) {
            int j = i + 1;
            int k = arr.size() - 1;

            while (j < k) {
                if (abs(arr[i]-arr[j]) <= a && j != k) {
                    if (abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c)
                        cnt++;
                    k--;

                    if (j == k) {
                        j++;
                        k = arr.size() - 1;
                    }
                } else {
                    j++;
                    k = arr.size() - 1;
                }
            }
        }

        return cnt;
    }
};
