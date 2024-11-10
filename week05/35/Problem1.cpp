struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // Create a dummy node that points to the head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Use two pointers: prev (initially pointing to dummy) and curr (initially pointing to head)
        ListNode *prev = dummy;
        ListNode *curr = head;

        // Traverse the list
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                // If the current node needs to be removed, skip it
                prev->next = curr->next;
            }
            else
            {
                // Otherwise, move prev to the current node
                prev = curr;
            }
            // Move to the next node
            curr = curr->next;
        }

        // Return the new head, which is dummy->next
        ListNode *newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};
