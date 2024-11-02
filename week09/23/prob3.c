#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
typedef struct Node {
    int val;
    struct Node** children;
    int numChildren;
} Node;

// Function to create a new node
Node* createNode(int val, int numChildren) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->numChildren = numChildren;
    node->children = (Node**)malloc(numChildren * sizeof(Node*));
    return node;
}

// Function to calculate the maximum depth of the tree
int maxDepth(Node* root) {
    if (!root) return 0;

    // Queue setup: each element is a pair (node, depth)
    struct QueueNode {
        Node* node;
        int depth;
    };

    // Simple array-based queue implementation
    struct QueueNode queue[1000];
    int front = 0, back = 0;

    // Initialize queue with root node
    queue[back++] = (struct QueueNode){root, 1};
    int maxDepth = 0;

    while (front < back) {
        struct QueueNode qnode = queue[front++];
        Node* node = qnode.node;
        int depth = qnode.depth;
        maxDepth = depth > maxDepth ? depth : maxDepth;

        // Enqueue children with increased depth
        for (int i = 0; i < node->numChildren; i++) {
            queue[back++] = (struct QueueNode){node->children[i], depth + 1};
        }
    }

    return maxDepth;
}

int main() {
    // Creating a sample tree:
    //        1
    //      / | \
    //     3  2  4
    //    / \
    //   5   6

    Node* node5 = createNode(5, 0);
    Node* node6 = createNode(6, 0);
    Node* node3 = createNode(3, 2);
    node3->children[0] = node5;
    node3->children[1] = node6;

    Node* node2 = createNode(2, 0);
    Node* node4 = createNode(4, 0);

    Node* root = createNode(1, 3);
    root->children[0] = node3;
    root->children[1] = node2;
    root->children[2] = node4;

    // Calculate max depth
    printf("Maximum depth of the tree: %d\n", maxDepth(root));

    // Free allocated memory
    free(node5->children);
    free(node6->children);
    free(node2->children);
    free(node4->children);
    free(node5);
    free(node6);
    free(node2);
    free(node4);
    free(node3->children);
    free(node3);
    free(root->children);
    free(root);

    return 0;
}
