class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removed = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            int x = nums[i];
            if (x == val) {
                
                nums[i] = nums.back();
                nums.pop_back();
                
                i--;
            }
        }
        
        return nums.size();
    }
};