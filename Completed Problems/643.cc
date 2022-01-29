class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double average = 0;
        
        for (int i = 0; i < k; i++) {
            average += nums[i];
        }
        
        average /= k;
        
        
        // now we have the initial moving average, continue looping 
        // keeping our window average intact
        double ans = average;
        
        // loop through rest of array; i = end of window
        for (int i = k; i < nums.size(); i++) {
            // move window
            int newNum = nums[i];
            int discardedNum = nums[i-k];
            
            
            // update average
            average += (double)newNum / (double) k;
            
            average -= (double) discardedNum / (double) k;
            
            ans = max(average, ans);
        }
        
        return ans;
    }
};