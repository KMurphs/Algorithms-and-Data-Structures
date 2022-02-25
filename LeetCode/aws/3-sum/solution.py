class Solution(object):

    def binary_search(self, nums, left, right, target):
        if left > right: return None

        middle = left + (right - left) // 2
        if nums[middle] == target: return middle
        elif nums[middle] > target: return self.binary_search(nums, left, middle - 1, target)
        elif nums[middle] < target: return self.binary_search(nums, middle + 1, right, target)

        return None

    def threeSum_v1(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 2: return []
        
        nums = sorted(nums)
        if nums[0] > 0: return []
        if nums[len(nums) - 1] < 0: return []
        
        sols = []  
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]: continue
            if nums[i] > 0: break
                
            for j in range(len(nums) - 1, i, -1):
                if j < len(nums) - 1 and nums[j] == nums[j + 1]: continue
                if nums[j] < 0: break

                target = 0 - nums[j] - nums[i]
                target_idx = self.binary_search(nums, i + 1, j - 1, target)
                if target_idx: sols.append([nums[i], nums[j], target])
    

        return sols
    
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 2: return []
        
        nums = sorted(nums)
        if nums[0] > 0: return []
        if nums[len(nums) - 1] < 0: return []
        
        sols = []  
        for lowest in range(len(nums)):
            if lowest > 0 and nums[lowest] == nums[lowest - 1]: continue
            if nums[lowest] > 0: break
                
            target = 0 - nums[lowest]
            
            left, right = lowest + 1, len(nums) - 1
            while left < right:
                
                if nums[left] + nums[right] > target: right = right - 1  
                elif nums[left] + nums[right] < target: left = left + 1
                else:
                    sols.append([nums[lowest], nums[left], nums[right]])
                    left = left + 1
                    while left < right and nums[left] == nums[left - 1]: left = left + 1

        return sols

solution = Solution()
print(solution.threeSum([-1,0,1,2,-1,-4]), [[-1,-1,2],[-1,0,1]])
print("Passed All Test Examples")