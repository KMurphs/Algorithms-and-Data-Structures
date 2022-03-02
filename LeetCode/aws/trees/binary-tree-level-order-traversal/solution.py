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
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None: return []
        
        q1 = list([root])
        q2 = list()
        q_curr = q1
        q_next = q2
        sols = list([[root.val]])
        
        while(len(q_curr) != 0):
            curr = q_curr.pop(0)
            if curr.left: q_next.append(curr.left)
            if curr.right: q_next.append(curr.right)
                
            if len(q_curr) == 0:
                if len(q_next) != 0: sols.append([node.val for node in q_next])
                q_curr, q_next = q_next, q_curr
        
        return sols
solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")