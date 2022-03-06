class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        left, right = 0, 0
        current_profit, best_profit = 0, 0
        while right < len(prices):
            if prices[right] < prices[left]:
                left = right
            else: 
                current_profit = prices[right] - prices[left]
                if current_profit > best_profit: best_profit = current_profit
                right = right + 1
                
        return best_profit
            
        
    def maxProfit_dp(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1: return 0
        
        # smallest price so far, greatest price so far, best profit so far
        dp = [[0, 0, 0] for i in prices]
        
        dp[0] = (prices[0], prices[0], 0)

        for i in range(1, len(prices)):
            
            if prices[i] < dp[i - 1][0]: # New cycle, register min of cycle and set max of cycle
                dp[i][0] = prices[i]
                dp[i][1] = prices[i]
            else: # Old cycle, find highest price
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = max(prices[i], dp[i - 1][1])

            
            current_profit = dp[i][1] - dp[i][0]
            dp[i][2] = max(current_profit, dp[i - 1][2])
            
        return dp[len(prices) - 1][2]
            

solution = Solution()
print("Solution", solution.groupAnagrams(["eat","tea","tan","ate","nat","bat"])) 
print("Expected", [["bat"],["nat","tan"],["ate","eat","tea"]])
# print("Passed All Test Examples")