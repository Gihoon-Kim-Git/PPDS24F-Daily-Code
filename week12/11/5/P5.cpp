#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> nums;
    queue<int> temp;
    MyStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
    }
    
    int pop() {
        while (nums.size() != 1){
            int a = nums.front();
            temp.push(a);
            nums.pop();
        }
        int result = nums.front();
        nums.pop();
        swap(nums, temp);
        return result;
    }
    
    int top() {
        while (nums.size() != 1){
            int a = nums.front();
            temp.push(a);
            nums.pop();
        }
        int result = nums.front();
        int a = nums.front();
        temp.push(a);
        nums.pop();
        swap(nums, temp);
        return result;
    }
    
    bool empty() {
        return (nums.size() == 0);
    }
};


int main(void){

    return 0;
}