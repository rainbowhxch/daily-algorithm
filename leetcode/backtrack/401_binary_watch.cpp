#include <string>
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class Solution {
public:
    const int hour[4]={1, 2, 4, 8};
    const int mins[6]={1, 2, 4, 8, 16, 32};
    vector<string> ans;

    void dfs(int n,int h,int m, int i){
        if(n == 0 ){
            string tmp="";

            if(m<10)
                tmp += "0";
            tmp += to_string(m);
            ans.emplace_back(to_string(h)+":"+tmp);
            return;
        }

        for( ; i < 4; i++){
            if(h + hour[i]<=11)
                dfs(n-1, h+hour[i], m, i+1);
        }

        for( ; i < 10; i++){
            if(m+ mins[i-4]<=59)
                dfs(n-1, h, m+mins[i-4], i+1);
        }
    }
    vector<string> readBinaryWatch(int num) {
        dfs(num, 0, 0, 0);

        return ans;
    }
};
