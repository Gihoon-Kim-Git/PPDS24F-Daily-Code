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

    def deleteDuplicates(self):
        if (self.head is None):
            return

        temp = self.head.next
        prev = self.head
            
        while (temp is not None):
            if (temp.val == prev.val):
                prev.next = temp.next
            else:
                prev = temp
            temp = temp.next

if __name__ == "__main__":
    head = Solution()
    head.insert(3)
    head.insert(3)
    head.insert(2)
    head.insert(1)
    head.insert(1)
    head.print_list()  # 1 -> 1 -> 2 -> 3 -> 3 -> nullptr

    head.deleteDuplicates()
    head.print_list()  # 1 -> 2 -> 3 -> nullptr