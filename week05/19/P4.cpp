#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insert_head(ListNode *head, int val) {
    ListNode *new_node = new ListNode(val, head);
    return new_node;
};

void printList(ListNode* head) {
    ListNode* current_node = head;
    while (current_node != nullptr) {
        cout << current_node->val << " -> ";
        current_node = current_node->next;
    }
    cout << "nullptr" << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merge_node = nullptr;
        if (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                merge_node = list1;
                merge_node->next = mergeTwoLists(list1->next, list2);
            } else {
                merge_node = list2;
                merge_node->next = mergeTwoLists(list1, list2->next);
            }
        }
        else if (list1 != nullptr) merge_node = list1;
        else if (list2 != nullptr) merge_node = list2;
        else merge_node = nullptr;
        return merge_node;
    }
};

int main() {
    ListNode *list1 = nullptr;
    list1 = insert_head(list1, 4);
    list1 = insert_head(list1, 2);
    list1 = insert_head(list1, 1);
    printList(list1);  // 1 -> 2 -> 4 -> nullptr

    ListNode *list2 = nullptr;
    list2 = insert_head(list2, 4);
    list2 = insert_head(list2, 3);
    list2 = insert_head(list2, 1);
    printList(list2);  // 1 -> 3 -> 4 -> nullptr
    
    Solution result;
    ListNode *merge = nullptr;
    merge = result.mergeTwoLists(list1, list2);
    printList(merge);  // 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr

    return 0;
}