#include <iostream>
#include <vector>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        TreeNode* current = root;
        int count = 0;
        
        while (current != nullptr || !stack.empty()) {
            // 왼쪽 서브트리를 모두 탐색
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            
            // 스택에서 노드를 꺼내어 방문
            current = stack.top();
            stack.pop();
            count++;
            if (count == k) {
                return current->val;
            }
            
            // 오른쪽 서브트리 탐색
            current = current->right;
        }
        
        // k가 트리의 노드 수를 초과하는 경우 (문제 조건상 발생하지 않음)
        return -1;
    }
};

int main(){
    // 트리 생성
    //       5
    //      / \
    //     3   6
    //    / \
    //   2   4
    //  /
    // 1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution sol;
    int k = 3;
    std::cout << "The " << k << "rd smallest element is " << sol.kthSmallest(root, k) << std::endl; // 출력: 3

    // 메모리 해제
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}