# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def traverse(self, current, child):
        current.val = child.val
        if child.next == None:
            current.next = None
            return
        
        return self.traverse(child, child.next)

    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        
        self.traverse(node, node.next)
        

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")