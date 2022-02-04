class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        
        // num elements in window
        vector<int> prefixSum;
        unordered_map<int, vector<int> > hash;
        
        // Calculate prefix sum
        prefixSum.push_back(nums[0] == 0 ? -1 : 1);
        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] == 0) {
                prefixSum.push_back(-1 + prefixSum[i-1]);
            } else {
                prefixSum.push_back(1 + prefixSum[i-1]);
            }
            
            // initialize vectors
            hash[prefixSum.back()] = {};
        }
        
        
        // Use prefix sum to find answer???
        int maxLength = 0;
        for (int i = 0; i < prefixSum.size(); i++) {
            // Keep track of values that are all of the same number of ones and zeroes from start
            
            hash[prefixSum[i]].push_back(i);
        }
        
        for (auto const& [key, val] : hash) {
            
            if (key == 0) {
                maxLength = max(maxLength, val.back() + 1);
            } else if (val.size() >= 2) {
                maxLength = max(maxLength, val.back() - val.front());
            } 
        }
        
        return maxLength;
    }
};