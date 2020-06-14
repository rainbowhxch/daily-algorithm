/* 将一个字符串中的空格替换成 "%20"。
Input:
"A B"

Output:
"A%20B" */

#include <exception>
#include <string>

using std::string;

string replace_space(string s)
{
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ')
	    s.append("   ");
    }

    int len_after_expand = s.length();
    while (len >= 0 && len_after_expand > len) {
        char c = s[len];
	if (c == ' ') {
	    s[len_after_expand--] = '0';
	    s[len_after_expand--] = '2';
	    s[len_after_expand--] = '%';
	} else {
	    s[len_after_expand--] = c;
	}
    }

    return s;
}
