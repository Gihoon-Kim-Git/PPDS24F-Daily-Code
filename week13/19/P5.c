#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int x, int y) {
      return (x > y) ? x : y;
}

int min(int x, int y) {
      return (x < y) ? x : y;
}

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

int* AncestorHelp(struct TreeNode* root) {
    int difleft = 0;
    int difright = 0;
    int* left = NULL;
    int* right = NULL;
    int minval = root->val;
    int maxval = root->val;
    if (root->left) {
        left = AncestorHelp(root->left);
        minval = min(minval, left[0]);
        maxval = max(maxval, left[1]);
        difleft = left[2];
        free(left);
    }
    if (root->right) {
        right = AncestorHelp(root->right);
        minval = min(minval, right[0]);
        maxval = max(maxval, right[1]);
        difright = right[2];
        free(right);
    }
    int maxdiff = max(root->val - minval, maxval - root->val);
    maxdiff = max(max(maxdiff, difleft), difright);
    int* answer = (int*)malloc(3 * sizeof(int));
    answer[0] = minval;
    answer[1] = maxval;
    answer[2] = maxdiff;
    return answer;
}

int maxAncestorDiff(struct TreeNode* root) {
    if (root == NULL) return 0;
    int* result = AncestorHelp(root);
    int answer = result[2];
    free(result);
    return answer;
}

int main() {
    struct TreeNode *root = addNodes(8);
    struct TreeNode *tree1 = addNodes(3);
    struct TreeNode *tree2 = addNodes(10);
    struct TreeNode *tree3 = addNodes(1);
    struct TreeNode *tree4 = addNodes(6);
    struct TreeNode *tree5 = addNodes(14);
    struct TreeNode *tree6 = addNodes(4);
    struct TreeNode *tree7 = addNodes(7);
    struct TreeNode *tree8 = addNodes(13);
    root->left = tree1;
    root->right = tree2;
    tree1->left = tree3;
    tree1->right = tree4;
    tree2->right = tree5;
    tree4->left = tree6;
    tree4->right = tree7;
    tree5->left = tree8;
    
    printf("%d\n", maxAncestorDiff(root));

    return 0;
}