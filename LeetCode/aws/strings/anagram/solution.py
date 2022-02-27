class Solution(object):
    
    def hasher(self, space): 
        hash_val = ""
        for i in range(len(space)):
            if space[i] != 0:
                hash_val = hash_val + str(chr(i + 97)) + str(space[i])
        return hash_val
    
    
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        word_cache = dict()
        
        for s in strs:
            hash_space = [0 for _ in range(26)]
            
            for c in s: hash_space[ord(c) - ord("a")] +=1
            hash_val = self.hasher(hash_space)
            
            if hash_val not in word_cache: word_cache[hash_val] = []
            word_cache[hash_val].append(s)
        
        # print(word_cache.keys())
        return list(word_cache.values())

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")