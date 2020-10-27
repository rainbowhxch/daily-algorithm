#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<vector<int>> out(numRows);

        for(size_t n=0; n < numRows; ++n){
            for(size_t j=0; j <= n; ++j){
                if(j == 0){
                    out[n].push_back(1);
                }
                else if(j == n){
                    out[n].push_back(1);
                }
                else{
                    out[n].push_back(out[n-1][j-1] + out[n-1][j]);
                }
            }
        }

        return out;
    }
};
