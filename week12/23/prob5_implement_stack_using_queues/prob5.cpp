#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    MyStack() {}

    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topElement = queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return topElement;
    }

    int top() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topElement = queue1.front();
        queue2.push(topElement);
        queue1.pop();
        swap(queue1, queue2);
        return topElement;
    }

    bool empty() {
        return queue1.empty();
    }
};

// Example usage
int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;   // Output: 2
    cout << stack.pop() << endl;   // Output: 2
    cout << stack.empty() << endl; // Output: 0
    return 0;
}
