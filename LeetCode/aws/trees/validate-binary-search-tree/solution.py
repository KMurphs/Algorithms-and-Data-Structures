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
    
    def in_order_traversal(self, root, prev_from_ancestors):
        prev_from_descendants = None
        
        
        if root.left:
            prev_from_descendants = self.in_order_traversal(root.left, prev_from_ancestors)
            if prev_from_descendants == None: return None
            if prev_from_descendants >= root.val: return None
        
        
        if prev_from_ancestors != None and prev_from_ancestors >= root.val: return None
        prev_from_descendants = root.val
        
        
        if root.right:
            prev_from_descendants = self.in_order_traversal(root.right, root.val)
            if prev_from_descendants == None: return None
            if prev_from_descendants <= root.val: return None
        
        
        return prev_from_descendants  
    
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None: return True
        largest = self.in_order_traversal(root, None)
        return largest != None
        
solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")