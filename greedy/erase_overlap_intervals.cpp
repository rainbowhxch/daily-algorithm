#include <bits/stdc++.h>

using namespace std;

struct interval {
    int start, end;
};

bool cmp(interval a, interval b)
{
    return a.end < b.end;
}

int erase_overlap_intervals(vector<interval> intvs)
{
    int cnt = 0;
    sort(intvs.begin(), intvs.end(), cmp);
    int end_cur = intvs[0].end;
    for (auto i : intvs) {
	int start_cur = i.start;
	if (start_cur >= end_cur) {
	    cnt++;
	    end_cur = i.end;
	}
    }

    return intvs.size() - cnt;
}
