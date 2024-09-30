class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = ListNode(data)
        new_node.next = self.head
        self.head = new_node

    def print_list(self):
        curr = self.head
        while (curr is not None):
            print(curr.val, end=" -> ")
            curr = curr.next
        print("nullptr")

    def middleNode(self):
        fast = self.head
            
        while (fast is not None and fast.next is not None):
            fast = fast.next.next
            self.head = self.head.next

if __name__ == "__main__":
    head = Solution()
    head.insert(6)
    head.insert(5)
    head.insert(4)
    head.insert(3)
    head.insert(2)
    head.insert(1)
    head.print_list()  # 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr

    head.middleNode()
    head.print_list()  # 4 -> 5 -> 6 -> nullptr