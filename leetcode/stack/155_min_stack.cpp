#include <stack>

using std::stack;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
		stack_normal.push(x);
		if (!stack_min.empty())
			stack_min.push(stack_min.top() < x ? stack_min.top() : x);
		else
			stack_min.push(x);
    }

    void pop() {
		if (!stack_normal.empty()) {
			stack_normal.pop();
			stack_min.pop();
		}
    }

    int top() {
		if (!stack_normal.empty())
			return stack_normal.top();

		return -1;
    }

    int getMin() {
		if (!stack_normal.empty())
			return stack_min.top();

		return -1;
    }

private:
	stack<int> stack_normal;
	stack<int> stack_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
