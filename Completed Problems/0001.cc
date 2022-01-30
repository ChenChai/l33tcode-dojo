class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (hash.find(x) != hash.end()) {
                return {i, hash[x]};   
            }
            
            hash[target - x] = i;
        }
        
        // Should never be reached.
        return {};
    }
};