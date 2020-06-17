/* 请实现一个函数用来匹配包括 '.' 和 '*' 的正则表达式。模式中的字符 '.' 表示任意一个字符，
 * 而 '*' 表示它前面的字符可以出现任意次（包含 0 次）。在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串 "aaa" 与模式 "a.a" 和 "ab*ac*a" 匹配，但是与 "aa.a" 和 "ab*a" 均不匹配。 */

#include <pthread.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

bool regex_match(string pattern, string s)
{
    int len_p = pattern.length(), len_s = s.length();
    vector<vector<bool> > dp(len_s, vector<bool>(len_p, false));
    dp[0][0] = true;

    for (int i = 2;i < len_p;++i) {
	if (pattern[i-1] == '*')
	    dp[0][i] = dp[0][i-2];
    }

    for (int i = 1;i < len_s;++i) {
	for (int j = 1;j < len_p;++j) {
	    if (s[i-1] == pattern[j-1] || pattern[j-1] == '.')
		dp[i][j] = dp[i-1][j-1];
	    else if (pattern[j-1] == '*') {
		if (pattern[j-2] == s[i-1]) {
		    dp[i][j] = dp[i][j] | dp[i][j-1];
		    dp[i][j] = dp[i][j] | dp[i-1][j];
		    dp[i][j] = dp[i][j] | dp[i][j-2];
		} else {
		    dp[i][j] = dp[i][j] | dp[i][j-2];
		}
	    }
	}
    }

    return dp[len_s][len_p];
}
