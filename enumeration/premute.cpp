#include <iterator>
#include <vector>

using std::vector;

vector<vector<int> > res;

void backtrack(vector<int> nums, vector<int> track)
{
    if (track.size() == nums.size()) {
        res.push_back(track);
        return;
    }

    for (int i = 0;i < nums.size();++i) {
        bool continued = false;

        for (auto d : track) {
            if (d == nums[i]) {
                continued = true;
            }
        }
        if (continued) continue;

        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}

vector<vector<int> > premute(vector<int> nums)
{
    vector<int> track;
    backtrack(nums, track);
    return res;
}
