/*Kth Smallest Element in a BST
LeetCode 230

*/

/**
 * Definition for a binary tree node.

 */


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int kthSmallest(struct TreeNode* root, int k) {
    
    int *arr = (int *)malloc(sizeof(int) * 10000);
    if (!arr) {
        return -1; // 메모리 할당 실패 시 에러 처리
    }

    int idx = 0;
    Inorder(root, arr, &idx);

    if (k < 1 || k > idx) {
        free(arr); // 범위 밖일 경우 메모리 해제 후 에러 반환
        return -1;
    }

    int result = arr[k - 1]; // k번째로 작은 요소 추출
    free(arr); // 메모리 해제
    
    return result;

}

// parent가 필요한 상황 -> 자기 자신을 return?
void Inorder(struct TreeNode *root, int arr[], int *idx)
{
    if (!root)
    {
        return;
    }

    Inorder(root->left,arr,idx);
    arr[(*idx)++] = root->val;
    Inorder(root->right,arr,idx);
    
}