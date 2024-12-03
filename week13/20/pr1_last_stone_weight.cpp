#include <queue>
#include <iostream>
using namespace std;
// #include <vector>
int main(){

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(3);
    pq.push(1);
    pq.push(10);

    for(int i=0;i<3;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    // return -1;
}


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // priority_queue<int> pq;
        // for(int x : stones){
        //     pq.push(x);
        // }
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a==b) continue;
            else pq.push(a-b);
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};