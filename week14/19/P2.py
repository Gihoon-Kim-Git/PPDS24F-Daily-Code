class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def print_list(head):
    curr = head
    while curr is not None:
        print(curr.val, end=" -> ")
        curr = curr.next
    print("nullptr")

class Solution(object):
    def swapPairs(self, head):
        if head is None or head.next is None:
            return head
        curr = head
        next = curr.next
        odd = 0
        while (next is not None):
            if (odd%2 == 0):
                next.val, curr.val = curr.val, next.val
            odd += 1
            curr = curr.next
            next = next.next
        return head

if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    print_list(head)
    result = Solution()
    new_head = result.swapPairs(head)
    print_list(new_head)