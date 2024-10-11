#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int solution(std::string &S) {
        std::stack<char> stack;
        
        for (char ch : S) {
            // If opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } 
            // If closing bracket, check if it matches the top of the stack
            else {
                if (stack.empty()) return 0; // unmatched closing bracket
                
                char top = stack.top();
                stack.pop();
                
                // Check if the top of the stack corresponds to the correct opening bracket
                if ((ch == ')' && top != '(') || 
                    (ch == '}' && top != '{') || 
                    (ch == ']' && top != '[')) {
                    return 0;
                }
            }
        }
        
        // In the end, stack should be empty if all brackets were matched
        return stack.empty() ? 1 : 0;
    }
};

int main() {
    Solution sol;
    std::string S1 = "{[()()]}";
    std::string S2 = "([)()]";
    
    std::cout << sol.solution(S1) << std::endl; // Output: 1
    std::cout << sol.solution(S2) << std::endl; // Output: 0
    
    return 0;
}
