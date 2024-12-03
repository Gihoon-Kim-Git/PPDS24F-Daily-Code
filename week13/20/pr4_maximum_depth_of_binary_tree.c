#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 3;
    int *ptr = &a;

    printf("%d\n",a);
    printf("%d\n",&a);
    printf("%d\n",ptr);
    printf("%d\n",*ptr);

    *ptr = 999;
    printf("%d\n",a);
    printf("%d\n",&a);
    printf("%d\n",ptr);
    printf("%d\n",*ptr);
    a = 777;
    printf("%d\n",a);
    printf("%d\n",&a);
    printf("%d\n",ptr);
    printf("%d\n",*ptr);
}


//  * Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}Tree;
 
int max(int a, int b){
    return a > b ? a : b;
}

int maxDepth(Tree* root) {
    if(!root) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left,right);

}

