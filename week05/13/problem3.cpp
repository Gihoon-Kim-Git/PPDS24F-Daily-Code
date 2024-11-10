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
    ListNode* middleNode(ListNode* head) {
        
        if(head==nullptr){
            return head;
        }

        ListNode* cur=head;
        int length=0;

        while(cur!=nullptr){
            length+=1;
            cur=cur->next;
        }
        std::cout<<length<<endl;
        length=length/2+1;

        ListNode* cur2=head;
        int num=0;

        while(cur2!=nullptr){
            num++;
            if(num==length){
                break;
            }
            cur2=cur2->next;
        }
        return cur2;
    }
};