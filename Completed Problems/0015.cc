class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        
        // minor optimization: remove duplicates that appear more than 3 times
        unordered_map<int, int> duplicateCount;
        for (int num : nums) {
            if (duplicateCount.find(num) == duplicateCount.end()) {
                duplicateCount[num] = 0;
            }
            duplicateCount[num]++;
        }
        
        nums.clear();
        for (auto [key, val] : duplicateCount) {
            
            if (val > 3) { val = 3; }
            
            while (val--) {
                nums.push_back(key);
            }
        }
        
        
        
        // Our solution will use a map to store potential solutions
        // sums and then do n^2 search to check the other ones
        
        // Key - given an i, what j + k need to be to add up to zero
        // Val - Index of i
        unordered_map<int, int> hash;
        
        // Fill hashmap
        for (int i = nums.size() - 1; i >= 0; i--) {
            // Store minimum possible values since we want the first 
            // occurrence for looping later without running into duplicates
            hash[-nums[i]] = i;
        }
        
        set<vector<int> > ans_set;
        
        for (int j = 0; j < nums.size(); j++) {
            
            // Do combinations of j and k
            // skips duplicates since we're only going 0->j-1
            for (int k = 0; k < j; k++) {
                
                int sum = nums[j] + nums[k];
                
                if (hash.find(sum) != hash.end()) {
                    // Found! check if unique
                    
                    // Same principle as 0->j-1 for k, except it's for i
                    if (hash[sum] < k) {
                        // Unique!!
                        vector<int> solve = {nums.at(hash[sum]), nums[j], nums[k]};
                        sort(solve.begin(), solve.end());
                        ans_set.insert(solve);
                    }
                }
            }
        }
        
        for (vector<int> singleAns : ans_set) {
            ans.push_back(singleAns);
        }
        
        return ans;
    }
};