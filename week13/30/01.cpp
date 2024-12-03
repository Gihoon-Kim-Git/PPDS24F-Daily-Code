#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

// <문제 이해>
// vector에서
// 젤 큰거 2개에 대해
// 1. 같으면 둘다 소멸
// 2. 하나가 더 크면 작은건 사라지고, 큰건 y-x로 바뀜 
// 1개 OR 0개의 STONE이 남음
// 그 무게 RETURN

// <전략>
// WHILE vector.size() >= 2일때까지 계속 반복하고
// 1개이면 그 무게
// 0개이면 0 return 



class Solution {
public:
    void desSort(vector<int>& myVec, function<bool(int,int)> comparator) {
        sort(myVec.begin(), myVec.end(), comparator);
    }

    bool descending(int a, int b) {
        if (a >= b) {
            return true;
        } else {
            return false;
        }
    }

    void printVec(vector<int>& myVec) {
        for (int i = 0; i < myVec.size(); i++) {
            cout << myVec[i] << " ";
        }
        cout << endl;
    }

    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() >= 2) {
            //(1). 내림차순으로 정렬
            desSort(stones, [this](int a, int b) {return descending(a,b);});
            printVec(stones);

            //(2). 젤 큰 2개에 대해 if문 걸기
            int y = stones[0]; int x = stones[1];
            size_t idx0 = 0; size_t idx1 = 1;
            if (x == y) {
                stones.erase(stones.begin() + idx0);
                stones.erase(stones.begin() + idx0);  //지우고나면 index 1 -> index 0이 되곘지!
            } else if (y > x) {
                stones[0] = y - x;
                stones.erase(stones.begin() + idx1);
            }
        }

        //(3). 현재 stones.size()는 1 or 0임
        if (stones.size() == 0) {
            return 0;
        } else {
            return stones[0];
        }
    }
};

int main() {

// Input: stones = [2,7,4,1,8,1]
// Output: 1
    vector<int> stones1 = {2,7,4,1,8,1};
    vector<int> stones2 = {1};
    vector<int> stones3 = {10,4,2,10};

    Solution mysol;
    cout << "ANS 1: \n" << mysol.lastStoneWeight(stones1) << endl;;
    cout << "ANS 2: \n" << mysol.lastStoneWeight(stones2) << endl;;
    cout << "ANS 3: \n" << mysol.lastStoneWeight(stones3) << endl;;
    return 0;
}