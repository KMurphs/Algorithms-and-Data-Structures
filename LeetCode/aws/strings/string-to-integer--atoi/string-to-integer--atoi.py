class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        pos = 0
        
        # Ignore white spaces
        while pos < len(s) and s[pos] == " ": pos = pos + 1
        if pos >= len(s): return 0
        
        # Read in + and -
        is_positive = not (s[pos] == "-")
        if s[pos] == "+": pos = pos + 1
        elif s[pos] == "-": pos = pos + 1
        

        max_positive = 2 ** 31 - 1 
        tenth_of_max_positive = max_positive / 10
        max_negative = 2 ** 31
        tenth_of_max_negative = max_negative / 10
        
        end = pos
        num = 0
        # Read in the actual numeric as positive number
        while is_positive and end < len(s) and ord("0") <= ord(s[end]) and ord(s[end]) <= ord("9"): 

              if tenth_of_max_positive < num: return max_positive
              num = num * 10
              if max_positive - num < (ord(s[end]) - ord("0")): return max_positive
              num = num + (ord(s[end]) - ord("0"))
              
              end = end + 1
              
        # Read in the actual numeric as negative number
        while not is_positive and end < len(s) and ord("0") <= ord(s[end]) and ord(s[end]) <= ord("9"): 

              if tenth_of_max_negative < num: return -1 * max_negative
              num = num * 10
              if max_negative - num < (ord(s[end]) - ord("0")): return -1 * max_negative
              num = num + (ord(s[end]) - ord("0"))
              
              end = end + 1        
              
        return num if is_positive else -1 * num
        
        


solution = Solution()
assert solution.myAtoi("42") == 42, "Failed to find solution"
assert solution.myAtoi("   -42") == -42, "Failed to find solution"
assert solution.myAtoi("4193 with words") == 4193, "Failed to find solution"
print("Passed All Test Examples")