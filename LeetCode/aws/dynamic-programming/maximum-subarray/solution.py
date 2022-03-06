class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        
        left, right = 0, 0
        running_sum, best_sum = 0, nums[0]
        
        for right in range(len(nums)):
            
            while left < right and running_sum <= 0:
                running_sum = running_sum - nums[left]
                left = left + 1
                
            running_sum = running_sum + nums[right]
            if best_sum < running_sum: best_sum = running_sum
                
        return best_sum  

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")