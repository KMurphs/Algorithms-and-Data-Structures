class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        
        char_freqs = dict()
        
        for c in s:
            if c not in char_freqs: char_freqs[c] = 0
            char_freqs[c] += 1
            
        for c in t:
            if c not in char_freqs: return False
            if char_freqs[c] == 0: return False
            char_freqs[c] -= 1
        
        for c in char_freqs:
            if char_freqs[c] != 0: return False
            
        return True

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")