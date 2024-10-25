#include <bits/stdc++.h>
#include <vector>
using namespace std;


class MinStack {
public:
    vector<pair<int,int>> a;

    MinStack() {
        
    }
    
    void push(int val) {
        if(a.empty()){
            a.push_back({val,val});
        }  
        else {
            a.push_back({val,min(a.back().second,val)});
        }
    }
    
    void pop() {
        a.pop_back();
    }
    
    int top() {
        return a.back().first;
    }
    
    int getMin() {
        return a.back().second;
    }
};