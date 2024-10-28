#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* addNodes(int val) {
    struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// k번째 작은 값을 찾기 위한 헬퍼 함수
int kthSmallestHelper(struct TreeNode* root, int* k) {
    if (root == NULL) return -1;

    int left = kthSmallestHelper(root->left, k);
    if (*k == 0) return left;  // 왼쪽 서브트리에서 k번째 요소를 찾은 경우 반환
    
    (*k)--; // 현재 노드를 방문
    if (*k == 0) return root->val;

    return kthSmallestHelper(root->right, k);  // 오른쪽 서브트리 탐색
}

// k번째 작은 값을 찾는 함수
int kthSmallest(struct TreeNode* root, int k) {
    return kthSmallestHelper(root, &k);
}

int main() {
    struct TreeNode *root = addNodes(5);
    struct TreeNode *tree1 = addNodes(3);
    struct TreeNode *tree2 = addNodes(6);
    struct TreeNode *tree3 = addNodes(2);
    struct TreeNode *tree4 = addNodes(4);
    struct TreeNode *tree5 = addNodes(1);
    root->left = tree1;
    root->right = tree2;
    tree1->left = tree3;
    tree1->right = tree4;
    tree3->left = tree5;
    
    printf("%d\n", kthSmallest(root, 3));

    return 0;
}