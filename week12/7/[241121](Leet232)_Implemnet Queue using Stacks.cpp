/* Stack Library method
    stack.push(element)
    stack.pop()
    stack.top()
    stack.size()
    stack.empty()
    swap(stack1, stack2)
*/


//Using 2 stack-----------------------------------------------------------------------------

#include <stack>
#include <vector>
using namespace std;

class MyQueue {
public:
    stack<int> store_stack;
    stack<int> temp_stack;

    MyQueue() {    
    }
    
    void push(int x) {
        store_stack.push(x);
    }
    
    int pop() {
        if (temp_stack.size() == 0){
            while (!store_stack.empty()){
                int t = store_stack.top();
                store_stack.pop();
                temp_stack.push(t);
            }
        }

        int pop_element = temp_stack.top();
        temp_stack.pop();

        return pop_element;
    }
    
    int peek() {
        if (temp_stack.size() == 0){
            while (!store_stack.empty()){
                int t = store_stack.top();
                store_stack.pop();
                temp_stack.push(t);
            }
        }

        return temp_stack.top();
    }
    
    bool empty() {
        return temp_stack.empty() && store_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



// Using 1 Stack ------------------------------------------------------------------------------
#include <stack>
#include <vector>
using namespace std;

class MyQueue {
public:
    stack<int> st1;

    MyQueue() {    
    }
    
    void push(int x) {
        vector<int> temp;

        while (!st1.empty()){
            int t = st1.top();
            st1.pop();
            temp.push_back(t);
        }

        st1.push(x);

        while (!temp.empty()){
            int t = temp[-1];
            temp.pop_back();
            st1.push(t);
        }
    }
    
    int pop() {
        int pop_element = st1.top();
        st1.pop();

        return pop_element;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};
