/* 用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。 */
#include <iterator>
#include <stack>
using std::stack;

static stack<int> in;
static stack<int> out;

void push(int i)
{
    in.push(i);
}

int pop()
{
    if (out.empty()) {
	while (!in.empty()) {
	    out.push(in.top());
	    in.pop();
	}
    }

    if (out.empty())
	return -1;

    int res = out.top();
    out.pop();
    return res;
}
