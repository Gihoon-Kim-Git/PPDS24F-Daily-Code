#include <stdio.h>
#include <stdlib.h>


//1. Remove Linked List Elements
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;

    if (curr == NULL) return NULL;

    while (curr != NULL) {
        if (curr->val == val) {
            if (curr == head) {
                curr = curr->next;
                head = curr;
            }
            else {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}


//2. Remove Duplicates from Sorted List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    if (head == NULL) return NULL;
    while (curr->next != NULL) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}


//3. Middle of the Linked List
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//4. merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
     // Base cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    // Recursive case
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);  // Move to the next node in list1
        return list1;  // Return the node that had the smaller value
    } else {
        list2->next = mergeTwoLists(list1, list2->next);  // Move to the next node in list2
        return list2;  // Return the node that had the smaller value
    }

}

//5. adding 1,2,3

int countWays(int n) {
    int dp[n+1];
    
    // 기저 상태
    dp[0] = 1;  // 아무것도 더하지 않는 방법 1가지
    dp[1] = 1;  // 1을 만드는 방법 1가지
    dp[2] = 2;  // 2를 만드는 방법 2가지
    dp[3] = 4;  // 3을 만드는 방법 4가지
    
    // dp 테이블 채우기
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[n];
}