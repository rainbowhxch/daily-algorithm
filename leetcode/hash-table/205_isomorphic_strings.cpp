#include <string>
using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int SIZE_ALP = 128;
        int map_stot[SIZE_ALP] = {0};
        int map_ttos[SIZE_ALP] = {0};
        bool is_isomorphic = true;

        for (int i = 0;i < t.length();++i) {
            int tmp_stot = s[i];
            int tmp_ttos = t[i];

            if (map_stot[tmp_stot] == 0 && map_ttos[tmp_ttos] == 0) {
                map_stot[tmp_stot] = tmp_ttos+1;
                map_ttos[tmp_ttos] = tmp_stot+1;
            } else if (map_stot[tmp_stot] != tmp_ttos+1
                    || map_ttos[tmp_ttos] != tmp_stot+1) {
                is_isomorphic = false;
            }
        }

        return is_isomorphic;
    }
};
