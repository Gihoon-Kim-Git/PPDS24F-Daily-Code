class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def print_list(node):
    curr = node
    while (curr is not None):
        print(curr.val, end=" -> ")
        curr = curr.next
    print("nullptr")

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        if (list1 is None):
            return list2
        elif (list2 is None):
            return list1
        elif (list1.val < list2.val):
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2

if __name__ == "__main__":
    list1 = ListNode(1, ListNode(2, ListNode(4, None)))
    print_list(list1)  # 1 -> 2 -> 4 -> nullptr

    list2 = ListNode(1, ListNode(3, ListNode(4, None)))
    print_list(list2)  # 1 -> 3 -> 4 -> nullptr

    merge = Solution()
    head = merge.mergeTwoLists(list1, list2)
    print_list(head)  # 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr