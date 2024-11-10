#include <iostream>
using namespace std;

class Solution {
public: int addbyOneTwoThree(int target) {
    int answer;
    if (target==1) {return 1;}
    else if (target==2) {return 2;}
    else if (target==3) {return 4;}
    
    else {
        return addbyOneTwoThree(target-1) + addbyOneTwoThree(target-2) + addbyOneTwoThree(target-3);
    }
}
};

int main(void) {
    Solution test;
    int answer = test.addbyOneTwoThree(7);
    cout << answer << endl;
    return 0;
}