#include <stack>
using namespace std;

class MinStack {
public:
    
    stack <long long> arr;
    long long min_val;

    MinStack() {
        
    }
    
    void push(int val) {
        long long val2 = (long long)val;
        if(arr.empty()) {
            min_val=val2;
            arr.push(val2);
        } else {
            if(val2>min_val) {
                arr.push(val2);
            } else {
                arr.push(long(2*val2*1LL)-min_val);
                min_val=val2;
            }
        }
    }
    
    void pop() {
        if (arr.empty()) {
            return;
        }
        long long x = arr.top();
        arr.pop();
        if (x<min_val) {
            min_val=(2*min_val)-x;
        }
    }
    
    int top() {
        if (arr.empty()){
            return -1;
        }
        long long x=arr.top();
        if (min_val<x) {
            return x;
        }
        return min_val;
    }
    
    int getMin() {
        return min_val;
    }
};