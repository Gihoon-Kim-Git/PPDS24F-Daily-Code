struct ListNode* removeElements(struct ListNode* head, int val) {
    //(0) 예외 처리
    while (head != NULL && head->val == val) {
        head = head->next;
    }

    //(1) 나머지 리스트 처리
    struct ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }

    return head;
}
