struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr; // 리스트가 비어있는 경우 처리
        
        ListNode *prev = head;
        ListNode *curr = head->next;

        while(curr)
        {
            if(prev->val == curr->val)
            {
                curr = curr->next;
                prev->next = curr;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return head; // 첫 번째 노드를 반환
    }
};