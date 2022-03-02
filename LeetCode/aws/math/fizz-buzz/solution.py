class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        sol = list()
        for i in range(1, n + 1):
            curr = ""
            if i % 3 == 0: curr = curr + "Fizz"
            if i % 5 == 0: curr = curr + "Buzz"
            if curr == "": curr = str(i)
            sol.append(curr)
        return sol
            

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")