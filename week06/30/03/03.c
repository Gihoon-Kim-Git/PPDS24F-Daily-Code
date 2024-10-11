#include <stdio.h>
#include <stdlib.h>

// 이진 트리의 노드를 정의하는 구조체
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int isLeaf(struct TreeNode* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    if (root->left != NULL) {
        if (isLeaf(root->left)) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = sumOfLeftLeaves(root);
    printf("Sum of left leaves: %d\n", result); 

    return 0;
}
