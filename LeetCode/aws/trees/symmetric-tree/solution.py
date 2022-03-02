# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def co_traversal(self, root1, root2):
        if root1 == None and root2 == None: return True
        if root1 == None and root2 != None: return False
        if root1 != None and root2 == None: return False
        
        if root1.val != root2.val: return False
        
        return self.co_traversal(root1.left, root2.right) and self.co_traversal(root1.right, root2.left)
    
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        
        if root == None: return True
        return self.co_traversal(root.left, root.right)
        
        
solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")