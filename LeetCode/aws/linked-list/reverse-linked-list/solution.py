# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    
    def traverse(self, curr, handle):
        if curr == None:
            return handle # Return new tmp head
        
        prev = self.traverse(curr.next, handle)
        prev.next = curr
        curr.next = None
        return curr
    
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fake_head = ListNode()
        self.traverse(head, fake_head)
        return fake_head.next

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")