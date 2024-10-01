/*문제 : sorted_SLL의 head가 주어졌을 때, 같은 값을 가지는 노드들이 여러 개 있으면 하나만 남기고 나머지는 삭제. return은 정리된 sorted_SLL의 head.
*/
/*constraint :
노드 개수는 0~300
-100 <= Node.val <= 100
SLL은 ascending order로 sort되어있어야 함.
*/

/*문제 풀이 : AyushBansalCodes Solution 참고
    1. Handling the Empty list.
        : if head is NULL -> return head 바로.
    2. Initialization .
        : pointer curr이 head 가리키도록.
    3. Traversing the List.
        : while (cur, cur.next 모두 NULL이 아닌동안 반복)
    4. Checking the Duplicates
        : loop 안에서 duplicate 여부 체크 (cur->val == cur.next.val)
    5. Remove the Duplicate  (4 조건 true)
        : cur->next가 duplicate node를 skip
        : duplicate node는 delete
        : curp->next는 cur->next->next로 update.
    6. Move to the next Node.(4 조건 false)
        :cur을 다음 노드로 이동.
    7. Retrun the modified list.
        : return head
 */

#include <iostream>
using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //1.
        if (head == nullptr) return head;

        //2. 
        ListNode* cur = head;

        //3.
        while (cur != nullptr && cur->next != nullptr){
            //4.
            if (cur->val == cur->next->val){ //5.
                ListNode* Node_to_del = cur->next;
                cur->next = cur->next->next;
                delete(Node_to_del);
            }
            else { // 6.
                cur = cur->next;
            }
        }
        //7.
        return head;
    }
};