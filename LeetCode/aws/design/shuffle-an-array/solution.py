import random

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
        self.permutations_count = 1 # Compute once for all how many permu
        for i in range(1, len(nums) + 1):
            self.permutations_count *= i
        
    def reset(self):
        """
        :rtype: List[int]
        """
        return [num for num in self.nums] # Avoid giving nums by ref to the client

    def shuffle(self):
        """
        :rtype: List[int]
        """
        # If we have fact(len(nums)) permutation, we can just choose a random number between 1 and that number
        # Build that permutation and return the array after this permutation
        # kth_permutation = int(1 + (random.random() * float(self.permutations_count - 1)))
        kth_permutation = random.randint(1, self.permutations_count)
        
        # We choose one permutation randomly. So all have equal chances. 
        # This (random) kth permutation must then just be built
        kth_permutation_elemts = find_kth_permutation(len(self.nums), kth_permutation)
        
        # Build the shuffled array
        return [self.nums[i - 1] for i in kth_permutation_elemts]

def find_kth_permutation(n, k):
    
    # To build some random permutation given its position
    # Notice that for position 3 for example, if n = 3, that element changes every 2 items
    # In general, at position pos, the element will change every fact(pos - 1)
    # where pos is counted from 1 (not 0)
    
    cycle_length = 1 # this is how long a value at position n will take before it changes: fact(n - 1)
    for i in range(1, n): cycle_length *= i
    
    # These represent the possible values at each position
    choices = [i for i in range(1, n + 1)] 
    
    solution = []
    for position in range(n, 1, -1):
        offset_idx = (k - 1) // cycle_length
        solution.append(choices.pop(offset_idx)) # Collect choices and remove it from possibilities of next iters
        
        # Update for next iter
        k %= cycle_length # prevent index calculation taht fall outside bounds of choice array
        cycle_length //= (position - 1) # Recompute fact(pos - 1) of next pos
    
    
    # There is still one element in choices
    return solution + choices


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")