#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int max_release_time = releaseTimes[0];

        for (int i = 1;i < releaseTimes.size();++i) {
            int tmp_release_time = releaseTimes[i]-releaseTimes[i-1];
            if (tmp_release_time > max_release_time) {
                max_release_time = tmp_release_time;
                res = keysPressed[i];
            } else if (tmp_release_time == max_release_time && keysPressed[i] > res) {
                res = keysPressed[i];
            }
        }

        return res;
    }
};
