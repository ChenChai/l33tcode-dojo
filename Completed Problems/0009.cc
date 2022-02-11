class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        // the furthest index you can jump to from this square directly  
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // You can't reach this square rip
            if (dp[i-1] < i) { return false; }
            dp[i] = max(dp[i-1], nums[i] + i);
        }
        
        return true;
    }
};