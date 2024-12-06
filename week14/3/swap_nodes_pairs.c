#include <stdio.h>
#include <stdlib.h>

// 단일 연결 리스트 노드 정의
struct ListNode {
    int val;
    struct ListNode* next;
};

// 연결 리스트에서 인접한 노드 두 개를 교환하는 함수
struct ListNode* swapPairs(struct ListNode* head) {
    // 베이스 케이스: 리스트가 비어 있거나 노드가 하나만 있는 경우 그대로 반환
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 두 개의 노드를 교환
    // 1. 첫 번째 노드와 두 번째 노드를 가리키는 포인터 설정
    struct ListNode* first = head;        // 첫 번째 노드
    struct ListNode* second = head->next; // 두 번째 노드

    // 2. 현재 노드(first)의 다음 노드를 재귀적으로 처리하여 연결
    first->next = swapPairs(second->next);

    // 3. 두 번째 노드(second)가 첫 번째 노드(first)를 가리키도록 설정
    second->next = first;

    // 4. 두 번째 노드를 새로운 head로 반환
    return second;
}

// 연결 리스트에 노드를 추가하는 유틸리티 함수
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 연결 리스트 출력 함수
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// 테스트용 메인 함수
int main() {
    // 테스트 케이스 1: [1, 2, 3, 4]
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);

    printf("Before swapping: ");
    printList(head1);

    head1 = swapPairs(head1);

    printf("After swapping: ");
    printList(head1);

    // 테스트 케이스 2: 빈 리스트 []
    struct ListNode* head2 = NULL;

    printf("Before swapping: ");
    printList(head2);

    head2 = swapPairs(head2);

    printf("After swapping: ");
    printList(head2);

    // 테스트 케이스 3: [1]
    struct ListNode* head3 = createNode(1);

    printf("Before swapping: ");
    printList(head3);

    head3 = swapPairs(head3);

    printf("After swapping: ");
    printList(head3);

    return 0;
}
