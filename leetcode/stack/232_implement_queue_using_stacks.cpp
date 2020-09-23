#include <stack>

using std::stack;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        pushed_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (poped_stack.empty()) {
            while (!pushed_stack.empty()) {
                auto tmp = pushed_stack.top();
                pushed_stack.pop();
                poped_stack.push(tmp);
            }
        }

        auto tmp = poped_stack.top();
        poped_stack.pop();

        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if (poped_stack.empty()) {
            while (!pushed_stack.empty()) {
                auto tmp = pushed_stack.top();
                pushed_stack.pop();
                poped_stack.push(tmp);
            }
        }

        return poped_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return poped_stack.empty() && pushed_stack.empty();
    }

private:
    stack<int> pushed_stack;
    stack<int> poped_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
