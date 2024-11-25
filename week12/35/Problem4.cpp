/*
Leetcode 232
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    // pop efficient method
    stack<int>st;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) { // O(n)
        // same as push at buttom
        if(st.size()==0) {
            st.push(x);
            return;
        }
        else {
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
    }
    
    int pop() { // O(1)
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() { // O(1)
        return st.top();
    }
    
    bool empty() {  // O(1)
       if(st.size()==0) return true;
       else return false; 
    }
};
    // push efficient method
    stack<int>st;
    stack<int>helper;
    // MyQueue() {
        
    // }
    
    void push(int x) { // O(1)
        st.push(x);
    }
    
    int pop() { // O(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() { // O(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {  // O(1)
       if(st.size()==0) return true;
       else return false; 
    }