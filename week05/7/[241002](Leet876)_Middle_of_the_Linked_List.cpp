/*문제
SLL의 head가 주어졌을 때, SLL의 middle node를 return
middle node가 두 개 있을 때는, second middle node를 return
*/

/*문제풀이
    1. slow, fast : slow는 한칸씩, fast는 두칸씩,
    2. while문 종료조건 : fast == NULL 또는 fast.next == NULL일 때
*/

//Definition for SLL
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};