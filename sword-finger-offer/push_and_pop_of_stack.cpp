/* 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。 */

#include <vector>
#include <stack>
using std::vector;
using std::stack;

bool is_pop_order(vector<int> push_seq, vector<int> pop_seq)
{
    int n = push_seq.size();
    stack<int> s;
    for (int push_idx = 0, pop_idx = 0; push_idx < n; push_idx++) {
	s.push(push_seq[push_idx]);
	while (pop_idx < n && !s.empty() && s.top() == pop_seq[pop_idx]) {
	    s.pop();
	    pop_idx++;
	}
    }

    return s.empty();
}
