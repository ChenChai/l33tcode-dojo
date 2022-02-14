class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // first we'll count how many of each number there are in the array
        map<int, int> hash;
        
        for (int num : nums) {
            if (hash.find(num) == hash.end()) {
                hash[num] = 0;
            }
            hash[num]++;
        }
        
        // C++ has an automatically sorted set
        // We'll use this to remove duplicates and sort the input nums
        set<int> numsSortedUnique(nums.begin(), nums.end());
        
        // dp[i] represents the maximum value we can get 
        // after deleting the nth unique number
        //
        // Could simplify to just two variables to have O(1) DP memo structure
        vector<int> dp;
            
        // When we take a number we eliminate the next number as a possibility 
        int lastNum = INT_MIN;
        for (auto num : numsSortedUnique) {
            // cout << " num = " << num << " lastNUM = " << lastNum;
            if (dp.empty()) {
                // Can delete num x times
                dp.push_back(num * hash[num]);
                // Next number is big enough that we don't need to worry about collisions from deleting (i.e. > nums[i] + 1)
                // cout << " case 1";
            } else if (num > lastNum + 1) {
                dp.push_back(num * hash[num] + dp[dp.size() - 1]);
                // cout << "case 2";
            } else {
                if (dp.size() == 1) {
                    dp.push_back(max(
                        // Use this current number
                        // means we can't use previous one
                        num * hash[num],
                        dp[dp.size() - 1]
                    ));
                    
                } else {
                    // We need to choose whether to use this current number or
                    // not!
                    dp.push_back(max(
                        // Use this current number
                        // means we can't use previous one
                        dp[dp.size() - 2] + num * hash[num],
                        dp[dp.size() - 1]
                    ));

                }
                
                // cout << " case 3";
            }
            // cout << endl;
            lastNum = num;
        }
        
        
        return dp.back();
    }
};