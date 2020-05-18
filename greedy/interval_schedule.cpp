#include <bits/stdc++.h>
using namespace std;

struct interval {
    int start, end;
};

bool cmp(interval a, interval b)
{
    return a.end < b.end;
}

int interval_schedule(vector<interval> ints)
{
    if (ints.size() == 0) return 0;

    sort(ints.begin(), ints.end(), cmp);
    int cnt = 1;
    int cur_end = ints[0].end;

    for (auto i : ints) {
        if (i.start >= cur_end) {
            cnt++;
            cur_end = i.end;
        }
    }

    return cnt;
}
