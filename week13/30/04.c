// 전략:
// leafnode의 level 구해서 그 중 max인거 뱉자.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int val) {
    struct TreeNode* myNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    myNode->left = NULL;
    myNode->right = NULL;
    myNode->val = val;

    return myNode;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
//_________MAIN_______________//


//______________________________________________
void traversal(struct TreeNode* root, int cur_depth, int* max_depth) {
    if (root == NULL) {return;}

    printf("node: %d || cur: %d - max: %d\n", root->val, cur_depth, *max_depth);
    //방문했을때 할 일
    cur_depth++;
    if (cur_depth > *max_depth) {
            *max_depth = cur_depth;
    }
    //방문 위해 할일
        traversal(root->right, cur_depth, max_depth);
        traversal(root->left, cur_depth, max_depth);

}

int maxDepth(struct TreeNode* root) {
    int max_depth = 0;
    traversal(root, 0, &max_depth);
    return max_depth;
}


// void printArr(int* arr, int size) {
//     printf("\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }


int main() {
//(1). TEST를 위한 TREE를 만들자. 
    struct TreeNode* node0 = createNode(3);
    struct TreeNode* node1 = createNode(9);
    struct TreeNode* node2 = createNode(20);
    struct TreeNode* node5 = createNode(15);
    struct TreeNode* node6 = createNode(7);
    node0->left = node1; node0->right = node2;
    node2->left = node5; node2->right = node6;
    printf("%d", maxDepth(node0));
    


    freeTree(node0);
    return 0;
}
// Input: root = []
// Output: 3

// Input: root = [1,null,2]
// Output: 2