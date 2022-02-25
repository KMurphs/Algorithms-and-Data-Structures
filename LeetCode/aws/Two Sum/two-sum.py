class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        memory = dict()
        
        for i, num in enumerate(nums):
            if target - num not in memory.keys(): memory[num] = i
            else: return (memory[target - num], i)


solution = Solution()
assert sorted(solution.twoSum([2,7,11,15], 9)) == [0,1], "Failed to find solution"
assert sorted(solution.twoSum([3,2,4], 6)) == [1,2], "Failed to find solution"
assert sorted(solution.twoSum([3,3], 6)) == [0,1], "Failed to find solution"
print("Passed All Test Examples")