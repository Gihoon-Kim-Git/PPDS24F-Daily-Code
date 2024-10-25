/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the
operation is successful, or false otherwise. boolean insertLast() Adds an item
at the rear of Deque. Returns true if the operation is successful, or false
otherwise. boolean deleteFront() Deletes an item from the front of Deque.
Returns true if the operation is successful, or false otherwise. boolean
deleteLast() Deletes an item from the rear of Deque. Returns true if the
operation is successful, or false otherwise. int getFront() Returns the front
item from the Deque. Returns -1 if the deque is empty. int getRear() Returns the
last item from Deque. Returns -1 if the deque is empty. boolean isEmpty()
Returns true if the deque is empty, or false otherwise. boolean isFull() Returns
true if the deque is full, or false otherwise.


Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront",
"getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4


Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront,
deleteLast, getFront, getRear, isEmpty, isFull.
*/
#include <cassert>
#include <memory>

using namespace std;

struct Node {
  int val;
  using NodePtr = shared_ptr<Node>;
  NodePtr prev;
  NodePtr next;
  Node(int val, NodePtr prev = NULL, NodePtr next = NULL)
      : val(val), prev(prev), next(next) {}
};

using NodePtr = shared_ptr<Node>;

class MyCircularDeque {
 private:
  NodePtr head;
  NodePtr rear;
  const int kCapacity;
  int size;

 public:
  MyCircularDeque(int k)
      : head(NodePtr(new Node(-1))),
        rear(NodePtr(new Node(-1))),
        kCapacity(k),
        size(0) {
    head->next = rear;
    rear->prev = head;
  }

  bool insertFront(int value) {
    if (size >= kCapacity) return false;

    NodePtr new_node(new Node(value, head, head->next));
    head->next->prev = new_node;
    new_node->next->prev = new_node;
    head->next = new_node;
    ++size;
    return true;
  }

  bool insertLast(int value) {
    if (size >= kCapacity) return false;

    NodePtr new_node(new Node(value, rear->prev, rear));
    rear->prev->next = new_node;
    new_node->prev->next = new_node;
    rear->prev = new_node;
    ++size;
    return true;
  }

  bool deleteFront() {
    // Check sentinel
    if (head->next->val < 0) return false;
    head->next = head->next->next;
    head->next->prev = head;
    --size;
    return true;
  }

  bool deleteLast() {
    // Check sentinel
    if (rear->prev->val < 0) return false;
    rear->prev = rear->prev->prev;
    rear->prev->next = rear;
    --size;
    return true;
  }

  int getFront() { return head->next->val; }

  int getRear() { return rear->prev->val; }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == kCapacity; }
};

int main() {
  MyCircularDeque* obj = new MyCircularDeque(3);
  assert(obj->insertLast(1) == true);    // return True
  assert(obj->insertLast(2) == true);    // return True
  assert(obj->insertFront(3) == true);   // return True
  assert(obj->insertFront(4) == false);  // return False, the queue is full.
  assert(obj->getRear() == 2);           // return 2
  assert(obj->isFull() == true);         // return True
  assert(obj->deleteLast() == true);     // return True
  assert(obj->insertFront(4) == true);   // return True
  assert(obj->getFront() == 4);          // return 4
  free(obj);

  return 0;
}
