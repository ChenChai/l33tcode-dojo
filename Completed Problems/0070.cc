class Solution {
public:
    int climbStairs(int n) {
        
        // DYNAMIC PROGRAMMING!!!
        
        // dp[i][j] means the number of ways that you can get to this step with.
        vector<int> dp(n + 1);
        
        // Only one way to reach first step!
        dp[0] = 1; 
        dp[1] = 1;
        
        for (int i = 2; i < dp.size(); i++) {
            
            dp[i] = 
                // Two ways of reaching this:
                // From the previous step
                dp[i-1]
                // Or from two steps back
                + dp[i-2];
        }
        
        // It's pretty much just fibonacci sequence right
        return dp[n];
    }
};