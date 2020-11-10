#include <functional>
#include <mutex>

using std::function;
using std::mutex;

class Foo {
public:
    Foo() {
        m_secondLock.lock();
        m_thirdLock.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_secondLock.unlock();
    }

    void second(function<void()> printSecond) {
        m_secondLock.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_thirdLock.unlock();
    }

    void third(function<void()> printThird) {
        m_thirdLock.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex m_secondLock;
    mutex m_thirdLock;
};
