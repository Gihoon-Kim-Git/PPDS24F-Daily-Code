#include <stdlib.h>
#include <stdio.h>
#define MAX 10000

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void dfs(struct Node* node, int* visited, int* depth, int parDepth) {
    if ( (node == NULL) || (visited[node->val] == 1)) {
        return;
    }
    visited[node->val] = 1;
    depth[node->val] = parDepth + 1;
    // printf("%d", depth[node->val]);

    for (int i = 0; i < node->numChildren; i++) {
        struct Node* nei = node->children[i];
        if ((nei != NULL) && (visited[nei->val] == 0)) {
            dfs(nei, visited, depth, depth[node->val]);
        }
    }
}

void print_arr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maxDepth(struct Node* root) {
    //dfs를 돌면서 node별 depth기록하기. 
    //(1). visited랑 depth만들깅! 노드 개수를 모르는디...푸 ㅎㅎㅎㅎㅎ 
    int* visited = (int*)malloc(MAX * sizeof(int));
    int* depth = (int*)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i ++) {
        visited[i] = 0;
        depth[i] = 0;
    }
    // print_arr(visited, MAX);
    // print_arr(depth, MAX);

    //(2). dfs 돌면서 기록하기
    dfs(root, visited, depth, 0);
    // print_arr(visited, MAX);
    // print_arr(depth, MAX);

    //(3). max값 찾기
    int max_depth = 0;
    for (int i = 0; i < MAX; i ++) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
        }
    } 

    free(visited);
    free(depth);
    // printf("MAX DEPTH = %d", max_depth);
    return max_depth;
}

int main() {
    // 노드 생성
    struct Node* nodes[MAX];
    for (int i = 1; i < MAX; i++) {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        nodes[i]->val = i;
        nodes[i]->numChildren = 0;
        nodes[i]->children = NULL;
    }

    // 루트 노드 1의 자식 (2, 3, 4, 5)
    nodes[1]->numChildren = 4;
    nodes[1]->children = (struct Node**)malloc(4 * sizeof(struct Node*));
    nodes[1]->children[0] = nodes[2];
    nodes[1]->children[1] = nodes[3];
    nodes[1]->children[2] = nodes[4];
    nodes[1]->children[3] = nodes[5];

    // 노드 3의 자식 (6, 7)
    nodes[3]->numChildren = 2;
    nodes[3]->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    nodes[3]->children[0] = nodes[6];
    nodes[3]->children[1] = nodes[7];

    // 노드 5의 자식 (9, 10)
    nodes[5]->numChildren = 2;
    nodes[5]->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    nodes[5]->children[0] = nodes[9];
    nodes[5]->children[1] = nodes[10];

    // 노드 7의 자식 (11)
    nodes[7]->numChildren = 1;
    nodes[7]->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    nodes[7]->children[0] = nodes[11];

    // 노드 11의 자식 (14)
    nodes[11]->numChildren = 1;
    nodes[11]->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    nodes[11]->children[0] = nodes[14];

    // 노드 4의 자식 (8)
    nodes[4]->numChildren = 1;
    nodes[4]->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    nodes[4]->children[0] = nodes[8];

    // 노드 8의 자식 (12)
    nodes[8]->numChildren = 1;
    nodes[8]->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    nodes[8]->children[0] = nodes[12];

    // 노드 9의 자식 (13)
    nodes[9]->numChildren = 1;
    nodes[9]->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    nodes[9]->children[0] = nodes[13];

    // 최댓값 깊이 계산
    maxDepth(nodes[1]);

    // 메모리 해제
    for (int i = 1; i < MAX; i++) {
        if (nodes[i]->children != NULL) {
            free(nodes[i]->children);
        }
        free(nodes[i]);
    }

    return 0;
}

// int main() {


// //예시 TREE를 만들쟈 후후후후후 넘 오래걸려;;; 🌳🌳
//     struct Node* myRoot = (struct Node*)malloc(sizeof(struct Node)); 
//     myRoot->val = 1; myRoot->numChildren = 3;

//     struct Node* N1_1 = (struct Node*)malloc(sizeof(struct Node)); 
//     N1_1 -> val = 3; N1_1->numChildren = 2; 
//     struct Node* N1_2 = (struct Node*)malloc(sizeof(struct Node)); 
//     N1_2 -> val = 2; N1_2->numChildren = 0;
//     struct Node* N1_3 = (struct Node*)malloc(sizeof(struct Node)); 
//     N1_3 -> val = 4; N1_3->numChildren = 0;

//     struct Node* N2_1 = (struct Node*)malloc(sizeof(struct Node)); 
//     N2_1 -> val = 5; N2_1->numChildren = 0;
//     struct Node* N2_2 = (struct Node*)malloc(sizeof(struct Node)); 
//     N2_2 -> val = 6; N2_2->numChildren = 0;

//     struct Node** myRootChildren = (struct Node**)malloc(myRoot->numChildren *sizeof(struct Node*));
//     myRootChildren[0] = N1_1;
//     myRootChildren[1] = N1_2;
//     myRootChildren[2] = N1_3;
//     myRoot-> children = myRootChildren;

//     struct Node** N1_1Children = (struct Node**)malloc(N1_1->numChildren *sizeof(struct Node*));
//     N1_1Children[0] = N2_1;
//     N1_1Children[1] = N2_2;
//     N1_1-> children = N1_1Children;

// // 돌려돌려~~
//     printf("%d", maxDepth(myRoot));

// // 뒷처리
//     free(N2_1);free(N2_2); 
//     free(N1_1Children);
//     free(N1_1); free(N1_2); free(N1_3); 
//     free(myRootChildren);
//     free(myRoot); 
//     return 0;
// }