class Solution {
public:
    int jump(vector<int>& nums) {  
        if (nums.size() == 1) { return 0; }
        int totalJumps = 1;

        int currentDistance = nums[0];
        int nextMax = -1;
        
        for (int i = 1; i < nums.size() - 1; i++) {
            
            
            nextMax = max(nextMax, nums[i] + i);
            
            if (currentDistance == i) {
                // take next jump
                
                totalJumps++;
                currentDistance = nextMax;
                nextMax = -1;
            } 
        }
        
        
        return totalJumps;
    }
};