#include <vector>

using std::vector;

class Solution {
public:
int sumOddLengthSubarrays(vector<int> &arr) {
    int odd=1;
    int sum=0;
    int result=0;

    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            sum+=arr[j];

            if(odd%2==1)
                result+=sum;
            odd++;
        }

        sum=0;
    }

    return result;
    }
};
