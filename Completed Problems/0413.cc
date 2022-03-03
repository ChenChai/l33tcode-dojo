class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int prevDiff = 0;
        int arithSize = 1;
        
        int total = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            
            int currentDiff = nums[i] - nums[i-1];
            
            if (currentDiff != prevDiff) {
                // reset arithmetic sequence
                arithSize = 1;
                prevDiff = currentDiff;
            }
            
            arithSize++;
            
            if (arithSize >= 3) {
                // Each additional length increases the number
                // of arithmetic slices by the current length
                total += arithSize - 2;
            }
        }
        
        return total;
    }
};