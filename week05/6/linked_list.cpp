#include <limits>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* RemoveElements(ListNode* head, int val) {
  auto prev = new ListNode();  // Sentinel
  prev->next = head;
  auto cur = head;
  head = prev;  // Refer to later

  while (cur) {
    if (cur->val == val) {
      // prev doesn't change
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
    } else {
      // Advance
      prev = cur;
      cur = cur->next;
    }
  }

  prev = head;
  head = head->next;
  delete prev;
  return head;
}

ListNode* DeleteDuplicates(ListNode* head) {
  int NEG_INF = numeric_limits<int>::min();
  auto prev = new ListNode(NEG_INF, head);
  auto cur = head;
  head = prev;

  while (cur) {
    if (prev->val == cur->val) {
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }

  prev = head;
  head = head->next;
  delete prev;
  return head;
}

ListNode* MiddleNode(ListNode* head) {
  auto a = head, b = head;
  while (b && b->next) {
    b = b->next;
    a = a->next;
    if (b->next) {
      b = b->next;
      continue;
    }
    break;
  }
  return a;
}

ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {
  if (!list1) return list2;
  if (!list2) return list1;

  if (list1->val < list2->val) {
    list1->next = MergeTwoLists(list1->next, list2);
    return list1;
  } else {
    list2->next = MergeTwoLists(list1, list2->next);
    return list2;
  }
}
