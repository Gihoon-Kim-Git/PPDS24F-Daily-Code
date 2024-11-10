#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode *root)
{
    // i:parent -> 2*i-1,2*i : children 인덱스
    // left leaf판별법 -> idx가 홀수이고, idx/2의 의 노드가 null이 아니다.
    // 그치만, 짱나게도, array로 주는게 아니네^^ pointer 두개? 부모랑 child가리키는

    // sum : leaf의 합을 저장
    // 재귀함수?
    // if parent,node->left == NULL && node->right==NULL && node == parent->left;
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        sum = root->left->val;
    }

    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}