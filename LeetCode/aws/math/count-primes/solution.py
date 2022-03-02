class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2: return 0
        
        sieve = [0 if i%2==1 else 1 for i in range(1, n + 1)]
        sieve[0] = 0
        sieve[1] = 0
        sieve[2] = 1

        
        sqrt_n = int(n ** 0.5)
        for i in range(3, 1 + sqrt_n):
            if sieve[i]:
                sieve[i*i:n:i] = [0] * len(sieve[i*i:n:i])
                    
        return sum(sieve)

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")