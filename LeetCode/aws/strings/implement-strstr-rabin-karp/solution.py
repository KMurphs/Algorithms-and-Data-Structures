def get_lowercase_rank(string, index): return ord(string[index]) - ord('a') if index < len(string) else None

DEBUG = 0
def debug_print(*args, **kwargs):
    if DEBUG: 
        print(args if args else "", kwargs if kwargs else "")

class Solution(object):
    
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        prime = 199 # used to avoid overflow during hash computation. 
        if len(needle) > len(haystack): return -1
        if len(needle) == 0: return 0
        if len(needle) == len(haystack): return 0 if needle == haystack else -1
        
        window_hash = 0
        needle_hash = 0
        for i in range(len(needle)):
            window_hash = ( 26 * window_hash + get_lowercase_rank(haystack, i) ) % prime
            needle_hash = ( 26 * needle_hash + get_lowercase_rank(needle, i) ) % prime
            
        if window_hash == needle_hash: 
            is_match = True
            for i in range(len(needle)): 
                is_match = is_match and (needle[i] == haystack[i])
            if is_match: return 0
            
            
        debug_print(window_hash, needle_hash)

        for right in range(len(needle), len(haystack)):
            left = right - len(needle)
            window_hash_shrank = window_hash - ( get_lowercase_rank(haystack, left) * (26 ** (len(needle) - 1)) % prime  )
            window_hash = ( (26 * window_hash_shrank) + get_lowercase_rank(haystack, right) ) % prime 
            

            debug_print("   ", window_hash_shrank, window_hash, left, right)
            
            
            if window_hash == needle_hash: 
                debug_print("hit")
                is_match = True
                for i in range(len(needle)): 
                    is_match = is_match and (needle[i] == haystack[left + 1 + i])
                if is_match: return left + 1

        return -1
            

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")