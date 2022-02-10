class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // This question is similar to the 
        // same number of 1s and zeros in subarray question
        
        // We'll tackle it using a prefix sum vector then hash map
        // to figure out how many times there is a difference of k between
        // entries withing the prefix sum vector.
        
        // Start it off with zero since that's the starting value of the array essentially
        vector<int> prefixSum = {nums[0]};
        
        // Create prefix sum tree
        for (int i = 1; i < nums.size(); i++) {
            prefixSum.push_back(prefixSum[i-1] + nums[i]);
        }
        
        int total = 0;
        // Calculate number of values that add up
        unordered_map<int, int> hash;
        hash[k] = 1; // from start of array
        for (int i = 0; i < prefixSum.size(); i++) {
            if (hash.find(prefixSum[i]) != hash.end()) {
                // We found a match!!
                total += hash[prefixSum[i]];
            }
            
            if (hash.find(prefixSum[i] + k) == hash.end()) {
                hash[prefixSum[i] + k] = 0;
            }
            hash[prefixSum[i] + k]++;
            
        }
        
        return total;
        
    }
};