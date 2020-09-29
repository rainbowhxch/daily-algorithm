#include <vector>
#include <unordered_set>
#include <string>

using std::vector;
using std::unordered_set;
using std::string;
using std::to_string;
using std::max;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, di = 0;
        int ans = 0;

        unordered_set<string> obstacle_set;
        for (auto i : obstacles)
            obstacle_set.insert(to_string(i[0])+":"+to_string(i[1]));

        for (auto cmd : commands) {
            if (cmd == -2) {
                di = (di+3) % 4;
            } else if (cmd == -1) {
                di = (di+1) % 4;
            } else {
                for (int i = 0;i < cmd;++i) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacle_set.find(to_string(nx)+":"+to_string(ny)) == obstacle_set.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }

        return ans;
    }

private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
};
