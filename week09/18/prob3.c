#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//3. maximum depth of n-aray tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int compare(void const *a, void const *b) {
    return *(int *)a - *(int *)b;
}

int num_node(struct TreeNode* root, int len) {
    if (root == NULL) return 0;

    return 1 + num_node(root->left, len) + num_node(root->right, len);
}

void kthSmallest_helper(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) return;
    arr[*idx] = root->val;
    (*idx)++;

    kthSmallest_helper(root->left, arr, idx);
    kthSmallest_helper(root->right, arr, idx);
}

int kthSmallest(struct TreeNode* root, int k) {
    int len = 0;
    int num = num_node(root, len);
    
    int* arr = (int*)malloc(sizeof(int)*num);
    int idx = 0;

    kthSmallest_helper(root, arr, &idx);

    qsort(arr, num, sizeof(int), compare);
    
    return arr[k-1];
}
