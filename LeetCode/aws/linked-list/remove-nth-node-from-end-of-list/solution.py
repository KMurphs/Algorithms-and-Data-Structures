# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    
    def traverse(self, parent, current, n):
        if current == None: return 0
        counter = 1 + self.traverse(parent.next, current.next, n)
        if counter == n:
            parent.next = current.next
            current.next = None
        return counter
    
    
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fake_head = ListNode(0, head)
        
        self.traverse(fake_head, head, n)
        return fake_head.next

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")