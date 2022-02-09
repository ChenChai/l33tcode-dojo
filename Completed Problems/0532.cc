class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int numPairs = 0;
        
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            hash[num + k] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (hash.find(num) != hash.end() &&  hash[num] != i) {
                numPairs++;
                hash.erase(num);
            }
        }
        
        return numPairs;
    }
};