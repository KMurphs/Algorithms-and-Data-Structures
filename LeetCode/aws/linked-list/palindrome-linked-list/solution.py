# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def traverse(self, root, current):
        if current == None: return True
        
        is_palyndrome_so_far = self.traverse(root, current.next)
        if not is_palyndrome_so_far: return False
        if root.next == None: return True
        
        is_palyndrome_so_far = (root.next.val == current.val)
        
        if root.next == current or (root.next != None and root.next.next == current):
            root.next = None
        else: 
            root.next = root.next.next
            
        return is_palyndrome_so_far
        
        
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fake_head = ListNode(0, head)
        return self.traverse(fake_head, head)

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")