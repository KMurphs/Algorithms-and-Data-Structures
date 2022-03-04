class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        is_positive = x >= 0
        
        int_max = 2 ** 31 - 1 
        tenth_of_int_max = int_max // 10
        int_min = 2 ** 31 
        tenth_of_int_min = int_min // 10
        
        ceiling = int_max if is_positive else int_min
        tenth_of_ceiling = tenth_of_int_max if is_positive else tenth_of_int_min
        
        curr, y = 0, abs(x)
        while y > 0:
            if tenth_of_ceiling < curr: return 0
            curr = curr * 10 
            
            diff = y % 10
            if ceiling - curr < diff: return 0
            curr += diff 
            
            y //= 10
        
        return curr if is_positive else -1 * curr

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")