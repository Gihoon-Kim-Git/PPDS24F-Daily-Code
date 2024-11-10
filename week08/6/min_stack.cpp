/*
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty
stacks. At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
#include <cassert>
#include <stack>

using namespace std;

class MinStack {
 private:
  stack<int> main;  // Usual stack
  stack<int> mins;  // Only min values

 public:
  MinStack() {}

  void push(int val) {
    main.push(val);
    if (mins.empty() || mins.top() >= val) mins.push(val);
  }

  void pop() {
    if (main.top() == mins.top()) mins.pop();
    main.pop();
  }

  int top() { return main.top(); }

  int getMin() { return mins.top(); }
};

int main() {
  MinStack* minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-3);
  assert(minStack->getMin() == -3);
  minStack->pop();
  assert(minStack->top() == 0);
  assert(minStack->getMin() == -2);
  free(minStack);

  return 0;
}
