#include <iostream>
using namespace std;
 
 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur=head;

        //prev가 nullptr이면 에러가 생기기 때문에 dummy로 처리해주기
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;

        if (head==nullptr)
        {
            return head;
        }

        if (head->val==val){
            head=head->next;
        }

        while(cur!=nullptr)
        {
            if(cur->val==val)
            {
                prev->next=cur->next;
            }
            else{
                prev=cur;
            }
            cur=cur->next;
        }

        //더미를 사용했을 때 헤드를 새롭게 변경해주자!
        ListNode* newHead=dummy->next;
        return newHead;
    }
};

//스킵하는 방법
//복사본을 만들어서 걔로 순회하고 head를 반환하면 됨
//cur=head;
//cur->next=next->next;
//cur=cur->next;