/*문제
SLL의 head가 주어졌을 때, SLL의 middle node를 return
middle node가 두 개 있을 때는, second middle node를 return
*/

/*문제풀이 : 다른 사람들도 다 fast, slow로 푸는 듯.
    1. slow(한칸씩 이동), fast(두 칸씩 이동)를 움직이면서 fast가 끝부분에 도달하는 순간의 slow를 출력하면 됨.
        fast의 끝이란: fast.next == NULL (Node개수 홀수), fast == NULL (Node개수 짝수)
    >> 이를 위해서는 slow, fast를 head에서 출발해서 한칸씩 동시에 움직이면 됨.
    2. SLL이 empty한 경우는 없으므로 따로 edge case 처리 불필요.
*/

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
