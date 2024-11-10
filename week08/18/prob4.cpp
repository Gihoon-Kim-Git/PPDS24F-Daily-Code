#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:

    vector<int> Stack;
    int Top_idx;
    int Size;

    MinStack() {
        Size = 0;  
        Top_idx = -1;      
    }
    
    void push(int val) {
        Top_idx = Size;
        Stack.push_back(val);
        Size++;
    }
    
    void pop() {
        if (Size == 0){;}
        else {
            Top_idx --;
            Stack.erase(Stack.end());
            Size--;            
        }
    }
    
    int top() {
        return Stack[Top_idx];
    }
    
    int getMin() {
        if (Size == 0){;}
        
        int min_el = INT_MAX;

        for (int i=0; i<Size; i++){
            min_el = min(min_el, Stack[i]);
        }
        
        return min_el;
    }
};
