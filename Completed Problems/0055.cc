class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (maxReachable < i) { return false; }

            maxReachable = max(
                maxReachable,
                i + nums[i]
            );
        }
        
        return true;
    }
};