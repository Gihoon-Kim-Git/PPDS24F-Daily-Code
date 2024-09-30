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

    def removeElements(self, val):
        while (self.head is not None and self.head.val == val):
            self.head = self.head.next

        temp = self.head
        prev = None
            
        while (temp is not None):
            if (temp.val == val):
                prev.next = temp.next
            else:
                prev = temp
            temp = temp.next

if __name__ == "__main__":
    head = Solution()
    head.insert(6)
    head.insert(3)
    head.insert(2)
    head.insert(6)
    head.insert(1)
    head.insert(6)
    head.insert(6)
    head.print_list()  # 6 -> 6 -> 1 -> 6 -> 2 -> 3 -> 6 -> nullptr

    head.removeElements(6)
    head.print_list()  # 1 -> 2 -> 3 -> nullptr