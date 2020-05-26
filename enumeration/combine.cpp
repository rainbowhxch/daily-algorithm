#include <vector>

using std::vector;

vector<vector<int> > res;

void backtrack(int n, int k, int cur, vector<int> track)
{
    if (track.size() == k) {
        res.push_back(track);
        return;
    }

    for (int i = cur;i < n;++i) {
        track.push_back(i);
        backtrack(n, k, i+1, track);
        track.pop_back();
    }
}

vector<vector<int> > combine(int n, int k)
{
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}
