# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        
        current1 = list1
        current2 = list2
        fake_head = ListNode(0, None)
        merged = fake_head
        
        while(current1 != None and current2 != None):
            if current1.val < current2.val:
                merged.next = current1
                current1 = current1.next
                merged  = merged.next
            else:
                merged.next = current2
                current2 = current2.next
                merged  = merged.next    
                
                
        while(current1 != None):
            merged.next = current1
            current1 = current1.next
            merged  = merged.next    
            
            
        while(current2 != None):
            merged.next = current2
            current2 = current2.next
            merged  = merged.next         
            
        return fake_head.next

solution = Solution()
# print("Solution", solution.removeNthFromEnd([1,2,3,4,5], 2)) 
print("Expected", [1,2,3,5])
# print("Passed All Test Examples")