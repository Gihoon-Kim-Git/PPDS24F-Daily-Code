#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addElements(struct ListNode *head, int val) {
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *merge_node = NULL;
    if (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            merge_node = list1;
            merge_node->next = mergeTwoLists(list1->next, list2);
        } else {
            merge_node = list2;
            merge_node->next = mergeTwoLists(list1, list2->next);
        }
    }
    else if (list1 != NULL) merge_node = list1;
    else if (list2 != NULL) merge_node = list2;
    else merge_node = NULL;
    return merge_node;
}

void printList(struct ListNode *head) {
    struct ListNode *current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->val);
        current_node = current_node->next;
    }
    printf("nullptr\n");
}

int main() {
    struct ListNode *list1 = NULL;
    list1 = addElements(list1, 4);
    list1 = addElements(list1, 2);
    list1 = addElements(list1, 1);
    printList(list1);  // 1 -> 2 -> 4 -> nullptr

    struct ListNode *list2 = NULL;
    list2 = addElements(list2, 4);
    list2 = addElements(list2, 3);
    list2 = addElements(list2, 1);
    printList(list2);  // 1 -> 3 -> 4 -> nullptr

    struct ListNode *merge = NULL;
    merge = mergeTwoLists(list1, list2);
    printList(merge);  // 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr
    
    return 0;
}