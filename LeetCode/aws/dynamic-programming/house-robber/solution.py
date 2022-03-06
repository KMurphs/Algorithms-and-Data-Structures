class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        
        best_sum = max(nums[0], nums[1])
        if len(nums) == 2: return best_sum
        
        
        dp = [0 for i in range(len(nums) + 1)]
        dp[1] = nums[0]
        dp[2] = nums[1]
        

        for i in range(3, len(dp)):
            dp[i] = nums[i - 1] + max(dp[i - 2], dp[i - 3])
            best_sum = best_sum if best_sum > dp[i] else dp[i]
        
        return best_sum

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")