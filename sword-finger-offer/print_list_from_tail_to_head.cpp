// 从尾到头反过来打印出链表每个结点的值。

#include <vector>
#include <stack>
#include <list>

using std::vector;
using std::stack;
using std::list;

vector<int> print_list_from_tail_to_head(list<int> l)
{
    vector<int> ret;
    stack<int> s;

    for (auto i : l)
	s.push(i);

    while (!s.empty()) {
        ret.emplace_back(s.top());
	s.pop();
    }

    return ret;
}
