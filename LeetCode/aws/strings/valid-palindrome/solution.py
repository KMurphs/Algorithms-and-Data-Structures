class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left, right = 0, len(s) - 1
        s = s.lower()
        valid_chars = set([i + ord('a') for i in range(26)] + [i + ord('0') for i in range(10)])
        while left < right:
            # print(left, right, s[left], s[right])
            if ord(s[left]) not in valid_chars: 
                left += 1
                continue
            if ord(s[right]) not in valid_chars: 
                right -= 1
                continue
            if s[left] != s[right]: 
                return False
            
            left += 1
            right -= 1
            
        return True

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")