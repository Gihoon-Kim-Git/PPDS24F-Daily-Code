


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // head1, head2 받아서, 크기 비교하면서 큰 애를 next로 넘겨주기 
        // 둘 중에 하나가 nullptr -> 둘 중에 나머지 하나 pointer로 잇고 끝냄

        ListNode* head = new ListNode();
        ListNode* curr = head;

        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else{
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }

        if (list1 == nullptr){
            curr->next = list2;
        } else{
            curr->next = list1;
        }

        return head->next;
    }
};