struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        struct ListNode* t;
        if(l1->val<l2->val){
            t=l1;
            l1=l1->next;
        }else{
            t=l2;
            l2=l2->next;
        }
        struct ListNode* head=t;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                t->next=l1;
                l1=l1->next;
            }else{
                t->next=l2;
                l2=l2->next;
            }
            t=t->next;
        }
        if(l1==NULL)
            t->next=l2;
        else
            t->next=l1;
        return head;
    
}