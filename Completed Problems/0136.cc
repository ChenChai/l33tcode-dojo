class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; // use bitwise operations?
        for (int i = 0; i < nums.size(); i++) {
            // If you xor something twice it'll cancel out
            // but the single number won't cancel out
            ans ^= nums[i];
        }
        
        return ans;
    }
};