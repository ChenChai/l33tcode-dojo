class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) {
            int maxNum = 0;
            for (int num : nums) {
                maxNum = max(maxNum, num);
            }
            return maxNum;
        }
        
        // dp[i][j] means max possible value robbed
        // after house i; if j==1 then we robbed house 1
        // otherwise we didn't
        vector<vector<int> > dp(nums.size(), {-1, -1});
        
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        
        
        for (int i = 2; i < nums.size(); i++) {
            
            // didn't rob house one
            dp[i][0] = max(dp[i-2][0] + nums[i], dp[i-1][0]);
            
            // robbed house i
            dp[i][1] = max(dp[i-2][1] + nums[i], dp[i-1][1]);
        }
        
        
        // final house is attached to the first so we need to special exception
        return max(dp.back()[0], 
                   dp[nums.size() - 2][1]); // can't rob last house if we robbed first one
    }
};