class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        freq_counter = dict()
        
        # Collect all freqs
        for c in s:
            if c not in freq_counter: freq_counter[c] = 0
            freq_counter[c] += 1
            
        # Find the first char with freq == 1
        for i in range(len(s)):
            if freq_counter[s[i]] == 1: return i
        
        return -1

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")