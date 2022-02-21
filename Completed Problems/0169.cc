class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = 0;
            }
            hash[nums[i]]++;
            if (hash[nums[i]] > nums.size() / 2) { return nums[i];}
        }
        
        return -1;
    }
};
