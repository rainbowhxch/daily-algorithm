#include <queue>

using std::queue;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
		q.push(x);
		auto size_q = q.size();

		for (auto size_q = q.size();size_q > 1;--size_q) {
			q.push(q.front());
			q.pop();
		}
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		auto tmp = q.front();
		q.pop();

		return tmp;
    }

    /** Get the top element. */
    int top() {
		return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
		return q.empty();
    }

private:
	queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
