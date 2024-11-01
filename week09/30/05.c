#include <stdlib.h>
#include <stdio.h>
#define MAX 10000

// 전략
// 1. Node를 다 뽑아서 array로 만들고
// 2. sort를 해서
// 3. k번째로 작은거 뽑쟝

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void print_arr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* Node_to_Arr(struct TreeNode* root, int* numN) {
//1. node 개수를 파악하자.

    struct TreeNode* queue[MAX];
    int i1 = 0; int i2 = 0;
    queue[i2++] = root;
    while (i1 < i2) {
        struct TreeNode* curNode = queue[i1++];
        //방문
        (*numN)++;
        //자식들 처리
        if (curNode->left) {
            queue[i2++] = curNode->left;
        }
        if (curNode->right) {
            queue[i2++] = curNode->right;
        }
    }

//2. array에 node value를 추가하자.
    int* valArr = (int*)malloc((*numN) * sizeof(int));
    int valIdx = 0;

    struct TreeNode* Queue[MAX];
    int I1 = 0; int I2 = 0;
    Queue[I2++] = root;
    while (I1 < I2) {
        struct TreeNode* CurNode = Queue[I1++];
        //방문
        valArr[valIdx++] = CurNode->val;
        //자식들 처리
        if (CurNode->left) {
            Queue[I2++] = CurNode->left;
        }
        if (CurNode->right) {
            Queue[I2++] = CurNode->right;
        }
    }

    return valArr;
}

void Sort_Arr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize-1; i++) {
        // 최소값을 찾기 위한 인덱스 초기화
        int min_idx = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // 찾은 최소값을 현재 위치로 스왑
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

}

int kthSmallest(struct TreeNode* root, int k) {
    int numN = 0;
    int* treeNodes = Node_to_Arr(root, &numN);
    // printf("ele count %d\n",numN);

    // print_arr(treeNodes, numN);

    Sort_Arr(treeNodes, numN );
    // print_arr(treeNodes, numN);

    return treeNodes[k-1];
}


//_________SUPPORT 함수_____________//
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* createTreeExample1() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->left->right = createNode(2);
    return root;
}
struct TreeNode* createTreeExample2() {
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->left->left->left = createNode(1);
    return root;
}
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* tree1 = createTreeExample1();
    struct TreeNode* tree2 = createTreeExample2();
    printf("Ex1: %d\n", kthSmallest(tree1, 1));
    printf("Ex2: %d", kthSmallest(tree2, 3));

    // 메모리 해제
    freeTree(tree1);
    freeTree(tree2);

    return 0;
}

