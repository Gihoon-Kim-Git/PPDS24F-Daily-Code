/*문제 : sorted_SLL의 head가 주어졌을 때, 같은 값을 가지는 노드들이 여러 개 있으면 하나만 남기고 나머지는 삭제. return은 정리된 sorted_SLL의 head.
*/
/*constraint :
노드 개수는 0~300
-100 <= Node.val <= 100
SLL은 ascending order로 sort되어있어야 함.
*/

/*문제풀이
    1. prev와 cur을 two pointer처럼 활용.
    2. prev는 첫번째 unique 값에 고정용, cur은 모든 노드 순회용.
        prev.val == cur.val인 동안은 cur을 계속 이동.
        prev.val != cur.val이면 prev.next를 cur로 연결->prev, cur을 모두 update
    3. 2만 했을 때는 마지막 쪽에 연속된 중복값을 처리못하므로, 마지막으로 update되었던 prev.next = None 조치.
    4. return head
    5. edge case인 빈 SLL일 경우에는 head 그대로 반환.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    struct ListNode* prev = head;
    struct ListNode* cur = head->next;

    while (cur != NULL){
        if (prev->val == cur->val){
            cur = cur->next;
        }
        else{
            prev->next = cur;
            prev = cur;
            cur = cur->next;
        }
    }

    prev->next = NULL;

    return head;
}