class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 1: return 1
        
        global_max = 0
        left, right = 0, 0
        window = set()
        
        for right in range(len(s)):
            
            while(s[right] in window):
                window.remove(s[left])
                left = left + 1
            
            window.add(s[right])
            right = right + 1
            global_max = global_max if global_max > len(window) else len(window)

                
            
            
        return global_max
            



solution = Solution()
assert solution.lengthOfLongestSubstring("abcabcbb") == 3, "Failed to find solution"
assert solution.lengthOfLongestSubstring("bbbbb") == 1, "Failed to find solution"
assert solution.lengthOfLongestSubstring("pwwkew") == 3, "Failed to find solution"

print("Passed All Test Examples")