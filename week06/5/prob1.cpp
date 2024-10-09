// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // Implement your solution here
    int is_valid = 1;

    vector<char> stack;

    for (char c : S) {
        // open 이면 enqueue
        if (c=='(') {
            stack.push_back(')');
        } else if (c=='{') {
            stack.push_back('}');
        } else if (c=='[') {
            stack.push_back(']');
        // close 면 가능한 지 체크 후 dequeue
        } else {
            // empty 면 더 볼 것도 없이 invalid
            if (stack.empty()) {
                is_valid = 0;
                break;
            // empty 가 아니면 top 이 close 와 동류인지 확인하고
            // - 동류가 맞으면 dequeue
            } else if (stack.back()==c) {
                stack.pop_back();
            // - 동류가 아니면 invalid
            } else {
                is_valid = 0;
                break;
            }
        }
    }

    // for loop 를 끝까지 통과했다는 것은 잘못된 close 로 인한 invalid 는 없었다는 뜻.
    // 잘못된 open 즉, close 로 마무리되지 못한 open 도 체크해야 함.
    // 다시 말해, for loop 통과 후 stack 이 empty 되었는지 확인해야 함.
    if (!stack.empty()) {
        is_valid = 0;
    }
    return is_valid;
}
