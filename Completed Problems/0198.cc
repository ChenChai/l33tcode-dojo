class Solution {
public:
    int rob(vector<int>& nums) {
        
        // maxPossible[i][j] represents the maximum possible value you
        // can have robbed by the time you've reached this house,
        // ascending the street. If j = 1, you robbed the house, if j = 0, you didn't
        vector<vector<int> > maxPossible(nums.size(), vector<int>(2, -1));
        
        //
        maxPossible[0][0] = 0; // didn't rob
        maxPossible[0][1] = nums[0]; // robbed first house
        
        for (int i = 1; i < nums.size(); i++) {
            // Rob house i
            // This means we can't have robbed previous house
            maxPossible[i][1] = nums[i] + maxPossible[i-1][0];
            
            // don't rob house i
            // This means we can have robbed previous house
            maxPossible[i][0] = max(maxPossible[i-1][1], maxPossible[i-1][0]);
        }
        
        return max (maxPossible.back()[0], maxPossible.back()[1]);
    }
};