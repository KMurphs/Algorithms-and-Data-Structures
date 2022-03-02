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
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None: return 0
        
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")