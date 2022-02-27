# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None: return False
        if head.next == None: return False
        
        fake_head = ListNode(0, head)
        slow, fast = fake_head, fake_head.next.next
        # counter = 0
        while fast and fast.next and fast.next.next and id(fast) != id(slow):
            slow = slow.next
            fast = fast.next.next
            # counter = counter + 1
        
        # print(id(fast), id(slow), fast.val, slow.val, counter)
        
        if fast == None or fast.next == None or fast.next.next == None: return False
        
        return id(fast) == id(slow)

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")