class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        // hashmap
        unordered_map<int, bool> hash;
        
        for (auto num : nums) {
            
            
            
            // check if it's lonely based on integers in the map so far
            if (hash.find(num) != hash.end()) {
                hash[num] = false;
            } else {
                hash[num] = true;
            }
            
            
            if (hash.find(num + 1) != hash.end()) {
                hash[num] = false;
                hash[num + 1] = false;
            }
            
            if (hash.find(num - 1) != hash.end()) {
                hash[num] = false;
                hash[num - 1] = false;
            }
            
            
            
        }
        
        vector<int> ans;
        
        for (const auto& [key, val] : hash) {
            if (val) { 
                ans.push_back(key);
            }
        }
        
        return ans;
        
    }
};