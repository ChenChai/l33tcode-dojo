class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // dp[i] is the minimum cost to reach step i
        // Add 1 to represent getting to the final part of the next floor
        vector<int> dp(cost.size() + 1);
        cost.push_back(0); // 'free' to get to the top of the floor
        
        // First step has a certain cost to take
        dp[0] = cost[0];
        // Alternatively, take the second step with less cost
        dp[1] = cost[1];
        
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = min(
                
                // Climb 2 steps to get to this location
                dp[i - 2],
                // Climb 1 step to get to this location
                dp[i - 1]
            ) + cost[i]; // add cost of current step
        }
        
        return dp.back();
    }
};