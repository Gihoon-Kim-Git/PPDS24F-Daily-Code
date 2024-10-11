#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string &S) {
    std::vector<char> stack; // 빈 벡터로 시작
    std::set<char> front = {'{', '[', '('}; // 여는 괄호 집합

    for(size_t i = 0; i < S.size(); i++) {
        if(front.find(S[i]) != front.end()) { // 여는 괄호일 때 스택에 푸시
            stack.push_back(S[i]);
        } else {
            if(stack.empty()) { // 스택이 비어있으면 잘못된 괄호
                return 0;
            }

            // 스택의 마지막 요소와 닫는 괄호 비교
            if((stack.back() == '(' && S[i] == ')') ||
               (stack.back() == '[' && S[i] == ']') ||
               (stack.back() == '{' && S[i] == '}')) {
                stack.pop_back(); // 짝이 맞으면 마지막 요소 제거
            } else {
                return 0; // 짝이 맞지 않으면 실패
            }
        }
    }

    // 모든 괄호가 짝이 맞아 스택이 비어 있어야 성공
    return stack.empty() ? 1 : 0;
}
