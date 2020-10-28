#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int n = M.size() ;
    if(n == 0)
        return M ;
    int m = M[0].size() ;
    if(m == 0)
        return M ;
    int last ;
    vector<vector<int> >Result(n,vector<int>(m,0)) ;

    // Taking sum Row wise
    for(int i = 0 ; i<n ; i++)
    {
        int sum = 0 ;
        int j = 0 ;
        for(; j<2 && j<m ; j++)
        {
            sum += M[i][j] ;
        }
        last = M[i][0] ;
        M[i][0] = sum ;
        for(; j <m ; j++)
        {
            int temp = M[i][j-1] ;
            sum += M[i][j] ;
            M[i][j-1] = (sum) ;
            sum -= last ;
            last = temp ;

        }
        M[i][m-1] = (sum) ;
    }

    // Taking sum Colomn wise and dividing with respective numbers


    for(int j = 0 ; j<m ; j++)
    {
        int i = 0 ;
        int sum = 0 ;
        for(; i<2 && i<n ; i++)
        {
            sum += M[i][j]  ;
        }
        last = M[0][j] ;
        if(j != 0 && j!= m-1)
        M[0][j] = (sum /(min(2,n) * min(3,m))) ;
        else
        M[0][j] = (sum /(min(2,n) * min(2,m))) ;

        for(;i<n ; i++)
        {
            sum += M[i][j] ;
            int temp = M[i-1][j] ;
            if(j != 0 && j!= m-1)
            M[i - 1][j] = (sum /(min(3,n) * min(3,m))) ;
            else
            M[i - 1][j] = (sum /(min(3,n) * min(2,m))) ;
            sum -= last  ;
            last = temp ;
        }
        if(j != 0 && j!= m-1)
        M[n-1][j] = (sum / (min(2,n) * min(3,m) ));
        else
        M[n-1][j] = (sum / (min(2,n) * min(2,m)) );
    }
    return M ;
}
};
