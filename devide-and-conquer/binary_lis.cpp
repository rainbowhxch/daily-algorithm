#include <bits/stdc++.h>
using namespace std;

int bin_lis(vector<int> nums)
{
    int *heaps = new int[nums.size()];
    int cnt = 0;
    for (auto i : nums) {
        int left = 0, right = cnt;
        while (left < right) {
            int mid = (left+right) / 2;
            if (i < nums[mid])
                left = mid + 1;
            else
                right = mid;
        }

        if (left == cnt) cnt++;
        heaps[left] = i;
    }

    return cnt;
}

int main()
{
    cout << bin_lis({5, 2, 1, 3, 4});
    return 0;
}
