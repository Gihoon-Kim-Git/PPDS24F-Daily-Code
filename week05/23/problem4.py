class Solution(object):
    def mergeTwoLists(self, l1, l2):
        if(l1==None):
            return l2
        if(l2==None):
            return l1
        t=l1
        if(l1.val<l2.val):
            t=l1
            l1=l1.next
        else:
            t=l2
            l2=l2.next
        head=t
        while(l1!=None and l2!=None):
            if(l1.val <= l2.val):
                t.next=l1
                l1=l1.next
            else:
                t.next=l2
                l2=l2.next
            t=t.next
        if(l1==None):
            t.next=l2
        else:
            t.next=l1
        return head