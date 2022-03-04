class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0: return ""
        if len(strs) == 1: return strs[0]
        if len(strs[0]) == 0: return ""
        
        position = 0
        while True:
            for i in range(1, len(strs)):
                if position >= len(strs[i]): return strs[i]
                if position >= len(strs[0]): return strs[0]
                if strs[i][position] != strs[0][position]: return strs[0][0:position]
            position += 1
            

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")