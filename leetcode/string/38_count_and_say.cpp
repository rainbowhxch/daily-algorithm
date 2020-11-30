#include <string>

using std::string;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";

        string str = "11";
        for(int i = 3; i <= n; ++i){
            str +="$";
            int cnt = 1;
            string next_str = "";
            for(int j = 1; j < str.length(); ++j){
                if(str[j] != str[j-1]){
                    next_str += cnt + '0';
                    next_str += str[j-1];
                    cnt = 1;
                }else {
                    cnt++;
                }
            }
            str = next_str;
        }

        return str;
    }
};
