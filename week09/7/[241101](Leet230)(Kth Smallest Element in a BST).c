/*문제
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.*/

/*Constraints:
    The number of nodes in the tree is n.
    1 <= k <= n <= 104
    0 <= Node.val <= 104
*/

// 방법 1 : values list 활용

/* 방법 2 : dfs동안 k값을 줄이면서 k==0 시점의 node.val 반환
    - 유의점! : 자기자신을 방문하면 curCount--.  그리고 난 후! curCount ==0 인지 확인.
*/


// 방법 1 ---------------------------------------
#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void sizeUp(int** values, int* sizeValues, int* valuesCapacity) {  //포인터인 values(int*형)의 자체의 값을 변경해야 함. 그러려면 int* values의 주소에 접근해야 하므로..  int**로 받아와야 함에 주의. 
    if (*valuesCapacity == *sizeValues) {
        *valuesCapacity *= 2;
        int* temp = realloc(*values, sizeof(int) * (*valuesCapacity));
        if (temp == NULL) {
            // 메모리 할당 실패 처리
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        *values = temp;  // 주소를 업데이트
    } else {
        return;
    }
}
void dfs(struct TreeNode* curNode, int** values, int* sizeValues, int* valuesCapacity, int k){
    if (curNode == NULL) return;
    // if (*sizeValues > k) return;

    if (curNode->left) dfs(curNode->left, values, sizeValues, valuesCapacity,k);
    sizeUp(values, sizeValues, valuesCapacity); // dfs에서 int* values로 argument 주고, 여기서 &values라고 전달한다면, realloc이 제대로 되지 않음. 왜냐면 함수 호출할 때 포인터의 복사본이 만들어지기 때문에 그 주솟값이 다름.
    (*sizeValues)++;
    (*values)[(*sizeValues)-1] = curNode->val;
    if (curNode->right) dfs(curNode->right, values, sizeValues,valuesCapacity, k); 
}


int kthSmallest(struct TreeNode* root, int k){
    int valuesCapacity = k; // 초기에 그냥 적당한 크기로 줌.
    int* values = (int*)malloc(sizeof(int) * (valuesCapacity));
    int sizeValues = 0;

    dfs(root, &values, &sizeValues, &valuesCapacity, k);

    int answer = values[k-1];

    free(values);
    return answer;
}



//방법2 : 통과 ----------------------------
#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* curNode, int* curCount, int* answer){
    if (curNode == NULL) return;

    if (curNode->left) dfs(curNode->left, curCount, answer);
    (*curCount)--;   #빼는 게 먼저 선행되어야 한다. *curCount ==0 여부를 확인하기 전에.
    if ((*curCount) == 0){
        *answer = curNode->val;
        return;
    }
    if (curNode->right) dfs(curNode->right, curCount, answer);

}

int kthSmallest(struct TreeNode* root, int k){
    int curCount = k;
    int answer = 0;

    dfs(root, &curCount, &answer);

    return answer;
}
