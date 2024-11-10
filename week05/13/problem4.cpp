
//Definition for singly-linked list.
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
        //더미를 사용해서 초기화하는 방법
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;

        //예외사항 처리인데 필요없는 코드
        // if (list1==nullptr && list2==nullptr)
        // {
        //     return nullptr;
        // }
        if (list1==nullptr)
        {
            return list2;
        }
        if (list2==nullptr)
        {
            return list1;
        }
        
        while(list1!=nullptr && list2!=nullptr)
        {
            if (list1->val<=list2->val)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }

        //하고 나서 남은거 덧붙이기
        if(list1!=nullptr){
            cur->next=list1;
        }
        else{
            cur->next=list2;
        }

        //dummy->next가 시작이니까 이걸 return
        return dummy->next;
    }
};