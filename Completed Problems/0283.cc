class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int numZeroes = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     numZeroes += nums[i] == 0;
        // }
        // 
        int filledTo = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (filledTo == i) { 
                                    filledTo++;

                    continue; }
                nums[filledTo] = nums[i];
                nums[i] = 0;
                filledTo++;
            }
        }
    }
};