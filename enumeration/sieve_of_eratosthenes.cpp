#include <vector>

using std::vector;

int count_primers(int n)
{
    vector<bool> is_primer(n, true);
    for (int i = 2;i * i < n;++i) {
	if (is_primer[i]) {
	    for (int j = i * i;j < n;j += i) {
		is_primer[j] = false;
	    }
	}
    }

    int cnt = 0;
    for (int i = 2;i < n;++i) {
	if (is_primer[i])
	    cnt++;
    }

    return cnt;
}
