#include <vector>

using std::vector;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> path_table(n, vector<int>());
        int ans = 0;

        for (const auto &i : edges) {
            path_table[i[0]].push_back(i[1]);
            path_table[i[1]].push_back(i[0]);
        }
        dfs(0, -1, path_table, hasApple, ans);

        return ans;
    }
private:
    void dfs(int cur_node, int parent, const vector<vector<int>> &path_table, vector<bool> &hasApple, int &ans) {
        for (const auto adj : path_table[cur_node]) {
            if (adj == parent)  continue;
            dfs(adj, cur_node, path_table, hasApple, ans);
            if (hasApple[adj]) {
                ans += 2;
                if (hasApple[adj])
                    hasApple[cur_node] = true;
            }
        }
    }
};
