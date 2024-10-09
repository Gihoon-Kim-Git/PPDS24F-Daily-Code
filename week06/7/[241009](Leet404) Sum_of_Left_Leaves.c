/* 문제
binary tree의 root가 주어졌을 때, sum of all left leaves를 구하라.

left leaf : child가 없으면서, 부모 노드의 left child인 노드.
*/

/* 문제풀이: queue를 사용하지 않는 DFS로 푸는 것이 간단.
    1. 현재노드가 leftchild인지 정보를 함께 받는 helper함수 활용. =>Recursive 방식.
    2. Helper(Node, isLeft) // Node가 Node.parent의 left이면 isLeft 1, 아니면 0
        1) Node == NULL : return 0
        2) Node != NULL && Node has 1,2 child :
            Left_result = Helper(Node.left, 1)
            Right_result = Helper(Node.right, 0)
            return Left_result + Right_result
        3) Node != NULL && Node가 leaf (no child)
            만약 현재 노드의 isLeft ==1, return Node.val
            만약 현재노드의 isLeft == 0, return 0
*/


#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int helper(struct TreeNode* cur, int isLeft){
    if (cur == NULL) return 0;
    else { // cur!=NULL
        if (cur->left == NULL && cur->right == NULL) {
            if (isLeft == 1) return cur->val;
            else return 0;
        } 
        else {
            int Left_Result = helper(cur->left, 1);
            int Right_Result = helper(cur->right, 0);
            return Left_Result + Right_Result;
        }
    }
}

int sumOfLeftLeaves(struct TreeNode* root){
    return helper(root, 0);
}