/* 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数即 999。 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void print_s(string s)
{
    int idx = 0;

    while (idx < s.length() && s[idx] == '0')
	idx++;
    while (idx < s.length())
	cout << s[idx++];

    cout << endl;
}

void print_n_numbers(string s, int cur_pos)
{
    if (s.length() == cur_pos) {
	print_s(s);
	return;
    }

    for (int i = 0;i < 10;++i) {
	s[cur_pos] = i + '0';
	print_n_numbers(s, cur_pos+1);
    }
}

void print_n_numbers(int n)
{
    if (n > 0) {
	string s(n, '0');
	print_n_numbers(s, 0);
    }
}
