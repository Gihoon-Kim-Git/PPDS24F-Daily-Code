#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 문제 이해
// 1. row별로 rank를 매기는거임 결국.
// 2. 1의 개수를 count하고 -> 같은 경우에는 더 낮은 index가 weaker 
// 3. pq에 index 정보랑, soldier개수를 넣어야게따. 

class Solution {
    public:
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
            int rowN = mat.size();
            int colN = mat[0].size();
//(1). rank 저장할 priority queue 만들기: .first에 soldier개수 넣고, .second에 index넣기. 
//오름차순~
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

//(2). soldier 개수 count해서 채우기~
            for (int i = 0; i < rowN; i++) {
                int solN = 0;
                for (int j = 0; j < colN; j++) {
                    if (mat[i][j] ==1) {solN++;}
                }
                pq.push({solN,i});
            }
//(3). 그럼 solN 오름차순으로 정렬되고, solN이 같으면 second로 비교할테니까 다 됐댜~~
            vector<int> result(k, -1);
            for (int i = 0; i < k; i++) {
                cout << pq.top().second << " ";
                result[i] = pq.top().second;
                pq.pop();
            }
            cout << endl;

            return result;
        }

};

int main() {
    Solution mySol;

    vector<vector<int>> mat1 = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}};
    int k1 = 3;
    mySol.kWeakestRows(mat1, k1);
    //Output: [2,0,3]
// The number of soldiers in each row is: 
// - Row 0: 2 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 2 
// - Row 4: 5 
// The rows ordered from weakest to strongest are [2,0,3,1,4].

    vector<vector<int>> mat2 = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}}; 
    int k2 = 2;
    mySol.kWeakestRows(mat2, k2);
// Output: [0,2]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 1 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 1 
// The rows ordered from weakest to strongest are [0,2,3,1].



    return 0;
}

