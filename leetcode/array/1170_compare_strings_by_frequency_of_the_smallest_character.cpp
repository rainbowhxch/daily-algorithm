#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int qsize = queries.size();
        vector<int> ans(qsize, 0);

        for (int i = 0;i < qsize;++i)
            ans[i] = get_frequency_of_the_smallest_char(queries[i]);

        int cnt_w[11] = {0};
        for (auto i : words)
            cnt_w[get_frequency_of_the_smallest_char(i)-1]++;
        for (int i = 9;i >= 1;--i)
            cnt_w[i] += cnt_w[i+1];

        for (auto &i : ans) {
            i = cnt_w[i];
        }

        return ans;
    }

private:
    int get_frequency_of_the_smallest_char(string s) {
        int cnt[26] = {0};

        for (auto c : s)
            cnt[c-'a']++;
        for (int i = 0;i < 26;++i) {
            if (cnt[i] != 0)
                return cnt[i];
        }

        return -1;
    }
};
