#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

struct Node* addNodes(int val, int numChildren, struct Node** children) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->numChildren = numChildren;
    new_node->children = children;
    return new_node;
}

int maxDepthHelp(struct Node* root, int depth) {
    if (root == NULL) return 0;
    int maxD = depth;
    if (root->children != NULL) {
        for (int i=0; i<root->numChildren; i++) {
            int childD = maxDepthHelp(root->children[i], depth+1);
            maxD = (childD > maxD ? childD : maxD);
        }
    }
    return maxD;
}

int maxDepth(struct Node* root) {
    return maxDepthHelp(root, 1);
}

int main() {
    struct Node *tree5 = addNodes(6, 0, NULL);
    struct Node *tree4 = addNodes(5, 0, NULL);
    struct Node *tree3 = addNodes(4, 0, NULL);
    struct Node *tree2 = addNodes(2, 0, NULL);
    struct Node *child2[] = {tree4, tree5};
    struct Node *tree1 = addNodes(3, 2, child2);
    struct Node *child1[] = {tree1, tree2, tree3};
    struct Node *root = addNodes(1, 3, child1);
    printf("%d\n", maxDepth(root));

    return 0;
}