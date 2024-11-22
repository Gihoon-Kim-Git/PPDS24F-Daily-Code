#include <cassert>
#include <memory>
#include <stack>

using namespace std;

class MyQueue {
 private:
  using StackPtr = shared_ptr<stack<int>>;

  StackPtr st1;
  StackPtr st2;

 public:
  MyQueue() : st1(new stack<int>()), st2(new stack<int>()) {}

  void push(int x) {
    while (!st1->empty()) {
      st2->push(st1->top());
      st1->pop();
    }
    st2->push(x);
    while (!st2->empty()) {
      st1->push(st2->top());
      st2->pop();
    }
  }

  int pop() {
    int res = st1->top();
    st1->pop();
    return res;
  }

  int peek() { return st1->top(); }

  bool empty() { return st1->empty(); }
};

int main() {
  MyQueue* mq = new MyQueue();
  mq->push(1);
  mq->push(2);
  assert(mq->peek() == 1);
  assert(mq->pop() == 1);
  assert(!mq->empty());
}