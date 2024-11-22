#include <cassert>
#include <memory>
#include <queue>

using namespace std;

class MyStack {
 private:
  using QueuePtr = shared_ptr<queue<int>>;

  QueuePtr q1;
  QueuePtr q2;
  int top_el;

 public:
  MyStack() : q1(new queue<int>()), q2(new queue<int>()) {}

  void push(int x) {
    q1->push(x);
    top_el = x;
  }

  int pop() {
    while (q1->size() > 1) {
      int e = q1->front();
      q2->push(q1->front());
      q1->pop();
    }
    int res = q1->front();
    q1->pop();

    while (q2->size() > 1) {
      q1->push(q2->front());
      q2->pop();
    }

    if (!q2->empty()) {
      top_el = q2->front();
      q1->push(q2->front());
      q2->pop();
    }

    return res;
  }

  int top() { return top_el; }

  bool empty() { return q1->empty(); }
};

int main() {
  shared_ptr<MyStack> st(new MyStack());
  st->push(1);
  st->push(2);
  st->push(3);
  assert(st->top() == 3);
  assert(st->pop() == 3);
  assert(st->top() == 2);
  assert(st->pop() == 2);
  assert(!st->empty());

  shared_ptr<MyStack> st1(new MyStack());
  st1->push(1);
  assert(st1->pop() == 1);
  assert(st1->empty());
}