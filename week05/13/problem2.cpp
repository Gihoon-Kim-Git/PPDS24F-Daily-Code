#include <iostream>
#include <set>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* cur=head;
        std::set<int> check; //별도로 선언 안해줘도 빈 셋

        //prev -> cur 2개의 포인터만 사용해서 구현할 수 있다!

        if (head==nullptr)
        {
            return head;
        }

        while(cur!=nullptr)
        {
            if(check.find(cur->val)!=check.end()) //이전에 있었다면
            {
                prev->next=cur->next;
            }
            else
            {
                check.insert(cur->val);
                prev=cur;
            }
            cur=cur->next;
        }

        return head;
    }
};

//set 선언하는 법
//std::set<int> [name];

//set의 경우
// .find() 함수는 찾는 값이 있으면 그 위치의 이터레이터를 반환하고, 
// 없으면 .end() 이터레이터를 반환함 --> set.find(value)!=set.end() 있다면 이라는 뜻

//set의 경우 push_back이 아니라 insert를 사용함